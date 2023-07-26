#define BOOST_TEST_MAIN // NOLINT(readability-identifier-naming)
#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/parameters.hpp"

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(Examples)

BOOST_AUTO_TEST_CASE(Knapsack)
{
    vector<int> w { 3, 4, 3, 3, 3, 3, 4, 2, 4, 1 };
    vector<int> v { 230, 134, 52, 60, 151, 95, 201, 245, 52, 55 };
    int c { 14 };

    Model model("KNAPSACK");
    auto x { model.addVars("x_", w.size(), v, VarType::BINARY) };
    LinExpr weight;
    for (size_t i { 0 }; i < w.size(); i++) {
        weight += w.at(i) * x.at(i);
    }
    model.addConstr(weight <= c, "weight");
    model.setObjsense(Sense::MAXIMIZE);
    model.setParam(params::LIMITS::MAXSOL, 1);
    model.setParam(params::DISPLAY::VERBLEVEL, 0);

    model.solve();
    BOOST_TEST(model.getPrimalbound() == 882);
    BOOST_TEST(model.getNSols() == 1);
}

BOOST_AUTO_TEST_CASE(StructuredBinding)
{
    Model model("StructuredBinding");
    array<int, 2> coeff { { 1, 1 } };
    const auto& [x1, x2] = model.addVars<2>("x_", coeff);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(StructuredBindingWithCoeff)
{
    Model model("StructuredBinding");
    const auto& [x1, x2] = model.addVars<2>("x_");
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 0);
}

BOOST_AUTO_TEST_CASE(StructuredBindingWithPredefinedConstantCoeff)
{
    Model model("StructuredBinding");
    const auto& [x1, x2] = model.addVars<2>("x_", COEFF_ONE);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(CoefficientsFromExternalSource)
{
    struct Coeff {
        string strangeCoeffSource;
        double operator[](size_t index) const
        {
            return strangeCoeffSource[index];
        }
    };
    Model model("StructuredBinding");
    const auto& [x1, x2] = model.addVars<2>("x_", Coeff { "22" });
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    char expected = '2';
    BOOST_TEST(model.getPrimalbound() == expected);
}

BOOST_AUTO_TEST_CASE(SimpleMaxRhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 <= 1, "capacityRight");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMaxLhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(1 >= x1 + x2, "capacityRight");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMinRhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(1 <= x1 + x2, "capacity");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMinLhs, *boost::unit_test::tolerance(1e-3))
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    BOOST_TEST(model.getPrimalbound() == 1);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.getSolVal(sol) == 0.5);
    BOOST_TEST(x2.getSolVal(sol) == 0.5);
}

BOOST_AUTO_TEST_CASE(GetLastReturnCodeOkay)
{
    Model model("Simple");
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    auto x1 = model.addVar("x_1", 1);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    auto x2 = model.addVar("x_2", 1);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.addConstr(x1 + x2 <= 1, "capacityRight");
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.setObjsense(Sense::MAXIMIZE);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    model.solve();
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    BOOST_TEST(model.getPrimalbound() == 1);
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
}

BOOST_AUTO_TEST_CASE(SetCallWrapper)
{
    string result;
    Model model("Simple");
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    BOOST_TEST(result.empty());
    model.setScipCallWrapper([&result](SCIP_Retcode r) {
        result += to_string(r);
    });
    auto x1 = model.addVar("x_1", 1);
    BOOST_TEST(!result.empty());
}

BOOST_AUTO_TEST_SUITE_END()
