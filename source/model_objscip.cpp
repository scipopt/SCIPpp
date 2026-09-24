#include "scippp/model.hpp"

#include <scip/bendersdefcuts.h>

namespace scippp {

Model::Model(
    const std::string& name,
    std::unique_ptr<scip::ObjProbData> probData,
    SCIP* scip,
    bool withDefaultPlugins)
    : Model(scip, withDefaultPlugins)
{
    assert(probData); // GCOVR_EXCL_LINE
    const auto RETCODE { SCIPcreateObjProb(m_scip, name.c_str(), probData.get(), TRUE) };
    // SCIP owns the problem data only on success, otherwise it is deleted when leaving this constructor.
    if (RETCODE == SCIP_OKAY) {
        probData.release();
    }
    m_scipCallWrapper(RETCODE);
}

Var& Model::addVar(
    const std::string& name,
    std::unique_ptr<scip::ObjVardata> vardata,
    SCIP_Real coeff,
    VarType varType,
    std::optional<SCIP_Real> lb,
    std::optional<SCIP_Real> ub)
{
    assert(vardata); // GCOVR_EXCL_LINE
    SCIP_VAR* var { nullptr };
    const auto RETCODE { SCIPcreateObjVar(
        m_scip, /* SCIP environment */
        &var, /* reference to the variable */
        name.c_str(), /* name of the variable */
        lb != std::nullopt ? lb.value() : -SCIPinfinity(m_scip), /* lower bound of the variable */
        ub != std::nullopt ? ub.value() : SCIPinfinity(m_scip), /* upper bound of the variable */
        coeff, /* obj. coefficient. */
        static_cast<SCIP_Vartype>(varType), /* variable type */
        TRUE, /* initial */
        FALSE, /* removable */
        vardata.get(), /* variable data */
        TRUE /* delete the variable data when the variable is freed */
        ) };
    // SCIP owns the variable data only on success, otherwise it is deleted when leaving this method.
    if (RETCODE == SCIP_OKAY) {
        vardata.release();
    }
    m_scipCallWrapper(RETCODE);
    m_scipCallWrapper(SCIPaddVar(m_scip, var));
    m_vars.emplace_back(Var { var });
    return m_vars.back();
}

void Model::setMessagehdlr(std::unique_ptr<scip::ObjMessagehdlr> handler) const
{
    assert(handler); // GCOVR_EXCL_LINE
    SCIP_MESSAGEHDLR* messagehdlr { nullptr };
    // SCIP owns the handler object from now on, it even deletes it if the creation fails
    m_scipCallWrapper(SCIPcreateObjMessagehdlr(&messagehdlr, handler.release(), TRUE));
    const auto RETCODE { SCIPsetMessagehdlr(m_scip, messagehdlr) };
    // SCIPsetMessagehdlr captures the message handler on success, so we always release our reference. Releasing before
    // passing RETCODE to the call wrapper avoids a leak if the wrapper throws, and keeps RETCODE as the last return code.
    m_scipCallWrapper(SCIPmessagehdlrRelease(&messagehdlr));
    m_scipCallWrapper(RETCODE);
}

void Model::activatePricer(const scip::ObjPricer& pricer) const
{
    m_scipCallWrapper(SCIPactivatePricer(m_scip, SCIPfindPricer(m_scip, pricer.scip_name_)));
}

void Model::activateBenders(const scip::ObjBenders& benders, int nSubproblems) const
{
    auto* scipBenders { SCIPfindBenders(m_scip, benders.scip_name_) };
    m_scipCallWrapper(SCIPincludeBendersDefaultCuts(m_scip, scipBenders));
    m_scipCallWrapper(SCIPactivateBenders(m_scip, scipBenders, nSubproblems));
    // otherwise the constraint handlers do not enforce the Benders' decomposition
    m_scipCallWrapper(SCIPsetBoolParam(m_scip, "constraints/benders/active", TRUE));
    m_scipCallWrapper(SCIPsetBoolParam(m_scip, "constraints/benderslp/active", TRUE));
    if (!benders.iscloneable()) {
        // SCIP crashes when copying the model to a sub-SCIP, e.g., in a heuristic, as it expects the copy to succeed
        m_scipCallWrapper(SCIPsetBoolParam(m_scip, "benders/copybenders", FALSE));
    }
}

}
