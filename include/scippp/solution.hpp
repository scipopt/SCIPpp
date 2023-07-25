#pragma once

// forward declare
struct Scip;
struct SCIP_Sol;

namespace scippp {

/**
 * Wrapper for a %SCIP solution.
 * @since 1.0.0
 */
struct Solution {
    //! Pointer to the underlying %SCIP object.
    Scip* scip { nullptr };
    //! Pointer to the underlying %SCIP solution.
    SCIP_Sol* sol { nullptr };
};

}
