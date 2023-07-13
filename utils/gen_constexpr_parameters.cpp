#include <boost/algorithm/string.hpp>
#include <iostream>
#include <map>
#include <scip/scip.h>
#include <scip/scipdefplugins.h>
#include <scip/struct_paramset.h>
#include <scip/struct_scip.h>
#include <scip/struct_set.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ScipParam {
    vector<string> nameSplit;
    string description;
    SCIP_PARAMTYPE type;
    static vector<string> fitToLineLength(string str, size_t line_sz)
    {
        if (std::all_of(std::begin(str), std::end(str), [](char c) { return std::isspace(c); }))
            return {}; // empty string or string with all spaces, return an empty vector

        std::vector<std::string> result(1); // vector containing one empty string

        std::istringstream stm(str); // use a string stream to split on white-space
        std::string word;
        while (stm >> word) // for each word in the string
        {
            // if this word will fit into the current line, append the word to the current line
            if ((result.back().size() + word.size()) <= line_sz)
                result.back() += word + ' ';

            else {
                result.back().pop_back(); // remove the trailing space at the end of the current line
                result.push_back(word + ' '); // and place this new word on the next line
            }
        }

        result.back().pop_back(); // remove the trailing space at the end of the last line
        return result;
    }
    static string getCppIdentifier(const string& s)
    {
        auto res { boost::algorithm::to_upper_copy(s) };
        boost::replace_all(res, "-", "_");
        return res;
    }
    string getScipName() const
    {
        return boost::algorithm::join(nameSplit, "/");
    }
    string getVariableName() const
    {
        return getCppIdentifier(nameSplit.back());
    }
    string getType() const
    {
        switch (type) {
        case SCIP_PARAMTYPE_BOOL:
            return "bool";
        case SCIP_PARAMTYPE_INT:
            return "int";
        case SCIP_PARAMTYPE_LONGINT:
            return "long long";
        case SCIP_PARAMTYPE_REAL:
            return "double";
        case SCIP_PARAMTYPE_CHAR:
            return "char";
        case SCIP_PARAMTYPE_STRING:
            return "std::string";
        }
    }

public:
    explicit ScipParam(SCIP_PARAM* param)
        : description { param->desc }
        , type { param->paramtype }
    {
        boost::split(nameSplit, param->name, boost::is_any_of("/"));
        // doxygen treats <xx> as xml
        boost::algorithm::replace_all(description, "<", "\\<");
        boost::algorithm::replace_all(description, ">", "\\>");
        boost::algorithm::replace_all(description, "#", "\\#");
    }
    string getNamespace() const
    {
        vector<string> parts(nameSplit.begin(), prev(nameSplit.end()));
        for_each(parts.begin(), parts.end(), [](string& s) {
            s = getCppIdentifier(s);
        });
        return boost::algorithm::join(parts, "::");
    }
    static string getPrefixFromNamespace(string namesp)
    {
        boost::algorithm::replace_all(namesp, "::", "/");
        boost::algorithm::to_lower(namesp);
        return namesp;
    }
    string getDoxygen() const
    {
        string res;
        for (const string line : fitToLineLength(description, 120 - 8)) {
            res += "    //! " + line + "\n";
        }
        return res;
    }
    string getConstexprParam() const
    {
        return "constexpr Param<" + getType() + "> " + getVariableName() + " { \"" + getScipName() + "\" };";
    }
};

string createNamespaceDocu(const string& namesp)
{
    return "//! Parameters with prefix " + ScipParam::getPrefixFromNamespace(namesp);
}

int main()
{
    SCIP* scip { nullptr };
    SCIPcreate(&scip);
    SCIPincludeDefaultPlugins(scip);
    auto* paramset = scip->set->paramset;
    map<string, vector<ScipParam>> paramsPerNamespace;
    for (size_t i = 0; i < paramset->nparams; ++i) {
        ScipParam param { paramset->params[i] };
        paramsPerNamespace[param.getNamespace()].push_back(param);
    }
    for (const auto& [namesp, elems] : paramsPerNamespace) {
        cout << createNamespaceDocu(namesp) << "\n";
        cout << "namespace " << namesp << " {\n";
        for (const auto& param : elems) {
            cout << param.getDoxygen();
            cout << "    " << param.getConstexprParam() << "\n";
        }
        cout << "}" << endl;
    }
    SCIPfree(&scip);
}
