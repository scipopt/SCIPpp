#pragma once

#include <vector>

#include "scippp/var.hpp"

namespace scippp {

/**
 * Represents a linear combination of variables plus a constant term.
 * @since 1.0.0
 */
class LinExpr {
    friend class Model;
    //! Constant term.
    double m_constant { 0.0 };
    //! Variables in the linear combination.
    std::vector<Var> m_vars {};
    //! Coefficients in the linear combination.
    std::vector<double> m_coeffs {};

public:
    /**
     * Sets constant term and linear combination to zero.
     * @since 1.0.0
     */
    LinExpr() = default;
    /**
     * Creates a linear expression with no variables.
     * @since 1.0.0
     * @remark This is on purpose not an explicit c'tor to allow expressions like x <= 1.
     * @tparam Arithmetic type that will be casted to \c double.
     * @warning \c Arithmetic is casted to \c double without creating a narrowing warning!
     * @param constant Constant term to set.
     */
    template <typename Arithmetic, std::enable_if_t<std::is_arithmetic_v<Arithmetic>, bool> = true>
    LinExpr(Arithmetic constant)
        : m_constant { static_cast<double>(constant) }
    {
    }
    /**
     * Creates a linear expression with zero as constant and the given variable with coefficient one.
     * @since 1.0.0
     * @remark This is on purpose not an explicit c'tor to allow expressions like <code>x <= 1</code>.
     * @param var Variable to store with coefficient one in the expression.
     */
    LinExpr(const Var& var);
    /**
     * Creates a linear expression with zero as constant and the given variables with coefficient one.
     * @since 1.3.0
     * @remark This is on purpose not an explicit c'tor to allow expressions like <code>... + {x1, x2}</code>.
     * @param vars Variables to store with coefficient one in the expression.
     */
    LinExpr(std::initializer_list<Var> vars);
    /**
     * Creates a linear expression with zero as constant and the given variables and coefficients.
     * @since 1.3.0
     * @param vars Variables to store in the expression.
     * @param coeffs Coefficients to store in the expression.
     * @pre \p vars and \p coeffs have the same length.
     */
    LinExpr(std::initializer_list<Var> vars, std::initializer_list<double> coeffs);
    /**
     * @copybrief LinExpr(std::initializer_list<Var>)
     * @since 1.3.0
     * @remark This is on purpose not an explicit c'tor to allow expressions like <code>... + vars</code>.
     * @tparam N Size of the array \p vars.
     * @param vars Variables to store with coefficient one in the expression.
     */
    template <std::size_t N>
    LinExpr(const std::array<Var, N>& vars)
        : m_vars { vars.begin(), vars.end() }
        , m_coeffs(vars.size(), 1)
    {
    }
    /**
     * @copybrief LinExpr(std::initializer_list<Var>, std::initializer_list<double>)
     * @since 1.3.0
     * @tparam N Size of the arrays \p vars and \p coeffs.
     * @param vars Variables to store in the expression.
     * @param coeffs Coefficients to store in the expression.
     */
    template <std::size_t N>
    LinExpr(const std::array<Var, N>& vars, std::array<double, N>& coeffs)
        : m_vars { vars.begin(), vars.end() }
        , m_coeffs { coeffs.begin(), coeffs.end() }
    {
    }
    /**
     * @copybrief LinExpr(std::initializer_list<Var>)
     * @since 1.3.0
     * @remark This is on purpose not an explicit c'tor to allow expressions like <code>... + vars</code>.
     * @param vars Variables to store with coefficient one in the expression.
     */
    LinExpr(const std::vector<Var>& vars);
    /**
     * @copybrief LinExpr(std::initializer_list<Var>, std::initializer_list<double>)
     * @since 1.3.0
     * @param vars Variables to store in the expression.
     * @param coeffs Coefficients to store in the expression.
     */
    LinExpr(const std::vector<Var>& vars, const std::vector<double>& coeffs);

    /**
     * Returns the constant term of the expression.
     * @since 1.0.0
     * @return the constant term of the expression.
     */
    [[nodiscard]] double getConstant() const;

    /**
     * Add another linear expression to this.
     * @since 1.0.0
     * @param expr Other linear expression to add.
     * @return Updated sum.
     */
    LinExpr& operator+=(const LinExpr& expr);
    /**
     * Subtract another expression from this.
     * @since 1.0.0
     * @param expr Right-hand-side of the subtraction.
     * @return Updated expression.
     */
    LinExpr& operator-=(const LinExpr& expr);
    /**
     * Multiply all coefficients.
     * @since 1.0.0
     * @param factor to multiply all coefficients with.
     * @return Scaled expression.
     */
    LinExpr& operator*=(double factor);
};

/**
 * Scales a linear expression by a factor.
 * @since 1.0.0
 * @param factor to scale the expression with.
 * @param rhs expression to scale.
 * @return scaled expression.
 */
LinExpr operator*(double factor, LinExpr rhs);

/**
 * Creates a new linear expression as the sum of two.
 * @since 1.0.0
 * @param lhs First summand.
 * @param rhs Second summand.
 * @return Sum of both expressions.
 */
LinExpr operator+(LinExpr lhs, const LinExpr& rhs);

/**
 * Creates the new linear expression \p lhs - \p rhs.
 * @since 1.0.0
 * @param lhs minuend.
 * @param rhs subtrahend.
 * @return minuend minus subtrahend.
 */
LinExpr operator-(LinExpr lhs, const LinExpr& rhs);

}
