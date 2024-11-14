#pragma once

#include <map>

// forward declare
struct Scip;
struct SCIP_Var;

namespace scippp {

// forward declare
class Var;

class InitialSolution {
    //! Variable assignment in the initial solution.
    std::map<SCIP_Var*, double> m_values {};
public:
    void setValue(const Var& var, double value);
};

}
