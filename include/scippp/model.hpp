#pragma once

#include <algorithm>
#include <array>
#include <filesystem>
#include <functional>
#include <memory>
#include <objscip/objscip.h>
#include <objscip/objtable.h> // not included by objscip.h
#include <optional>
#include <scip/scip.h>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "scippp/constant_coefficient.hpp"
#include "scippp/iis.hpp"
#include "scippp/initial_solution.hpp"
#include "scippp/lin_expr.hpp"
#include "scippp/lin_ineq.hpp"
#include "scippp/param.hpp"
#include "scippp/solution.hpp"
#include "scippp/statistics.hpp"
#include "scippp/var.hpp"
#include "scippp/var_type.hpp"

//! C++ wrapper for %SCIP.
namespace scippp {

//! Optimization goal.
enum class Sense {
    //! Maximize
    MAXIMIZE = SCIP_OBJSENSE_MAXIMIZE,
    //! Minimize
    MINIMIZE = SCIP_OBJSENSE_MINIMIZE
};

/**
 * A %SCIP optimization model.
 *
 * Variables and constraints are automatically released when the model is destructed.
 * @since 1.0.0
 */
class Model {
    //! Pointer to the underlying %SCIP object.
    Scip* m_scip;
    //! \c true if %SCIPcreate was called in the c'tor and %SCIPfree has to be called in the d'tor.
    bool m_weCreatedANewScipObject { false };
    //! Variables.
    std::vector<Var> m_vars {};
    //! Constraints.
    std::vector<SCIP_Cons*> m_cons {};
    //! Stores the return of the last %SCIP call when the default call wrapper is used.
    mutable SCIP_Retcode m_lastReturnCode;
    //! Wrapper for every call to %SCIP's %C %API.
    std::function<void(SCIP_Retcode)> m_scipCallWrapper;

    /**
     * Constructs a plugin and includes it, %SCIP takes ownership on success.
     *
     * @tparam Plugin Type of the plugin, derived from \p Base.
     * @tparam Base objscip base class of the plugin.
     * @tparam Args Types of the additional constructor arguments.
     * @param scipInclude %SCIP's include function for \p Base, e.g., SCIPincludeObjEventhdlr.
     * @param args passed to the constructor of \p Plugin after the %SCIP data structure.
     * @return Non-owning pointer to the plugin, or \c nullptr if including failed.
     */
    template <typename Plugin, typename Base, typename... Args>
    Plugin* constructAndInclude(SCIP_RETCODE (*scipInclude)(SCIP*, Base*, SCIP_Bool), Args&&... args) const
    {
        static_assert(std::is_base_of_v<Base, Plugin>, "Plugin must derive from the objscip base class");
        auto plugin { std::make_unique<Plugin>(m_scip, std::forward<Args>(args)...) };
        const auto RETCODE { scipInclude(m_scip, plugin.get(), TRUE) };
        // SCIP owns the plugin only on success, otherwise it is deleted when leaving this method.
        Plugin* result { RETCODE == SCIP_OKAY ? plugin.release() : nullptr };
        m_scipCallWrapper(RETCODE);
        return result;
    }

    /**
     * Activates an included variable pricer, so that it is used when solving the model.
     *
     * @param pricer to activate.
     */
    void activatePricer(const scip::ObjPricer& pricer) const;

    /**
     * Includes the default Benders' cuts for an included Benders' decomposition and activates it together with the
     * constraint handlers enforcing it, so that it is used when solving the model.
     *
     * @param benders Benders' decomposition to activate.
     * @param nSubproblems number of subproblems of the Benders' decomposition.
     */
    void activateBenders(const scip::ObjBenders& benders, int nSubproblems) const;

    /**
     * Prepares the %SCIP data structure without creating a problem in it.
     *
     * @param scip to use. If \c nullptr, a new %SCIP data structure will be created.
     * @param includeDefaultPlugins if \c true, the default plugins are added to \p scip.
     */
    Model(SCIP* scip, bool includeDefaultPlugins);

public:
    /**
     * Creates an empty problem and sets the optimization goal to Sense::MINIMIZE.
     *
     * By default, all calls to the underlying %C %API are wrapped and the last return code is stored.
     *
     * A model can be created without an existing %SCIP data structure, or with an existing one where the default
     * plugins are added to or not:
     * @code
     * Model m1("ModelWithoutExistingSCIPEnvironment");
     *
     * SCIP* scip2 { nullptr };
     * SCIPcreate(&scip2);
     * Model m2("ModelWithExistingSCIPEnvironmentWhereDefaultPluginsWillBeAdded", scip2);
     *
     * SCIP* scip3 { nullptr };
     * SCIPcreate(&scip3);
     * SCIPincludeDefaultPlugins(scip3);
     * Model m3("ModelWithExistingSCIPEnvironmentWhereNoPluginsWillBeAdded", scip3, false);
     * @endcode
     *
     * @since 1.0.0
     * @param name for the problem.
     * @param scip to create the problem in. If \c nullptr, a new %SCIP data structure will be created.
     * @param includeDefaultPlugins if \c true, the default plugins are added to \p scip.
     */
    explicit Model(const std::string& name, SCIP* scip = nullptr, bool includeDefaultPlugins = true);

