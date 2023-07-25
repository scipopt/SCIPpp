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
    //! Pointer to the underlying %SCIP variable.
    SCIP_Var* var { nullptr };
    /**
     * Get the assigned value in the solution.
     * @since 1.0.0
     * @param solution Primal %CIP solution.
     * @return value of this variable in primal %CIP solution.
     */
    double getSolVal(Solution& solution) const;
};

}
