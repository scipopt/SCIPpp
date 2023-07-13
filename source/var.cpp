#include "scippp/var.hpp"

#include "scippp/solution.hpp"
#include <scip/scip_sol.h>

namespace scippp {

double Var::getSolVal(Solution& sol) const
{
    return SCIPgetSolVal(sol.scip, sol.sol, var);
}

}