    /**
     * Creates an empty problem with custom problem data and sets the optimization goal to Sense::MINIMIZE.
     *
     * Derive from scip::ObjProbData to store problem-specific data, which plugins can access via SCIPgetObjProbData:
     * @code
     * class MyProblemData : public scip::ObjProbData { ... };
     * ...
     * Model model("Problem", std::make_unique<MyProblemData>());
     * @endcode
     *
     * @since 1.5.0
     * @param name for the problem.
     * @param probData to store in the problem, must not be \c nullptr. %SCIP takes ownership and deletes it when the
     *                 problem is freed.
     * @param scip to create the problem in. If \c nullptr, a new %SCIP data structure will be created.
     * @param includeDefaultPlugins if \c true, the default plugins are added to \p scip.
     */
    Model(
        const std::string& name,
        std::unique_ptr<scip::ObjProbData> probData,
        SCIP* scip = nullptr,
        bool includeDefaultPlugins = true);

    /**
     * Releases the variables and constraints.
     * @since 1.0.0
     */
    ~Model();

    /**
     * Gets the return code of the last call to %SCIP's %C %API when the default call wrapper is used.
     * @since 1.0.0
     * @return return code of the last call to %SCIP's %C %API.
     */
    [[nodiscard]] SCIP_Retcode getLastReturnCode() const;

    /**
     * Replace the current wrapper for every call to %SCIP's %C %API.
     * @since 1.0.0
     * @param wrapper New wrapper tp use.
     */
    void setScipCallWrapper(std::function<void(SCIP_Retcode)> wrapper);

    /**
     * Adds a variable to the model.
     * @since 1.0.0
     * @param name of the variable when the model is written.
     * @param coeff Coefficient in the objective function.
     * @param varType variable type.
     * @param lb lower bound. \c std::nullopt is interpreted as -infinity.
     * @param ub upper bound. \c std::nullopt is interpreted as infinity.
     * @return Reference to the newly created variable.
     */
    Var& addVar(
        const std::string& name,
        SCIP_Real coeff = 0.0,
        VarType varType = VarType::CONTINUOUS,
        std::optional<SCIP_Real> lb = 0.0,
        std::optional<SCIP_Real> ub = 1.0);

    /**
     * Adds a variable with custom variable data to the model.
     *
     * Derive from scip::ObjVardata to store variable-specific data, which plugins can access via SCIPgetObjVardata:
     * @code
     * class MyVariableData : public scip::ObjVardata { ... };
     * ...
     * auto& x = model.addVar("x", std::make_unique<MyVariableData>(), 1.0, VarType::BINARY);
     * @endcode
     *
     * @since 1.5.0
     * @param name of the variable when the model is written.
     * @param vardata to store in the variable, must not be \c nullptr. %SCIP takes ownership and deletes it when the
     *                variable is freed.
     * @param coeff Coefficient in the objective function.
     * @param varType variable type.
     * @param lb lower bound. \c std::nullopt is interpreted as -infinity.
     * @param ub upper bound. \c std::nullopt is interpreted as infinity.
     * @return Reference to the newly created variable.
     */
    Var& addVar(
        const std::string& name,
        std::unique_ptr<scip::ObjVardata> vardata,
        SCIP_Real coeff = 0.0,
        VarType varType = VarType::CONTINUOUS,
        std::optional<SCIP_Real> lb = 0.0,
        std::optional<SCIP_Real> ub = 1.0);

