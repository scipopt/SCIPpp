#include "scippp/lin_expr.hpp"

namespace scippp {

LinExpr::LinExpr(double constant)
    : m_constant { constant }
{
}

LinExpr::LinExpr(const Var& var)
    : m_vars { var }
    , m_coeffs(1, 1)
{
}

double LinExpr::getConstant() const
{
    return m_constant;
}

LinExpr& LinExpr::operator-=(const LinExpr& expr)
{
    m_vars.insert(m_vars.end(), expr.m_vars.begin(), expr.m_vars.end());
    for (auto coeff : expr.m_coeffs) {
        m_coeffs.push_back(-coeff);
    }
    m_constant -= expr.m_constant;
    return *this;
}

LinExpr& LinExpr::operator+=(const LinExpr& expr)
{
    m_vars.insert(m_vars.end(), expr.m_vars.begin(), expr.m_vars.end());
    m_coeffs.insert(m_coeffs.end(), expr.m_coeffs.begin(), expr.m_coeffs.end());
    m_constant += expr.m_constant;
    return *this;
}

LinExpr& LinExpr::operator*=(double factor)
{
    m_constant *= factor;
    for (auto& coeff : m_coeffs) {
        coeff *= factor;
    }
    return *this;
}

LinExpr operator*(double factor, LinExpr rhs)
{
    rhs *= factor;
    return rhs;
}

LinExpr operator+(LinExpr lhs, const LinExpr& rhs)
{
    lhs += rhs;
    return lhs;
}

LinExpr operator-(LinExpr lhs, const LinExpr& rhs)
{
    lhs -= rhs;
    return lhs;
}

}
