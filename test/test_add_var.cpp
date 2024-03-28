#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/solving_statistics.hpp"

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(AddVar)

// lb nullopt ub value lNuD
// lb nullopt ub nullopt lNuN
// lb value ub value GetSolVal
// lb value ub nullopt lDuN

const SCIP_Real LB_DEFAULT { 0.0 };
const SCIP_Real UB_DEFAULT { 1.0 };

BOOST_AUTO_TEST_CASE(lDuN, *boost::unit_test::tolerance(1e-3))
{
    Model m1("Simple");
    auto x1 = m1.addVar("x_1", 1, VarType::CONTINUOUS, LB_DEFAULT, nullopt);
    auto x2 = m1.addVar("x_2", 1);
    m1.addConstr(x1 + x2 <= 1, "line");
    m1.setObjsense(Sense::MINIMIZE);
    m1.solve();
    BOOST_REQUIRE(m1.getNSols() > 0);
    BOOST_TEST(m1.getSolvingStatistic(statistics::PRIMALBOUND) == 0);

    Model m2("Simple");
    x1 = m2.addVar("x_1", 1, VarType::CONTINUOUS, LB_DEFAULT, nullopt);
    x2 = m2.addVar("x_2", 1);
    m2.addConstr(x1 + x2 >= 1, "line");
    m2.setObjsense(Sense::MAXIMIZE);
    m2.solve();
    BOOST_TEST(m2.getStatus() == SCIP_STATUS_UNBOUNDED);
}

BOOST_AUTO_TEST_CASE(lNuD, *boost::unit_test::tolerance(1e-3))
{
    Model m1("Simple");
    auto x1 = m1.addVar("x_1", 1, VarType::CONTINUOUS, nullopt, UB_DEFAULT);
    auto x2 = m1.addVar("x_2", 1);
    m1.addConstr(x1 + x2 <= 1, "line");
    m1.setObjsense(Sense::MINIMIZE);
    m1.solve();
    BOOST_TEST(m1.getStatus() == SCIP_STATUS_UNBOUNDED);

    Model m2("Simple");
    x1 = m2.addVar("x_1", 1, VarType::CONTINUOUS, nullopt, UB_DEFAULT);
    x2 = m2.addVar("x_2", 1);
    m2.addConstr(x1 + x2 <= 1, "line");
    m2.setObjsense(Sense::MAXIMIZE);
    m2.solve();
    BOOST_REQUIRE(m2.getNSols() > 0);
    BOOST_TEST(m2.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(lNuN, *boost::unit_test::tolerance(1e-3))
{
    Model m1("Simple");
    auto x1 = m1.addVar("x_1", 1, VarType::CONTINUOUS, nullopt, nullopt);
    auto x2 = m1.addVar("x_2", 1);
    m1.addConstr(x1 + x2 <= 1, "line");
    m1.setObjsense(Sense::MINIMIZE);
    m1.solve();
    BOOST_TEST(m1.getStatus() == SCIP_STATUS_UNBOUNDED);

    Model m2("Simple");
    x1 = m2.addVar("x_1", 1, VarType::CONTINUOUS, nullopt, nullopt);
    x2 = m2.addVar("x_2", 1);
    m2.addConstr(x1 + x2 <= 1, "line");
    m2.setObjsense(Sense::MAXIMIZE);
    m2.solve();
    BOOST_REQUIRE(m2.getNSols() > 0);
    BOOST_TEST(m2.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_SUITE_END()
