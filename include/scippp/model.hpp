#pragma once

#include <algorithm>
#include <array>
#include <filesystem>
#include <functional>
#include <memory>
#include <objscip/objscip.h>
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
};
}
