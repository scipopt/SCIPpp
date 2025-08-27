#include <boost/test/unit_test.hpp>

#include <algorithm>

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
    array objCoeff { 1.0, 1.0 };

    Model m1("m1");
    const auto VARS1 = m1.addVars<2>("x_", objCoeff);
    LinExpr l1(VARS1);
    m1.addConstr(l1 <= 1, "capacity");
    m1.setObjsense(Sense::MAXIMIZE);
    m1.solve();
    BOOST_TEST(m1.getSolvingStatistic(statistics::PRIMALBOUND) == 1.0);

    Model m2("m2");
    const auto VARS2 = m2.addVars<2>("x_", objCoeff);
    LinExpr l2(VARS2, objCoeff); // same as before, but different c'tor
    m2.addConstr(l2 <= 1, "capacity");
    m2.setObjsense(Sense::MAXIMIZE);
    m2.solve();
    BOOST_TEST(m2.getSolvingStatistic(statistics::PRIMALBOUND) == 1.0);

    const double FAC { 2.0 };
    array constrCoeff { FAC, FAC };

    Model m3("m3");
    const auto VARS3 = m3.addVars<2>("x_", objCoeff);
    LinExpr l3(VARS3, constrCoeff);
    m3.addConstr(l3 <= 1, "capacity");
    m3.setObjsense(Sense::MAXIMIZE);
    m3.solve();
    BOOST_TEST(m3.getSolvingStatistic(statistics::PRIMALBOUND) == 1.0 / FAC);
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
    LinExpr l1;
    l1 += VARS;
    model.addConstr(l1 <= 1, "capacity1");
    LinExpr l2(VARS, vector { 2.0, 2.0 });
    model.addConstr(l2 <= 2, "capacity2"); // duplicate, but different c'tor
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
    // duplicate, but different c'tor:
    model.addConstr(LinExpr({ x1, x2 }, { 2.0, 2.0 }) <= 2, "capacity2");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(CheckInternalsUsingFriendStruct)
{
    const double VAL { 2.0 };
    for (size_t num { 1 }; num < 4; ++num) {
        Model m("m");
        const auto VARS = m.addVars("x", num);

        LinExpr lDef(VARS);
        BOOST_TEST(lDef.getConstant() == 0);
        BOOST_TEST(lDef.m_constant == 0);
        BOOST_TEST(lDef.m_vars.size() == num);
        BOOST_TEST(lDef.m_coeffs.size() == num);
        BOOST_TEST(all_of(lDef.m_coeffs.begin(), lDef.m_coeffs.end(), [](double d) { return d == 1; }));

        const vector COEFF(num, VAL);
        LinExpr lCoeff(VARS, COEFF);
        BOOST_TEST(lCoeff.getConstant() == 0);
        BOOST_TEST(lCoeff.m_constant == 0);
        BOOST_TEST(lCoeff.m_vars.size() == num);
        BOOST_TEST(lCoeff.m_coeffs.size() == num);
        BOOST_TEST(all_of(lCoeff.m_coeffs.begin(), lCoeff.m_coeffs.end(), [&VAL](double d) { return d == VAL; }));
    }
}

BOOST_AUTO_TEST_SUITE_END()
