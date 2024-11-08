#pragma once

// forward declare
struct SCIP_Var;

namespace scippp {

// forward declare
struct Solution;

/**
 * Wrapper for a %SCIP variable.
 *
 * It does not own the memory. Memory management is done by the Model.
 * @since 1.0.0
 */
struct Var {
    /**
     * Pointer to the underlying %SCIP variable.
     * @deprecated since 1.3.0: Use #getVar() instead
     */
    SCIP_Var* var { nullptr };

    /**
     * Pointer to the underlying %SCIP variable.
     * @since 1.3.0
     * @return underlying %SCIP variable.
     */
    [[nodiscard]] SCIP_Var* getVar();

    /**
     * Pointer to the underlying %SCIP variable.
     *
     * @since 1.3.0
     * @return underlying %SCIP variable.
     */
    [[nodiscard]] const SCIP_Var* getVar() const;

    /**
     * Get the assigned value in the solution.
     * @since 1.0.0
     * @param solution Primal %CIP solution.
     * @return value of this variable in primal %CIP solution.
     */
    [[nodiscard]] double getSolVal(const Solution& solution) const;

    /**
     * Gets the assigned value in the solution and converts it to int.
     * @since 1.1.0
     * @param solution Primal %CIP solution.
     * @return value of this variable in primal %CIP solution as integer.
     */
    [[nodiscard]] int getSolValAsInt(const Solution& solution) const;

    /**
     * Gets the assigned value in the solution and converts it to long long.
     * @since 1.1.0
     * @param solution Primal %CIP solution.
     * @return value of this variable in primal %CIP solution as long integer.
     */
    [[nodiscard]] long long getSolValAsLongInt(const Solution& solution) const;

    /**
     * Checks whether the value of this variable in the primal solution is in range epsilon of 0.0.
     * @since 1.1.0
     * @param solution Primal %CIP solution.
     * @return \c true iff the value of this variable in the primal solution is in range epsilon of 0.0.
     */
    [[nodiscard]] bool isZero(const Solution& solution) const;

    /**
     * Checks whether an existing %SCIP variable is wrapped or the wrapper is empty.
     * @since 1.2.0
     * @return \c true iff the wrapper is empty
     */
    [[nodiscard]] bool isVoid() const;
};

}
