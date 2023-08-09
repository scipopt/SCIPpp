#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(Var)

BOOST_AUTO_TEST_CASE(GetSolVal, *boost::unit_test::tolerance(1e-3))
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.getSolVal(sol) == 0.5);
    BOOST_TEST(x2.getSolVal(sol) == 0.5);
}

BOOST_AUTO_TEST_SUITE_END()
