#include "scippp/model.hpp"

#include <scip/scipdefplugins.h>

#include <utility>

namespace scippp {

Var& Model::addVar(
    const std::string& name,
    SCIP_Real coeff,
    VarType varType,
    std::optional<SCIP_Real> lb,
    std::optional<SCIP_Real> ub)
{
    SCIP_VAR* var { nullptr };
    m_scipCallWrapper(SCIPcreateVarBasic(
        m_scip, /* SCIP environment */
        &var, /* reference to the variable */
        name.c_str(), /* name of the variable */
        lb != std::nullopt ? lb.value() : -SCIPinfinity(m_scip), /* lower bound of the variable */
        ub != std::nullopt ? ub.value() : SCIPinfinity(m_scip), /* upper bound of the variable */
        coeff, /* obj. coefficient. */
        static_cast<SCIP_Vartype>(varType) /* variable is binary */
        ));
    m_scipCallWrapper(SCIPaddVar(m_scip, var));
    m_vars.emplace_back(Var { var });
    return m_vars.back();
}

Model::Model(const std::string& name, SCIP* scip, bool withDefaultPlugins)
{
    m_scipCallWrapper = [this](SCIP_Retcode r) { m_lastReturnCode = r; };
    if (scip) {
        m_scip = scip;
    } else {
        m_scipCallWrapper(SCIPcreate(&m_scip));
        m_weCreatedANewScipObject = true;
    }
    if (withDefaultPlugins) {
        m_scipCallWrapper(SCIPincludeDefaultPlugins(m_scip));
    }
    m_scipCallWrapper(SCIPcreateProbBasic(m_scip, name.c_str()));
}

SCIP_Retcode Model::getLastReturnCode() const
{
    return m_lastReturnCode;
}

void Model::setScipCallWrapper(std::function<void(SCIP_Retcode)> wrapper)
{
    m_scipCallWrapper = std::move(wrapper);
}

Model::~Model()
{
    for (auto& var : m_vars) {
        m_scipCallWrapper(SCIPreleaseVar(m_scip, &var.var));
    }
    for (auto* cons : m_cons) {
        m_scipCallWrapper(SCIPreleaseCons(m_scip, &cons));
    }
    if (m_weCreatedANewScipObject) {
        m_scipCallWrapper(SCIPfree(&m_scip));
    }
}

void Model::addConstr(const scippp::LinIneq& ineq, const std::string& name)
{
    SCIP_CONS* con { nullptr };
    m_scipCallWrapper(SCIPcreateConsBasicLinear(
        m_scip,
        &con, /* pointer to hold the created constraint */
        name.c_str(), /* name of constraint */
        0, /* number of nonzeros in the constraint */
        nullptr, /* array with variables of constraint entries */
        nullptr, /* array with coefficients of constraint entries */
        ineq.m_lhs, /* left hand side of constraint */
        ineq.m_rhs.has_value() ? ineq.m_rhs.value() : infinity()));
    for (size_t index { 0 }; index < ineq.m_linExpr.m_vars.size(); index++) {
        m_scipCallWrapper(SCIPaddCoefLinear(m_scip, con, ineq.m_linExpr.m_vars.at(index).var, ineq.m_linExpr.m_coeffs.at(index)));
    }
    m_scipCallWrapper(SCIPaddCons(m_scip, con));
    m_cons.push_back(con);
}

SCIP_Real Model::infinity()
{
    return SCIPinfinity(m_scip);
}

void Model::solve()
{
    m_scipCallWrapper(SCIPsolve(m_scip));
}

void Model::setObjsense(Sense objsense)
{
    m_scipCallWrapper(SCIPsetObjsense(m_scip, static_cast<SCIP_Objsense>(objsense)));
}

Scip* Model::scip()
{
    return m_scip;
}

SCIP_STATUS Model::getStatus()
{
    return SCIPgetStatus(m_scip);
}

int Model::getNSols()
{
    return SCIPgetNSols(m_scip);
}

Solution Model::getBestSol()
{
    return Solution { m_scip, SCIPgetBestSol(m_scip) };
}

double Model::getPrimalbound()
{
    return SCIPgetPrimalbound(m_scip);
}

}
