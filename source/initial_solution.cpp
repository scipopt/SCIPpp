#include "scippp/initial_solution.hpp"

namespace scippp {

void InitialSolution::setValue(const Var& var, double value)
{
    m_values[&var] = value;
}

double& InitialSolution::operator()(const Var& var)
{
    return m_values[&var];
}

}
