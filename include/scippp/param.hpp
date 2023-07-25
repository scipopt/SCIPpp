#pragma once

#include <string_view>

//! Enum equivalent of SCIP's string parameters.
namespace scippp::params {

/**
 * Stores the argument type and string representation of a parameter.
 * @since 1.0.0
 * @tparam baseType Parameter value type.
 */
template <typename baseType>
struct Param {
    //! Original name of the parameter in %SCIP.
    std::string_view scipName;
    /**
     * C'tor that stores the original parameter name and its type as template parameter.
     * @since 1.0.0
     * @param name Original name of the parameter in %SCIP.
     */
    constexpr explicit Param(const std::string_view& name)
        : scipName { name }
    {
    }
};

}
