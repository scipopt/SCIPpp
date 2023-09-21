#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <sstream>

#include "scippp/model.hpp"

using namespace boost::algorithm;
using namespace scippp;
using namespace std;

class TempFile {
    filesystem::path m_path { filesystem::temp_directory_path() };

public:
    explicit TempFile(const string& extension)
    {
        m_path += boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%." + extension).string();
    }
    ~TempFile()
    {
        filesystem::remove(m_path);
    }
    [[nodiscard]] filesystem::directory_entry path() const
    {
        return filesystem::directory_entry(m_path);
    }
    [[nodiscard]] string content() const
    {
        ifstream t(m_path);
        ostringstream sstr;
        sstr << t.rdbuf();
        return sstr.str();
    }
};

auto createModel()
{
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(x1 + x2 >= 1, "capacity");
    model.addConstr(x1 == x2, "equal");
    model.setObjsense(Sense::MINIMIZE);
    return model;
}

BOOST_AUTO_TEST_SUITE(IO)

BOOST_AUTO_TEST_CASE(FileLP)
{
    auto model { createModel() };

    TempFile tf("lp");
    model.writeOrigProblem(tf.path());
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    auto content { tf.content() };
    BOOST_TEST(contains(content, "Obj: +1 x_1 +1 x_2"));
    BOOST_TEST(contains(content, "capacity:"));
    BOOST_TEST(contains(content, "equal:"));
    BOOST_TEST(contains(content, "Minimize"));
}

BOOST_AUTO_TEST_CASE(FileMPS)
{
    auto model { createModel() };

    TempFile tf("mps");
    model.writeOrigProblem(tf.path());
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
    auto content { tf.content() };
    BOOST_TEST(contains(content, "G  capacity"));
    BOOST_TEST(contains(content, "E  equal"));
    BOOST_TEST(contains(content, "\n  MIN"));
}

BOOST_AUTO_TEST_CASE(StdoutLP)
{
    auto model { createModel() };
    model.writeOrigProblem("lp");
    BOOST_TEST(model.getLastReturnCode() == SCIP_OKAY);
}

BOOST_AUTO_TEST_CASE(StdoutWithInvalidExtension)
{
    auto model { createModel() };
    model.writeOrigProblem("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    BOOST_TEST(model.getLastReturnCode() == SCIP_PLUGINNOTFOUND);
}

BOOST_AUTO_TEST_SUITE_END()
