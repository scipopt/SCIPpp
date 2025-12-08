#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/parameters.hpp"

#include <algorithm>

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(IIS)

BOOST_AUTO_TEST_CASE(CanBeCreated)
{
    Model model("Simple");
    const auto& [x1, x2] = model.addVars<2>("x_");
    model.addConstr(x1 + x2 >= 2, "lower");
    model.addConstr(x1 + x2 <= 1, "upper");
    model.addConstr(x1 + x2 >= 0, "useless");
    model.setObjsense(Sense::MINIMIZE);

    model.setParam(params::IIS::SILENT, true); // to avoid output during testing
    model.solve();
    BOOST_REQUIRE(model.getStatus() == SCIP_STATUS_INFEASIBLE);
    auto iis { model.generateIIS() };
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);

    const auto& icons { iis.consIds };
    BOOST_TEST(icons.size() == 2);
    BOOST_TEST((std::find(icons.begin(), icons.end(), "lower") != iis.consIds.end()));
    BOOST_TEST((std::find(icons.begin(), icons.end(), "upper") != iis.consIds.end()));
    BOOST_TEST((std::find(icons.begin(), icons.end(), "useless") == iis.consIds.end()));
}

BOOST_AUTO_TEST_CASE(WorksOnEmptyProblem)
{
    Model model("Simple");
    model.solve();
    auto iis { model.generateIIS() };
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    BOOST_TEST(iis.consIds.size() == 0);
}

BOOST_AUTO_TEST_CASE(WorksWithoutSolving)
{
    Model model("Simple");
    auto iis { model.generateIIS() };
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    BOOST_TEST(iis.consIds.size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
