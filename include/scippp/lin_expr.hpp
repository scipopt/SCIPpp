#pragma once

#include <vector>

#include "scippp/var.hpp"

namespace scippp {

//! Represents a linear combination of variables plus a constant term.
class LinExpr {
    friend class Model;
    //! Constant term.
    double m_constant { 0.0 };
    //! Variables in the linear combination.
    std::vector<Var> m_vars {};
    //! Coefficients in the linear combination.
    std::vector<double> m_coeffs {};

public:
    //! Sets constant term and linear combination to zero.
    LinExpr() = default;
    /**
     * Creates a linear expression with no variables.
     * @remark This is on purpose not an explicit c'tor to allow expressions like x <= 1.
     * @param constant Constant term to set.
     */
    LinExpr(double constant);
    /**
     * Creates a linear expression with zero as constant the given variable with coefficient one.
     * @remark This is on purpose not an explicit c'tor to allow expressions like x <= 1.
     * @param var Variable to store with coefficient one in the expression.
     */
    LinExpr(const Var& var);

    /**
     * Returns the constant term of the expression.
     * @return the constant term of the expression.
     */
    [[nodiscard]] double getConstant() const;

    /**
     * Add another linear expression to this.
     * @param expr Other linear expression to add.
     * @return Updated sum.
     */
    LinExpr& operator+=(const LinExpr& expr);
    /**
     * Subtract another expression from this.
     * @param expr Right-hand-side of the subtraction.
     * @return Updated expression.
     */
    LinExpr& operator-=(const LinExpr& expr);
    /**
     * Multiply all coefficients.
     * @param factor to multiply all coefficients with.
     * @return Scaled expression.
     */
    LinExpr& operator*=(double factor);
};

/**
 * Scales a linear expression by a factor.
 * @param factor to scale the expression with.
 * @param rhs expression to scale.
 * @return scaled expression.
 */
LinExpr operator*(double factor, LinExpr rhs);

/**
 * Creates a new linear expression as the sum of two.
 * @param lhs First summand.
 * @param rhs Second summand.
 * @return Sum of both expressions.
 */
LinExpr operator+(LinExpr lhs, const LinExpr& rhs);

/**
 * Creates the new linear expression \p lhs - \p rhs
 * @param lhs minuend.
 * @param rhs subtrahend.
 * @return minuend minus subtrahend.
 */
LinExpr operator-(LinExpr lhs, const LinExpr& rhs);

}
