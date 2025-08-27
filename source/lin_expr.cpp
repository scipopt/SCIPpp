#include "scippp/lin_expr.hpp"

#include <cassert>

namespace scippp {

LinExpr::LinExpr(const Var& var)
    : m_vars { var }
    , m_coeffs(1, 1)
{
}

LinExpr::LinExpr(std::initializer_list<Var> vars)
    : m_vars { vars }
    , m_coeffs(vars.size(), 1)
{
}

LinExpr::LinExpr(std::initializer_list<Var> vars, std::initializer_list<double> coeffs)
    : m_vars { vars }
    , m_coeffs { coeffs }
{
    assert(vars.size() == coeffs.size()); // GCOVR_EXCL_LINE
}

LinExpr::LinExpr(const std::vector<Var>& vars)
    : m_vars { vars }
    , m_coeffs(vars.size(), 1)
{
}

LinExpr::LinExpr(const std::vector<Var>& vars, const std::vector<double>& coeffs)
    : m_vars { vars }
    , m_coeffs { coeffs }
{
    assert(vars.size() == coeffs.size()); // GCOVR_EXCL_LINE
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
