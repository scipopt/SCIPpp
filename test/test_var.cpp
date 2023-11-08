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

BOOST_AUTO_TEST_CASE(GetSolValInt)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 2, "capacity");
    model.addConstr(x1 == x2, "equal");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.getSolValAsInt(sol) == 1);
    BOOST_TEST(x2.getSolValAsInt(sol) == 1);
}

BOOST_AUTO_TEST_CASE(GetSolValLongInt)
{
    long long big { static_cast<long long>(numeric_limits<int>::max()) + 1 };
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1.0, VarType::CONTINUOUS, 0.0, model.infinity());
    model.addConstr(x1 >= static_cast<double>(big), "capacity");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.getSolValAsLongInt(sol) == big);
}

BOOST_AUTO_TEST_CASE(IsZero)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.isZero(sol));
    BOOST_TEST(model.isZero(x1.getSolVal(sol)));
}

BOOST_AUTO_TEST_CASE(IsVoid)
{
    scippp::Var x;
    BOOST_TEST(x.var == nullptr);
    BOOST_TEST(x.isVoid());

    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    BOOST_TEST(x1.var != nullptr);
    BOOST_TEST(!x1.isVoid());
}

BOOST_AUTO_TEST_SUITE_END()
