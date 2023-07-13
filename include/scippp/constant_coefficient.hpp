#pragma once

#include <cstdlib>

namespace scippp {

//! A class which an index operator that always returns a constant value.
class ConstantCoefficient {
    //! Constant value to return.
    const double m_COEFF;

public:
    /**
     * Stores the constant value that will be returned by the index operator.
     * @param c Constant value to return.
     */
    constexpr ConstantCoefficient(double c)
        : m_COEFF { c }
    {
    }
    /**
     * Index operator that always returns the same constant value.
     * @return the constant value.
     */
    inline double operator[](std::size_t) const
    {
        return m_COEFF;
    }
};

//! An object which index operator always returns 0.
static constexpr ConstantCoefficient COEFF_ZERO { 0 };
//! An object which index operator always returns 1.
static constexpr ConstantCoefficient COEFF_ONE { 1 };

}