    /**
     * Adds multiple variables to the model.
     *
     * By default, all variables have a coefficient of zero in the objective function. Use scippp::COEFF_ONE for a
     * coefficient of one, or any object providing <code>double operator[](std::size_t index) const</code>:
     * @code
     * auto x = model.addVars("x_", 42);
     * auto y = model.addVars("y_", 42, COEFF_ONE);
     * std::vector<double> costs { 1.5, 2, 3 };
     * auto z = model.addVars("z_", costs.size(), costs, VarType::INTEGER);
     * @endcode
     *
     * @since 1.0.0
     * @tparam CoeffType Type of the object holding the coefficients. They are accessed via \c [i] where i goes from 0
     *                   to \p numVars - 1.
     * @param prefix to construct variable names from: prefix + index.
     * @param numVars number of variables to create.
     * @param coeffs Object holding the coefficients for the objective function.
     * @param varType variable type.
     * @param lb lower bound. \c std::nullopt is interpreted as -infinity.
     * @param ub upper bound. \c std::nullopt is interpreted as infinity.
     * @return Vector of variables.
     */
    template <typename CoeffType = ConstantCoefficient>
    std::vector<Var> addVars(
        const std::string& prefix,
        size_t numVars,
        const CoeffType& coeffs = COEFF_ZERO,
        VarType varType = VarType::CONTINUOUS,
        std::optional<SCIP_Real> lb = 0.0,
        std::optional<SCIP_Real> ub = 1.0)
    {
        std::vector<Var> result;
        result.reserve(numVars);
        for (size_t index { 0 }; index < numVars; index++) {
            result.push_back(addVar(prefix + std::to_string(index), coeffs[index], varType, lb, ub));
        }
        return result;
    }

    /**
     * Adds multiple variables to the model.
     *
     * This method can be used when the number of variables to add is known at compile time. The result can be used in a
     * structured binding:
     * @code
     * const auto& [x0, x1] = model.addVars<2>("x_", COEFF_ONE);
     * @endcode
     *
     * @since 1.0.0
     * @tparam NumVars Number of variables to add.
     * @tparam CoeffType Type of the object holding the coefficients. They are accessed via \c [i] where i goes from 0
     *                   to \p NumVars - 1.
     * @param prefix to construct variable names from: prefix + index.
     * @param coeffs Object holding the coefficients for the objective function.
     * @param varType variable type.
     * @param lb lower bound.
     * @param ub upper bound.
     * @return Array of variables.
     */
    template <size_t NumVars, typename CoeffType = ConstantCoefficient>
    std::array<Var, NumVars> addVars(
        const std::string& prefix,
        const CoeffType& coeffs = COEFF_ZERO,
        VarType varType = VarType::CONTINUOUS,
        std::optional<SCIP_Real> lb = 0.0,
        std::optional<SCIP_Real> ub = 1.0)
    {
        std::array<Var, NumVars> result;
        auto vec { addVars(prefix, NumVars, coeffs, varType, lb, ub) };
        std::copy_n(std::make_move_iterator(vec.begin()), NumVars, result.begin());
        return result;
    }

    /**
     * Adds a constraint to the model.
     *
     * Linear inequalities are built from linear expressions, see LinExpr:
     * @code
     * const auto& [x0, x1, x2, x3] = model.addVars<4>("x_");
     *
     * LinExpr sum1;
     * sum1 += 42 * x0;
     * sum1 += x1;
     * model.addConstr(sum1 <= 0.5, "constraint1");
     *
     * LinExpr sum2 = x1 + x2;
     * model.addConstr(sum2 == 1.25, "constraint2");
     *
     * model.addConstr(1 <= x2 + 2 * x3, "constraint3");
     * @endcode
     *
     * @since 1.0.0
     * @param ineq linear inequality to add.
     * @param name for the constraint when the model is written.
     */
    void addConstr(const LinIneq& ineq, const std::string& name);

    /**
     * Infinity according the %SCIP config. To be used in variable bounds and constants in constraints.
     * @since 1.0.0
     * @return infinity according the %SCIP config.
     */
    [[nodiscard]] SCIP_Real infinity() const;

    /**
     * Value treated as zero.
     * @since 1.1.0
     * @return value treated as zero.
     */
    [[nodiscard]] SCIP_Real epsilon() const;

    /**
     * Rounds value to the nearest integer with epsilon tolerance.
     * @since 1.1.0
     * @param value to round
     * @return nearest integer as double
     */
    [[nodiscard]] SCIP_Real round(SCIP_Real value) const;

    /**
     * Checks, if value is in range epsilon of 0.0.
     * @since 1.1.0
     * @param value to check
     * @return \c true iff the value is in range epsilon of 0.0.
     */
    [[nodiscard]] bool isZero(SCIP_Real value) const;

    /**
     * Solve the model.
     * @since 1.0.0
     */
    void solve() const;

    /**
     * Set objective goal.
     * @since 1.0.0
     * @param objsense Minimize or Maximize.
     */
    void setObjsense(Sense objsense) const;

    /**
     * Returns the solution status.
     * @since 1.0.0
     * @return solution status.
     */
    [[nodiscard]] SCIP_Status getStatus() const;

    /**
     * Query statistics about the solving process.
     *
     * Use the scippp::statistics::Statistic objects from the header solving_statistics.hpp to access the statistics in
     * a type-safe way:
     * @code
     * model.solve();
     * auto pb { model.getSolvingStatistic(statistics::PRIMALBOUND) };
     * @endcode
     *
     * @tparam T Type of the statistics value.
     * @since 1.2.0
     * @param statistic Statistics value to access.
     * @return Statistics value.
     */
    template <typename T>
    [[nodiscard]] T getSolvingStatistic(const statistics::Statistic<T>& statistic) const
    {
        return statistic(m_scip);
    }

