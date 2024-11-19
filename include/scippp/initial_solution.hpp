#pragma once

#include <map>

// forward declare
struct SCIP_Var;

namespace scippp {

// forward declare
class Var;

/**
 * A primal solution to be added to %SCIP's solution pool.
 *
 * @since 1.3.0
 */
class InitialSolution {
    friend class Model;
    //! Variable assignment in the initial solution.
    std::map<SCIP_Var*, double> m_values {};

public:
    /**
     * Sets the value for a variable in the solution.
     *
     * @param var Variable to assign a value to.
     * @param value to assign to the variable.
     */
    void setValue(const Var& var, double value);
};

}
