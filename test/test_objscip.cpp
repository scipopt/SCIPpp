#include <algorithm>
#include <array>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

#include "scippp/model.hpp"
#include "scippp/parameters.hpp"
#include "scippp/solving_statistics.hpp"
#include <objscip/objbenders.h>
#include <objscip/objbenderscut.h>
#include <objscip/objbranchrule.h>
#include <objscip/objconshdlr.h>
#include <objscip/objcutsel.h>
#include <objscip/objdisp.h>
#include <objscip/objeventhdlr.h>
#include <objscip/objheur.h>
#include <objscip/objiisfinder.h>
#include <objscip/objmessagehdlr.h>
#include <objscip/objnodesel.h>
#include <objscip/objpresol.h>
#include <objscip/objpricer.h>
#include <objscip/objprobdata.h>
#include <objscip/objprop.h>
#include <objscip/objreader.h>
#include <objscip/objrelax.h>
#include <objscip/objsepa.h>
#include <objscip/objvardata.h>
#include <scip/cons_linear.h>

using namespace boost::algorithm;
using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(ObjSCIP)

/**
 * Counts how often a new best solution is found.
 */
class BestSolCounter : public scip::ObjEventhdlr {
    int& m_nBestSols;

public:
    BestSolCounter(SCIP* scip, int& nBestSols)
        : scip::ObjEventhdlr(scip, "bestsolcounter", "counts new best solutions")
        , m_nBestSols(nBestSols)
    {
    }
    SCIP_DECL_EVENTINIT(scip_init)
    override
    {
        return SCIPcatchEvent(scip, SCIP_EVENTTYPE_BESTSOLFOUND, eventhdlr, nullptr, nullptr);
    }
    SCIP_DECL_EVENTEXIT(scip_exit)
    override
    {
        return SCIPdropEvent(scip, SCIP_EVENTTYPE_BESTSOLFOUND, eventhdlr, nullptr, -1);
    }
    SCIP_DECL_EVENTEXEC(scip_exec)
    override
    {
        ++m_nBestSols;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseEventHandler)
{
    int nBestSols { 0 };
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    BOOST_TEST(model.includeEventhdlr<BestSolCounter>(nBestSols) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_TEST(model.getNSols() > 0);
    BOOST_TEST(nBestSols > 0);
}

BOOST_AUTO_TEST_CASE(IncludeEventHandlerTwice)
{
    int nBestSols { 0 };
    Model model("Simple");
    BOOST_TEST(model.includeEventhdlr<BestSolCounter>(nBestSols) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    // SCIP rejects a second event handler with the same name, the handler is then deleted by SCIP++
    BOOST_TEST(model.includeEventhdlr<BestSolCounter>(nBestSols) == nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_INVALIDDATA);
}

/**
 * Lazily enforces a non-negative variable to be zero, without any constraint.
 */
class ZeroVarConshdlr : public scip::ObjConshdlr {
    SCIP_VAR* m_var;

    [[nodiscard]] bool isViolated(SCIP* scip, SCIP_SOL* sol) const
    {
        return SCIPisFeasPositive(scip, SCIPgetSolVal(scip, sol, m_var));
    }

    SCIP_RETCODE enforce(SCIP* scip, SCIP_RESULT* result) const
    {
        *result = SCIP_FEASIBLE;
        if (isViolated(scip, nullptr)) {
            SCIP_Bool infeasible { FALSE };
            SCIP_Bool tightened { FALSE };
            SCIP_CALL(SCIPtightenVarUb(scip, SCIPvarGetTransVar(m_var), 0.0, FALSE, &infeasible, &tightened));
            *result = infeasible ? SCIP_CUTOFF : SCIP_REDUCEDDOM;
        }
        return SCIP_OKAY;
    }

public:
    ZeroVarConshdlr(SCIP* scip, SCIP_VAR* var)
        : scip::ObjConshdlr(
            scip,
            "zerovar",
            "enforces a variable to be zero",
            0, // sepapriority
            -1, // enfopriority, negative to be called for integral solutions only
            -1, // checkpriority
            -1, // sepafreq
            -1, // propfreq
            -1, // eagerfreq
            0, // maxprerounds
            FALSE, // delaysepa
            FALSE, // delayprop
            FALSE, // needscons
            SCIP_PROPTIMING_BEFORELP,
            SCIP_PRESOLTIMING_FAST)
        , m_var(var)
    {
    }
    SCIP_DECL_CONSTRANS(scip_trans)
    override
    {
        // there are no constraints of this handler to transform
        return SCIP_INVALIDCALL;
    }
    SCIP_DECL_CONSENFOLP(scip_enfolp)
    override
    {
        return enforce(scip, result);
    }
    SCIP_DECL_CONSENFOPS(scip_enfops)
    override
    {
        return enforce(scip, result);
    }
    SCIP_DECL_CONSCHECK(scip_check)
    override
    {
        *result = isViolated(scip, sol) ? SCIP_INFEASIBLE : SCIP_FEASIBLE;
        return SCIP_OKAY;
    }
    SCIP_DECL_CONSLOCK(scip_lock)
    override
    {
        // called without constraint as this handler does not need constraints, increasing the variable may violate it
        return SCIPaddVarLocksType(scip, SCIPvarGetTransVar(m_var), locktype, nlocksneg, nlockspos);
    }
};

BOOST_AUTO_TEST_CASE(UseConstraintHandler)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    model.setObjsense(Sense::MAXIMIZE);
    BOOST_TEST(model.includeConshdlr<ZeroVarConshdlr>(x1.getVar()) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
    BOOST_TEST(x1.getSolValAsInt(model.getBestSol()) == 0);
    BOOST_TEST(x2.getSolValAsInt(model.getBestSol()) == 1);
}

/**
 * Proposes the solution where a given binary variable is one and all others are zero, before presolving.
 */
class OneVarHeur : public scip::ObjHeur {
    SCIP_VAR* m_var;
    int m_nFound { 0 };

public:
    OneVarHeur(SCIP* scip, SCIP_VAR* var)
        : scip::ObjHeur(
            scip,
            "onevar",
            "proposes a solution where a given binary variable is one",
            'O', // dispchar
            20000, // priority, higher than the one of the trivial heuristic to be called first
            1, // freq
            0, // freqofs
            -1, // maxdepth
            SCIP_HEURTIMING_BEFOREPRESOL,
            FALSE) // usessubscip
        , m_var(var)
    {
    }
    [[nodiscard]] int getNFound() const
    {
        return m_nFound;
    }
    SCIP_DECL_HEUREXEC(scip_exec)
    override
    {
        SCIP_SOL* sol { nullptr };
        SCIP_CALL(SCIPcreateSol(scip, &sol, heur));
        SCIP_CALL(SCIPsetSolVal(scip, sol, SCIPvarGetTransVar(m_var), 1.0));
        SCIP_Bool stored { FALSE };
        SCIP_CALL(SCIPtrySolFree(scip, &sol, FALSE, FALSE, TRUE, TRUE, TRUE, &stored));
        if (stored) {
            ++m_nFound;
            *result = SCIP_FOUNDSOL;
        } else {
            *result = SCIP_DIDNOTFIND;
        }
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseHeuristic)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    const auto* heur { model.includeHeur<OneVarHeur>(x1.getVar()) };
    BOOST_REQUIRE(heur != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    // the heuristic is called first, so its solution is stored as there is no other solution yet
    BOOST_TEST(heur->getNFound() == 1);
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

/**
 * Fixes a variable to zero, e.g., based on problem-specific knowledge.
 */
class ZeroVarPresol : public scip::ObjPresol {
    SCIP_VAR* m_var;

public:
    ZeroVarPresol(SCIP* scip, SCIP_VAR* var)
        : scip::ObjPresol(
            scip,
            "zerovar",
            "fixes a variable to zero",
            10000000, // priority, higher than the ones of the default presolvers to be called first
            -1, // maxrounds
            SCIP_PRESOLTIMING_FAST)
        , m_var(var)
    {
    }
    SCIP_DECL_PRESOLEXEC(scip_exec)
    override
    {
        SCIP_Bool infeasible { FALSE };
        SCIP_Bool fixed { FALSE };
        SCIP_CALL(SCIPfixVar(scip, SCIPvarGetTransVar(m_var), 0.0, &infeasible, &fixed));
        if (infeasible) {
            *result = SCIP_CUTOFF;
        } else if (fixed) {
            ++(*nfixedvars);
            *result = SCIP_SUCCESS;
        } else {
            *result = SCIP_DIDNOTFIND;
        }
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UsePresolver)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 2, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    BOOST_TEST(model.includePresol<ZeroVarPresol>(x1.getVar()) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    // without the presolver, x_1 = 1 would be optimal with objective 2
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
    BOOST_TEST(x1.getSolValAsInt(model.getBestSol()) == 0);
    BOOST_TEST(x2.getSolValAsInt(model.getBestSol()) == 1);
}

/**
 * Counts how often it is called for domain propagation.
 */
class CountingProp : public scip::ObjProp {
    int m_nCalls { 0 };

public:
    explicit CountingProp(SCIP* scip)
        : scip::ObjProp(
            scip,
            "counting",
            "counts how often it is called",
            0, // priority
            1, // freq
            FALSE, // delay
            SCIP_PROPTIMING_BEFORELP,
            0, // presolpriority
            -1, // presolmaxrounds
            SCIP_PRESOLTIMING_NONE)
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_PROPEXEC(scip_exec)
    override
    {
        ++m_nCalls;
        *result = SCIP_DIDNOTFIND;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UsePropagator)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 2, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    // otherwise presolving solves the problem and no node is processed
    model.setParam(params::PRESOLVING::MAXROUNDS, 0);
    const auto* prop { model.includeProp<CountingProp>() };
    BOOST_REQUIRE(prop != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(prop->getNCalls() > 0);
}

/**
 * Adds max 1.1 x_1 + x_2 s.t. 2 x_1 + 3 x_2 <= 4 with binary variables, whose LP relaxation has the fractional
 * solution x_1 = 1, x_2 = 2/3, while x_1 = 1, x_2 = 0 is optimal.
 */
array<Var, 2> addFractionalProblem(Model& model)
{
    auto x1 = model.addVar("x_1", 1.1, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    model.addConstr(2 * x1 + 3 * x2 <= 4, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    // otherwise presolving or propagation solve the problem before the LP relaxation is solved
    model.setParam(params::PRESOLVING::MAXROUNDS, 0);
    model.setParam(params::PROPAGATING::MAXROUNDSROOT, 0);
    return { x1, x2 };
}

/**
 * Separates the cut x_1 + x_2 <= 1 at the root, which is valid for binary variables with 2 x_1 + 3 x_2 <= 4.
 */
class CapacitySepa : public scip::ObjSepa {
    array<SCIP_VAR*, 2> m_vars;
    int m_nCuts { 0 };

public:
    CapacitySepa(SCIP* scip, SCIP_VAR* x1, SCIP_VAR* x2)
        : scip::ObjSepa(
            scip,
            "capacity",
            "separates x_1 + x_2 <= 1",
            1000000, // priority, higher than the ones of the default separators to be called first
            0, // freq
            1.0, // maxbounddist
            FALSE, // usessubscip
            FALSE) // delay
        , m_vars { x1, x2 }
    {
    }
    [[nodiscard]] int getNCuts() const
    {
        return m_nCuts;
    }
    SCIP_DECL_SEPAEXECLP(scip_execlp)
    override
    {
        *result = SCIP_DIDNOTFIND;
        SCIP_ROW* row { nullptr };
        SCIP_CALL(SCIPcreateEmptyRowSepa(scip, &row, sepa, "capacity", -SCIPinfinity(scip), 1.0, FALSE, FALSE, TRUE));
        for (auto* var : m_vars) {
            SCIP_CALL(SCIPaddVarToRow(scip, row, SCIPvarGetTransVar(var), 1.0));
        }
        if (SCIPisCutEfficacious(scip, nullptr, row)) {
            SCIP_Bool infeasible { FALSE };
            SCIP_CALL(SCIPaddRow(scip, row, FALSE, &infeasible));
            ++m_nCuts;
            *result = infeasible ? SCIP_CUTOFF : SCIP_SEPARATED;
        }
        return SCIPreleaseRow(scip, &row);
    }
};

BOOST_AUTO_TEST_CASE(UseSeparator)
{
    Model model("Simple");
    auto [x1, x2] = addFractionalProblem(model);
    const auto* sepa { model.includeSepa<CapacitySepa>(x1.getVar(), x2.getVar()) };
    BOOST_REQUIRE(sepa != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(sepa->getNCuts() > 0);
}

/**
 * Selects all cuts, up to the maximal number of cuts to select.
 */
class AllCutsel : public scip::ObjCutsel {
    int m_nCalls { 0 };

public:
    explicit AllCutsel(SCIP* scip)
        : scip::ObjCutsel(
            scip,
            "all",
            "selects all cuts",
            1000000) // priority, higher than the ones of the default cut selectors to be used
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_CUTSELSELECT(scip_select)
    override
    {
        ++m_nCalls;
        *nselectedcuts = min(ncuts, maxnselectedcuts);
        *result = SCIP_SUCCESS;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseCutSelector)
{
    Model model("Simple");
    auto [x1, x2] = addFractionalProblem(model);
    BOOST_REQUIRE(model.includeSepa<CapacitySepa>(x1.getVar(), x2.getVar()) != nullptr);
    const auto* cutsel { model.includeCutsel<AllCutsel>() };
    BOOST_REQUIRE(cutsel != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(cutsel->getNCalls() > 0);
}

/**
 * Branches on the first fractional variable of the LP solution.
 */
class FirstFracBranchrule : public scip::ObjBranchrule {
    int m_nCalls { 0 };

public:
    explicit FirstFracBranchrule(SCIP* scip)
        : scip::ObjBranchrule(
            scip,
            "firstfrac",
            "branches on the first fractional variable",
            1000000, // priority, higher than the ones of the default branching rules to be used
            -1, // maxdepth
            1.0) // maxbounddist
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_BRANCHEXECLP(scip_execlp)
    override
    {
        ++m_nCalls;
        SCIP_VAR** cands { nullptr };
        int nCands { 0 };
        SCIP_CALL(SCIPgetLPBranchCands(scip, &cands, nullptr, nullptr, &nCands, nullptr, nullptr));
        if (nCands == 0) {
            *result = SCIP_DIDNOTRUN;
            return SCIP_OKAY;
        }
        SCIP_CALL(SCIPbranchVar(scip, cands[0], nullptr, nullptr, nullptr));
        *result = SCIP_BRANCHED;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseBranchingRule)
{
    Model model("Simple");
    addFractionalProblem(model);
    // otherwise the problem is solved at the root by separation or conflict analysis
    model.setParam(params::SEPARATING::MAXROUNDSROOT, 0);
    model.setParam(params::CONFLICT::ENABLE, false);
    const auto* branchrule { model.includeBranchrule<FirstFracBranchrule>() };
    BOOST_REQUIRE(branchrule != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(branchrule->getNCalls() > 0);
}

/**
 * Selects nodes in depth-first order.
 */
class DepthFirstNodesel : public scip::ObjNodesel {
    int m_nCalls { 0 };

public:
    explicit DepthFirstNodesel(SCIP* scip)
        : scip::ObjNodesel(
            scip,
            "depthfirst",
            "selects nodes in depth-first order",
            1000000, // stdpriority, higher than the ones of the default node selectors to be used
            0) // memsavepriority
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_NODESELSELECT(scip_select)
    override
    {
        ++m_nCalls;
        *selnode = SCIPgetPrioChild(scip);
        if (*selnode == nullptr) {
            *selnode = SCIPgetPrioSibling(scip);
        }
        if (*selnode == nullptr) {
            *selnode = SCIPgetBestLeaf(scip);
        }
        return SCIP_OKAY;
    }
    SCIP_DECL_NODESELCOMP(scip_comp)
    override
    {
        // deeper nodes first
        return SCIPnodeGetDepth(node2) - SCIPnodeGetDepth(node1);
    }
};

BOOST_AUTO_TEST_CASE(UseNodeSelector)
{
    Model model("Simple");
    addFractionalProblem(model);
    // otherwise the problem is solved at the root by separation or conflict analysis
    model.setParam(params::SEPARATING::MAXROUNDSROOT, 0);
    model.setParam(params::CONFLICT::ENABLE, false);
    const auto* nodesel { model.includeNodesel<DepthFirstNodesel>() };
    BOOST_REQUIRE(nodesel != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(nodesel->getNCalls() > 0);
}

/**
 * Counts how often it is called before the LP relaxation is solved.
 */
class CountingRelax : public scip::ObjRelax {
    int m_nCalls { 0 };

public:
    explicit CountingRelax(SCIP* scip)
        : scip::ObjRelax(
            scip,
            "counting",
            "counts how often it is called",
            0, // priority, non-negative to be called before the LP relaxation is solved
            1, // freq
            FALSE) // includeslp
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_RELAXEXEC(scip_exec)
    override
    {
        ++m_nCalls;
        *result = SCIP_DIDNOTRUN;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseRelaxator)
{
    Model model("Simple");
    addFractionalProblem(model);
    const auto* relax { model.includeRelax<CountingRelax>() };
    BOOST_REQUIRE(relax != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(relax->getNCalls() > 0);
}

/**
 * Displays how often it was displayed.
 */
class CountingDisp : public scip::ObjDisp {
    int m_nCalls { 0 };

public:
    explicit CountingDisp(SCIP* scip)
        : scip::ObjDisp(
            scip,
            "counting",
            "displays how often it was displayed",
            "calls", // header
            5, // width
            1000000, // priority, higher than the ones of the default display columns to be displayed
            100000, // position, higher than the ones of the default display columns to be the last column
            TRUE) // stripline
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_DISPOUTPUT(scip_output)
    override
    {
        ++m_nCalls;
        SCIPinfoMessage(scip, file, "%5d", m_nCalls);
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseDisplayColumn)
{
    Model model("Simple");
    // nodes have to be processed, otherwise no display line is printed
    addFractionalProblem(model);
    const auto* disp { model.includeDisp<CountingDisp>() };
    BOOST_REQUIRE(disp != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(disp->getNCalls() > 0);
}

/**
 * Writes the number of variables and constraints of a problem to files with extension cnt.
 */
class CountReader : public scip::ObjReader {
public:
    explicit CountReader(SCIP* scip)
        : scip::ObjReader(scip, "count", "writes the number of variables and constraints", "cnt")
    {
    }
    SCIP_DECL_READERWRITE(scip_write)
    override
    {
        SCIPinfoMessage(scip, file, "%d %d\n", nvars, nconss);
        *result = SCIP_SUCCESS;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseReader)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    BOOST_TEST(model.includeReader<CountReader>() != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    const auto FILE_NAME { filesystem::temp_directory_path()
        / boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%.cnt").string() };
    model.writeOrigProblem(filesystem::directory_entry(FILE_NAME));
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    ifstream file(FILE_NAME);
    ostringstream content;
    content << file.rdbuf();
    file.close();
    filesystem::remove(FILE_NAME);
    BOOST_TEST(content.str() == "2 1\n");
}

/**
 * Counts how often it is called and leaves the work to the other %IIS finders.
 */
class CountingIISfinder : public scip::ObjIISfinder {
    int m_nCalls { 0 };

public:
    explicit CountingIISfinder(SCIP* scip)
        : scip::ObjIISfinder(
            scip,
            "counting",
            "counts how often it is called",
            1000000) // priority, higher than the ones of the default IIS finders to be called first
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_IISFINDEREXEC(scip_exec)
    override
    {
        ++m_nCalls;
        *result = SCIP_DIDNOTRUN;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseIISFinder)
{
    Model model("Simple");
    const auto& [x1, x2] = model.addVars<2>("x_");
    model.addConstr(x1 + x2 >= 2, "lower");
    model.addConstr(x1 + x2 <= 1, "upper");
    model.setParam(params::IIS::SILENT, true);
    const auto* iisfinder { model.includeIISfinder<CountingIISfinder>() };
    BOOST_REQUIRE(iisfinder != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_REQUIRE(model.getStatus() == SCIP_STATUS_INFEASIBLE);
    // the default IIS finder still computes the IIS
    BOOST_TEST(model.generateIIS().consIds.size() == 2);
    BOOST_TEST(iisfinder->getNCalls() == 1);
}

/**
 * Counts how often it is called for pricing, but never adds a variable.
 */
class CountingPricer : public scip::ObjPricer {
    int m_nCalls { 0 };

public:
    explicit CountingPricer(SCIP* scip)
        : scip::ObjPricer(
            scip,
            "counting",
            "counts how often it is called",
            0, // priority
            FALSE) // delay
    {
    }
    [[nodiscard]] int getNCalls() const
    {
        return m_nCalls;
    }
    SCIP_DECL_PRICERREDCOST(scip_redcost)
    override
    {
        ++m_nCalls;
        *result = SCIP_SUCCESS;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UsePricer)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    // otherwise presolving solves the problem and no LP is solved
    model.setParam(params::PRESOLVING::MAXROUNDS, 0);
    const auto* pricer { model.includePricer<CountingPricer>() };
    BOOST_REQUIRE(pricer != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(pricer->getNCalls() > 0);
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(IncludePricerTwice)
{
    Model model("Simple");
    BOOST_TEST(model.includePricer<CountingPricer>() != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    // SCIP rejects a second pricer with the same name, the pricer is then deleted by SCIP++ without being activated
    BOOST_TEST(model.includePricer<CountingPricer>() == nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_INVALIDDATA);
}

/**
 * Decomposes min x + y s.t. y >= 2 - c x with binary x and continuous y >= 0 into the master problem min x, which is
 * the model, and the subproblem min y s.t. y >= 2 - c x, y >= 0, where x is fixed to its value in the master problem.
 * The decomposition computes the optimal value max(0, 2 - c x) of the subproblem itself, so there is no SCIP instance
 * for it.
 */
class DemandBenders : public scip::ObjBenders {
    SCIP_VAR* m_masterX;
    double m_coverage;
    int m_nSolves { 0 };

public:
    DemandBenders(SCIP* scip, SCIP_VAR* masterX, double coverage)
        : scip::ObjBenders(
            scip,
            "demand",
            "decomposes the demand problem",
            1, // priority, positive to be higher than the one of the inactive default Benders' decomposition
            TRUE, // cutlp
            TRUE, // cutpseudo
            TRUE, // cutrelax
            FALSE) // shareauxvars
        , m_masterX(masterX)
        , m_coverage(coverage)
    {
    }
    [[nodiscard]] int getNSolves() const
    {
        return m_nSolves;
    }
    SCIP_DECL_BENDERSCREATESUB(scip_createsub)
    override
    {
        SCIP_CALL(SCIPaddBendersSubproblem(scip, benders, nullptr));
        // required as the subproblem is solved by this decomposition
        SCIPbendersSetSubproblemType(benders, probnumber, SCIP_BENDERSSUBTYPE_CONVEXCONT);
        // the smallest optimal value of the subproblem, which is attained for x = 1
        SCIPbendersUpdateSubproblemLowerbound(benders, probnumber, max(0.0, 2.0 - m_coverage));
        return SCIP_OKAY;
    }
    SCIP_DECL_BENDERSSOLVESUBCONVEX(scip_solvesubconvex)
    override
    {
        ++m_nSolves;
        *objective = max(0.0, 2.0 - m_coverage * SCIPgetSolVal(scip, sol, m_masterX));
        *result = SCIP_FEASIBLE;
        return SCIP_OKAY;
    }
    SCIP_DECL_BENDERSGETVAR(scip_getvar)
    override
    {
        // there is no SCIP instance for the subproblem, hence no variables to map
        *mappedvar = nullptr;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseBenders)
{
    Model model("Master");
    auto x = model.addVar("x", 1, VarType::BINARY);
    // without coverage, the subproblem has the constant optimal value 2, which is its lower bound, so no cut is needed
    const auto* benders { model.includeBenders<DemandBenders>(1, x.getVar(), 0.0) };
    BOOST_REQUIRE(benders != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(model.getStatus() == SCIP_STATUS_OPTIMAL);
    BOOST_TEST(benders->getNSolves() > 0);
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 2.0, boost::test_tools::tolerance(1e-6));
    BOOST_TEST(x.getSolValAsInt(model.getBestSol()) == 0);
}

BOOST_AUTO_TEST_CASE(IncludeBendersTwice)
{
    Model model("Master");
    auto x = model.addVar("x", 1, VarType::BINARY);
    BOOST_TEST(model.includeBenders<DemandBenders>(1, x.getVar(), 0.0) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    // SCIP rejects a second Benders' decomposition with the same name, it is then deleted by SCIP++ without being
    // activated
    BOOST_TEST(model.includeBenders<DemandBenders>(1, x.getVar(), 0.0) == nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_INVALIDDATA);
}

/**
 * Can be copied to sub-SCIPs. It is never solved, hence it creates no subproblems.
 */
class CloneableBenders : public scip::ObjBenders {
public:
    explicit CloneableBenders(SCIP* scip)
        : scip::ObjBenders(
            scip,
            "cloneable",
            "can be copied to sub-SCIPs",
            1, // priority, positive to be higher than the one of the inactive default Benders' decomposition
            TRUE, // cutlp
            TRUE, // cutpseudo
            TRUE, // cutrelax
            FALSE) // shareauxvars
    {
    }
    SCIP_DECL_OBJCLONEABLECLONE(ObjCloneable* clone)
    override
    {
        return new CloneableBenders(scip);
    }
    SCIP_DECL_OBJCLONEABLEISCLONEABLE(iscloneable)
    override
    {
        return TRUE;
    }
    SCIP_DECL_BENDERSCREATESUB(scip_createsub)
    override
    {
        return SCIP_OKAY;
    }
    SCIP_DECL_BENDERSGETVAR(scip_getvar)
    override
    {
        *mappedvar = nullptr;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(CopyBendersOnlyIfCloneable)
{
    SCIP_Bool copyBenders { FALSE };
    Model cloneable("Master");
    BOOST_REQUIRE(cloneable.includeBenders<CloneableBenders>(1) != nullptr);
    BOOST_TEST(SCIPgetBoolParam(cloneable.scip(), "benders/copybenders", &copyBenders) == SCIP_OKAY);
    BOOST_TEST(copyBenders);

    Model notCloneable("Master");
    auto x = notCloneable.addVar("x", 1, VarType::BINARY);
    BOOST_REQUIRE(notCloneable.includeBenders<DemandBenders>(1, x.getVar(), 0.0) != nullptr);
    BOOST_TEST(SCIPgetBoolParam(notCloneable.scip(), "benders/copybenders", &copyBenders) == SCIP_OKAY);
    BOOST_TEST(!copyBenders);
}

/**
 * Adds the optimality cut theta + c x >= 2 for the subproblem of DemandBenders, where theta is the auxiliary variable
 * of the subproblem in the master problem.
 */
class DemandBenderscut : public scip::ObjBenderscut {
    SCIP_VAR* m_masterX;
    double m_coverage;
    int m_nCuts { 0 };

public:
    DemandBenderscut(SCIP* scip, SCIP_VAR* masterX, double coverage)
        : scip::ObjBenderscut(
            scip,
            "demand",
            "adds the optimality cut of the demand subproblem",
            1000000, // priority, higher than the ones of the default Benders' cuts to be called first
            TRUE) // islpcut
        , m_masterX(masterX)
        , m_coverage(coverage)
    {
    }
    [[nodiscard]] int getNCuts() const
    {
        return m_nCuts;
    }
    SCIP_DECL_BENDERSCUTEXEC(scip_exec)
    override
    {
        SCIP_CONS* cons { nullptr };
        SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, "demand", 0, nullptr, nullptr, 2.0, SCIPinfinity(scip)));
        SCIP_CALL(SCIPaddCoefLinear(scip, cons, SCIPbendersGetAuxiliaryVar(benders, probnumber), 1.0));
        SCIP_CALL(SCIPaddCoefLinear(scip, cons, SCIPvarGetTransVar(m_masterX), m_coverage));
        SCIP_CALL(SCIPaddCons(scip, cons));
        SCIP_CALL(SCIPreleaseCons(scip, &cons));
        ++m_nCuts;
        *result = SCIP_CONSADDED;
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseBendersCut)
{
    Model model("Master");
    auto x = model.addVar("x", 1, VarType::BINARY);
    // x = 1 costs 1 in the master problem, whereas x = 0 costs 2 in the subproblem
    auto* benders { model.includeBenders<DemandBenders>(1, x.getVar(), 2.0) };
    BOOST_REQUIRE(benders != nullptr);
    const auto* cut { model.includeBenderscut<DemandBenderscut>(*benders, x.getVar(), 2.0) };
    BOOST_REQUIRE(cut != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(model.getStatus() == SCIP_STATUS_OPTIMAL);
    BOOST_TEST(cut->getNCuts() > 0);
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1.0, boost::test_tools::tolerance(1e-6));
    BOOST_TEST(x.getSolValAsInt(model.getBestSol()) == 1);
}

BOOST_AUTO_TEST_CASE(IncludeBenderscutTwice)
{
    Model model("Master");
    auto x = model.addVar("x", 1, VarType::BINARY);
    auto* benders { model.includeBenders<DemandBenders>(1, x.getVar(), 2.0) };
    BOOST_REQUIRE(benders != nullptr);
    BOOST_TEST(model.includeBenderscut<DemandBenderscut>(*benders, x.getVar(), 2.0) != nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    // SCIP rejects a second cut with the same name for the same Benders' decomposition, the cut is then deleted by
    // SCIP++
    BOOST_TEST(model.includeBenderscut<DemandBenderscut>(*benders, x.getVar(), 2.0) == nullptr);
    BOOST_TEST(model.getLastReturnCode() == SCIP_INVALIDDATA);
}

/**
 * Tracks whether it was deleted.
 */
class TrackingProbData : public scip::ObjProbData {
    bool& m_deleted;

public:
    explicit TrackingProbData(bool& deleted)
        : m_deleted(deleted)
    {
    }
    ~TrackingProbData() override
    {
        m_deleted = true;
    }
};

BOOST_AUTO_TEST_CASE(UseProblemData)
{
    bool deleted { false };
    {
        Model model("Simple", make_unique<TrackingProbData>(deleted));
        BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
        model.addVar("x", 1);
        model.solve();
        BOOST_TEST(model.getStatus() == SCIP_STATUS_OPTIMAL);
        // plugins access the problem data via SCIP
        BOOST_TEST(dynamic_cast<TrackingProbData*>(SCIPgetObjProbData(model.scip())) != nullptr);
        BOOST_TEST(!deleted);
    }
    // SCIP deletes the problem data when the model is destructed
    BOOST_TEST(deleted);
}

/**
 * Tracks whether it was deleted.
 */
class TrackingVardata : public scip::ObjVardata {
    bool& m_deleted;

public:
    explicit TrackingVardata(bool& deleted)
        : m_deleted(deleted)
    {
    }
    ~TrackingVardata() override
    {
        m_deleted = true;
    }
};

BOOST_AUTO_TEST_CASE(UseVariableData)
{
    bool deleted { false };
    {
        Model model("Simple");
        auto& x = model.addVar("x", make_unique<TrackingVardata>(deleted), 1, VarType::BINARY);
        BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
        model.addConstr(x >= 1, "lower");
        model.solve();
        BOOST_TEST(model.getStatus() == SCIP_STATUS_OPTIMAL);
        BOOST_TEST(x.getSolValAsInt(model.getBestSol()) == 1);
        // plugins access the variable data via SCIP
        BOOST_TEST(dynamic_cast<TrackingVardata*>(SCIPgetObjVardata(model.scip(), x.getVar())) != nullptr);
        BOOST_TEST(!deleted);
    }
    // SCIP deletes the variable data when the model is destructed
    BOOST_TEST(deleted);
}

BOOST_AUTO_TEST_CASE(AddVariableDataWithBounds)
{
    Model model("Simple");
    auto& x = model.addVar("x", make_unique<scip::ObjVardata>(), 1, VarType::CONTINUOUS, 2.0, 3.0);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    BOOST_TEST(SCIPvarGetLbOriginal(x.getVar()) == 2.0);
    BOOST_TEST(SCIPvarGetUbOriginal(x.getVar()) == 3.0);
}

BOOST_AUTO_TEST_CASE(AddVariableDataFails)
{
    bool deleted { false };
    Model model("Simple");
    // by default, SCIP++ continues after a failed call, but a variable that was not created cannot be added
    model.setScipCallWrapper([](SCIP_Retcode retcode) {
        if (retcode != SCIP_OKAY) {
            throw runtime_error("SCIP call failed");
        }
    });
    // SCIP rejects an infinite objective coefficient, the variable data is then deleted by SCIP++
    BOOST_CHECK_THROW(
        model.addVar("x", make_unique<TrackingVardata>(deleted), SCIPinfinity(model.scip())), runtime_error);
    BOOST_TEST(deleted);
}

/**
 * Forwards all messages to a file.
 */
class FileMessageHandler : public scip::ObjMessagehdlr {
    ofstream m_file;

    void write(const char* msg)
    {
        if (msg) {
            m_file << msg;
        } else {
            m_file.flush();
        }
    }

public:
    explicit FileMessageHandler(const filesystem::path& path)
        : scip::ObjMessagehdlr(false)
        , m_file(path)
    {
    }
    SCIP_DECL_MESSAGEWARNING(scip_warning)
    override
    {
        write(msg);
    }
    SCIP_DECL_MESSAGEDIALOG(scip_dialog)
    override
    {
        write(msg);
    }
    SCIP_DECL_MESSAGEINFO(scip_info)
    override
    {
        write(msg);
    }
};

BOOST_AUTO_TEST_CASE(UseMessageHandler)
{
    const auto LOG_FILE { filesystem::temp_directory_path()
        / boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%.log").string() };
    { // SCIP deletes the handler, and thereby closes the file, when the model is destructed
        Model model("Simple");
        auto x1 = model.addVar("x_1", 1);
        auto x2 = model.addVar("x_2", 1);
        model.addConstr(x1 + x2 >= 1, "capacity");
        model.setMessagehdlr(make_unique<FileMessageHandler>(LOG_FILE));
        BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
        model.solve();
        BOOST_TEST(model.getNSols() > 0);
    }
    ifstream file(LOG_FILE);
    ostringstream content;
    content << file.rdbuf();
    BOOST_TEST(contains(content.str(), "SCIP Status"));
    BOOST_TEST(contains(content.str(), "optimal solution found"));
    file.close();
    filesystem::remove(LOG_FILE);
}

BOOST_AUTO_TEST_SUITE_END()
