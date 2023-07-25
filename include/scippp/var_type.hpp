#pragma once

#include <scip/type_var.h>

namespace scippp {

/**
 * Type of a variable.
 * @since 1.0.0
 */
enum class VarType {
    /**
     * Binary variable.
     * @since 1.0.0
     */
    BINARY = SCIP_VARTYPE_BINARY,
    /**
     * Integral variable.
     * @since 1.0.0
     */
    INTEGER = SCIP_VARTYPE_INTEGER,
    /**
     * Implicit integral variable.
     * @since 1.0.0
     */
    IMPL_INT = SCIP_VARTYPE_IMPLINT,
    /**
     * Continuous variable.
     * @since 1.0.0
     */
    CONTINUOUS = SCIP_VARTYPE_CONTINUOUS
};

}