    /**
     * Returns the number of feasible primal solutions stored in the solution storage.
     * @since 1.0.0
     * @return number of solutions.
     */
    [[nodiscard]] int getNSols() const;

    /**
     * Returns the best feasible primal solution found so far or best solution candidate.
     *
     * The values of the variables in the solution are accessed via Var::getSolVal, Var::getSolValAsInt,
     * Var::getSolValAsLongInt, and Var::isZero:
     * @code
     * const auto& [x0, x1] = model.addVars<2>("x_");
     * model.solve();
     * if (model.getNSols() > 0 && model.getStatus() == SCIP_STATUS_OPTIMAL) {
     *     Solution sol { model.getBestSol() };
     *     std::cout << "x0 + x1 = " << x0.getSolVal(sol) + x1.getSolVal(sol) << std::endl;
     * }
     * @endcode
     *
     * @since 1.0.0
     * @return best feasible primal solution.
     */
    [[nodiscard]] Solution getBestSol() const;

    /**
     * Returns the objective value of best solution.
     * @since 1.0.0
     * @deprecated since 1.2.0, use getSolvingStatistic with statistics::PRIMALBOUND instead.
     * @return objective value of best solution.
     */
    [[deprecated("use getSolvingStatistic with statistics::PRIMALBOUND instead")]] //
    [[nodiscard]] double
    getPrimalbound() const;

    /**
     * Sets a parameter.
     *
     * The namespace scippp::params in the header parameters.hpp contains all parameters listed at
     * https://www.scipopt.org/doc/html/PARAMETERS.php. They are strongly typed, so that, e.g., no string can be set as
     * the value for a parameter expecting an integer. Instead of using the predefined parameters, one can also create
     * new ones using params::Param:
     * @code
     * model.setParam(params::LIMITS::MAXSOL, 1);
     * model.setParam(params::DISPLAY::VERBLEVEL, 0);
     * model.setParam(params::Param<bool>("write/printzeros"), true);
     * @endcode
     *
     * @since 1.0.0
     * @tparam T Type of the value.
     * @tparam PT Value type the parameter expects
     * @param parameter to set.
     * @param value to set the parameter to.
     */
    template <typename T, typename PT>
    void setParam(params::Param<PT> parameter, T value) const
    {
        auto ptValue { static_cast<PT>(value) };
        const auto* cName { parameter.scipName.data() };
        if constexpr (std::is_same_v<PT, int>) {
            m_scipCallWrapper(SCIPsetIntParam(m_scip, cName, ptValue));
        } else if constexpr (std::is_same_v<PT, double>) {
            m_scipCallWrapper(SCIPsetRealParam(m_scip, cName, ptValue));
        } else if constexpr (std::is_same_v<PT, char>) {
            m_scipCallWrapper(SCIPsetCharParam(m_scip, cName, value));
        } else if constexpr (std::is_same_v<PT, bool>) {
            m_scipCallWrapper(SCIPsetBoolParam(m_scip, cName, value));
        } else if constexpr (std::is_same_v<PT, SCIP_Longint>) {
            m_scipCallWrapper(SCIPsetLongintParam(m_scip, cName, value));
        } else if constexpr (std::is_same_v<PT, std::string>) {
            m_scipCallWrapper(SCIPsetStringParam(m_scip, cName, value.c_str()));
        } else {
            // make this not compile
            // https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2593r0.html#workarounds
            static_assert(sizeof(T) == 0);
        }
    }

    /**
     * Writes original problem to file.
     *
     * @since 1.1.0
     * @param filename output file name including extension
     * @param genericNames using generic variable (x0, x1, ...) and constraint names (c0, c1, ...) instead of the
     *                     user-given names?
     * @attention Do not use an std::string or std::filesystem::path as argument \p filename,
     *            as this will call the other overload instead!
     */
    void writeOrigProblem(const std::filesystem::directory_entry& filename, bool genericNames = false) const;

    /**
     * Writes original problem to standard output.
     *
     * @since 1.1.0
     * @param extension file extension to derive the output format from
     * @param genericNames using generic variable (x0, x1, ...) and constraint names (c0, c1, ...) instead of the
     *                     user-given names?
     */
    void writeOrigProblem(const std::string& extension, bool genericNames = false) const;

