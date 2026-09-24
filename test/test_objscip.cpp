#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <memory>
#include <sstream>

#include "scippp/model.hpp"
#include "scippp/solving_statistics.hpp"
#include <objscip/objconshdlr.h>
#include <objscip/objeventhdlr.h>
#include <objscip/objheur.h>
#include <objscip/objmessagehdlr.h>
#include <objscip/objpresol.h>

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
