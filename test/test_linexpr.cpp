#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/solving_statistics.hpp"

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(LinExpression)

BOOST_AUTO_TEST_CASE(AddOneVar)
{
    Model model("Simple");
    array coeff { 1, 1 };
    const auto& [x1, x2] = model.addVars<2>("x_", coeff);
    LinExpr l;
    l += x1; // allocates memory, thus slow
    l += x2; // allocates memory again, thus slow
    model.addConstr(l <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(CtorArray)
{
    Model model("Simple");
    array coeff { 1, 1 };
    const auto VARS = model.addVars<2>("x_", coeff);
    LinExpr l(VARS);
    model.addConstr(l <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(AddArray)
{
    Model model("Simple");
    array coeff { 1, 1 };
    const auto VARS = model.addVars<2>("x_", coeff);
    LinExpr l;
    l += VARS;
    model.addConstr(l <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(AddVector)
{
    Model model("Simple");
    array coeff { 1, 1 };
    const auto A_VARS { model.addVars<2>("x_", coeff) };
    const vector<Var> VARS { A_VARS.begin(), A_VARS.end() };
    LinExpr l;
    l += VARS;
    model.addConstr(l <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(AddInitializerList)
{
    Model model("Simple");
    array coeff { 1, 1 };
    const auto& [x1, x2] = model.addVars<2>("x_", coeff);
    LinExpr l;
    l += { x1, x2 };
    model.addConstr(l <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_SUITE_END()
