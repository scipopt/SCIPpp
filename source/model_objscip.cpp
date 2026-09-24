#include "scippp/model.hpp"

#include <utility>

namespace scippp {

namespace {

    /**
     * Includes an objscip plugin, %SCIP takes ownership on success.
     *
     * @tparam Base objscip base class of the plugin.
     * @param scip %SCIP data structure to include the plugin in.
     * @param scipCallWrapper Wrapper for the call to %SCIP's include function.
     * @param scipInclude %SCIP's include function for \p Base, e.g., SCIPincludeObjEventhdlr.
     * @param plugin to include, it is deleted if including fails.
     * @return \c true iff including succeeded.
     */
    template <typename Base>
    bool includeObjPlugin(
        SCIP* scip,
        const std::function<void(SCIP_Retcode)>& scipCallWrapper,
        SCIP_RETCODE (*scipInclude)(SCIP*, Base*, SCIP_Bool),
        std::unique_ptr<Base> plugin)
    {
        const auto RETCODE { scipInclude(scip, plugin.get(), TRUE) };
        // SCIP owns the plugin only on success, otherwise it is deleted when leaving this function.
        if (RETCODE == SCIP_OKAY) {
            plugin.release();
        }
        scipCallWrapper(RETCODE);
        return RETCODE == SCIP_OKAY;
    }

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

bool Model::includeObj(std::unique_ptr<scip::ObjEventhdlr> eventhdlr) const
{
    return includeObjPlugin(m_scip, m_scipCallWrapper, &SCIPincludeObjEventhdlr, std::move(eventhdlr));
}

bool Model::includeObj(std::unique_ptr<scip::ObjConshdlr> conshdlr) const
{
    return includeObjPlugin(m_scip, m_scipCallWrapper, &SCIPincludeObjConshdlr, std::move(conshdlr));
}

}
