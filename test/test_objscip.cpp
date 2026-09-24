#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <memory>
#include <sstream>

#include "scippp/model.hpp"
#include <objscip/objeventhdlr.h>
#include <objscip/objmessagehdlr.h>

using namespace boost::algorithm;
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
    SCIP_DECL_EVENTINIT(scip_init)
    override
    {
        clog << "MyEventHandler: Here I am" << endl;
        return SCIP_OKAY;
    }
    SCIP_DECL_EVENTEXEC(scip_exec)
    override
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

/**
 * Forwards all messages to a file.
 */
class FileMessageHandler : public scip::ObjMessagehdlr {
    ofstream m_file;

    void write(const char* msg)
    {
        if (msg) {
            m_file << msg;
        } else {
            m_file.flush();
        }
    }

public:
    explicit FileMessageHandler(const filesystem::path& path)
        : scip::ObjMessagehdlr(false)
        , m_file(path)
    {
    }
    SCIP_DECL_MESSAGEWARNING(scip_warning)
    override
    {
        write(msg);
    }
    SCIP_DECL_MESSAGEDIALOG(scip_dialog)
    override
    {
        write(msg);
    }
    SCIP_DECL_MESSAGEINFO(scip_info)
    override
    {
        write(msg);
    }
};

BOOST_AUTO_TEST_CASE(UseMessageHandler)
{
    const auto LOG_FILE { filesystem::temp_directory_path()
        / boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%.log").string() };
    { // SCIP deletes the handler, and thereby closes the file, when the model is destructed
        Model model("Simple");
        auto x1 = model.addVar("x_1", 1);
        auto x2 = model.addVar("x_2", 1);
        model.addConstr(x1 + x2 >= 1, "capacity");
        model.setMessagehdlr(make_unique<FileMessageHandler>(LOG_FILE));
        BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
        model.solve();
        BOOST_TEST(model.getNSols() > 0);
    }
    ifstream file(LOG_FILE);
    ostringstream content;
    content << file.rdbuf();
    BOOST_TEST(contains(content.str(), "SCIP Status"));
    BOOST_TEST(contains(content.str(), "optimal solution found"));
    file.close();
    filesystem::remove(LOG_FILE);
}

BOOST_AUTO_TEST_SUITE_END()
