#pragma once

#include <functional>

// forward declare
struct Scip;

namespace scippp::statistics {

template<typename T>
struct Statistic {
    using fptr = T(*)(Scip*);
    const fptr m_PLAIN_CALL;
    T operator()(Scip* s) const {
        return m_PLAIN_CALL(s);
    }
};

}
