#pragma once

#include <optional>
#include <vector>

#include "scippp/lin_expr.hpp"

namespace scippp {

/**
 * Represents a linear inequality: lhs <= expr <= rhs.
 *
 * Can be constructed only by operators.
 * @since 1.0.0
 */
class LinIneq {
    //! Left-hand-side of the inequality: lhs <= expr <= rhs.
    double m_lhs;
    //! Reft-hand-side of the inequality: lhs <= expr <= rhs. Non-present values are replaced by infinity later
    std::optional<double> m_rhs;
    //! Linear expression of the inequality: lhs <= expr <= rhs.
    LinExpr m_linExpr;
    friend class Model;
    friend LinIneq operator<=(const LinExpr& lhs, const LinExpr& rhs);
    friend LinIneq operator==(const LinExpr& lhs, const LinExpr& rhs);
    //! Private c'tor so that such objects cannot be created by the user manually.
    LinIneq() = default;
};

/**
 * Creates the inequality \p lhs <= \p rhs.
 * @since 1.0.0
 * @param lhs Left-hand-side of the less-or-equal inequality.
 * @param rhs Right-hand-side of the less-or-equal inequality.
 * @return Inequality less-or-equal.
 */
LinIneq operator<=(const LinExpr& lhs, const LinExpr& rhs);

/**
 * Creates the equality \p lhs == \p rhs.
 * @since 1.0.0
 * @param lhs Left-hand-side of the equality.
 * @param rhs Right-hand-side of the equality.
 * @return Equality inequality.
 */
LinIneq operator==(const LinExpr& lhs, const LinExpr& rhs);

/**
 * Creates the inequality \p lhs >= \p rhs.
 * @since 1.0.0
 * @param lhs Left-hand-side of the greater-or-equal inequality.
 * @param rhs Right-hand-side of the greater-or-equal inequality.
 * @return Inequality greater-or-equal.
 */
LinIneq operator>=(const LinExpr& lhs, const LinExpr& rhs);

}
