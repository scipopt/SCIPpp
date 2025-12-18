#pragma once

#include <string>
#include <vector>

namespace scippp {

/**
 * A data structure to hold an %IIS (%Irreducible %Infeasible %Subsystem).
 * @since 1.4.0
 */
struct IIS {
    //! Ids of the constraints in the %IIS.
    std::vector<std::string> consIds;
};

}
