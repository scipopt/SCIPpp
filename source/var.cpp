#include "scippp/var.hpp"

#include "scippp/solution.hpp"
#include <scip/scip_numerics.h>
#include <scip/scip_sol.h>

namespace scippp {

double Var::getSolVal(const Solution& sol) const
{
    return SCIPgetSolVal(sol.scip, sol.sol, var);
}

int Var::getSolValAsInt(const Solution& solution) const
{
    return SCIPconvertRealToInt(solution.scip, getSolVal(solution));
}

long long Var::getSolValAsLongInt(const Solution& solution) const
{
    return SCIPconvertRealToLongint(solution.scip, getSolVal(solution));
}

bool Var::isZero(const Solution& solution) const
{
    return SCIPisZero(solution.scip, getSolVal(solution));
}

bool Var::isVoid() const
{
    return var == nullptr;
}

}
