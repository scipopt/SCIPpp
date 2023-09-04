#include <boost/test/unit_test.hpp>

#include "scippp/model.hpp"
#include <objscip/objeventhdlr.h>

using namespace scippp;
using namespace std;

BOOST_AUTO_TEST_SUITE(ObjSCIP)

/**
 * We check whether SCIP++ works with ObjSCIP
 */
class MyEventHandler : public scip::ObjEventhdlr {
public:
    MyEventHandler(SCIP* scip)
        : scip::ObjEventhdlr(scip, "NAME", "DESC")
    {
    }
    SCIP_DECL_EVENTINIT(scip_init) override
    {
        clog << "MyEventHandler: Here I am" << endl;
        return SCIP_OKAY;
    }
    SCIP_DECL_EVENTEXEC(scip_exec) override
    {
        return SCIP_OKAY;
    }
};

BOOST_AUTO_TEST_CASE(UseEventHandler)
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    SCIPincludeObjEventhdlr(model.scip(), new MyEventHandler(model.scip()), false);
    model.setObjsense(Sense::MINIMIZE);
    model.solve();
    BOOST_TEST(model.getNSols() > 0);
}

BOOST_AUTO_TEST_SUITE_END()
