#pragma once

#include <scip/type_var.h>

namespace scippp {

//! Type of a variable.
enum class VarType {
    //! Binary variable.
    BINARY = SCIP_VARTYPE_BINARY,
    //! Integral variable.
    INTEGER = SCIP_VARTYPE_INTEGER,
    //! Implicit integral variable.
    IMPL_INT = SCIP_VARTYPE_IMPLINT,
    //! Continuous variable.
    CONTINUOUS = SCIP_VARTYPE_CONTINUOUS
};

}
