#pragma once

#include <functional>

// forward declare
struct Scip;

/**
 * Parameters to access statistics with.
 *
 * since 1.2.0
 */
namespace scippp::statistics {

/**
 * Storage for a function pointer.
 * @since 1.2.0
 * @tparam T
 */
template<typename T>
struct Statistic {
    //! Type of the function pointer to store the original call to %SCIP.
    using fptr = T(*)(Scip*);
    //! Function pointer to the original %SCIP call.
    const fptr m_PLAIN_CALL;
    /**
     * Returns the value of the statistics.
     *
     * @param s Raw pointer to a %C-SCIP object.
     * @return Value that the original call stored in the pointer returns.
     */
    T operator()(Scip* s) const {
        return m_PLAIN_CALL(s);
    }
};

}
