#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include "scippp/parameters.hpp"
#include "scippp/solving_statistics.hpp"

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
    BOOST_TEST(model.getSolvingStatistic(statistics::PRIMALBOUND) == 882);
    BOOST_TEST(model.getNSols() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