    /**
     * Returns a pointer to the underlying %SCIP object.
     *
     * @since 1.0.0
     * @attention Use this to access the raw SCIP object. That is required only for use-cases not supported by SCIP++.
     *            Consider adding the feature you are using to SCIP++!
     * @return the underlying %SCIP object.
     */
    [[deprecated(R"(Use this to access the raw SCIP object.
                    That is only required for use-cases not supported by SCIP++.
                    Consider adding the feature you are using to SCIP++!)")]] [[nodiscard]] Scip*
    scip() const;

    /**
     * Adds a solution to %SCIP's solution pool.
     *
     * @since 1.3.0
     * @param initialSolution to add to the solution pool.
     * @param printReason Should all reasons of violations be printed?
     * @param completely Should all violations be checked if \p printReason is true?
     * @param checkBounds Should the bounds of the variables be checked?
     * @param checkIntegrality Should integrality be checked?
     * @param checkLpRows Do constraints represented by rows in the current LP have to be checked?
     * @return \c true iff the solution was feasible and stored in the solution storage (i.e, good enough to keep).
     */
    bool addSolution(
        const InitialSolution& initialSolution,
        bool printReason = true,
        bool completely = true,
        bool checkBounds = true,
        bool checkIntegrality = true,
        bool checkLpRows = true) const;

    /**
     * Creates an %Irreducible %Infeasible %Subsystem (%IIS) of the current model.
     *
     * @since 1.4.0
     * @return The generated %IIS.
     */
    [[nodiscard]] IIS generateIIS() const;

    /**
     * Installs a custom message handler, i.e., all info, warning, and dialog messages of %SCIP are passed to it.
     *
     * Derive from scip::ObjMessagehdlr to process the output of %SCIP, e.g., to write it to a logger:
     * @code
     * class MyMessageHandler : public scip::ObjMessagehdlr { ... };
     * ...
     * model.setMessagehdlr(std::make_unique<MyMessageHandler>());
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @param handler to install, must not be \c nullptr. %SCIP takes ownership and deletes it when it is no longer
     *                used.
     * @attention Must be called before solve(). Error messages are not passed to \p handler as %SCIP prints them via a
     *            global error printing function.
     */
    void setMessagehdlr(std::unique_ptr<scip::ObjMessagehdlr> handler) const;

    /**
     * Includes a custom event handler.
     *
     * The handler is constructed by this method as scip::ObjEventhdlr requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjEventhdlr to react to events of %SCIP, e.g., to track new best solutions:
     * @code
     * class MyEventHandler : public scip::ObjEventhdlr {
     * public:
     *     MyEventHandler(SCIP* scip, int& counter);
     *     ...
     * };
     * ...
     * int counter { 0 };
     * model.includeEventhdlr<MyEventHandler>(counter);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Eventhdlr Type of the event handler, derived from scip::ObjEventhdlr.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Eventhdlr after the %SCIP data structure.
     * @return Non-owning pointer to the handler, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Eventhdlr, typename... Args>
    Eventhdlr* includeEventhdlr(Args&&... args) const
    {
        return constructAndInclude<Eventhdlr>(&SCIPincludeObjEventhdlr, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom constraint handler.
     *
     * The handler is constructed by this method as scip::ObjConshdlr requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjConshdlr to enforce constraints that cannot be expressed linearly, e.g., lazily:
     * @code
     * class MyConstraintHandler : public scip::ObjConshdlr {
     * public:
     *     MyConstraintHandler(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeConshdlr<MyConstraintHandler>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Conshdlr Type of the constraint handler, derived from scip::ObjConshdlr.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Conshdlr after the %SCIP data structure.
     * @return Non-owning pointer to the handler, or \c nullptr if including failed.
     * @attention Must be called before solve().
     * @note SCIP++ cannot create constraints of a custom constraint handler. Thus, pass \c needscons = \c FALSE to the
     *       constructor of scip::ObjConshdlr, so that the handler is called without constraints, and lock the
     *       variables in \c scip_lock, which is then called with \c cons = \c nullptr.
     */
    template <typename Conshdlr, typename... Args>
    Conshdlr* includeConshdlr(Args&&... args) const
    {
        return constructAndInclude<Conshdlr>(&SCIPincludeObjConshdlr, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom primal heuristic.
     *
     * The heuristic is constructed by this method as scip::ObjHeur requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjHeur to construct solutions from problem-specific knowledge:
     * @code
     * class MyHeuristic : public scip::ObjHeur {
     * public:
     *     MyHeuristic(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeHeur<MyHeuristic>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Heur Type of the heuristic, derived from scip::ObjHeur.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Heur after the %SCIP data structure.
     * @return Non-owning pointer to the heuristic, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Heur, typename... Args>
    Heur* includeHeur(Args&&... args) const
    {
        return constructAndInclude<Heur>(&SCIPincludeObjHeur, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom presolver.
     *
     * The presolver is constructed by this method as scip::ObjPresol requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjPresol to reduce the problem before solving it, e.g., based on problem-specific knowledge:
     * @code
     * class MyPresolver : public scip::ObjPresol {
     * public:
     *     MyPresolver(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includePresol<MyPresolver>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Presol Type of the presolver, derived from scip::ObjPresol.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Presol after the %SCIP data structure.
     * @return Non-owning pointer to the presolver, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Presol, typename... Args>
    Presol* includePresol(Args&&... args) const
    {
        return constructAndInclude<Presol>(&SCIPincludeObjPresol, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom propagator.
     *
     * The propagator is constructed by this method as scip::ObjProp requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjProp to tighten the domains of variables during the search, e.g., based on
     * problem-specific knowledge:
     * @code
     * class MyPropagator : public scip::ObjProp {
     * public:
     *     MyPropagator(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeProp<MyPropagator>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Prop Type of the propagator, derived from scip::ObjProp.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Prop after the %SCIP data structure.
     * @return Non-owning pointer to the propagator, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Prop, typename... Args>
    Prop* includeProp(Args&&... args) const
    {
        return constructAndInclude<Prop>(&SCIPincludeObjProp, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom separator.
     *
     * The separator is constructed by this method as scip::ObjSepa requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjSepa to cut off fractional solutions of the LP relaxation, e.g., with problem-specific
     * valid inequalities:
     * @code
     * class MySeparator : public scip::ObjSepa {
     * public:
     *     MySeparator(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeSepa<MySeparator>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Sepa Type of the separator, derived from scip::ObjSepa.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Sepa after the %SCIP data structure.
     * @return Non-owning pointer to the separator, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Sepa, typename... Args>
    Sepa* includeSepa(Args&&... args) const
    {
        return constructAndInclude<Sepa>(&SCIPincludeObjSepa, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom cut selector.
     *
     * The cut selector is constructed by this method as scip::ObjCutsel requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjCutsel to decide which of the separated cuts are added to the LP relaxation:
     * @code
     * class MyCutSelector : public scip::ObjCutsel {
     * public:
     *     MyCutSelector(SCIP* scip, double minEfficacy);
     *     ...
     * };
     * ...
     * model.includeCutsel<MyCutSelector>(0.1);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Cutsel Type of the cut selector, derived from scip::ObjCutsel.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Cutsel after the %SCIP data structure.
     * @return Non-owning pointer to the cut selector, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Cutsel, typename... Args>
    Cutsel* includeCutsel(Args&&... args) const
    {
        return constructAndInclude<Cutsel>(&SCIPincludeObjCutsel, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom branching rule.
     *
     * The branching rule is constructed by this method as scip::ObjBranchrule requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjBranchrule to decide how to split the search space, e.g., based on problem-specific
     * knowledge:
     * @code
     * class MyBranchingRule : public scip::ObjBranchrule {
     * public:
     *     MyBranchingRule(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeBranchrule<MyBranchingRule>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Branchrule Type of the branching rule, derived from scip::ObjBranchrule.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Branchrule after the %SCIP data structure.
     * @return Non-owning pointer to the branching rule, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Branchrule, typename... Args>
    Branchrule* includeBranchrule(Args&&... args) const
    {
        return constructAndInclude<Branchrule>(&SCIPincludeObjBranchrule, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom node selector.
     *
     * The node selector is constructed by this method as scip::ObjNodesel requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjNodesel to decide which open node of the search tree is processed next:
     * @code
     * class MyNodeSelector : public scip::ObjNodesel {
     * public:
     *     explicit MyNodeSelector(SCIP* scip);
     *     ...
     * };
     * ...
     * model.includeNodesel<MyNodeSelector>();
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Nodesel Type of the node selector, derived from scip::ObjNodesel.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Nodesel after the %SCIP data structure.
     * @return Non-owning pointer to the node selector, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Nodesel, typename... Args>
    Nodesel* includeNodesel(Args&&... args) const
    {
        return constructAndInclude<Nodesel>(&SCIPincludeObjNodesel, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom relaxator.
     *
     * The relaxator is constructed by this method as scip::ObjRelax requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjRelax to solve problem-specific relaxations in addition to the LP relaxation:
     * @code
     * class MyRelaxator : public scip::ObjRelax {
     * public:
     *     MyRelaxator(SCIP* scip, const std::vector<Var>& vars);
     *     ...
     * };
     * ...
     * auto vars = model.addVars("x_", 42);
     * model.includeRelax<MyRelaxator>(vars);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Relax Type of the relaxator, derived from scip::ObjRelax.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Relax after the %SCIP data structure.
     * @return Non-owning pointer to the relaxator, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Relax, typename... Args>
    Relax* includeRelax(Args&&... args) const
    {
        return constructAndInclude<Relax>(&SCIPincludeObjRelax, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom display column.
     *
     * The display column is constructed by this method as scip::ObjDisp requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjDisp to show additional information in the lines %SCIP prints during the solving process:
     * @code
     * class MyDisplayColumn : public scip::ObjDisp {
     * public:
     *     explicit MyDisplayColumn(SCIP* scip);
     *     ...
     * };
     * ...
     * model.includeDisp<MyDisplayColumn>();
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Disp Type of the display column, derived from scip::ObjDisp.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Disp after the %SCIP data structure.
     * @return Non-owning pointer to the display column, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Disp, typename... Args>
    Disp* includeDisp(Args&&... args) const
    {
        return constructAndInclude<Disp>(&SCIPincludeObjDisp, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom statistics table.
     *
     * The statistics table is constructed by this method as scip::ObjTable requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjTable to add problem-specific information to the statistics %SCIP prints:
     * @code
     * class MyStatisticsTable : public scip::ObjTable {
     * public:
     *     explicit MyStatisticsTable(SCIP* scip);
     *     ...
     * };
     * ...
     * model.includeTable<MyStatisticsTable>();
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Table Type of the statistics table, derived from scip::ObjTable.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Table after the %SCIP data structure.
     * @return Non-owning pointer to the statistics table, or \c nullptr if including failed.
     * @attention Must be called before solve().
     * @note SCIP++ does not print statistics, this requires %SCIP's %C %API, e.g., SCIPprintStatistics.
     */
    template <typename Table, typename... Args>
    Table* includeTable(Args&&... args) const
    {
        return constructAndInclude<Table>(&SCIPincludeObjTable, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom file reader.
     *
     * The file reader is constructed by this method as scip::ObjReader requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjReader to write the problem in a custom file format via writeOrigProblem(), which selects
     * the file reader by the extension of the file name:
     * @code
     * class MyFileReader : public scip::ObjReader {
     * public:
     *     explicit MyFileReader(SCIP* scip); // passes "myext" as extension to scip::ObjReader
     *     ...
     * };
     * ...
     * model.includeReader<MyFileReader>();
     * model.writeOrigProblem(std::filesystem::directory_entry("problem.myext"));
     * @endcode
     *
     * @since 1.5.0
     * @tparam Reader Type of the file reader, derived from scip::ObjReader.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Reader after the %SCIP data structure.
     * @return Non-owning pointer to the file reader, or \c nullptr if including failed.
     */
    template <typename Reader, typename... Args>
    Reader* includeReader(Args&&... args) const
    {
        return constructAndInclude<Reader>(&SCIPincludeObjReader, std::forward<Args>(args)...);
    }

    /**
     * Includes a custom %IIS finder.
     *
     * The %IIS finder is constructed by this method as scip::ObjIISfinder requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjIISfinder to compute an %IIS of an infeasible problem via generateIIS(), e.g., based on
     * problem-specific knowledge:
     * @code
     * class MyIISFinder : public scip::ObjIISfinder {
     * public:
     *     explicit MyIISFinder(SCIP* scip);
     *     ...
     * };
     * ...
     * model.includeIISfinder<MyIISFinder>();
     * model.solve();
     * auto iis { model.generateIIS() };
     * @endcode
     *
     * @since 1.5.0
     * @tparam IISfinder Type of the %IIS finder, derived from scip::ObjIISfinder.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p IISfinder after the %SCIP data structure.
     * @return Non-owning pointer to the %IIS finder, or \c nullptr if including failed.
     */
    template <typename IISfinder, typename... Args>
    IISfinder* includeIISfinder(Args&&... args) const
    {
        return constructAndInclude<IISfinder>(&SCIPincludeObjIISfinder, std::forward<Args>(args)...);
    }

    /**
     * Includes and activates a custom variable pricer.
     *
     * The pricer is constructed by this method as scip::ObjPricer requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjPricer to add variables with negative reduced costs during the solving process, i.e., to
     * implement column generation:
     * @code
     * class MyPricer : public scip::ObjPricer {
     * public:
     *     MyPricer(SCIP* scip, const std::vector<SCIP_CONS*>& conss);
     *     ...
     * };
     * ...
     * model.includePricer<MyPricer>(conss);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Pricer Type of the pricer, derived from scip::ObjPricer.
     * @tparam Args Types of the additional constructor arguments.
     * @param args passed to the constructor of \p Pricer after the %SCIP data structure.
     * @return Non-owning pointer to the pricer, or \c nullptr if including failed.
     * @attention Must be called before solve().
     * @note Constraints added via addConstr() are not modifiable, i.e., priced variables cannot be added to them.
     */
    template <typename Pricer, typename... Args>
    Pricer* includePricer(Args&&... args) const
    {
        auto* pricer { constructAndInclude<Pricer>(&SCIPincludeObjPricer, std::forward<Args>(args)...) };
        if (pricer != nullptr) {
            activatePricer(*pricer);
        }
        return pricer;
    }

    /**
     * Includes and activates a custom Benders' decomposition together with %SCIP's default Benders' cuts.
     *
     * The Benders' decomposition is constructed by this method as scip::ObjBenders requires the %SCIP data structure
     * in its constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjBenders to solve the model as master problem of a Benders' decomposition. The
     * decomposition creates the subproblems, solves them, and maps the variables between the master problem and the
     * subproblems:
     * @code
     * class MyBenders : public scip::ObjBenders {
     * public:
     *     MyBenders(SCIP* scip, const std::vector<Var>& masterVars);
     *     ...
     * };
     * ...
     * auto masterVars = model.addVars("x_", 42);
     * model.includeBenders<MyBenders>(nSubproblems, masterVars);
     * model.solve();
     * @endcode
     *
     * Activating the Benders' decomposition also activates the constraint handlers \c benders and \c benderslp, which
     * enforce it. If \p Benders is not cloneable, copying Benders' decompositions to sub-SCIPs is disabled via the
     * parameter \c benders/copybenders, as %SCIP cannot copy it.
     *
     * @since 1.5.0
     * @tparam Benders Type of the Benders' decomposition, derived from scip::ObjBenders.
     * @tparam Args Types of the additional constructor arguments.
     * @param nSubproblems number of subproblems of the Benders' decomposition.
     * @param args passed to the constructor of \p Benders after the %SCIP data structure.
     * @return Non-owning pointer to the Benders' decomposition, or \c nullptr if including failed.
     * @attention Must be called before solve(). The priority of \p Benders has to be positive, as %SCIP expects
     *            active Benders' decompositions to have higher priorities than the inactive default one.
     * @attention scip::ObjBenders always provides the callbacks to solve subproblems, so %SCIP does not solve them
     *            itself. Hence, \p Benders has to implement \c scip_solvesubconvex or \c scip_solvesub.
     * @note The default Benders' cuts can be disabled via the parameters
     *       <code>benders/\<name\>/benderscut/\<cut\>/enabled</code>.
     */
    template <typename Benders, typename... Args>
    Benders* includeBenders(int nSubproblems, Args&&... args) const
    {
        auto* benders { constructAndInclude<Benders>(&SCIPincludeObjBenders, std::forward<Args>(args)...) };
        if (benders != nullptr) {
            activateBenders(*benders, nSubproblems);
        }
        return benders;
    }

    /**
     * Includes a custom Benders' decomposition cut for a Benders' decomposition.
     *
     * The cut is constructed by this method as scip::ObjBenderscut requires the %SCIP data structure in its
     * constructor. %SCIP takes ownership and deletes it when the model is destructed.
     *
     * Derive from scip::ObjBenderscut to generate problem-specific cuts from the subproblems of a Benders'
     * decomposition:
     * @code
     * class MyBendersCut : public scip::ObjBenderscut {
     * public:
     *     explicit MyBendersCut(SCIP* scip);
     *     ...
     * };
     * ...
     * auto* benders { model.includeBenders<MyBenders>(nSubproblems) };
     * model.includeBenderscut<MyBendersCut>(*benders);
     * model.solve();
     * @endcode
     *
     * @since 1.5.0
     * @tparam Benderscut Type of the cut, derived from scip::ObjBenderscut.
     * @tparam Args Types of the additional constructor arguments.
     * @param benders Benders' decomposition to generate the cuts for, see includeBenders().
     * @param args passed to the constructor of \p Benderscut after the %SCIP data structure.
     * @return Non-owning pointer to the cut, or \c nullptr if including failed.
     * @attention Must be called before solve().
     */
    template <typename Benderscut, typename... Args>
    Benderscut* includeBenderscut(scip::ObjBenders& benders, Args&&... args) const
    {
        // like constructAndInclude, but the include function additionally requires the Benders' decomposition
        static_assert(
            std::is_base_of_v<scip::ObjBenderscut, Benderscut>, "Benderscut must derive from scip::ObjBenderscut");
        auto cut { std::make_unique<Benderscut>(m_scip, std::forward<Args>(args)...) };
        const auto RETCODE { SCIPincludeObjBenderscut(m_scip, &benders, cut.get(), TRUE) };
        // SCIP owns the cut only on success, otherwise it is deleted when leaving this method.
        Benderscut* result { RETCODE == SCIP_OKAY ? cut.release() : nullptr };
        m_scipCallWrapper(RETCODE);
        return result;
    }
};
}
