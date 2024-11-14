#include "scippp/initial_solution.hpp"

#include <scippp/var.hpp>

namespace scippp {

InitialSolution::InitialSolution(Scip* scip)
    : m_scip { scip }
{
}

void InitialSolution::setValue(const Var& var, double value)
{
    // maybe add scip pointer to var and check this here
    m_values[var.var] = value;
}



}