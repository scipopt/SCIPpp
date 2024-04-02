#pragma once

#include <algorithm>
#include <array>
#include <filesystem>
#include <functional>
#include <optional>
#include <scip/scip.h>
#include <string>
#include <type_traits>
#include <vector>

#include "scippp/constant_coefficient.hpp"
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
    SCIP_Retcode m_lastReturnCode;
    //! Wrapper for every call to %SCIP's %C %API.
    std::function<void(SCIP_Retcode)> m_scipCallWrapper;

public:
    /**
     * Creates an empty problem and sets the optimization goal to Sense::MINIMIZE.
     *
     * By default, all calls to the underlying %C %API are wrapped and the last return code is stored.
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
     * structured binding.
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
    void solve();

    /**
     * Set objective goal.
     * @since 1.0.0
     * @param objsense Minimize or Maximize.
     */
    void setObjsense(Sense objsense);

    /**
     * Returns the solution status.
     * @since 1.0.0
     * @return solution status.
     */
    [[nodiscard]] SCIP_Status getStatus() const;

    /**
     * Query statistics about the solving process.
     *
     * @tparam T Type of the statistics value.
     * @since 1.2.0
     * @param statistic Statistics value to access.
     * @return Statistics value.
     */
    template<typename T>
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
    [[deprecated("use getSolvingStatistic with statistics::PRIMALBOUND instead")]]
    [[nodiscard]] double getPrimalbound() const;

    /**
     * Sets a parameter.
     *
     * See the namespace scippp::params for a list of parameters, or create new ones using params::Param.
     *
     * @since 1.0.0
     * @tparam T Type of the value.
     * @tparam PT Value type the parameter expects
     * @param parameter to set.
     * @param value to set the parameter to.
     */
    template <typename T, typename PT>
    void setParam(params::Param<PT> parameter, T value)
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
};
}
