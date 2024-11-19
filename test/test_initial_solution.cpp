#include <boost/test/unit_test.hpp>

#include <boost/test/data/test_case.hpp>

#include "scippp/model.hpp"

using namespace scippp;
using namespace std;
namespace bdata = boost::unit_test::data;

BOOST_AUTO_TEST_SUITE(InitSolution)

BOOST_DATA_TEST_CASE(InitialSolutionStored, bdata::make({ 1, 2, 3 }), indexSetToOne)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1, VarType::BINARY);
    auto x2 = model.addVar("x_2", 1, VarType::BINARY);
    auto x3 = model.addVar("x_3", 1, VarType::BINARY);
    model.addConstr(x1 + x2 + x3 <= 1, "upperBound");
    model.setObjsense(Sense::MAXIMIZE);

    InitialSolution is;
    is.setValue(x1, indexSetToOne == 1 ? 1 : 0);
    is.setValue(x2, indexSetToOne == 2 ? 1 : 0);
    is.setValue(x3, indexSetToOne == 3 ? 1 : 0);
    BOOST_TEST(model.addSolution(is));

    BOOST_REQUIRE(model.getNSols() > 0);
    auto sol = model.getBestSol();
    BOOST_TEST(x1.getSolValAsInt(sol) == (indexSetToOne == 1 ? 1 : 0));
    BOOST_TEST(x2.getSolValAsInt(sol) == (indexSetToOne == 2 ? 1 : 0));
    BOOST_TEST(x3.getSolValAsInt(sol) == (indexSetToOne == 3 ? 1 : 0));
}

BOOST_AUTO_TEST_CASE(Infeasible)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1, VarType::BINARY);
    model.setObjsense(Sense::MAXIMIZE);
    InitialSolution is;
    is.setValue(x1, 2);
    BOOST_TEST(!model.addSolution(is));
}

BOOST_AUTO_TEST_SUITE_END()