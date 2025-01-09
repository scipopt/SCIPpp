#pragma once

#include <map>

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
    std::map<const Var*, double> m_values {};

public:
    /**
     * Sets the value for a variable in the solution.
     *
     * @since 1.3.0
     * @param var Variable to assign a value to.
     * @param value to assign to the variable.
     */
    void setValue(const Var& var, double value);

    /**
     * Access the mutable value assigned to the variable.
     *
     * Initializes the assigned value to 0 if no value was assigned to the variable so far.
     *
     * @since 1.3.0
     * @param var Variable to manipulate the value in the solution for.
     * @return Mutable value assigned to the variable.
     */
    double& operator()(const Var& var);
};

}
