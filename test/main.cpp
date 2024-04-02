#define BOOST_TEST_MAIN // NOLINT(readability-identifier-naming)
#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/parameters.hpp"
#include "scippp/solving_statistics.hpp"

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(Basic)

BOOST_AUTO_TEST_CASE(ModelCtorWithScip)
{
    SCIP* scip;
    { // to enforce that the d'tor of Model is called
        SCIPcreate(&scip);
        Model model("StructuredBinding", scip);
        BOOST_TEST(model.scip() == scip);
        array<int, 2> coeff { { 1, 1 } };
        const auto& [x1, x2] = model.addVars<2>("x_", coeff);
        model.addConstr(x1 + x2 <= 1, "capacity");
        model.setObjsense(Sense::MAXIMIZE);
        model.solve();
        BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
    }
    SCIPfree(&scip);
}

BOOST_AUTO_TEST_CASE(StructuredBinding)
{
    Model model("StructuredBinding");
    array<int, 2> coeff { { 1, 1 } };
    const auto& [x1, x2] = model.addVars<2>("x_", coeff);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
    // test that deprecated method returns the same result
    BOOST_TEST(model.getPrimalbound() == 1);
}

BOOST_AUTO_TEST_CASE(StructuredBindingWithCoeff)
{
    Model model("StructuredBinding");
    const auto& [x1, x2] = model.addVars<2>("x_");
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 0);
}

BOOST_AUTO_TEST_CASE(StructuredBindingWithPredefinedConstantCoeff)
{
    Model model("StructuredBinding");
    const auto& [x1, x2] = model.addVars<2>("x_", COEFF_ONE);
    model.addConstr(x1 + x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
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
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == expected);
}

BOOST_AUTO_TEST_CASE(SimpleMaxRhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 <= 1, "capacityRight");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMaxLhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(1 >= x1 + x2, "capacityRight");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMinRhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(1 <= x1 + x2, "capacity");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
}

BOOST_AUTO_TEST_CASE(SimpleMinLhs)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_REQUIRE(model.getNSols() > 0);
    BOOST_TEST(model.getStatus() == SCIP_STATUS_OPTIMAL);
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
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
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 1);
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

BOOST_AUTO_TEST_CASE(EpsilonIsNotZero)
{
    Model model("Simple");
    BOOST_TEST(model.epsilon() > 0);
    BOOST_TEST(model.isZero(model.epsilon()));
    BOOST_TEST(model.round(model.epsilon()) == 0.0);
}

BOOST_AUTO_TEST_SUITE_END()
