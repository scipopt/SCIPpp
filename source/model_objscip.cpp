#include "scippp/model.hpp"

namespace scippp {

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

}
