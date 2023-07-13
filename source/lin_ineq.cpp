#include "scippp/lin_ineq.hpp"

namespace scippp {

LinIneq operator<=(const LinExpr& lhs, const LinExpr& rhs)
{
    LinIneq result;
    result.m_linExpr = rhs - lhs;
    result.m_lhs = -result.m_linExpr.getConstant();
    // rhs infinity
    return result;
}

LinIneq operator==(const LinExpr& lhs, const LinExpr& rhs)
{
    LinIneq result;
    result.m_linExpr = rhs - lhs;
    result.m_lhs = -result.m_linExpr.getConstant();
    result.m_rhs = -result.m_linExpr.getConstant();
    return result;
}

LinIneq operator>=(const LinExpr& lhs, const LinExpr& rhs)
{
    return rhs <= lhs;
}

}
