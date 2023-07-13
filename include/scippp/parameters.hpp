#pragma once

#include "scippp/param.hpp"
#undef INFINITY

//! Enum equivalent of SCIP's string parameters.
namespace scippp::params {

//! Parameters with prefix benders
namespace BENDERS {
    //! the tolerance used for checking optimality in Benders' decomposition. tol where optimality is given by LB + tol
    //! \> UB.
    constexpr Param<double> SOLUTIONTOL { "benders/solutiontol" };
    //! should Benders' cuts be generated from the solution to the LP relaxation?
    constexpr Param<bool> CUTLPSOL { "benders/cutlpsol" };
    //! should Benders' decomposition be copied for use in sub-SCIPs?
    constexpr Param<bool> COPYBENDERS { "benders/copybenders" };
}
//! Parameters with prefix benders/default
namespace BENDERS::DEFAULT {
    //! priority of Benders' decomposition \<default\>
    constexpr Param<int> PRIORITY { "benders/default/priority" };
    //! should Benders' cuts be generated for LP solutions?
    constexpr Param<bool> CUTLP { "benders/default/cutlp" };
    //! should Benders' cuts be generated for pseudo solutions?
    constexpr Param<bool> CUTPSEUDO { "benders/default/cutpseudo" };
    //! should Benders' cuts be generated for relaxation solutions?
    constexpr Param<bool> CUTRELAX { "benders/default/cutrelax" };
    //! should Benders' cuts from LNS heuristics be transferred to the main SCIP instance?
    constexpr Param<bool> TRANSFERCUTS { "benders/default/transfercuts" };
    //! should Benders' decomposition be used in LNS heurisics?
    constexpr Param<bool> LNSCHECK { "benders/default/lnscheck" };
    //! maximum depth at which the LNS check is performed (-1: no limit)
    constexpr Param<int> LNSMAXDEPTH { "benders/default/lnsmaxdepth" };
    //! the maximum number of Benders' decomposition calls in LNS heuristics (-1: no limit)
    constexpr Param<int> LNSMAXCALLS { "benders/default/lnsmaxcalls" };
    //! the maximum number of root node Benders' decomposition calls in LNS heuristics (-1: no limit)
    constexpr Param<int> LNSMAXCALLSROOT { "benders/default/lnsmaxcallsroot" };
    //! should the transferred cuts be added as constraints?
    constexpr Param<bool> CUTSASCONSS { "benders/default/cutsasconss" };
    //! fraction of subproblems that are solved in each iteration
    constexpr Param<double> SUBPROBFRAC { "benders/default/subprobfrac" };
    //! should the auxiliary variable bound be updated by solving the subproblem?
    constexpr Param<bool> UPDATEAUXVARBOUND { "benders/default/updateauxvarbound" };
    //! if the subproblem objective is integer, then define the auxiliary variables as implied integers?
    constexpr Param<bool> AUXVARSIMPLINT { "benders/default/auxvarsimplint" };
    //! should Benders' cuts be generated while checking solutions?
    constexpr Param<bool> CUTCHECK { "benders/default/cutcheck" };
    //! the convex combination multiplier for the cut strengthening
    constexpr Param<double> CUTSTRENGTHENMULT { "benders/default/cutstrengthenmult" };
    //! the maximum number of cut strengthening without improvement
    constexpr Param<int> NOIMPROVELIMIT { "benders/default/noimprovelimit" };
    //! the constant use to perturb the cut strengthening core point
    constexpr Param<double> COREPOINTPERTURB { "benders/default/corepointperturb" };
    //! should the core point cut strengthening be employed (only applied to fractional solutions or continuous
    //! subproblems)?
    constexpr Param<bool> CUTSTRENGTHENENABLED { "benders/default/cutstrengthenenabled" };
    //! where should the strengthening interior point be sourced from ('l'p relaxation, 'f'irst solution, 'i'ncumbent
    //! solution, 'r'elative interior point, vector of 'o'nes, vector of 'z'eros)
    constexpr Param<char> CUTSTRENGTHENINTPOINT { "benders/default/cutstrengthenintpoint" };
    //! the number of threads to use when solving the subproblems
    constexpr Param<int> NUMTHREADS { "benders/default/numthreads" };
    //! should a feasibility phase be executed during the root node, i.e. adding slack variables to constraints to
    //! ensure feasibility
    constexpr Param<bool> EXECFEASPHASE { "benders/default/execfeasphase" };
    //! the initial objective coefficient of the slack variables in the subproblem
    constexpr Param<double> SLACKVARCOEF { "benders/default/slackvarcoef" };
    //! the maximal objective coefficient of the slack variables in the subproblem
    constexpr Param<double> MAXSLACKVARCOEF { "benders/default/maxslackvarcoef" };
    //! should the constraints of the subproblems be checked for convexity?
    constexpr Param<bool> CHECKCONSCONVEXITY { "benders/default/checkconsconvexity" };
}
//! Parameters with prefix benders/default/benderscut/feas
namespace BENDERS::DEFAULT::BENDERSCUT::FEAS {
    //! priority of Benders' cut \<feas\>
    constexpr Param<int> PRIORITY { "benders/default/benderscut/feas/priority" };
    //! is this Benders' decomposition cut method used to generate cuts?
    constexpr Param<bool> ENABLED { "benders/default/benderscut/feas/enabled" };
}
//! Parameters with prefix benders/default/benderscut/feasalt
namespace BENDERS::DEFAULT::BENDERSCUT::FEASALT {
    //! priority of Benders' cut \<feasalt\>
    constexpr Param<int> PRIORITY { "benders/default/benderscut/feasalt/priority" };
    //! is this Benders' decomposition cut method used to generate cuts?
    constexpr Param<bool> ENABLED { "benders/default/benderscut/feasalt/enabled" };
}
//! Parameters with prefix benders/default/benderscut/integer
namespace BENDERS::DEFAULT::BENDERSCUT::INTEGER {
    //! priority of Benders' cut \<integer\>
    constexpr Param<int> PRIORITY { "benders/default/benderscut/integer/priority" };
    //! is this Benders' decomposition cut method used to generate cuts?
    constexpr Param<bool> ENABLED { "benders/default/benderscut/integer/enabled" };
    //! the constant term of the integer Benders' cuts.
    constexpr Param<double> CUTSCONSTANT { "benders/default/benderscut/integer/cutsconstant" };
    //! should cuts be generated and added to the cutpool instead of global constraints directly added to the problem.
    constexpr Param<bool> ADDCUTS { "benders/default/benderscut/integer/addcuts" };
}
//! Parameters with prefix benders/default/benderscut/nogood
namespace BENDERS::DEFAULT::BENDERSCUT::NOGOOD {
    //! priority of Benders' cut \<nogood\>
    constexpr Param<int> PRIORITY { "benders/default/benderscut/nogood/priority" };
    //! is this Benders' decomposition cut method used to generate cuts?
    constexpr Param<bool> ENABLED { "benders/default/benderscut/nogood/enabled" };
    //! should cuts be generated and added to the cutpool instead of global constraints directly added to the problem.
    constexpr Param<bool> ADDCUTS { "benders/default/benderscut/nogood/addcuts" };
}
//! Parameters with prefix benders/default/benderscut/optimality
namespace BENDERS::DEFAULT::BENDERSCUT::OPTIMALITY {
    //! priority of Benders' cut \<optimality\>
    constexpr Param<int> PRIORITY { "benders/default/benderscut/optimality/priority" };
    //! is this Benders' decomposition cut method used to generate cuts?
    constexpr Param<bool> ENABLED { "benders/default/benderscut/optimality/enabled" };
    //! should cuts be generated and added to the cutpool instead of global constraints directly added to the problem.
    constexpr Param<bool> ADDCUTS { "benders/default/benderscut/optimality/addcuts" };
    //! should the mixed integer rounding procedure be applied to cuts
    constexpr Param<bool> MIR { "benders/default/benderscut/optimality/mir" };
}
//! Parameters with prefix branching
namespace BRANCHING {
    //! branching score function ('s'um, 'p'roduct, 'q'uotient)
    constexpr Param<char> SCOREFUNC { "branching/scorefunc" };
    //! branching score factor to weigh downward and upward gain prediction in sum score function
    constexpr Param<double> SCOREFAC { "branching/scorefac" };
    //! should branching on binary variables be preferred?
    constexpr Param<bool> PREFERBINARY { "branching/preferbinary" };
    //! minimal relative distance of branching point to bounds when branching on a continuous variable
    constexpr Param<double> CLAMP { "branching/clamp" };
    //! fraction by which to move branching point of a continuous variable towards the middle of the domain; a value of
    //! 1.0 leads to branching always in the middle of the domain
    constexpr Param<double> MIDPULL { "branching/midpull" };
    //! multiply midpull by relative domain width if the latter is below this value
    constexpr Param<double> MIDPULLRELDOMTRIG { "branching/midpullreldomtrig" };
    //! strategy for normalization of LP gain when updating pseudocosts of continuous variables (divide by movement of
    //! 'l'p value, reduction in 'd'omain width, or reduction in domain width of 's'ibling)
    constexpr Param<char> LPGAINNORMALIZE { "branching/lpgainnormalize" };
    //! should updating pseudo costs for continuous variables be delayed to the time after separation?
    constexpr Param<bool> DELAYPSCOSTUPDATE { "branching/delaypscostupdate" };
    //! should pseudo costs be updated also in diving and probing mode?
    constexpr Param<bool> DIVINGPSCOST { "branching/divingpscost" };
    //! should all strong branching children be regarded even if one is detected to be infeasible? (only with
    //! propagation)
    constexpr Param<bool> FORCEALLCHILDREN { "branching/forceallchildren" };
    //! child node to be regarded first during strong branching (only with propagation): 'u'p child, 'd'own child,
    //! 'h'istory-based, or 'a'utomatic
    constexpr Param<char> FIRSTSBCHILD { "branching/firstsbchild" };
    //! should LP solutions during strong branching with propagation be checked for feasibility?
    constexpr Param<bool> CHECKSOL { "branching/checksol" };
    //! should LP solutions during strong branching with propagation be rounded? (only when checksbsol=TRUE)
    constexpr Param<bool> ROUNDSBSOL { "branching/roundsbsol" };
    //! score adjustment near zero by adding epsilon (TRUE) or using maximum (FALSE)
    constexpr Param<bool> SUMADJUSTSCORE { "branching/sumadjustscore" };
}
//! Parameters with prefix branching/allfullstrong
namespace BRANCHING::ALLFULLSTRONG {
    //! priority of branching rule \<allfullstrong\>
    constexpr Param<int> PRIORITY { "branching/allfullstrong/priority" };
    //! maximal depth level, up to which branching rule \<allfullstrong\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/allfullstrong/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/allfullstrong/maxbounddist" };
}
//! Parameters with prefix branching/cloud
namespace BRANCHING::CLOUD {
    //! priority of branching rule \<cloud\>
    constexpr Param<int> PRIORITY { "branching/cloud/priority" };
    //! maximal depth level, up to which branching rule \<cloud\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/cloud/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/cloud/maxbounddist" };
    //! should a cloud of points be used?
    constexpr Param<bool> USECLOUD { "branching/cloud/usecloud" };
    //! should only F2 be used?
    constexpr Param<bool> ONLYF2 { "branching/cloud/onlyF2" };
    //! should the union of candidates be used?
    constexpr Param<bool> USEUNION { "branching/cloud/useunion" };
    //! maximum number of points for the cloud (-1 means no limit)
    constexpr Param<int> MAXPOINTS { "branching/cloud/maxpoints" };
    //! minimum success rate for the cloud
    constexpr Param<double> MINSUCCESSRATE { "branching/cloud/minsuccessrate" };
    //! minimum success rate for the union
    constexpr Param<double> MINSUCCESSUNION { "branching/cloud/minsuccessunion" };
    //! maximum depth for the union
    constexpr Param<int> MAXDEPTHUNION { "branching/cloud/maxdepthunion" };
}
//! Parameters with prefix branching/distribution
namespace BRANCHING::DISTRIBUTION {
    //! priority of branching rule \<distribution\>
    constexpr Param<int> PRIORITY { "branching/distribution/priority" };
    //! maximal depth level, up to which branching rule \<distribution\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/distribution/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/distribution/maxbounddist" };
    //! the score;largest 'd'ifference, 'l'owest cumulative probability,'h'ighest c.p., 'v'otes lowest c.p., votes
    //! highest c.p.('w')
    constexpr Param<char> SCOREPARAM { "branching/distribution/scoreparam" };
    //! should only rows which are active at the current node be considered?
    constexpr Param<bool> ONLYACTIVEROWS { "branching/distribution/onlyactiverows" };
    //! should the branching score weigh up- and down-scores of a variable
    constexpr Param<bool> WEIGHTEDSCORE { "branching/distribution/weightedscore" };
}
//! Parameters with prefix branching/fullstrong
namespace BRANCHING::FULLSTRONG {
    //! priority of branching rule \<fullstrong\>
    constexpr Param<int> PRIORITY { "branching/fullstrong/priority" };
    //! maximal depth level, up to which branching rule \<fullstrong\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/fullstrong/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/fullstrong/maxbounddist" };
    //! number of intermediate LPs solved to trigger reevaluation of strong branching value for a variable that was
    //! already evaluated at the current node
    constexpr Param<long long> REEVALAGE { "branching/fullstrong/reevalage" };
    //! maximum number of propagation rounds to be performed during strong branching before solving the LP (-1: no
    //! limit, -2: parameter settings)
    constexpr Param<int> MAXPROPROUNDS { "branching/fullstrong/maxproprounds" };
    //! should valid bounds be identified in a probing-like fashion during strong branching (only with propagation)?
    constexpr Param<bool> PROBINGBOUNDS { "branching/fullstrong/probingbounds" };
    //! should strong branching be applied even if there is just a single candidate?
    constexpr Param<bool> FORCESTRONGBRANCH { "branching/fullstrong/forcestrongbranch" };
}
//! Parameters with prefix branching/inference
namespace BRANCHING::INFERENCE {
    //! priority of branching rule \<inference\>
    constexpr Param<int> PRIORITY { "branching/inference/priority" };
    //! maximal depth level, up to which branching rule \<inference\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/inference/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/inference/maxbounddist" };
    //! weight in score calculations for conflict score
    constexpr Param<double> CONFLICTWEIGHT { "branching/inference/conflictweight" };
    //! weight in score calculations for inference score
    constexpr Param<double> INFERENCEWEIGHT { "branching/inference/inferenceweight" };
    //! weight in score calculations for cutoff score
    constexpr Param<double> CUTOFFWEIGHT { "branching/inference/cutoffweight" };
    //! should branching on LP solution be restricted to the fractional variables?
    constexpr Param<bool> FRACTIONALS { "branching/inference/fractionals" };
    //! should a weighted sum of inference, conflict and cutoff weights be used?
    constexpr Param<bool> USEWEIGHTEDSUM { "branching/inference/useweightedsum" };
    //! weight in score calculations for conflict score
    constexpr Param<double> RELIABLESCORE { "branching/inference/reliablescore" };
    //! priority value for using conflict weights in lex. order
    constexpr Param<int> CONFLICTPRIO { "branching/inference/conflictprio" };
    //! priority value for using cutoff weights in lex. order
    constexpr Param<int> CUTOFFPRIO { "branching/inference/cutoffprio" };
}
//! Parameters with prefix branching/leastinf
namespace BRANCHING::LEASTINF {
    //! priority of branching rule \<leastinf\>
    constexpr Param<int> PRIORITY { "branching/leastinf/priority" };
    //! maximal depth level, up to which branching rule \<leastinf\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/leastinf/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/leastinf/maxbounddist" };
}
//! Parameters with prefix branching/lookahead
namespace BRANCHING::LOOKAHEAD {
    //! priority of branching rule \<lookahead\>
    constexpr Param<int> PRIORITY { "branching/lookahead/priority" };
    //! maximal depth level, up to which branching rule \<lookahead\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/lookahead/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/lookahead/maxbounddist" };
    //! should binary constraints be collected and applied?
    constexpr Param<bool> USEIMPLIEDBINCONS { "branching/lookahead/useimpliedbincons" };
    //! should binary constraints be added as rows to the base LP? (0: no, 1: separate, 2: as initial rows)
    constexpr Param<int> ADDBINCONSROW { "branching/lookahead/addbinconsrow" };
    //! how many constraints that are violated by the base lp solution should be gathered until the rule is stopped and
    //! they are added? [0 for unrestricted]
    constexpr Param<int> MAXNVIOLATEDCONS { "branching/lookahead/maxnviolatedcons" };
    //! how many binary constraints that are violated by the base lp solution should be gathered until the rule is
    //! stopped and they are added? [0 for unrestricted]
    constexpr Param<int> MAXNVIOLATEDBINCONS { "branching/lookahead/maxnviolatedbincons" };
    //! how many domain reductions that are violated by the base lp solution should be gathered until the rule is
    //! stopped and they are added? [0 for unrestricted]
    constexpr Param<int> MAXNVIOLATEDDOMREDS { "branching/lookahead/maxnviolateddomreds" };
    //! max number of LPs solved after which a previous prob branching results are recalculated
    constexpr Param<long long> REEVALAGE { "branching/lookahead/reevalage" };
    //! max number of LPs solved after which a previous FSB scoring results are recalculated
    constexpr Param<long long> REEVALAGEFSB { "branching/lookahead/reevalagefsb" };
    //! the max depth of LAB.
    constexpr Param<int> RECURSIONDEPTH { "branching/lookahead/recursiondepth" };
    //! should domain reductions be collected and applied?
    constexpr Param<bool> USEDOMAINREDUCTION { "branching/lookahead/usedomainreduction" };
    //! should domain reductions of feasible siblings should be merged?
    constexpr Param<bool> MERGEDOMAINREDUCTIONS { "branching/lookahead/mergedomainreductions" };
    //! should domain reductions only be applied if there are simple bound changes?
    constexpr Param<bool> PREFERSIMPLEBOUNDS { "branching/lookahead/prefersimplebounds" };
    //! should only domain reductions that violate the LP solution be applied?
    constexpr Param<bool> ONLYVIOLDOMREDS { "branching/lookahead/onlyvioldomreds" };
    //! should binary constraints, that are not violated by the base LP, be collected and added?
    constexpr Param<bool> ADDNONVIOCONS { "branching/lookahead/addnonviocons" };
    //! toggles the abbreviated LAB.
    constexpr Param<bool> ABBREVIATED { "branching/lookahead/abbreviated" };
    //! if abbreviated: The max number of candidates to consider at the node.
    constexpr Param<int> MAXNCANDS { "branching/lookahead/maxncands" };
    //! if abbreviated: The max number of candidates to consider per deeper node.
    constexpr Param<int> MAXNDEEPERCANDS { "branching/lookahead/maxndeepercands" };
    //! if abbreviated: Should the information gathered to obtain the best candidates be reused?
    constexpr Param<bool> REUSEBASIS { "branching/lookahead/reusebasis" };
    //! if only non violating constraints are added, should the branching decision be stored till the next call?
    constexpr Param<bool> STOREUNVIOLATEDSOL { "branching/lookahead/storeunviolatedsol" };
    //! if abbreviated: Use pseudo costs to estimate the score of a candidate.
    constexpr Param<bool> ABBREVPSEUDO { "branching/lookahead/abbrevpseudo" };
    //! should the average score be used for uninitialized scores in level 2?
    constexpr Param<bool> LEVEL2AVGSCORE { "branching/lookahead/level2avgscore" };
    //! should uninitialized scores in level 2 be set to 0?
    constexpr Param<bool> LEVEL2ZEROSCORE { "branching/lookahead/level2zeroscore" };
    //! add binary constraints with two variables found at the root node also as a clique
    constexpr Param<bool> ADDCLIQUE { "branching/lookahead/addclique" };
    //! should domain propagation be executed before each temporary node is solved?
    constexpr Param<bool> PROPAGATE { "branching/lookahead/propagate" };
    //! should branching data generated at depth level 2 be stored for re-using it?
    constexpr Param<bool> USELEVEL2DATA { "branching/lookahead/uselevel2data" };
    //! should bounds known for child nodes be applied?
    constexpr Param<bool> APPLYCHILDBOUNDS { "branching/lookahead/applychildbounds" };
    //! should the maximum number of domain reductions maxnviolateddomreds be enforced?
    constexpr Param<bool> ENFORCEMAXDOMREDS { "branching/lookahead/enforcemaxdomreds" };
    //! should branching results (and scores) be updated w.r.t. proven dual bounds?
    constexpr Param<bool> UPDATEBRANCHINGRESULTS { "branching/lookahead/updatebranchingresults" };
    //! maximum number of propagation rounds to perform at each temporary node (-1: unlimited, 0: SCIP default)
    constexpr Param<int> MAXPROPROUNDS { "branching/lookahead/maxproprounds" };
    //! scoring function to be used at the base level
    constexpr Param<char> SCORINGFUNCTION { "branching/lookahead/scoringfunction" };
    //! scoring function to be used at deeper levels
    constexpr Param<char> DEEPERSCORINGFUNCTION { "branching/lookahead/deeperscoringfunction" };
    //! scoring function to be used during FSB scoring
    constexpr Param<char> SCORINGSCORINGFUNCTION { "branching/lookahead/scoringscoringfunction" };
    //! if scoringfunction is 's', this value is used to weight the min of the gains of two child problems in the convex
    //! combination
    constexpr Param<double> MINWEIGHT { "branching/lookahead/minweight" };
    //! if the FSB score is of a candidate is worse than the best by this factor, skip this candidate (-1: disable)
    constexpr Param<double> WORSEFACTOR { "branching/lookahead/worsefactor" };
    //! should lookahead branching only be applied if the max gain in level 1 is not uniquely that of the best
    //! candidate?
    constexpr Param<bool> FILTERBYMAXGAIN { "branching/lookahead/filterbymaxgain" };
}
//! Parameters with prefix branching/mostinf
namespace BRANCHING::MOSTINF {
    //! priority of branching rule \<mostinf\>
    constexpr Param<int> PRIORITY { "branching/mostinf/priority" };
    //! maximal depth level, up to which branching rule \<mostinf\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/mostinf/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/mostinf/maxbounddist" };
}
//! Parameters with prefix branching/multaggr
namespace BRANCHING::MULTAGGR {
    //! priority of branching rule \<multaggr\>
    constexpr Param<int> PRIORITY { "branching/multaggr/priority" };
    //! maximal depth level, up to which branching rule \<multaggr\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/multaggr/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/multaggr/maxbounddist" };
    //! number of intermediate LPs solved to trigger reevaluation of strong branching value for a variable that was
    //! already evaluated at the current node
    constexpr Param<long long> REEVALAGE { "branching/multaggr/reevalage" };
    //! maximum number of propagation rounds to be performed during multaggr branching before solving the LP (-1: no
    //! limit, -2: parameter settings)
    constexpr Param<int> MAXPROPROUNDS { "branching/multaggr/maxproprounds" };
    //! should valid bounds be identified in a probing-like fashion during multaggr branching (only with propagation)?
    constexpr Param<bool> PROBINGBOUNDS { "branching/multaggr/probingbounds" };
}
//! Parameters with prefix branching/nodereopt
namespace BRANCHING::NODEREOPT {
    //! priority of branching rule \<nodereopt\>
    constexpr Param<int> PRIORITY { "branching/nodereopt/priority" };
    //! maximal depth level, up to which branching rule \<nodereopt\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/nodereopt/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/nodereopt/maxbounddist" };
}
//! Parameters with prefix branching/pscost
namespace BRANCHING::PSCOST {
    //! priority of branching rule \<pscost\>
    constexpr Param<int> PRIORITY { "branching/pscost/priority" };
    //! maximal depth level, up to which branching rule \<pscost\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/pscost/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/pscost/maxbounddist" };
    //! strategy for utilizing pseudo-costs of external branching candidates (multiply as in pseudo costs 'u'pdate rule,
    //! or by 'd'omain reduction, or by domain reduction of 's'ibling, or by 'v'ariable score)
    constexpr Param<char> STRATEGY { "branching/pscost/strategy" };
    //! weight for minimum of scores of a branching candidate when building weighted sum of min/max/sum of scores
    constexpr Param<double> MINSCOREWEIGHT { "branching/pscost/minscoreweight" };
    //! weight for maximum of scores of a branching candidate when building weighted sum of min/max/sum of scores
    constexpr Param<double> MAXSCOREWEIGHT { "branching/pscost/maxscoreweight" };
    //! weight for sum of scores of a branching candidate when building weighted sum of min/max/sum of scores
    constexpr Param<double> SUMSCOREWEIGHT { "branching/pscost/sumscoreweight" };
    //! number of children to create in n-ary branching
    constexpr Param<int> NCHILDREN { "branching/pscost/nchildren" };
    //! maximal depth where to do n-ary branching, -1 to turn off
    constexpr Param<int> NARYMAXDEPTH { "branching/pscost/narymaxdepth" };
    //! minimal domain width in children when doing n-ary branching, relative to global bounds
    constexpr Param<double> NARYMINWIDTH { "branching/pscost/naryminwidth" };
    //! factor of domain width in n-ary branching when creating nodes with increasing distance from branching value
    constexpr Param<double> NARYWIDTHFACTOR { "branching/pscost/narywidthfactor" };
}
//! Parameters with prefix branching/random
namespace BRANCHING::RANDOM {
    //! priority of branching rule \<random\>
    constexpr Param<int> PRIORITY { "branching/random/priority" };
    //! maximal depth level, up to which branching rule \<random\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/random/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/random/maxbounddist" };
    //! initial random seed value
    constexpr Param<int> SEED { "branching/random/seed" };
}
//! Parameters with prefix branching/relpscost
namespace BRANCHING::RELPSCOST {
    //! priority of branching rule \<relpscost\>
    constexpr Param<int> PRIORITY { "branching/relpscost/priority" };
    //! maximal depth level, up to which branching rule \<relpscost\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/relpscost/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/relpscost/maxbounddist" };
    //! weight in score calculations for conflict score
    constexpr Param<double> CONFLICTWEIGHT { "branching/relpscost/conflictweight" };
    //! weight in score calculations for conflict length score
    constexpr Param<double> CONFLICTLENGTHWEIGHT { "branching/relpscost/conflictlengthweight" };
    //! weight in score calculations for inference score
    constexpr Param<double> INFERENCEWEIGHT { "branching/relpscost/inferenceweight" };
    //! weight in score calculations for cutoff score
    constexpr Param<double> CUTOFFWEIGHT { "branching/relpscost/cutoffweight" };
    //! weight in score calculations for pseudo cost score
    constexpr Param<double> PSCOSTWEIGHT { "branching/relpscost/pscostweight" };
    //! weight in score calculations for nlcount score
    constexpr Param<double> NLSCOREWEIGHT { "branching/relpscost/nlscoreweight" };
    //! minimal value for minimum pseudo cost size to regard pseudo cost value as reliable
    constexpr Param<double> MINRELIABLE { "branching/relpscost/minreliable" };
    //! maximal value for minimum pseudo cost size to regard pseudo cost value as reliable
    constexpr Param<double> MAXRELIABLE { "branching/relpscost/maxreliable" };
    //! maximal fraction of strong branching LP iterations compared to node relaxation LP iterations
    constexpr Param<double> SBITERQUOT { "branching/relpscost/sbiterquot" };
    //! additional number of allowed strong branching LP iterations
    constexpr Param<int> SBITEROFS { "branching/relpscost/sbiterofs" };
    //! maximal number of further variables evaluated without better score
    constexpr Param<int> MAXLOOKAHEAD { "branching/relpscost/maxlookahead" };
    //! maximal number of candidates initialized with strong branching per node
    constexpr Param<int> INITCAND { "branching/relpscost/initcand" };
    //! iteration limit for strong branching initializations of pseudo cost entries (0: auto)
    constexpr Param<int> INITITER { "branching/relpscost/inititer" };
    //! maximal number of bound tightenings before the node is reevaluated (-1: unlimited)
    constexpr Param<int> MAXBDCHGS { "branching/relpscost/maxbdchgs" };
    //! maximum number of propagation rounds to be performed during strong branching before solving the LP (-1: no
    //! limit, -2: parameter settings)
    constexpr Param<int> MAXPROPROUNDS { "branching/relpscost/maxproprounds" };
    //! should valid bounds be identified in a probing-like fashion during strong branching (only with propagation)?
    constexpr Param<bool> PROBINGBOUNDS { "branching/relpscost/probingbounds" };
    //! should reliability be based on relative errors?
    constexpr Param<bool> USERELERRORRELIABILITY { "branching/relpscost/userelerrorreliability" };
    //! low relative error tolerance for reliability
    constexpr Param<double> LOWERRORTOL { "branching/relpscost/lowerrortol" };
    //! high relative error tolerance for reliability
    constexpr Param<double> HIGHERRORTOL { "branching/relpscost/higherrortol" };
    //! should strong branching result be considered for pseudo costs if the other direction was infeasible?
    constexpr Param<bool> STORESEMIINITCOSTS { "branching/relpscost/storesemiinitcosts" };
    //! should the scoring function use only local cutoff and inference information obtained for strong branching
    //! candidates?
    constexpr Param<bool> USESBLOCALINFO { "branching/relpscost/usesblocalinfo" };
    //! should the strong branching decision be based on a hypothesis test?
    constexpr Param<bool> USEHYPTESTFORRELIABILITY { "branching/relpscost/usehyptestforreliability" };
    //! should the confidence level be adjusted dynamically?
    constexpr Param<bool> USEDYNAMICCONFIDENCE { "branching/relpscost/usedynamicconfidence" };
    //! should branching rule skip candidates that have a low probability to be better than the best strong-branching or
    //! pseudo-candidate?
    constexpr Param<bool> SKIPBADINITCANDS { "branching/relpscost/skipbadinitcands" };
    //! the confidence level for statistical methods, between 0 (Min) and 4 (Max).
    constexpr Param<int> CONFIDENCELEVEL { "branching/relpscost/confidencelevel" };
    //! should candidates be initialized in randomized order?
    constexpr Param<bool> RANDINITORDER { "branching/relpscost/randinitorder" };
    //! should smaller weights be used for pseudo cost updates after hitting the LP iteration limit?
    constexpr Param<bool> USESMALLWEIGHTSITLIM { "branching/relpscost/usesmallweightsitlim" };
    //! should the weights of the branching rule be adjusted dynamically during solving based on objective and
    //! infeasible leaf counters?
    constexpr Param<bool> DYNAMICWEIGHTS { "branching/relpscost/dynamicweights" };
    //! should degeneracy be taken into account to update weights and skip strong branching? (0: off, 1: after root, 2:
    //! always)
    constexpr Param<int> DEGENERACYAWARE { "branching/relpscost/degeneracyaware" };
    //! start seed for random number generation
    constexpr Param<int> STARTRANDSEED { "branching/relpscost/startrandseed" };
    //! Use symmetry to filter branching candidates?
    constexpr Param<bool> FILTERCANDSSYM { "branching/relpscost/filtercandssym" };
    //! Transfer pscost information to symmetric variables?
    constexpr Param<bool> TRANSSYMPSCOST { "branching/relpscost/transsympscost" };
}
//! Parameters with prefix branching/treemodel
namespace BRANCHING::TREEMODEL {
    //! should candidate branching variables be scored using the Treemodel branching rules?
    constexpr Param<bool> ENABLE { "branching/treemodel/enable" };
    //! scoring function to use at nodes predicted to be high in the tree ('d'efault, 's'vts, 'r'atio, 't'ree sample)
    constexpr Param<char> HIGHRULE { "branching/treemodel/highrule" };
    //! scoring function to use at nodes predicted to be low in the tree ('d'efault, 's'vts, 'r'atio, 't'ree sample)
    constexpr Param<char> LOWRULE { "branching/treemodel/lowrule" };
    //! estimated tree height at which we switch from using the low rule to the high rule
    constexpr Param<int> HEIGHT { "branching/treemodel/height" };
    //! should dominated candidates be filtered before using the high scoring function? ('a'uto, 't'rue, 'f'alse)
    constexpr Param<char> FILTERHIGH { "branching/treemodel/filterhigh" };
    //! should dominated candidates be filtered before using the low scoring function? ('a'uto, 't'rue, 'f'alse)
    constexpr Param<char> FILTERLOW { "branching/treemodel/filterlow" };
    //! maximum number of fixed-point iterations when computing the ratio
    constexpr Param<int> MAXFPITER { "branching/treemodel/maxfpiter" };
    //! maximum height to compute the SVTS score exactly before approximating
    constexpr Param<int> MAXSVTSHEIGHT { "branching/treemodel/maxsvtsheight" };
    //! which method should be used as a fallback if the tree size estimates are infinite? ('d'efault, 'r'atio)
    constexpr Param<char> FALLBACKINF { "branching/treemodel/fallbackinf" };
    //! which method should be used as a fallback if there is no primal bound available? ('d'efault, 'r'atio)
    constexpr Param<char> FALLBACKNOPRIM { "branching/treemodel/fallbacknoprim" };
    //! threshold at which pseudocosts are considered small, making hybrid scores more likely to be the deciding factor
    //! in branching
    constexpr Param<double> SMALLPSCOST { "branching/treemodel/smallpscost" };
}
//! Parameters with prefix branching/vanillafullstrong
namespace BRANCHING::VANILLAFULLSTRONG {
    //! priority of branching rule \<vanillafullstrong\>
    constexpr Param<int> PRIORITY { "branching/vanillafullstrong/priority" };
    //! maximal depth level, up to which branching rule \<vanillafullstrong\> should be used (-1 for no limit)
    constexpr Param<int> MAXDEPTH { "branching/vanillafullstrong/maxdepth" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying branching rule (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "branching/vanillafullstrong/maxbounddist" };
    //! should integral variables in the current LP solution be considered as branching candidates?
    constexpr Param<bool> INTEGRALCANDS { "branching/vanillafullstrong/integralcands" };
    //! should strong branching side-effects be prevented (e.g., domain changes, stat updates etc.)?
    constexpr Param<bool> IDEMPOTENT { "branching/vanillafullstrong/idempotent" };
    //! should strong branching scores be computed for all candidates, or can we early stop when a variable has infinite
    //! score?
    constexpr Param<bool> SCOREALL { "branching/vanillafullstrong/scoreall" };
    //! should strong branching scores be collected?
    constexpr Param<bool> COLLECTSCORES { "branching/vanillafullstrong/collectscores" };
    //! should candidates only be scored, but no branching be performed?
    constexpr Param<bool> DONOTBRANCH { "branching/vanillafullstrong/donotbranch" };
}
//! Parameters with prefix compression
namespace COMPRESSION {
    //! should automatic tree compression after the presolving be enabled?
    constexpr Param<bool> ENABLE { "compression/enable" };
}
//! Parameters with prefix compression/largestrepr
namespace COMPRESSION::LARGESTREPR {
    //! priority of compression \<largestrepr\>
    constexpr Param<int> PRIORITY { "compression/largestrepr/priority" };
    //! minimal number of leave nodes for calling tree compression \<largestrepr\>
    constexpr Param<int> MINNLEAVES { "compression/largestrepr/minnleaves" };
    //! number of runs in the constrained part.
    constexpr Param<int> ITERATIONS { "compression/largestrepr/iterations" };
    //! minimal number of common variables.
    constexpr Param<int> MINCOMMONVARS { "compression/largestrepr/mincommonvars" };
}
//! Parameters with prefix compression/weakcompr
namespace COMPRESSION::WEAKCOMPR {
    //! priority of compression \<weakcompr\>
    constexpr Param<int> PRIORITY { "compression/weakcompr/priority" };
    //! minimal number of leave nodes for calling tree compression \<weakcompr\>
    constexpr Param<int> MINNLEAVES { "compression/weakcompr/minnleaves" };
    //! convert constraints into nodes
    constexpr Param<bool> CONVERTCONSS { "compression/weakcompr/convertconss" };
}
//! Parameters with prefix concurrent
namespace CONCURRENT {
    //! set different random seeds in each concurrent solver?
    constexpr Param<bool> CHANGESEEDS { "concurrent/changeseeds" };
    //! use different child selection rules in each concurrent solver?
    constexpr Param<bool> CHANGECHILDSEL { "concurrent/changechildsel" };
    //! should the concurrent solvers communicate global variable bound changes?
    constexpr Param<bool> COMMVARBNDS { "concurrent/commvarbnds" };
    //! should the problem be presolved before it is copied to the concurrent solvers?
    constexpr Param<bool> PRESOLVEBEFORE { "concurrent/presolvebefore" };
    //! maximum number of solutions that will be shared in a one synchronization
    constexpr Param<int> INITSEED { "concurrent/initseed" };
    //! path prefix for parameter setting files of concurrent solvers
    constexpr Param<std::string> PARAMSETPREFIX { "concurrent/paramsetprefix" };
}
//! Parameters with prefix concurrent/scip
namespace CONCURRENT::SCIP {
    //! the preferred number concurrent solvers of type \<scip\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip/prefprio" };
}
//! Parameters with prefix concurrent/scip_counter
namespace CONCURRENT::SCIP_COUNTER {
    //! the preferred number concurrent solvers of type \<scip-counter\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-counter/prefprio" };
}
//! Parameters with prefix concurrent/scip_cpsolver
namespace CONCURRENT::SCIP_CPSOLVER {
    //! the preferred number concurrent solvers of type \<scip-cpsolver\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-cpsolver/prefprio" };
}
//! Parameters with prefix concurrent/scip_default
namespace CONCURRENT::SCIP_DEFAULT {
    //! the preferred number concurrent solvers of type \<scip-default\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-default/prefprio" };
}
//! Parameters with prefix concurrent/scip_easycip
namespace CONCURRENT::SCIP_EASYCIP {
    //! the preferred number concurrent solvers of type \<scip-easycip\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-easycip/prefprio" };
}
//! Parameters with prefix concurrent/scip_feas
namespace CONCURRENT::SCIP_FEAS {
    //! the preferred number concurrent solvers of type \<scip-feas\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-feas/prefprio" };
}
//! Parameters with prefix concurrent/scip_hardlp
namespace CONCURRENT::SCIP_HARDLP {
    //! the preferred number concurrent solvers of type \<scip-hardlp\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-hardlp/prefprio" };
}
//! Parameters with prefix concurrent/scip_opti
namespace CONCURRENT::SCIP_OPTI {
    //! the preferred number concurrent solvers of type \<scip-opti\> with respect to the number of threads
    constexpr Param<double> PREFPRIO { "concurrent/scip-opti/prefprio" };
}
//! Parameters with prefix concurrent/sync
namespace CONCURRENT::SYNC {
    //! initial frequency of synchronization with other threads
    constexpr Param<double> FREQINIT { "concurrent/sync/freqinit" };
    //! maximal frequency of synchronization with other threads
    constexpr Param<double> FREQMAX { "concurrent/sync/freqmax" };
    //! factor by which the frequency of synchronization is changed
    constexpr Param<double> FREQFACTOR { "concurrent/sync/freqfactor" };
    //! when adapting the synchronization frequency this value is the targeted relative difference by which the absolute
    //! gap decreases per synchronization
    constexpr Param<double> TARGETPROGRESS { "concurrent/sync/targetprogress" };
    //! maximum number of solutions that will be shared in a single synchronization
    constexpr Param<int> MAXNSOLS { "concurrent/sync/maxnsols" };
    //! maximum number of synchronizations before reading is enforced regardless of delay
    constexpr Param<int> MAXNSYNCDELAY { "concurrent/sync/maxnsyncdelay" };
    //! minimum delay before synchronization data is read
    constexpr Param<double> MINSYNCDELAY { "concurrent/sync/minsyncdelay" };
    //! how many of the N best solutions should be considered for synchronization?
    constexpr Param<int> NBESTSOLS { "concurrent/sync/nbestsols" };
}
//! Parameters with prefix conflict
namespace CONFLICT {
    //! should conflict analysis be enabled?
    constexpr Param<bool> ENABLE { "conflict/enable" };
    //! should conflicts based on an old cutoff bound be removed from the conflict pool after improving the primal
    //! bound?
    constexpr Param<bool> CLEANBOUNDEXCEEDINGS { "conflict/cleanboundexceedings" };
    //! use local rows to construct infeasibility proofs
    constexpr Param<bool> USELOCALROWS { "conflict/uselocalrows" };
    //! should propagation conflict analysis be used?
    constexpr Param<bool> USEPROP { "conflict/useprop" };
    //! should infeasible LP conflict analysis be used? ('o'ff, 'c'onflict graph, 'd'ual ray, 'b'oth conflict graph and
    //! dual ray)
    constexpr Param<char> USEINFLP { "conflict/useinflp" };
    //! should bound exceeding LP conflict analysis be used? ('o'ff, 'c'onflict graph, 'd'ual ray, 'b'oth conflict graph
    //! and dual ray)
    constexpr Param<char> USEBOUNDLP { "conflict/useboundlp" };
    //! should infeasible/bound exceeding strong branching conflict analysis be used?
    constexpr Param<bool> USESB { "conflict/usesb" };
    //! should pseudo solution conflict analysis be used?
    constexpr Param<bool> USEPSEUDO { "conflict/usepseudo" };
    //! maximal fraction of variables involved in a conflict constraint
    constexpr Param<double> MAXVARSFAC { "conflict/maxvarsfac" };
    //! minimal absolute maximum of variables involved in a conflict constraint
    constexpr Param<int> MINMAXVARS { "conflict/minmaxvars" };
    //! maximal number of LP resolving loops during conflict analysis (-1: no limit)
    constexpr Param<int> MAXLPLOOPS { "conflict/maxlploops" };
    //! maximal number of LP iterations in each LP resolving loop (-1: no limit)
    constexpr Param<int> LPITERATIONS { "conflict/lpiterations" };
    //! number of depth levels up to which first UIP's are used in conflict analysis (-1: use All-FirstUIP rule)
    constexpr Param<int> FUIPLEVELS { "conflict/fuiplevels" };
    //! maximal number of intermediate conflict constraints generated in conflict graph (-1: use every intermediate
    //! constraint)
    constexpr Param<int> INTERCONSS { "conflict/interconss" };
    //! number of depth levels up to which UIP reconvergence constraints are generated (-1: generate reconvergence
    //! constraints in all depth levels)
    constexpr Param<int> RECONVLEVELS { "conflict/reconvlevels" };
    //! maximal number of conflict constraints accepted at an infeasible node (-1: use all generated conflict
    //! constraints)
    constexpr Param<int> MAXCONSS { "conflict/maxconss" };
    //! maximal size of conflict store (-1: auto, 0: disable storage)
    constexpr Param<int> MAXSTORESIZE { "conflict/maxstoresize" };
    //! should binary conflicts be preferred?
    constexpr Param<bool> PREFERBINARY { "conflict/preferbinary" };
    //! prefer infeasibility proof to boundexceeding proof
    constexpr Param<bool> PREFINFPROOF { "conflict/prefinfproof" };
    //! should conflict constraints be generated that are only valid locally?
    constexpr Param<bool> ALLOWLOCAL { "conflict/allowlocal" };
    //! should conflict constraints be attached only to the local subtree where they can be useful?
    constexpr Param<bool> SETTLELOCAL { "conflict/settlelocal" };
    //! should earlier nodes be repropagated in order to replace branching decisions by deductions?
    constexpr Param<bool> REPROPAGATE { "conflict/repropagate" };
    //! should constraints be kept for repropagation even if they are too long?
    constexpr Param<bool> KEEPREPROP { "conflict/keepreprop" };
    //! should the conflict constraints be separated?
    constexpr Param<bool> SEPARATE { "conflict/separate" };
    //! should the conflict constraints be subject to aging?
    constexpr Param<bool> DYNAMIC { "conflict/dynamic" };
    //! should the conflict's relaxations be subject to LP aging and cleanup?
    constexpr Param<bool> REMOVABLE { "conflict/removable" };
    //! score factor for impact on acticity in bound relaxation heuristic
    constexpr Param<double> PROOFSCOREFAC { "conflict/proofscorefac" };
    //! score factor for up locks in bound relaxation heuristic
    constexpr Param<double> UPLOCKSCOREFAC { "conflict/uplockscorefac" };
    //! score factor for down locks in bound relaxation heuristic
    constexpr Param<double> DOWNLOCKSCOREFAC { "conflict/downlockscorefac" };
    //! factor to decrease importance of variables' earlier conflict scores
    constexpr Param<double> SCOREFAC { "conflict/scorefac" };
    //! number of successful conflict analysis calls that trigger a restart (0: disable conflict restarts)
    constexpr Param<int> RESTARTNUM { "conflict/restartnum" };
    //! factor to increase restartnum with after each restart
    constexpr Param<double> RESTARTFAC { "conflict/restartfac" };
    //! should relaxed bounds be ignored?
    constexpr Param<bool> IGNORERELAXEDBD { "conflict/ignorerelaxedbd" };
    //! maximal number of variables to try to detect global bound implications and shorten the whole conflict set (0:
    //! disabled)
    constexpr Param<int> MAXVARSDETECTIMPLIEDBOUNDS { "conflict/maxvarsdetectimpliedbounds" };
    //! try to shorten the whole conflict set or terminate early (depending on the 'maxvarsdetectimpliedbounds'
    //! parameter)
    constexpr Param<bool> FULLSHORTENCONFLICT { "conflict/fullshortenconflict" };
    //! the weight the VSIDS score is weight by updating the VSIDS for a variable if it is part of a conflict
    constexpr Param<double> CONFLICTWEIGHT { "conflict/conflictweight" };
    //! the weight the VSIDS score is weight by updating the VSIDS for a variable if it is part of a conflict graph
    constexpr Param<double> CONFLICTGRAPHWEIGHT { "conflict/conflictgraphweight" };
    //! minimal improvement of primal bound to remove conflicts based on a previous incumbent
    constexpr Param<double> MINIMPROVE { "conflict/minimprove" };
    //! weight of the size of a conflict used in score calculation
    constexpr Param<double> WEIGHTSIZE { "conflict/weightsize" };
    //! weight of the repropagation depth of a conflict used in score calculation
    constexpr Param<double> WEIGHTREPROPDEPTH { "conflict/weightrepropdepth" };
    //! weight of the valid depth of a conflict used in score calculation
    constexpr Param<double> WEIGHTVALIDDEPTH { "conflict/weightvaliddepth" };
    //! apply cut generating functions to construct alternative proofs
    constexpr Param<bool> SEPAALTPROOFS { "conflict/sepaaltproofs" };
}
//! Parameters with prefix conflict/bounddisjunction
namespace CONFLICT::BOUNDDISJUNCTION {
    //! maximal percantage of continuous variables within a conflict
    constexpr Param<double> CONTINUOUSFRAC { "conflict/bounddisjunction/continuousfrac" };
    //! priority of conflict handler \<bounddisjunction\>
    constexpr Param<int> PRIORITY { "conflict/bounddisjunction/priority" };
}
//! Parameters with prefix conflict/graph
namespace CONFLICT::GRAPH {
    //! score factor for depth level in bound relaxation heuristic
    constexpr Param<double> DEPTHSCOREFAC { "conflict/graph/depthscorefac" };
}
//! Parameters with prefix conflict/indicatorconflict
namespace CONFLICT::INDICATORCONFLICT {
    //! priority of conflict handler \<indicatorconflict\>
    constexpr Param<int> PRIORITY { "conflict/indicatorconflict/priority" };
}
//! Parameters with prefix conflict/linear
namespace CONFLICT::LINEAR {
    //! priority of conflict handler \<linear\>
    constexpr Param<int> PRIORITY { "conflict/linear/priority" };
}
//! Parameters with prefix conflict/logicor
namespace CONFLICT::LOGICOR {
    //! priority of conflict handler \<logicor\>
    constexpr Param<int> PRIORITY { "conflict/logicor/priority" };
}
//! Parameters with prefix conflict/setppc
namespace CONFLICT::SETPPC {
    //! priority of conflict handler \<setppc\>
    constexpr Param<int> PRIORITY { "conflict/setppc/priority" };
}
//! Parameters with prefix constraints
namespace CONSTRAINTS {
    //! maximum age an unnecessary constraint can reach before it is deleted (0: dynamic, -1: keep all constraints)
    constexpr Param<int> AGELIMIT { "constraints/agelimit" };
    //! age of a constraint after which it is marked obsolete (0: dynamic, -1 do not mark constraints obsolete)
    constexpr Param<int> OBSOLETEAGE { "constraints/obsoleteage" };
    //! should enforcement of pseudo solution be disabled?
    constexpr Param<bool> DISABLEENFOPS { "constraints/disableenfops" };
}
//! Parameters with prefix constraints/and
namespace CONSTRAINTS::AND {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/and/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/and/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/and/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/and/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/and/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/and/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/and/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/and/presoltiming" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/and/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/and/presolusehashing" };
    //! should the AND-constraint get linearized and removed (in presolving)?
    constexpr Param<bool> LINEARIZE { "constraints/and/linearize" };
    //! should cuts be separated during LP enforcing?
    constexpr Param<bool> ENFORCECUTS { "constraints/and/enforcecuts" };
    //! should an aggregated linearization be used?
    constexpr Param<bool> AGGRLINEARIZATION { "constraints/and/aggrlinearization" };
    //! should all binary resultant variables be upgraded to implicit binary variables?
    constexpr Param<bool> UPGRADERESULTANT { "constraints/and/upgraderesultant" };
    //! should dual presolving be performed?
    constexpr Param<bool> DUALPRESOLVING { "constraints/and/dualpresolving" };
}
//! Parameters with prefix constraints/benders
namespace CONSTRAINTS::BENDERS {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/benders/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/benders/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/benders/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/benders/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/benders/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/benders/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/benders/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/benders/presoltiming" };
    //! is the Benders' decomposition constraint handler active?
    constexpr Param<bool> ACTIVE { "constraints/benders/active" };
}
//! Parameters with prefix constraints/benderslp
namespace CONSTRAINTS::BENDERSLP {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/benderslp/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/benderslp/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/benderslp/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/benderslp/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/benderslp/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/benderslp/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/benderslp/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/benderslp/presoltiming" };
    //! depth at which Benders' decomposition cuts are generated from the LP solution (-1: always, 0: only at root)
    constexpr Param<int> MAXDEPTH { "constraints/benderslp/maxdepth" };
    //! the depth frequency for generating LP cuts after the max depth is reached (0: never, 1: all nodes, ...)
    constexpr Param<int> DEPTHFREQ { "constraints/benderslp/depthfreq" };
    //! the number of nodes processed without a dual bound improvement before enforcing the LP relaxation, 0: no stall
    //! count applied
    constexpr Param<int> STALLLIMIT { "constraints/benderslp/stalllimit" };
    //! after the root node, only iterlimit fractional LP solutions are used at each node to generate Benders'
    //! decomposition cuts.
    constexpr Param<int> ITERLIMIT { "constraints/benderslp/iterlimit" };
    //! is the Benders' decomposition LP cut constraint handler active?
    constexpr Param<bool> ACTIVE { "constraints/benderslp/active" };
}
//! Parameters with prefix constraints/bounddisjunction
namespace CONSTRAINTS::BOUNDDISJUNCTION {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/bounddisjunction/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/bounddisjunction/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/bounddisjunction/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/bounddisjunction/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/bounddisjunction/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/bounddisjunction/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/bounddisjunction/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/bounddisjunction/presoltiming" };
}
//! Parameters with prefix constraints/cardinality
namespace CONSTRAINTS::CARDINALITY {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/cardinality/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/cardinality/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/cardinality/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/cardinality/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/cardinality/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/cardinality/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/cardinality/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/cardinality/presoltiming" };
    //! whether to use balanced instead of unbalanced branching
    constexpr Param<bool> BRANCHBALANCED { "constraints/cardinality/branchbalanced" };
    //! maximum depth for using balanced branching (-1: no limit)
    constexpr Param<int> BALANCEDDEPTH { "constraints/cardinality/balanceddepth" };
    //! determines that balanced branching is only used if the branching cut off value w.r.t. the current LP solution is
    //! greater than a given value
    constexpr Param<double> BALANCEDCUTOFF { "constraints/cardinality/balancedcutoff" };
}
//! Parameters with prefix constraints/components
namespace CONSTRAINTS::COMPONENTS {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/components/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/components/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/components/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/components/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/components/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/components/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/components/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/components/presoltiming" };
    //! maximum depth of a node to run components detection (-1: disable component detection during solving)
    constexpr Param<int> MAXDEPTH { "constraints/components/maxdepth" };
    //! maximum number of integer (or binary) variables to solve a subproblem during presolving (-1: unlimited)
    constexpr Param<int> MAXINTVARS { "constraints/components/maxintvars" };
    //! minimum absolute size (in terms of variables) to solve a component individually during branch-and-bound
    constexpr Param<int> MINSIZE { "constraints/components/minsize" };
    //! minimum relative size (in terms of variables) to solve a component individually during branch-and-bound
    constexpr Param<double> MINRELSIZE { "constraints/components/minrelsize" };
    //! maximum number of nodes to be solved in subproblems during presolving
    constexpr Param<long long> NODELIMIT { "constraints/components/nodelimit" };
    //! the weight of an integer variable compared to binary variables
    constexpr Param<double> INTFACTOR { "constraints/components/intfactor" };
    //! factor to increase the feasibility tolerance of the main SCIP in all sub-SCIPs, default value 1.0
    constexpr Param<double> FEASTOLFACTOR { "constraints/components/feastolfactor" };
}
//! Parameters with prefix constraints/conjunction
namespace CONSTRAINTS::CONJUNCTION {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/conjunction/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/conjunction/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/conjunction/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/conjunction/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/conjunction/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/conjunction/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/conjunction/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/conjunction/presoltiming" };
}
//! Parameters with prefix constraints/countsols
namespace CONSTRAINTS::COUNTSOLS {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/countsols/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/countsols/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/countsols/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/countsols/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/countsols/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/countsols/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/countsols/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/countsols/presoltiming" };
    //! is the constraint handler active?
    constexpr Param<bool> ACTIVE { "constraints/countsols/active" };
    //! should the sparse solution test be turned on?
    constexpr Param<bool> SPARSETEST { "constraints/countsols/sparsetest" };
    //! is it allowed to discard solutions?
    constexpr Param<bool> DISCARDSOLS { "constraints/countsols/discardsols" };
    //! should the solutions be collected?
    constexpr Param<bool> COLLECT { "constraints/countsols/collect" };
    //! counting stops, if the given number of solutions were found (-1: no limit)
    constexpr Param<long long> SOLLIMIT { "constraints/countsols/sollimit" };
}
//! Parameters with prefix constraints/cumulative
namespace CONSTRAINTS::CUMULATIVE {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/cumulative/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/cumulative/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/cumulative/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/cumulative/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/cumulative/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/cumulative/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/cumulative/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/cumulative/presoltiming" };
    //! should time-table (core-times) propagator be used to infer bounds?
    constexpr Param<bool> TTINFER { "constraints/cumulative/ttinfer" };
    //! should edge-finding be used to detect an overload?
    constexpr Param<bool> EFCHECK { "constraints/cumulative/efcheck" };
    //! should edge-finding be used to infer bounds?
    constexpr Param<bool> EFINFER { "constraints/cumulative/efinfer" };
    //! should edge-finding be executed?
    constexpr Param<bool> USEADJUSTEDJOBS { "constraints/cumulative/useadjustedjobs" };
    //! should time-table edge-finding be used to detect an overload?
    constexpr Param<bool> TTEFCHECK { "constraints/cumulative/ttefcheck" };
    //! should time-table edge-finding be used to infer bounds?
    constexpr Param<bool> TTEFINFER { "constraints/cumulative/ttefinfer" };
    //! should the binary representation be used?
    constexpr Param<bool> USEBINVARS { "constraints/cumulative/usebinvars" };
    //! should cuts be added only locally?
    constexpr Param<bool> LOCALCUTS { "constraints/cumulative/localcuts" };
    //! should covering cuts be added every node?
    constexpr Param<bool> USECOVERCUTS { "constraints/cumulative/usecovercuts" };
    //! should the cumulative constraint create cuts as knapsack constraints?
    constexpr Param<bool> CUTSASCONSS { "constraints/cumulative/cutsasconss" };
    //! shall old sepa algo be applied?
    constexpr Param<bool> SEPAOLD { "constraints/cumulative/sepaold" };
    //! should branching candidates be added to storage?
    constexpr Param<bool> FILLBRANCHCANDS { "constraints/cumulative/fillbranchcands" };
    //! should dual presolving be applied?
    constexpr Param<bool> DUALPRESOLVE { "constraints/cumulative/dualpresolve" };
    //! should coefficient tightening be applied?
    constexpr Param<bool> COEFTIGHTENING { "constraints/cumulative/coeftightening" };
    //! should demands and capacity be normalized?
    constexpr Param<bool> NORMALIZE { "constraints/cumulative/normalize" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/cumulative/presolpairwise" };
    //! extract disjunctive constraints?
    constexpr Param<bool> DISJUNCTIVE { "constraints/cumulative/disjunctive" };
    //! number of branch-and-bound nodes to solve an independent cumulative constraint (-1: no limit)?
    constexpr Param<long long> MAXNODES { "constraints/cumulative/maxnodes" };
    //! search for conflict set via maximal cliques to detect disjunctive constraints
    constexpr Param<bool> DETECTDISJUNCTIVE { "constraints/cumulative/detectdisjunctive" };
    //! search for conflict set via maximal cliques to detect variable bound constraints
    constexpr Param<bool> DETECTVARBOUNDS { "constraints/cumulative/detectvarbounds" };
    //! should bound widening be used during the conflict analysis?
    constexpr Param<bool> USEBDWIDENING { "constraints/cumulative/usebdwidening" };
}
//! Parameters with prefix constraints/disjunction
namespace CONSTRAINTS::DISJUNCTION {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/disjunction/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/disjunction/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/disjunction/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/disjunction/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/disjunction/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/disjunction/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/disjunction/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/disjunction/presoltiming" };
    //! alawys perform branching if one of the constraints is violated, otherwise only if all integers are fixed
    constexpr Param<bool> ALWAYSBRANCH { "constraints/disjunction/alwaysbranch" };
}
//! Parameters with prefix constraints/indicator
namespace CONSTRAINTS::INDICATOR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/indicator/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/indicator/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/indicator/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/indicator/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/indicator/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/indicator/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/indicator/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/indicator/presoltiming" };
    //! Branch on indicator constraints in enforcing?
    constexpr Param<bool> BRANCHINDICATORS { "constraints/indicator/branchindicators" };
    //! Generate logicor constraints instead of cuts?
    constexpr Param<bool> GENLOGICOR { "constraints/indicator/genlogicor" };
    //! Add coupling constraints or rows if big-M is small enough?
    constexpr Param<bool> ADDCOUPLING { "constraints/indicator/addcoupling" };
    //! maximum coefficient for binary variable in coupling constraint
    constexpr Param<double> MAXCOUPLINGVALUE { "constraints/indicator/maxcouplingvalue" };
    //! Add initial variable upper bound constraints, if 'addcoupling' is true?
    constexpr Param<bool> ADDCOUPLINGCONS { "constraints/indicator/addcouplingcons" };
    //! Should the coupling inequalities be separated dynamically?
    constexpr Param<bool> SEPACOUPLINGCUTS { "constraints/indicator/sepacouplingcuts" };
    //! Allow to use local bounds in order to separate coupling inequalities?
    constexpr Param<bool> SEPACOUPLINGLOCAL { "constraints/indicator/sepacouplinglocal" };
    //! maximum coefficient for binary variable in separated coupling constraint
    constexpr Param<double> SEPACOUPLINGVALUE { "constraints/indicator/sepacouplingvalue" };
    //! Separate cuts based on perspective formulation?
    constexpr Param<bool> SEPAPERSPECTIVE { "constraints/indicator/sepaperspective" };
    //! Allow to use local bounds in order to separate perspective cuts?
    constexpr Param<bool> SEPAPERSPLOCAL { "constraints/indicator/sepapersplocal" };
    //! maximal number of separated non violated IISs, before separation is stopped
    constexpr Param<int> MAXSEPANONVIOLATED { "constraints/indicator/maxsepanonviolated" };
    //! Update bounds of original variables for separation?
    constexpr Param<bool> UPDATEBOUNDS { "constraints/indicator/updatebounds" };
    //! maximum estimated condition of the solution basis matrix of the alternative LP to be trustworthy (0.0 to disable
    //! check)
    constexpr Param<double> MAXCONDITIONALTLP { "constraints/indicator/maxconditionaltlp" };
    //! maximal number of cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "constraints/indicator/maxsepacuts" };
    //! maximal number of cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "constraints/indicator/maxsepacutsroot" };
    //! Remove indicator constraint if corresponding variable bound constraint has been added?
    constexpr Param<bool> REMOVEINDICATORS { "constraints/indicator/removeindicators" };
    //! Do not generate indicator constraint, but a bilinear constraint instead?
    constexpr Param<bool> GENERATEBILINEAR { "constraints/indicator/generatebilinear" };
    //! Scale slack variable coefficient at construction time?
    constexpr Param<bool> SCALESLACKVAR { "constraints/indicator/scaleslackvar" };
    //! Try to make solutions feasible by setting indicator variables?
    constexpr Param<bool> TRYSOLUTIONS { "constraints/indicator/trysolutions" };
    //! In enforcing try to generate cuts (only if sepaalternativelp is true)?
    constexpr Param<bool> ENFORCECUTS { "constraints/indicator/enforcecuts" };
    //! Should dual reduction steps be performed?
    constexpr Param<bool> DUALREDUCTIONS { "constraints/indicator/dualreductions" };
    //! Add opposite inequality in nodes in which the binary variable has been fixed to 0?
    constexpr Param<bool> ADDOPPOSITE { "constraints/indicator/addopposite" };
    //! Try to upgrade bounddisjunction conflicts by replacing slack variables?
    constexpr Param<bool> CONFLICTSUPGRADE { "constraints/indicator/conflictsupgrade" };
    //! fraction of binary variables that need to be fixed before restart occurs (in forcerestart)
    constexpr Param<double> RESTARTFRAC { "constraints/indicator/restartfrac" };
    //! Collect other constraints to alternative LP?
    constexpr Param<bool> USEOTHERCONSS { "constraints/indicator/useotherconss" };
    //! Use objective cut with current best solution to alternative LP?
    constexpr Param<bool> USEOBJECTIVECUT { "constraints/indicator/useobjectivecut" };
    //! Try to construct a feasible solution from a cover?
    constexpr Param<bool> TRYSOLFROMCOVER { "constraints/indicator/trysolfromcover" };
    //! Try to upgrade linear constraints to indicator constraints?
    constexpr Param<bool> UPGRADELINEAR { "constraints/indicator/upgradelinear" };
    //! Separate using the alternative LP?
    constexpr Param<bool> SEPAALTERNATIVELP { "constraints/indicator/sepaalternativelp" };
    //! Force restart if absolute gap is 1 or enough binary variables have been fixed?
    constexpr Param<bool> FORCERESTART { "constraints/indicator/forcerestart" };
    //! Decompose problem (do not generate linear constraint if all variables are continuous)?
    constexpr Param<bool> NOLINCONSCONT { "constraints/indicator/nolinconscont" };
}
//! Parameters with prefix constraints/integral
namespace CONSTRAINTS::INTEGRAL {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/integral/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/integral/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/integral/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/integral/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/integral/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/integral/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/integral/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/integral/presoltiming" };
}
//! Parameters with prefix constraints/knapsack
namespace CONSTRAINTS::KNAPSACK {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/knapsack/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/knapsack/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/knapsack/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/knapsack/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/knapsack/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/knapsack/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/knapsack/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/knapsack/presoltiming" };
    //! multiplier on separation frequency, how often knapsack cuts are separated (-1: never, 0: only at root)
    constexpr Param<int> SEPACARDFREQ { "constraints/knapsack/sepacardfreq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! separating knapsack cuts
    constexpr Param<double> MAXCARDBOUNDDIST { "constraints/knapsack/maxcardbounddist" };
    //! lower clique size limit for greedy clique extraction algorithm (relative to largest clique)
    constexpr Param<double> CLIQUEEXTRACTFACTOR { "constraints/knapsack/cliqueextractfactor" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "constraints/knapsack/maxrounds" };
    //! maximal number of separation rounds per node in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "constraints/knapsack/maxroundsroot" };
    //! maximal number of cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "constraints/knapsack/maxsepacuts" };
    //! maximal number of cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "constraints/knapsack/maxsepacutsroot" };
    //! should disaggregation of knapsack constraints be allowed in preprocessing?
    constexpr Param<bool> DISAGGREGATION { "constraints/knapsack/disaggregation" };
    //! should presolving try to simplify knapsacks
    constexpr Param<bool> SIMPLIFYINEQUALITIES { "constraints/knapsack/simplifyinequalities" };
    //! should negated clique information be used in solving process
    constexpr Param<bool> NEGATEDCLIQUE { "constraints/knapsack/negatedclique" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/knapsack/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/knapsack/presolusehashing" };
    //! should dual presolving steps be performed?
    constexpr Param<bool> DUALPRESOLVING { "constraints/knapsack/dualpresolving" };
    //! should GUB information be used for separation?
    constexpr Param<bool> USEGUBS { "constraints/knapsack/usegubs" };
    //! should presolving try to detect constraints parallel to the objective function defining an upper bound and
    //! prevent these constraints from entering the LP?
    constexpr Param<bool> DETECTCUTOFFBOUND { "constraints/knapsack/detectcutoffbound" };
    //! should presolving try to detect constraints parallel to the objective function defining a lower bound and
    //! prevent these constraints from entering the LP?
    constexpr Param<bool> DETECTLOWERBOUND { "constraints/knapsack/detectlowerbound" };
    //! should clique partition information be updated when old partition seems outdated?
    constexpr Param<bool> UPDATECLIQUEPARTITIONS { "constraints/knapsack/updatecliquepartitions" };
    //! factor on the growth of global cliques to decide when to update a previous (negated) clique partition (used only
    //! if updatecliquepartitions is set to TRUE)
    constexpr Param<double> CLQPARTUPDATEFAC { "constraints/knapsack/clqpartupdatefac" };
}
//! Parameters with prefix constraints/linear
namespace CONSTRAINTS::LINEAR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/linear/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/linear/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/linear/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/linear/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/linear/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/linear/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/linear/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/linear/presoltiming" };
    //! multiplier on propagation frequency, how often the bounds are tightened (-1: never, 0: only at root)
    constexpr Param<int> TIGHTENBOUNDSFREQ { "constraints/linear/tightenboundsfreq" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "constraints/linear/maxrounds" };
    //! maximal number of separation rounds per node in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "constraints/linear/maxroundsroot" };
    //! maximal number of cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "constraints/linear/maxsepacuts" };
    //! maximal number of cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "constraints/linear/maxsepacutsroot" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/linear/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/linear/presolusehashing" };
    //! number for minimal pairwise presolve comparisons
    constexpr Param<int> NMINCOMPARISONS { "constraints/linear/nmincomparisons" };
    //! minimal gain per minimal pairwise presolve comparisons to repeat pairwise comparison round
    constexpr Param<double> MINGAINPERNMINCOMPARISONS { "constraints/linear/mingainpernmincomparisons" };
    //! maximal allowed relative gain in maximum norm for constraint aggregation (0.0: disable constraint aggregation)
    constexpr Param<double> MAXAGGRNORMSCALE { "constraints/linear/maxaggrnormscale" };
    //! maximum activity delta to run easy propagation on linear constraint (faster, but numerically less stable)
    constexpr Param<double> MAXEASYACTIVITYDELTA { "constraints/linear/maxeasyactivitydelta" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! separating knapsack cardinality cuts
    constexpr Param<double> MAXCARDBOUNDDIST { "constraints/linear/maxcardbounddist" };
    //! should all constraints be subject to cardinality cut generation instead of only the ones with non-zero dual
    //! value?
    constexpr Param<bool> SEPARATEALL { "constraints/linear/separateall" };
    //! should presolving search for aggregations in equations
    constexpr Param<bool> AGGREGATEVARIABLES { "constraints/linear/aggregatevariables" };
    //! should presolving try to simplify inequalities
    constexpr Param<bool> SIMPLIFYINEQUALITIES { "constraints/linear/simplifyinequalities" };
    //! should dual presolving steps be performed?
    constexpr Param<bool> DUALPRESOLVING { "constraints/linear/dualpresolving" };
    //! should stuffing of singleton continuous variables be performed?
    constexpr Param<bool> SINGLETONSTUFFING { "constraints/linear/singletonstuffing" };
    //! should single variable stuffing be performed, which tries to fulfill constraints using the cheapest variable?
    constexpr Param<bool> SINGLEVARSTUFFING { "constraints/linear/singlevarstuffing" };
    //! apply binaries sorting in decr. order of coeff abs value?
    constexpr Param<bool> SORTVARS { "constraints/linear/sortvars" };
    //! should the violation for a constraint with side 0.0 be checked relative to 1.0 (FALSE) or to the maximum
    //! absolute value in the activity (TRUE)?
    constexpr Param<bool> CHECKRELMAXABS { "constraints/linear/checkrelmaxabs" };
    //! should presolving try to detect constraints parallel to the objective function defining an upper bound and
    //! prevent these constraints from entering the LP?
    constexpr Param<bool> DETECTCUTOFFBOUND { "constraints/linear/detectcutoffbound" };
    //! should presolving try to detect constraints parallel to the objective function defining a lower bound and
    //! prevent these constraints from entering the LP?
    constexpr Param<bool> DETECTLOWERBOUND { "constraints/linear/detectlowerbound" };
    //! should presolving try to detect subsets of constraints parallel to the objective function?
    constexpr Param<bool> DETECTPARTIALOBJECTIVE { "constraints/linear/detectpartialobjective" };
    //! should presolving and propagation try to improve bounds, detect infeasibility, and extract sub-constraints from
    //! ranged rows and equations?
    constexpr Param<bool> RANGEDROWPROPAGATION { "constraints/linear/rangedrowpropagation" };
    //! should presolving and propagation extract sub-constraints from ranged rows and equations?
    constexpr Param<bool> RANGEDROWARTCONS { "constraints/linear/rangedrowartcons" };
    //! maximum depth to apply ranged row propagation
    constexpr Param<int> RANGEDROWMAXDEPTH { "constraints/linear/rangedrowmaxdepth" };
    //! frequency for applying ranged row propagation
    constexpr Param<int> RANGEDROWFREQ { "constraints/linear/rangedrowfreq" };
    //! should multi-aggregations only be performed if the constraint can be removed afterwards?
    constexpr Param<bool> MULTAGGRREMOVE { "constraints/linear/multaggrremove" };
    //! maximum coefficient dynamism (ie. maxabsval / minabsval) for primal multiaggregation
    constexpr Param<double> MAXMULTAGGRQUOT { "constraints/linear/maxmultaggrquot" };
    //! maximum coefficient dynamism (ie. maxabsval / minabsval) for dual multiaggregation
    constexpr Param<double> MAXDUALMULTAGGRQUOT { "constraints/linear/maxdualmultaggrquot" };
    //! should Cliques be extracted?
    constexpr Param<bool> EXTRACTCLIQUES { "constraints/linear/extractcliques" };
}
//! Parameters with prefix constraints/linear/upgrade
namespace CONSTRAINTS::LINEAR::UPGRADE {
    //! enable linear upgrading for constraint handler \<indicator\>
    constexpr Param<bool> INDICATOR { "constraints/linear/upgrade/indicator" };
    //! enable linear upgrading for constraint handler \<knapsack\>
    constexpr Param<bool> KNAPSACK { "constraints/linear/upgrade/knapsack" };
    //! enable linear upgrading for constraint handler \<logicor\>
    constexpr Param<bool> LOGICOR { "constraints/linear/upgrade/logicor" };
    //! enable linear upgrading for constraint handler \<setppc\>
    constexpr Param<bool> SETPPC { "constraints/linear/upgrade/setppc" };
    //! enable linear upgrading for constraint handler \<varbound\>
    constexpr Param<bool> VARBOUND { "constraints/linear/upgrade/varbound" };
    //! enable linear upgrading for constraint handler \<xor\>
    constexpr Param<bool> XOR { "constraints/linear/upgrade/xor" };
}
//! Parameters with prefix constraints/linking
namespace CONSTRAINTS::LINKING {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/linking/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/linking/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/linking/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/linking/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/linking/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/linking/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/linking/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/linking/presoltiming" };
    //! this constraint will not propagate or separate, linear and setppc are used?
    constexpr Param<bool> LINEARIZE { "constraints/linking/linearize" };
}
//! Parameters with prefix constraints/logicor
namespace CONSTRAINTS::LOGICOR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/logicor/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/logicor/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/logicor/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/logicor/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/logicor/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/logicor/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/logicor/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/logicor/presoltiming" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/logicor/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/logicor/presolusehashing" };
    //! should dual presolving steps be performed?
    constexpr Param<bool> DUALPRESOLVING { "constraints/logicor/dualpresolving" };
    //! should negated clique information be used in presolving
    constexpr Param<bool> NEGATEDCLIQUE { "constraints/logicor/negatedclique" };
    //! should implications/cliques be used in presolving
    constexpr Param<bool> IMPLICATIONS { "constraints/logicor/implications" };
    //! should pairwise constraint comparison try to strengthen constraints by removing superflous non-zeros?
    constexpr Param<bool> STRENGTHEN { "constraints/logicor/strengthen" };
}
//! Parameters with prefix constraints/nonlinear
namespace CONSTRAINTS::NONLINEAR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/nonlinear/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/nonlinear/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/nonlinear/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/nonlinear/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/nonlinear/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/nonlinear/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/nonlinear/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/nonlinear/presoltiming" };
    //! limit on number of propagation rounds for a set of constraints within one round of SCIP propagation
    constexpr Param<int> MAXPROPROUNDS { "constraints/nonlinear/maxproprounds" };
    //! whether to check bounds of all auxiliary variable to seed reverse propagation
    constexpr Param<bool> PROPAUXVARS { "constraints/nonlinear/propauxvars" };
    //! strategy on how to relax variable bounds during bound tightening: relax (n)ot, relax by (a)bsolute value, relax
    //! always by a(b)solute value, relax by (r)relative value
    constexpr Param<char> VARBOUNDRELAX { "constraints/nonlinear/varboundrelax" };
    //! by how much to relax variable bounds during bound tightening if strategy 'a', 'b', or 'r'
    constexpr Param<double> VARBOUNDRELAXAMOUNT { "constraints/nonlinear/varboundrelaxamount" };
    //! by how much to relax constraint sides during bound tightening
    constexpr Param<double> CONSSIDERELAXAMOUNT { "constraints/nonlinear/conssiderelaxamount" };
    //! maximal relative perturbation of reference point when computing facet of envelope of vertex-polyhedral function
    //! (dim\>2)
    constexpr Param<double> VPMAXPERTURB { "constraints/nonlinear/vpmaxperturb" };
    //! adjust computed facet of envelope of vertex-polyhedral function up to a violation of this value times LP
    //! feasibility tolerance
    constexpr Param<double> VPADJFACETTHRESH { "constraints/nonlinear/vpadjfacetthresh" };
    //! whether to use dual simplex instead of primal simplex for LP that computes facet of vertex-polyhedral function
    constexpr Param<bool> VPDUALSIMPLEX { "constraints/nonlinear/vpdualsimplex" };
    //! maximal number of auxiliary expressions per bilinear term
    constexpr Param<int> BILINMAXNAUXEXPRS { "constraints/nonlinear/bilinmaxnauxexprs" };
    //! whether to reformulate products of binary variables during presolving
    constexpr Param<bool> REFORMBINPRODS { "constraints/nonlinear/reformbinprods" };
    //! whether to use the AND constraint handler for reformulating binary products
    constexpr Param<bool> REFORMBINPRODSAND { "constraints/nonlinear/reformbinprodsand" };
    //! minimum number of terms to reformulate bilinear binary products by factorizing variables (\<= 1: disabled)
    constexpr Param<int> REFORMBINPRODSFAC { "constraints/nonlinear/reformbinprodsfac" };
    //! whether to forbid multiaggregation of nonlinear variables
    constexpr Param<bool> FORBIDMULTAGGRNLVAR { "constraints/nonlinear/forbidmultaggrnlvar" };
    //! whether to tighten LP feasibility tolerance during enforcement, if it seems useful
    constexpr Param<bool> TIGHTENLPFEASTOL { "constraints/nonlinear/tightenlpfeastol" };
    //! whether to (re)run propagation in enforcement
    constexpr Param<bool> PROPINENFORCE { "constraints/nonlinear/propinenforce" };
    //! threshold for when to regard a cut from an estimator as weak (lower values allow more weak cuts)
    constexpr Param<double> WEAKCUTTHRESHOLD { "constraints/nonlinear/weakcutthreshold" };
    //! "strong" cuts will be scaled to have their maximal coef in [1/strongcutmaxcoef,strongcutmaxcoef]
    constexpr Param<double> STRONGCUTMAXCOEF { "constraints/nonlinear/strongcutmaxcoef" };
    //! consider efficacy requirement when deciding whether a cut is "strong"
    constexpr Param<bool> STRONGCUTEFFICACY { "constraints/nonlinear/strongcutefficacy" };
    //! whether to force "strong" cuts in enforcement
    constexpr Param<bool> FORCESTRONGCUT { "constraints/nonlinear/forcestrongcut" };
    //! an expression will be enforced if the "auxiliary" violation is at least this factor times the "original"
    //! violation
    constexpr Param<double> ENFOAUXVIOLFACTOR { "constraints/nonlinear/enfoauxviolfactor" };
    //! retry enfo of constraint with weak cuts if violation is least this factor of maximal violated constraints
    constexpr Param<double> WEAKCUTMINVIOLFACTOR { "constraints/nonlinear/weakcutminviolfactor" };
    //! whether to make rows to be non-removable in the node where they are added (can prevent some cycling): 'o'ff, in
    //! 'e'nforcement only, 'a'lways
    constexpr Param<char> ROWNOTREMOVABLE { "constraints/nonlinear/rownotremovable" };
    //! method how to scale violations to make them comparable (not used for feasibility check): (n)one, (a)ctivity and
    //! side, norm of (g)radient
    constexpr Param<char> VIOLSCALE { "constraints/nonlinear/violscale" };
    //! whether variables contained in a single constraint should be forced to be at their lower or upper bounds
    //! ('d'isable, change 't'ype, add 'b'ound disjunction)
    constexpr Param<char> CHECKVARLOCKS { "constraints/nonlinear/checkvarlocks" };
    //! whether tight linearizations of nonlinear constraints should be added to cutpool when some heuristics finds a
    //! new solution ('o'ff, on new 'i'ncumbents, on 'e'very solution)
    constexpr Param<char> LINEARIZEHEURSOL { "constraints/nonlinear/linearizeheursol" };
    //! whether to assume that any constraint is convex
    constexpr Param<bool> ASSUMECONVEX { "constraints/nonlinear/assumeconvex" };
}
//! Parameters with prefix constraints/nonlinear/branching
namespace CONSTRAINTS::NONLINEAR::BRANCHING {
    //! from which depth on in the tree to allow branching on auxiliary variables (variables added for extended
    //! formulation)
    constexpr Param<int> AUX { "constraints/nonlinear/branching/aux" };
    //! whether to use external branching candidates and branching rules for branching
    constexpr Param<bool> EXTERNAL { "constraints/nonlinear/branching/external" };
    //! consider a constraint highly violated if its violation is \>= this factor * maximal violation among all
    //! constraints
    constexpr Param<double> HIGHVIOLFACTOR { "constraints/nonlinear/branching/highviolfactor" };
    //! consider a variable branching score high if its branching score \>= this factor * maximal branching score among
    //! all variables
    constexpr Param<double> HIGHSCOREFACTOR { "constraints/nonlinear/branching/highscorefactor" };
    //! weight by how much to consider the violation assigned to a variable for its branching score
    constexpr Param<double> VIOLWEIGHT { "constraints/nonlinear/branching/violweight" };
    //! weight by how much to consider the dual values of rows that contain a variable for its branching score
    constexpr Param<double> DUALWEIGHT { "constraints/nonlinear/branching/dualweight" };
    //! weight by how much to consider the pseudo cost of a variable for its branching score
    constexpr Param<double> PSCOSTWEIGHT { "constraints/nonlinear/branching/pscostweight" };
    //! weight by how much to consider the domain width in branching score
    constexpr Param<double> DOMAINWEIGHT { "constraints/nonlinear/branching/domainweight" };
    //! weight by how much to consider variable type (continuous: 0, binary: 1, integer: 0.1, impl-integer: 0.01) in
    //! branching score
    constexpr Param<double> VARTYPEWEIGHT { "constraints/nonlinear/branching/vartypeweight" };
    //! how to aggregate several branching scores given for the same expression: 'a'verage, 'm'aximum, 's'um
    constexpr Param<char> SCOREAGG { "constraints/nonlinear/branching/scoreagg" };
    //! method used to split violation in expression onto variables: 'u'niform, 'm'idness of solution, 'd'omain width,
    //! 'l'ogarithmic domain width
    constexpr Param<char> VIOLSPLIT { "constraints/nonlinear/branching/violsplit" };
    //! minimum pseudo-cost update count required to consider pseudo-costs reliable
    constexpr Param<double> PSCOSTRELIABLE { "constraints/nonlinear/branching/pscostreliable" };
}
//! Parameters with prefix constraints/nonlinear/upgrade
namespace CONSTRAINTS::NONLINEAR::UPGRADE {
    //! enable nonlinear upgrading for constraint handler \<linear\>
    constexpr Param<bool> LINEAR { "constraints/nonlinear/upgrade/linear" };
    //! enable nonlinear upgrading for constraint handler \<setppc\>
    constexpr Param<bool> SETPPC { "constraints/nonlinear/upgrade/setppc" };
}
//! Parameters with prefix constraints/or
namespace CONSTRAINTS::OR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/or/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/or/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/or/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/or/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/or/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/or/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/or/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/or/presoltiming" };
}
//! Parameters with prefix constraints/orbisack
namespace CONSTRAINTS::ORBISACK {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/orbisack/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/orbisack/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/orbisack/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/orbisack/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/orbisack/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/orbisack/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/orbisack/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/orbisack/presoltiming" };
    //! Separate cover inequalities for orbisacks?
    constexpr Param<bool> COVERSEPARATION { "constraints/orbisack/coverseparation" };
    //! Separate orbisack inequalities?
    constexpr Param<bool> ORBISEPARATION { "constraints/orbisack/orbiSeparation" };
    //! Maximum size of coefficients for orbisack inequalities
    constexpr Param<double> COEFFBOUND { "constraints/orbisack/coeffbound" };
    //! Upgrade orbisack constraints to packing/partioning orbisacks?
    constexpr Param<bool> CHECKPPORBISACK { "constraints/orbisack/checkpporbisack" };
    //! Whether orbisack constraints should be forced to be copied to sub SCIPs.
    constexpr Param<bool> FORCECONSCOPY { "constraints/orbisack/forceconscopy" };
}
//! Parameters with prefix constraints/orbitope
namespace CONSTRAINTS::ORBITOPE {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/orbitope/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/orbitope/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/orbitope/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/orbitope/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/orbitope/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/orbitope/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/orbitope/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/orbitope/presoltiming" };
    //! Strengthen orbitope constraints to packing/partioning orbitopes?
    constexpr Param<bool> CHECKPPORBITOPE { "constraints/orbitope/checkpporbitope" };
    //! Whether we separate inequalities for full orbitopes?
    constexpr Param<bool> SEPAFULLORBITOPE { "constraints/orbitope/sepafullorbitope" };
    //! Whether orbitope constraints should be forced to be copied to sub SCIPs.
    constexpr Param<bool> FORCECONSCOPY { "constraints/orbitope/forceconscopy" };
}
//! Parameters with prefix constraints/pseudoboolean
namespace CONSTRAINTS::PSEUDOBOOLEAN {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/pseudoboolean/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/pseudoboolean/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/pseudoboolean/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/pseudoboolean/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/pseudoboolean/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/pseudoboolean/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/pseudoboolean/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/pseudoboolean/presoltiming" };
    //! decompose all normal pseudo boolean constraint into a "linear" constraint and "and" constraints
    constexpr Param<bool> DECOMPOSENORMAL { "constraints/pseudoboolean/decomposenormal" };
    //! decompose all indicator pseudo boolean constraint into a "linear" constraint and "and" constraints
    constexpr Param<bool> DECOMPOSEINDICATOR { "constraints/pseudoboolean/decomposeindicator" };
    //! should the nonlinear constraints be separated during LP processing?
    constexpr Param<bool> NLCSEPARATE { "constraints/pseudoboolean/nlcseparate" };
    //! should the nonlinear constraints be propagated during node processing?
    constexpr Param<bool> NLCPROPAGATE { "constraints/pseudoboolean/nlcpropagate" };
    //! should the nonlinear constraints be removable?
    constexpr Param<bool> NLCREMOVABLE { "constraints/pseudoboolean/nlcremovable" };
}
//! Parameters with prefix constraints/setppc
namespace CONSTRAINTS::SETPPC {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/setppc/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/setppc/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/setppc/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/setppc/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/setppc/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/setppc/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/setppc/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/setppc/presoltiming" };
    //! number of children created in pseudo branching (0: disable pseudo branching)
    constexpr Param<int> NPSEUDOBRANCHES { "constraints/setppc/npseudobranches" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/setppc/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/setppc/presolusehashing" };
    //! should dual presolving steps be performed?
    constexpr Param<bool> DUALPRESOLVING { "constraints/setppc/dualpresolving" };
    //! should we try to lift variables into other clique constraints, fix variables, aggregate them, and also shrink
    //! the amount of variables in clique constraints
    constexpr Param<bool> CLIQUELIFTING { "constraints/setppc/cliquelifting" };
    //! should we try to generate extra cliques out of all binary variables to maybe fasten redundant constraint
    //! detection
    constexpr Param<bool> ADDVARIABLESASCLIQUES { "constraints/setppc/addvariablesascliques" };
    //! should we try to shrink the number of variables in a clique constraints, by replacing more than one variable by
    //! only one
    constexpr Param<bool> CLIQUESHRINKING { "constraints/setppc/cliqueshrinking" };
}
//! Parameters with prefix constraints/sos1
namespace CONSTRAINTS::SOS1 {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/SOS1/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/SOS1/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/SOS1/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/SOS1/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/SOS1/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/SOS1/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/SOS1/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/SOS1/presoltiming" };
    //! do not create an adjacency matrix if number of SOS1 variables is larger than predefined value (-1: no limit)
    constexpr Param<int> MAXSOSADJACENCY { "constraints/SOS1/maxsosadjacency" };
    //! maximal number of extensions that will be computed for each SOS1 constraint (-1: no limit)
    constexpr Param<int> MAXEXTENSIONS { "constraints/SOS1/maxextensions" };
    //! maximal number of bound tightening rounds per presolving round (-1: no limit)
    constexpr Param<int> MAXTIGHTENBDS { "constraints/SOS1/maxtightenbds" };
    //! if TRUE then perform implication graph analysis (might add additional SOS1 constraints)
    constexpr Param<bool> PERFIMPLANALYSIS { "constraints/SOS1/perfimplanalysis" };
    //! number of recursive calls of implication graph analysis (-1: no limit)
    constexpr Param<int> DEPTHIMPLANALYSIS { "constraints/SOS1/depthimplanalysis" };
    //! whether to use conflict graph propagation
    constexpr Param<bool> CONFLICTPROP { "constraints/SOS1/conflictprop" };
    //! whether to use implication graph propagation
    constexpr Param<bool> IMPLPROP { "constraints/SOS1/implprop" };
    //! whether to use SOS1 constraint propagation
    constexpr Param<bool> SOSCONSPROP { "constraints/SOS1/sosconsprop" };
    //! which branching rule should be applied ? ('n': neighborhood, 'b': bipartite, 's': SOS1/clique) (note: in some
    //! cases an automatic switching to SOS1 branching is possible)
    constexpr Param<char> BRANCHINGRULE { "constraints/SOS1/branchingrule" };
    //! if TRUE then automatically switch to SOS1 branching if the SOS1 constraints do not overlap
    constexpr Param<bool> AUTOSOS1BRANCH { "constraints/SOS1/autosos1branch" };
    //! if neighborhood branching is used, then fix the branching variable (if positive in sign) to the value of the
    //! feasibility tolerance
    constexpr Param<bool> FIXNONZERO { "constraints/SOS1/fixnonzero" };
    //! if TRUE then add complementarity constraints to the branching nodes (can be used in combination with
    //! neighborhood or bipartite branching)
    constexpr Param<bool> ADDCOMPS { "constraints/SOS1/addcomps" };
    //! maximal number of complementarity constraints added per branching node (-1: no limit)
    constexpr Param<int> MAXADDCOMPS { "constraints/SOS1/maxaddcomps" };
    //! minimal feasibility value for complementarity constraints in order to be added to the branching node
    constexpr Param<double> ADDCOMPSFEAS { "constraints/SOS1/addcompsfeas" };
    //! minimal feasibility value for bound inequalities in order to be added to the branching node
    constexpr Param<double> ADDBDSFEAS { "constraints/SOS1/addbdsfeas" };
    //! should added complementarity constraints be extended to SOS1 constraints to get tighter bound inequalities
    constexpr Param<bool> ADDEXTENDEDBDS { "constraints/SOS1/addextendedbds" };
    //! Use SOS1 branching in enforcing (otherwise leave decision to branching rules)? This value can only be set to
    //! false if all SOS1 variables are binary
    constexpr Param<bool> BRANCHSOS { "constraints/SOS1/branchsos" };
    //! Branch on SOS constraint with most number of nonzeros?
    constexpr Param<bool> BRANCHNONZEROS { "constraints/SOS1/branchnonzeros" };
    //! Branch on SOS cons. with highest nonzero-variable weight for branching (needs branchnonzeros = false)?
    constexpr Param<bool> BRANCHWEIGHT { "constraints/SOS1/branchweight" };
    //! only add complementarity constraints to branching nodes for predefined depth (-1: no limit)
    constexpr Param<int> ADDCOMPSDEPTH { "constraints/SOS1/addcompsdepth" };
    //! maximal number of strong branching rounds to perform for each node (-1: auto); only available for neighborhood
    //! and bipartite branching
    constexpr Param<int> NSTRONGROUNDS { "constraints/SOS1/nstrongrounds" };
    //! maximal number LP iterations to perform for each strong branching round (-2: auto, -1: no limit)
    constexpr Param<int> NSTRONGITER { "constraints/SOS1/nstrongiter" };
    //! if TRUE separate bound inequalities from initial SOS1 constraints
    constexpr Param<bool> BOUNDCUTSFROMSOS1 { "constraints/SOS1/boundcutsfromsos1" };
    //! if TRUE separate bound inequalities from the conflict graph
    constexpr Param<bool> BOUNDCUTSFROMGRAPH { "constraints/SOS1/boundcutsfromgraph" };
    //! if TRUE then automatically switch to separating initial SOS1 constraints if the SOS1 constraints do not overlap
    constexpr Param<bool> AUTOCUTSFROMSOS1 { "constraints/SOS1/autocutsfromsos1" };
    //! frequency for separating bound cuts; zero means to separate only in the root node
    constexpr Param<int> BOUNDCUTSFREQ { "constraints/SOS1/boundcutsfreq" };
    //! node depth of separating bound cuts (-1: no limit)
    constexpr Param<int> BOUNDCUTSDEPTH { "constraints/SOS1/boundcutsdepth" };
    //! maximal number of bound cuts separated per branching node
    constexpr Param<int> MAXBOUNDCUTS { "constraints/SOS1/maxboundcuts" };
    //! maximal number of bound cuts separated per iteration in the root node
    constexpr Param<int> MAXBOUNDCUTSROOT { "constraints/SOS1/maxboundcutsroot" };
    //! if TRUE then bound cuts are strengthened in case bound variables are available
    constexpr Param<bool> STRTHENBOUNDCUTS { "constraints/SOS1/strthenboundcuts" };
    //! frequency for separating implied bound cuts; zero means to separate only in the root node
    constexpr Param<int> IMPLCUTSFREQ { "constraints/SOS1/implcutsfreq" };
    //! node depth of separating implied bound cuts (-1: no limit)
    constexpr Param<int> IMPLCUTSDEPTH { "constraints/SOS1/implcutsdepth" };
    //! maximal number of implied bound cuts separated per branching node
    constexpr Param<int> MAXIMPLCUTS { "constraints/SOS1/maximplcuts" };
    //! maximal number of implied bound cuts separated per iteration in the root node
    constexpr Param<int> MAXIMPLCUTSROOT { "constraints/SOS1/maximplcutsroot" };
}
//! Parameters with prefix constraints/sos2
namespace CONSTRAINTS::SOS2 {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/SOS2/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/SOS2/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/SOS2/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/SOS2/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/SOS2/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/SOS2/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/SOS2/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/SOS2/presoltiming" };
}
//! Parameters with prefix constraints/superindicator
namespace CONSTRAINTS::SUPERINDICATOR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/superindicator/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/superindicator/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/superindicator/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/superindicator/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/superindicator/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/superindicator/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/superindicator/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/superindicator/presoltiming" };
    //! should type of slack constraint be checked when creating superindicator constraint?
    constexpr Param<bool> CHECKSLACKTYPE { "constraints/superindicator/checkslacktype" };
    //! maximum big-M coefficient of binary variable in upgrade to a linear constraint (relative to smallest
    //! coefficient)
    constexpr Param<double> MAXUPGDCOEFLINEAR { "constraints/superindicator/maxupgdcoeflinear" };
    //! priority for upgrading to an indicator constraint (-1: never)
    constexpr Param<int> UPGDPRIOINDICATOR { "constraints/superindicator/upgdprioindicator" };
    //! priority for upgrading to an indicator constraint (-1: never)
    constexpr Param<int> UPGDPRIOLINEAR { "constraints/superindicator/upgdpriolinear" };
}
//! Parameters with prefix constraints/symresack
namespace CONSTRAINTS::SYMRESACK {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/symresack/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/symresack/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/symresack/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/symresack/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/symresack/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/symresack/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/symresack/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/symresack/presoltiming" };
    //! Upgrade symresack constraints to packing/partioning symresacks?
    constexpr Param<bool> PPSYMRESACK { "constraints/symresack/ppsymresack" };
    //! Check whether permutation is monotone when upgrading to packing/partioning symresacks?
    constexpr Param<bool> CHECKMONOTONICITY { "constraints/symresack/checkmonotonicity" };
    //! Whether symresack constraints should be forced to be copied to sub SCIPs.
    constexpr Param<bool> FORCECONSCOPY { "constraints/symresack/forceconscopy" };
}
//! Parameters with prefix constraints/varbound
namespace CONSTRAINTS::VARBOUND {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/varbound/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/varbound/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/varbound/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/varbound/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/varbound/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/varbound/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/varbound/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/varbound/presoltiming" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/varbound/presolpairwise" };
    //! maximum coefficient in varbound constraint to be added as a row into LP
    constexpr Param<double> MAXLPCOEF { "constraints/varbound/maxlpcoef" };
    //! should bound widening be used in conflict analysis?
    constexpr Param<bool> USEBDWIDENING { "constraints/varbound/usebdwidening" };
}
//! Parameters with prefix constraints/xor
namespace CONSTRAINTS::XOR {
    //! frequency for separating cuts (-1: never, 0: only in root node)
    constexpr Param<int> SEPAFREQ { "constraints/xor/sepafreq" };
    //! frequency for propagating domains (-1: never, 0: only in root node)
    constexpr Param<int> PROPFREQ { "constraints/xor/propfreq" };
    //! timing when constraint propagation should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS)
    constexpr Param<int> PROPTIMING { "constraints/xor/proptiming" };
    //! frequency for using all instead of only the useful constraints in separation, propagation and enforcement (-1:
    //! never, 0: only in first evaluation)
    constexpr Param<int> EAGERFREQ { "constraints/xor/eagerfreq" };
    //! maximal number of presolving rounds the constraint handler participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "constraints/xor/maxprerounds" };
    //! should separation method be delayed, if other separators found cuts?
    constexpr Param<bool> DELAYSEPA { "constraints/xor/delaysepa" };
    //! should propagation method be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAYPROP { "constraints/xor/delayprop" };
    //! timing mask of the constraint handler's presolving method (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "constraints/xor/presoltiming" };
    //! should pairwise constraint comparison be performed in presolving?
    constexpr Param<bool> PRESOLPAIRWISE { "constraints/xor/presolpairwise" };
    //! should hash table be used for detecting redundant constraints in advance?
    constexpr Param<bool> PRESOLUSEHASHING { "constraints/xor/presolusehashing" };
    //! should the extended formulation be added in presolving?
    constexpr Param<bool> ADDEXTENDEDFORM { "constraints/xor/addextendedform" };
    //! should the extended flow formulation be added (nonsymmetric formulation otherwise)?
    constexpr Param<bool> ADDFLOWEXTENDED { "constraints/xor/addflowextended" };
    //! should parity inequalities be separated?
    constexpr Param<bool> SEPARATEPARITY { "constraints/xor/separateparity" };
    //! frequency for applying the Gauss propagator
    constexpr Param<int> GAUSSPROPFREQ { "constraints/xor/gausspropfreq" };
}
//! Parameters with prefix cutselection/hybrid
namespace CUTSELECTION::HYBRID {
    //! priority of cut selection rule \<hybrid\>
    constexpr Param<int> PRIORITY { "cutselection/hybrid/priority" };
    //! weight of efficacy in cut score calculation
    constexpr Param<double> EFFICACYWEIGHT { "cutselection/hybrid/efficacyweight" };
    //! weight of directed cutoff distance in cut score calculation
    constexpr Param<double> DIRCUTOFFDISTWEIGHT { "cutselection/hybrid/dircutoffdistweight" };
    //! weight of objective parallelism in cut score calculation
    constexpr Param<double> OBJPARALWEIGHT { "cutselection/hybrid/objparalweight" };
    //! weight of integral support in cut score calculation
    constexpr Param<double> INTSUPPORTWEIGHT { "cutselection/hybrid/intsupportweight" };
    //! minimal orthogonality for a cut to enter the LP
    constexpr Param<double> MINORTHO { "cutselection/hybrid/minortho" };
    //! minimal orthogonality for a cut to enter the LP in the root node
    constexpr Param<double> MINORTHOROOT { "cutselection/hybrid/minorthoroot" };
}
//! Parameters with prefix decomposition
namespace DECOMPOSITION {
    //! should the variables be labelled for the application of Benders' decomposition?
    constexpr Param<bool> BENDERSLABELS { "decomposition/benderslabels" };
    //! if a decomposition exists, should Benders' decomposition be applied?
    constexpr Param<bool> APPLYBENDERS { "decomposition/applybenders" };
    //! maximum number of edges in block graph computation (-1: no limit, 0: disable block graph computation)
    constexpr Param<int> MAXGRAPHEDGE { "decomposition/maxgraphedge" };
    //! disable expensive measures
    constexpr Param<bool> DISABLEMEASURES { "decomposition/disablemeasures" };
}
//! Parameters with prefix display
namespace DISPLAY {
    //! verbosity level of output
    constexpr Param<int> VERBLEVEL { "display/verblevel" };
    //! maximal number of characters in a node information line
    constexpr Param<int> WIDTH { "display/width" };
    //! frequency for displaying node information lines
    constexpr Param<int> FREQ { "display/freq" };
    //! frequency for displaying header lines (every n'th node information line)
    constexpr Param<int> HEADERFREQ { "display/headerfreq" };
    //! should the LP solver display status messages?
    constexpr Param<bool> LPINFO { "display/lpinfo" };
    //! display all violations for a given start solution / the best solution after the solving process?
    constexpr Param<bool> ALLVIOLS { "display/allviols" };
    //! should the relevant statistics be displayed at the end of solving?
    constexpr Param<bool> RELEVANTSTATS { "display/relevantstats" };
}
//! Parameters with prefix display/avgdualbound
namespace DISPLAY::AVGDUALBOUND {
    //! display activation status of display column \<avgdualbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/avgdualbound/active" };
}
//! Parameters with prefix display/completed
namespace DISPLAY::COMPLETED {
    //! display activation status of display column \<completed\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/completed/active" };
}
//! Parameters with prefix display/concdualbound
namespace DISPLAY::CONCDUALBOUND {
    //! display activation status of display column \<concdualbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/concdualbound/active" };
}
//! Parameters with prefix display/concgap
namespace DISPLAY::CONCGAP {
    //! display activation status of display column \<concgap\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/concgap/active" };
}
//! Parameters with prefix display/concmemused
namespace DISPLAY::CONCMEMUSED {
    //! display activation status of display column \<concmemused\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/concmemused/active" };
}
//! Parameters with prefix display/concprimalbound
namespace DISPLAY::CONCPRIMALBOUND {
    //! display activation status of display column \<concprimalbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/concprimalbound/active" };
}
//! Parameters with prefix display/concsolfound
namespace DISPLAY::CONCSOLFOUND {
    //! display activation status of display column \<concsolfound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/concsolfound/active" };
}
//! Parameters with prefix display/conflicts
namespace DISPLAY::CONFLICTS {
    //! display activation status of display column \<conflicts\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/conflicts/active" };
}
//! Parameters with prefix display/conss
namespace DISPLAY::CONSS {
    //! display activation status of display column \<conss\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/conss/active" };
}
//! Parameters with prefix display/curcols
namespace DISPLAY::CURCOLS {
    //! display activation status of display column \<curcols\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/curcols/active" };
}
//! Parameters with prefix display/curconss
namespace DISPLAY::CURCONSS {
    //! display activation status of display column \<curconss\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/curconss/active" };
}
//! Parameters with prefix display/curdualbound
namespace DISPLAY::CURDUALBOUND {
    //! display activation status of display column \<curdualbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/curdualbound/active" };
}
//! Parameters with prefix display/currows
namespace DISPLAY::CURROWS {
    //! display activation status of display column \<currows\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/currows/active" };
}
//! Parameters with prefix display/cutoffbound
namespace DISPLAY::CUTOFFBOUND {
    //! display activation status of display column \<cutoffbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/cutoffbound/active" };
}
//! Parameters with prefix display/cuts
namespace DISPLAY::CUTS {
    //! display activation status of display column \<cuts\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/cuts/active" };
}
//! Parameters with prefix display/depth
namespace DISPLAY::DEPTH {
    //! display activation status of display column \<depth\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/depth/active" };
}
//! Parameters with prefix display/dualbound
namespace DISPLAY::DUALBOUND {
    //! display activation status of display column \<dualbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/dualbound/active" };
}
//! Parameters with prefix display/estimate
namespace DISPLAY::ESTIMATE {
    //! display activation status of display column \<estimate\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/estimate/active" };
}
//! Parameters with prefix display/feasst
namespace DISPLAY::FEASST {
    //! display activation status of display column \<feasST\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/feasST/active" };
}
//! Parameters with prefix display/gap
namespace DISPLAY::GAP {
    //! display activation status of display column \<gap\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/gap/active" };
}
//! Parameters with prefix display/lpavgiterations
namespace DISPLAY::LPAVGITERATIONS {
    //! display activation status of display column \<lpavgiterations\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/lpavgiterations/active" };
}
//! Parameters with prefix display/lpcond
namespace DISPLAY::LPCOND {
    //! display activation status of display column \<lpcond\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/lpcond/active" };
}
//! Parameters with prefix display/lpiterations
namespace DISPLAY::LPITERATIONS {
    //! display activation status of display column \<lpiterations\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/lpiterations/active" };
}
//! Parameters with prefix display/lpobj
namespace DISPLAY::LPOBJ {
    //! display activation status of display column \<lpobj\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/lpobj/active" };
}
//! Parameters with prefix display/maxdepth
namespace DISPLAY::MAXDEPTH {
    //! display activation status of display column \<maxdepth\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/maxdepth/active" };
}
//! Parameters with prefix display/memtotal
namespace DISPLAY::MEMTOTAL {
    //! display activation status of display column \<memtotal\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/memtotal/active" };
}
//! Parameters with prefix display/memused
namespace DISPLAY::MEMUSED {
    //! display activation status of display column \<memused\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/memused/active" };
}
//! Parameters with prefix display/nexternbranchcands
namespace DISPLAY::NEXTERNBRANCHCANDS {
    //! display activation status of display column \<nexternbranchcands\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nexternbranchcands/active" };
}
//! Parameters with prefix display/nfrac
namespace DISPLAY::NFRAC {
    //! display activation status of display column \<nfrac\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nfrac/active" };
}
//! Parameters with prefix display/ninfeasleaves
namespace DISPLAY::NINFEASLEAVES {
    //! display activation status of display column \<ninfeasleaves\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/ninfeasleaves/active" };
}
//! Parameters with prefix display/nnodes
namespace DISPLAY::NNODES {
    //! display activation status of display column \<nnodes\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nnodes/active" };
}
//! Parameters with prefix display/nnodesbelowinc
namespace DISPLAY::NNODESBELOWINC {
    //! display activation status of display column \<nnodesbelowinc\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nnodesbelowinc/active" };
}
//! Parameters with prefix display/nobjleaves
namespace DISPLAY::NOBJLEAVES {
    //! display activation status of display column \<nobjleaves\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nobjleaves/active" };
}
//! Parameters with prefix display/nodesleft
namespace DISPLAY::NODESLEFT {
    //! display activation status of display column \<nodesleft\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nodesleft/active" };
}
//! Parameters with prefix display/nrank1nodes
namespace DISPLAY::NRANK1NODES {
    //! display activation status of display column \<nrank1nodes\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nrank1nodes/active" };
}
//! Parameters with prefix display/nsols
namespace DISPLAY::NSOLS {
    //! display activation status of display column \<nsols\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/nsols/active" };
}
//! Parameters with prefix display/plungedepth
namespace DISPLAY::PLUNGEDEPTH {
    //! display activation status of display column \<plungedepth\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/plungedepth/active" };
}
//! Parameters with prefix display/poolsize
namespace DISPLAY::POOLSIZE {
    //! display activation status of display column \<poolsize\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/poolsize/active" };
}
//! Parameters with prefix display/primalbound
namespace DISPLAY::PRIMALBOUND {
    //! display activation status of display column \<primalbound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/primalbound/active" };
}
//! Parameters with prefix display/primalgap
namespace DISPLAY::PRIMALGAP {
    //! display activation status of display column \<primalgap\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/primalgap/active" };
}
//! Parameters with prefix display/pseudoobj
namespace DISPLAY::PSEUDOOBJ {
    //! display activation status of display column \<pseudoobj\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/pseudoobj/active" };
}
//! Parameters with prefix display/separounds
namespace DISPLAY::SEPAROUNDS {
    //! display activation status of display column \<separounds\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/separounds/active" };
}
//! Parameters with prefix display/solfound
namespace DISPLAY::SOLFOUND {
    //! display activation status of display column \<solfound\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/solfound/active" };
}
//! Parameters with prefix display/sols
namespace DISPLAY::SOLS {
    //! display activation status of display column \<sols\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/sols/active" };
}
//! Parameters with prefix display/strongbranchs
namespace DISPLAY::STRONGBRANCHS {
    //! display activation status of display column \<strongbranchs\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/strongbranchs/active" };
}
//! Parameters with prefix display/time
namespace DISPLAY::TIME {
    //! display activation status of display column \<time\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/time/active" };
}
//! Parameters with prefix display/vars
namespace DISPLAY::VARS {
    //! display activation status of display column \<vars\> (0: off, 1: auto, 2:on)
    constexpr Param<int> ACTIVE { "display/vars/active" };
}
//! Parameters with prefix estimation
namespace ESTIMATION {
    //! tree size estimation method: (c)ompletion, (e)nsemble, time series forecasts on either (g)ap, (l)eaf frequency,
    //! (o)open nodes, tree (w)eight, (s)sg, or (t)ree profile or w(b)e
    constexpr Param<char> METHOD { "estimation/method" };
    //! coefficient of tree weight in monotone approximation of search completion
    constexpr Param<double> COEFMONOWEIGHT { "estimation/coefmonoweight" };
    //! coefficient of 1 - SSG in monotone approximation of search completion
    constexpr Param<double> COEFMONOSSG { "estimation/coefmonossg" };
    //! report frequency on estimation: -1: never, 0:always, k \>= 1: k times evenly during search
    constexpr Param<int> REPORTFREQ { "estimation/reportfreq" };
    //! user regression forest in RFCSV format
    constexpr Param<std::string> REGFORESTFILENAME { "estimation/regforestfilename" };
    //! approximation of search tree completion: (a)uto, (g)ap, tree (w)eight, (m)onotone regression, (r)egression
    //! forest, (s)sg
    constexpr Param<char> COMPLETIONTYPE { "estimation/completiontype" };
    //! use leaf nodes as basic observations for time series, or all nodes?
    constexpr Param<bool> USELEAFTS { "estimation/useleafts" };
    //! should statistics be shown at the end?
    constexpr Param<bool> SHOWSTATS { "estimation/showstats" };
}
//! Parameters with prefix estimation/restarts
namespace ESTIMATION::RESTARTS {
    //! restart policy: (a)lways, (c)ompletion, (e)stimation, (n)ever
    constexpr Param<char> RESTARTPOLICY { "estimation/restarts/restartpolicy" };
    //! restart limit
    constexpr Param<int> RESTARTLIMIT { "estimation/restarts/restartlimit" };
    //! minimum number of nodes before restart
    constexpr Param<long long> MINNODES { "estimation/restarts/minnodes" };
    //! should only leaves count for the minnodes parameter?
    constexpr Param<bool> COUNTONLYLEAVES { "estimation/restarts/countonlyleaves" };
    //! factor by which the estimated number of nodes should exceed the current number of nodes
    constexpr Param<double> RESTARTFACTOR { "estimation/restarts/restartfactor" };
    //! whether to apply a restart when nonlinear constraints are present
    constexpr Param<bool> RESTARTNONLINEAR { "estimation/restarts/restartnonlinear" };
    //! whether to apply a restart when active pricers are used
    constexpr Param<bool> RESTARTACTPRICERS { "estimation/restarts/restartactpricers" };
    //! limit on the number of successive samples to really trigger a restart
    constexpr Param<int> HITCOUNTERLIM { "estimation/restarts/hitcounterlim" };
}
//! Parameters with prefix estimation/ssg
namespace ESTIMATION::SSG {
    //! the maximum number of individual SSG subtrees; -1: no limit
    constexpr Param<int> NMAXSUBTREES { "estimation/ssg/nmaxsubtrees" };
    //! minimum number of nodes to process between two consecutive SSG splits
    constexpr Param<long long> NMINNODESLASTSPLIT { "estimation/ssg/nminnodeslastsplit" };
}
//! Parameters with prefix estimation/treeprofile
namespace ESTIMATION::TREEPROFILE {
    //! should the event handler collect data?
    constexpr Param<bool> ENABLED { "estimation/treeprofile/enabled" };
    //! minimum average number of nodes at each depth before producing estimations
    constexpr Param<double> MINNODESPERDEPTH { "estimation/treeprofile/minnodesperdepth" };
}
//! Parameters with prefix expr/log
namespace EXPR::LOG {
    //! minimal distance from zero to enforce for child in bound tightening
    constexpr Param<double> MINZERODISTANCE { "expr/log/minzerodistance" };
}
//! Parameters with prefix expr/pow
namespace EXPR::POW {
    //! minimal distance from zero to enforce for child in bound tightening
    constexpr Param<double> MINZERODISTANCE { "expr/pow/minzerodistance" };
}
//! Parameters with prefix heuristics
namespace HEURISTICS {
    //! should setting of common subscip parameters include the activation of the UCT node selector?
    constexpr Param<bool> USEUCTSUBSCIP { "heuristics/useuctsubscip" };
}
//! Parameters with prefix heuristics/actconsdiving
namespace HEURISTICS::ACTCONSDIVING {
    //! priority of heuristic \<actconsdiving\>
    constexpr Param<int> PRIORITY { "heuristics/actconsdiving/priority" };
    //! frequency for calling primal heuristic \<actconsdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/actconsdiving/freq" };
    //! frequency offset for calling primal heuristic \<actconsdiving\>
    constexpr Param<int> FREQOFS { "heuristics/actconsdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<actconsdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/actconsdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/actconsdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/actconsdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/actconsdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/actconsdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/actconsdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/actconsdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/actconsdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/actconsdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/actconsdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/actconsdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/actconsdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/actconsdiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/adaptivediving
namespace HEURISTICS::ADAPTIVEDIVING {
    //! priority of heuristic \<adaptivediving\>
    constexpr Param<int> PRIORITY { "heuristics/adaptivediving/priority" };
    //! frequency for calling primal heuristic \<adaptivediving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/adaptivediving/freq" };
    //! frequency offset for calling primal heuristic \<adaptivediving\>
    constexpr Param<int> FREQOFS { "heuristics/adaptivediving/freqofs" };
    //! maximal depth level to call primal heuristic \<adaptivediving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/adaptivediving/maxdepth" };
    //! parameter that increases probability of exploration among divesets (only active if seltype is 'e')
    constexpr Param<double> EPSILON { "heuristics/adaptivediving/epsilon" };
    //! score parameter for selection: minimize either average 'n'odes, LP 'i'terations,backtrack/'c'onflict ratio,
    //! 'd'epth, 1 / 's'olutions, or 1 / solutions'u'ccess
    constexpr Param<char> SCORETYPE { "heuristics/adaptivediving/scoretype" };
    //! selection strategy: (e)psilon-greedy, (w)eighted distribution, (n)ext diving
    constexpr Param<char> SELTYPE { "heuristics/adaptivediving/seltype" };
    //! should the heuristic use its own statistics, or shared statistics?
    constexpr Param<bool> USEADAPTIVECONTEXT { "heuristics/adaptivediving/useadaptivecontext" };
    //! coefficient c to decrease initial confidence (calls + 1.0) / (calls + c) in scores
    constexpr Param<double> SELCONFIDENCECOEFF { "heuristics/adaptivediving/selconfidencecoeff" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/adaptivediving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<long long> MAXLPITEROFS { "heuristics/adaptivediving/maxlpiterofs" };
    //! weight of incumbent solutions compared to other solutions in computation of LP iteration limit
    constexpr Param<double> BESTSOLWEIGHT { "heuristics/adaptivediving/bestsolweight" };
}
//! Parameters with prefix heuristics/alns
namespace HEURISTICS::ALNS {
    //! priority of heuristic \<alns\>
    constexpr Param<int> PRIORITY { "heuristics/alns/priority" };
    //! frequency for calling primal heuristic \<alns\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/alns/freq" };
    //! frequency offset for calling primal heuristic \<alns\>
    constexpr Param<int> FREQOFS { "heuristics/alns/freqofs" };
    //! maximal depth level to call primal heuristic \<alns\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/alns/maxdepth" };
    //! show statistics on neighborhoods?
    constexpr Param<bool> SHOWNBSTATS { "heuristics/alns/shownbstats" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/alns/maxnodes" };
    //! offset added to the nodes budget
    constexpr Param<long long> NODESOFS { "heuristics/alns/nodesofs" };
    //! minimum number of nodes required to start a sub-SCIP
    constexpr Param<long long> MINNODES { "heuristics/alns/minnodes" };
    //! number of nodes since last incumbent solution that the heuristic should wait
    constexpr Param<long long> WAITINGNODES { "heuristics/alns/waitingnodes" };
    //! fraction of nodes compared to the main SCIP for budget computation
    constexpr Param<double> NODESQUOT { "heuristics/alns/nodesquot" };
    //! lower bound fraction of nodes compared to the main SCIP for budget computation
    constexpr Param<double> NODESQUOTMIN { "heuristics/alns/nodesquotmin" };
    //! initial factor by which ALNS should at least improve the incumbent
    constexpr Param<double> STARTMINIMPROVE { "heuristics/alns/startminimprove" };
    //! lower threshold for the minimal improvement over the incumbent
    constexpr Param<double> MINIMPROVELOW { "heuristics/alns/minimprovelow" };
    //! upper bound for the minimal improvement over the incumbent
    constexpr Param<double> MINIMPROVEHIGH { "heuristics/alns/minimprovehigh" };
    //! limit on the number of improving solutions in a sub-SCIP call
    constexpr Param<int> NSOLSLIM { "heuristics/alns/nsolslim" };
    //! the bandit algorithm: (u)pper confidence bounds, (e)xp.3, epsilon (g)reedy
    constexpr Param<char> BANDITALGO { "heuristics/alns/banditalgo" };
    //! weight between uniform (gamma ~ 1) and weight driven (gamma ~ 0) probability distribution for exp3
    constexpr Param<double> GAMMA { "heuristics/alns/gamma" };
    //! reward offset between 0 and 1 at every observation for Exp.3
    constexpr Param<double> BETA { "heuristics/alns/beta" };
    //! parameter to increase the confidence width in UCB
    constexpr Param<double> ALPHA { "heuristics/alns/alpha" };
    //! distances from fixed variables be used for variable prioritization
    constexpr Param<bool> USEDISTANCES { "heuristics/alns/usedistances" };
    //! should reduced cost scores be used for variable prioritization?
    constexpr Param<bool> USEREDCOST { "heuristics/alns/useredcost" };
    //! should the ALNS heuristic do more fixings by itself based on variable prioritization until the target fixing
    //! rate is reached?
    constexpr Param<bool> DOMOREFIXINGS { "heuristics/alns/domorefixings" };
    //! should the heuristic adjust the target fixing rate based on the success?
    constexpr Param<bool> ADJUSTFIXINGRATE { "heuristics/alns/adjustfixingrate" };
    //! should the heuristic activate other sub-SCIP heuristics during its search?
    constexpr Param<bool> USESUBSCIPHEURS { "heuristics/alns/usesubscipheurs" };
    //! reward control to increase the weight of the simple solution indicator and decrease the weight of the closed gap
    //! reward
    constexpr Param<double> REWARDCONTROL { "heuristics/alns/rewardcontrol" };
    //! factor by which target node number is eventually increased
    constexpr Param<double> TARGETNODEFACTOR { "heuristics/alns/targetnodefactor" };
    //! initial random seed for bandit algorithms and random decisions by neighborhoods
    constexpr Param<int> SEED { "heuristics/alns/seed" };
    //! number of allowed executions of the heuristic on the same incumbent solution (-1: no limit, 0: number of active
    //! neighborhoods)
    constexpr Param<int> MAXCALLSSAMESOL { "heuristics/alns/maxcallssamesol" };
    //! should the factor by which the minimum improvement is bound be dynamically updated?
    constexpr Param<bool> ADJUSTMINIMPROVE { "heuristics/alns/adjustminimprove" };
    //! should the target nodes be dynamically adjusted?
    constexpr Param<bool> ADJUSTTARGETNODES { "heuristics/alns/adjusttargetnodes" };
    //! increase exploration in epsilon-greedy bandit algorithm
    constexpr Param<double> EPS { "heuristics/alns/eps" };
    //! the reward baseline to separate successful and failed calls
    constexpr Param<double> REWARDBASELINE { "heuristics/alns/rewardbaseline" };
    //! should the bandit algorithms be reset when a new problem is read?
    constexpr Param<bool> RESETWEIGHTS { "heuristics/alns/resetweights" };
    //! file name to store all rewards and the selection of the bandit
    constexpr Param<std::string> REWARDFILENAME { "heuristics/alns/rewardfilename" };
    //! should random seeds of sub-SCIPs be altered to increase diversification?
    constexpr Param<bool> SUBSCIPRANDSEEDS { "heuristics/alns/subsciprandseeds" };
    //! should the reward be scaled by the effort?
    constexpr Param<bool> SCALEBYEFFORT { "heuristics/alns/scalebyeffort" };
    //! should cutting planes be copied to the sub-SCIP?
    constexpr Param<bool> COPYCUTS { "heuristics/alns/copycuts" };
    //! tolerance by which the fixing rate may be missed without generic fixing
    constexpr Param<double> FIXTOL { "heuristics/alns/fixtol" };
    //! tolerance by which the fixing rate may be exceeded without generic unfixing
    constexpr Param<double> UNFIXTOL { "heuristics/alns/unfixtol" };
    //! should local reduced costs be used for generic (un)fixing?
    constexpr Param<bool> USELOCALREDCOST { "heuristics/alns/uselocalredcost" };
    //! should pseudo cost scores be used for variable priorization?
    constexpr Param<bool> USEPSCOST { "heuristics/alns/usepscost" };
    //! should the heuristic be executed multiple times during the root node?
    constexpr Param<bool> INITDURINGROOT { "heuristics/alns/initduringroot" };
}
//! Parameters with prefix heuristics/alns/crossover
namespace HEURISTICS::ALNS::CROSSOVER {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/crossover/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/crossover/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/crossover/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/crossover/priority" };
    //! the number of solutions that crossover should combine
    constexpr Param<int> NSOLS { "heuristics/alns/crossover/nsols" };
}
//! Parameters with prefix heuristics/alns/dins
namespace HEURISTICS::ALNS::DINS {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/dins/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/dins/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/dins/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/dins/priority" };
    //! number of pool solutions where binary solution values must agree
    constexpr Param<int> NPOOLSOLS { "heuristics/alns/dins/npoolsols" };
}
//! Parameters with prefix heuristics/alns/localbranching
namespace HEURISTICS::ALNS::LOCALBRANCHING {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/localbranching/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/localbranching/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/localbranching/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/localbranching/priority" };
}
//! Parameters with prefix heuristics/alns/mutation
namespace HEURISTICS::ALNS::MUTATION {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/mutation/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/mutation/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/mutation/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/mutation/priority" };
}
//! Parameters with prefix heuristics/alns/proximity
namespace HEURISTICS::ALNS::PROXIMITY {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/proximity/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/proximity/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/proximity/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/proximity/priority" };
}
//! Parameters with prefix heuristics/alns/rens
namespace HEURISTICS::ALNS::RENS {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/rens/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/rens/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/rens/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/rens/priority" };
}
//! Parameters with prefix heuristics/alns/rins
namespace HEURISTICS::ALNS::RINS {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/rins/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/rins/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/rins/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/rins/priority" };
}
//! Parameters with prefix heuristics/alns/trustregion
namespace HEURISTICS::ALNS::TRUSTREGION {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/trustregion/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/trustregion/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/trustregion/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/trustregion/priority" };
    //! the penalty for each change in the binary variables from the candidate solution
    constexpr Param<double> VIOLPENALTY { "heuristics/alns/trustregion/violpenalty" };
}
//! Parameters with prefix heuristics/alns/zeroobjective
namespace HEURISTICS::ALNS::ZEROOBJECTIVE {
    //! minimum fixing rate for this neighborhood
    constexpr Param<double> MINFIXINGRATE { "heuristics/alns/zeroobjective/minfixingrate" };
    //! maximum fixing rate for this neighborhood
    constexpr Param<double> MAXFIXINGRATE { "heuristics/alns/zeroobjective/maxfixingrate" };
    //! is this neighborhood active?
    constexpr Param<bool> ACTIVE { "heuristics/alns/zeroobjective/active" };
    //! positive call priority to initialize bandit algorithms
    constexpr Param<double> PRIORITY { "heuristics/alns/zeroobjective/priority" };
}
//! Parameters with prefix heuristics/bound
namespace HEURISTICS::BOUND {
    //! priority of heuristic \<bound\>
    constexpr Param<int> PRIORITY { "heuristics/bound/priority" };
    //! frequency for calling primal heuristic \<bound\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/bound/freq" };
    //! frequency offset for calling primal heuristic \<bound\>
    constexpr Param<int> FREQOFS { "heuristics/bound/freqofs" };
    //! maximal depth level to call primal heuristic \<bound\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/bound/maxdepth" };
    //! Should heuristic only be executed if no primal solution was found, yet?
    constexpr Param<bool> ONLYWITHOUTSOL { "heuristics/bound/onlywithoutsol" };
    //! maximum number of propagation rounds during probing (-1 infinity, -2 parameter settings)
    constexpr Param<int> MAXPROPROUNDS { "heuristics/bound/maxproprounds" };
    //! to which bound should integer variables be fixed? ('l'ower, 'u'pper, or 'b'oth)
    constexpr Param<char> BOUND { "heuristics/bound/bound" };
}
//! Parameters with prefix heuristics/clique
namespace HEURISTICS::CLIQUE {
    //! priority of heuristic \<clique\>
    constexpr Param<int> PRIORITY { "heuristics/clique/priority" };
    //! frequency for calling primal heuristic \<clique\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/clique/freq" };
    //! frequency offset for calling primal heuristic \<clique\>
    constexpr Param<int> FREQOFS { "heuristics/clique/freqofs" };
    //! maximal depth level to call primal heuristic \<clique\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/clique/maxdepth" };
    //! minimum percentage of integer variables that have to be fixable
    constexpr Param<double> MININTFIXINGRATE { "heuristics/clique/minintfixingrate" };
    //! minimum percentage of fixed variables in the sub-MIP
    constexpr Param<double> MINMIPFIXINGRATE { "heuristics/clique/minmipfixingrate" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/clique/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/clique/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/clique/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/clique/nodesquot" };
    //! factor by which clique heuristic should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/clique/minimprove" };
    //! maximum number of propagation rounds during probing (-1 infinity)
    constexpr Param<int> MAXPROPROUNDS { "heuristics/clique/maxproprounds" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/clique/copycuts" };
    //! should more variables be fixed based on variable locks if the fixing rate was not reached?
    constexpr Param<bool> USELOCKFIXINGS { "heuristics/clique/uselockfixings" };
    //! maximum number of backtracks during the fixing process
    constexpr Param<int> MAXBACKTRACKS { "heuristics/clique/maxbacktracks" };
}
//! Parameters with prefix heuristics/coefdiving
namespace HEURISTICS::COEFDIVING {
    //! priority of heuristic \<coefdiving\>
    constexpr Param<int> PRIORITY { "heuristics/coefdiving/priority" };
    //! frequency for calling primal heuristic \<coefdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/coefdiving/freq" };
    //! frequency offset for calling primal heuristic \<coefdiving\>
    constexpr Param<int> FREQOFS { "heuristics/coefdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<coefdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/coefdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/coefdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/coefdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/coefdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/coefdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/coefdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/coefdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/coefdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/coefdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/coefdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/coefdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/coefdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/coefdiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/completesol
namespace HEURISTICS::COMPLETESOL {
    //! priority of heuristic \<completesol\>
    constexpr Param<int> PRIORITY { "heuristics/completesol/priority" };
    //! frequency for calling primal heuristic \<completesol\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/completesol/freq" };
    //! frequency offset for calling primal heuristic \<completesol\>
    constexpr Param<int> FREQOFS { "heuristics/completesol/freqofs" };
    //! maximal depth level to call primal heuristic \<completesol\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/completesol/maxdepth" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/completesol/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/completesol/minnodes" };
    //! maximal rate of unknown solution values
    constexpr Param<double> MAXUNKNOWNRATE { "heuristics/completesol/maxunknownrate" };
    //! should all subproblem solutions be added to the original SCIP?
    constexpr Param<bool> ADDALLSOLS { "heuristics/completesol/addallsols" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/completesol/nodesofs" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/completesol/nodesquot" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/completesol/lplimfac" };
    //! weight of the original objective function (1: only original objective)
    constexpr Param<double> OBJWEIGHT { "heuristics/completesol/objweight" };
    //! bound widening factor applied to continuous variables (0: fix variables to given solution values, 1: relax to
    //! global bounds)
    constexpr Param<double> BOUNDWIDENING { "heuristics/completesol/boundwidening" };
    //! factor by which the incumbent should be improved at least
    constexpr Param<double> MINIMPROVE { "heuristics/completesol/minimprove" };
    //! should number of continuous variables be ignored?
    constexpr Param<bool> IGNORECONT { "heuristics/completesol/ignorecont" };
    //! heuristic stops, if the given number of improving solutions were found (-1: no limit)
    constexpr Param<int> SOLUTIONS { "heuristics/completesol/solutions" };
    //! maximal number of iterations in propagation (-1: no limit)
    constexpr Param<int> MAXPROPROUNDS { "heuristics/completesol/maxproprounds" };
    //! should the heuristic run before presolving?
    constexpr Param<bool> BEFOREPRESOL { "heuristics/completesol/beforepresol" };
    //! maximal number of LP iterations (-1: no limit)
    constexpr Param<long long> MAXLPITER { "heuristics/completesol/maxlpiter" };
    //! maximal number of continuous variables after presolving
    constexpr Param<int> MAXCONTVARS { "heuristics/completesol/maxcontvars" };
}
//! Parameters with prefix heuristics/conflictdiving
namespace HEURISTICS::CONFLICTDIVING {
    //! priority of heuristic \<conflictdiving\>
    constexpr Param<int> PRIORITY { "heuristics/conflictdiving/priority" };
    //! frequency for calling primal heuristic \<conflictdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/conflictdiving/freq" };
    //! frequency offset for calling primal heuristic \<conflictdiving\>
    constexpr Param<int> FREQOFS { "heuristics/conflictdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<conflictdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/conflictdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/conflictdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/conflictdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/conflictdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/conflictdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/conflictdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/conflictdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/conflictdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/conflictdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/conflictdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/conflictdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/conflictdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/conflictdiving/onlylpbranchcands" };
    //! try to maximize the violation
    constexpr Param<bool> MAXVIOL { "heuristics/conflictdiving/maxviol" };
    //! perform rounding like coefficient diving
    constexpr Param<bool> LIKECOEF { "heuristics/conflictdiving/likecoef" };
    //! minimal number of conflict locks per variable
    constexpr Param<int> MINCONFLICTLOCKS { "heuristics/conflictdiving/minconflictlocks" };
    //! weight used in a convex combination of conflict and variable locks
    constexpr Param<double> LOCKWEIGHT { "heuristics/conflictdiving/lockweight" };
}
//! Parameters with prefix heuristics/crossover
namespace HEURISTICS::CROSSOVER {
    //! priority of heuristic \<crossover\>
    constexpr Param<int> PRIORITY { "heuristics/crossover/priority" };
    //! frequency for calling primal heuristic \<crossover\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/crossover/freq" };
    //! frequency offset for calling primal heuristic \<crossover\>
    constexpr Param<int> FREQOFS { "heuristics/crossover/freqofs" };
    //! maximal depth level to call primal heuristic \<crossover\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/crossover/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/crossover/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/crossover/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/crossover/minnodes" };
    //! number of solutions to be taken into account
    constexpr Param<int> NUSEDSOLS { "heuristics/crossover/nusedsols" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<long long> NWAITINGNODES { "heuristics/crossover/nwaitingnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/crossover/nodesquot" };
    //! minimum percentage of integer variables that have to be fixed
    constexpr Param<double> MINFIXINGRATE { "heuristics/crossover/minfixingrate" };
    //! factor by which Crossover should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/crossover/minimprove" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/crossover/lplimfac" };
    //! should the choice which sols to take be randomized?
    constexpr Param<bool> RANDOMIZATION { "heuristics/crossover/randomization" };
    //! should the nwaitingnodes parameter be ignored at the root node?
    constexpr Param<bool> DONTWAITATROOT { "heuristics/crossover/dontwaitatroot" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/crossover/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/crossover/copycuts" };
    //! should the subproblem be permuted to increase diversification?
    constexpr Param<bool> PERMUTE { "heuristics/crossover/permute" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/crossover/bestsollimit" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/crossover/useuct" };
}
//! Parameters with prefix heuristics/dins
namespace HEURISTICS::DINS {
    //! priority of heuristic \<dins\>
    constexpr Param<int> PRIORITY { "heuristics/dins/priority" };
    //! frequency for calling primal heuristic \<dins\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/dins/freq" };
    //! frequency offset for calling primal heuristic \<dins\>
    constexpr Param<int> FREQOFS { "heuristics/dins/freqofs" };
    //! maximal depth level to call primal heuristic \<dins\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/dins/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/dins/nodesofs" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/dins/nodesquot" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/dins/minnodes" };
    //! number of pool-solutions to be checked for flag array update (for hard fixing of binary variables)
    constexpr Param<int> SOLNUM { "heuristics/dins/solnum" };
    //! radius (using Manhattan metric) of the incumbent's neighborhood to be searched
    constexpr Param<int> NEIGHBORHOODSIZE { "heuristics/dins/neighborhoodsize" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/dins/maxnodes" };
    //! factor by which dins should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/dins/minimprove" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<long long> NWAITINGNODES { "heuristics/dins/nwaitingnodes" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/dins/lplimfac" };
    //! minimum percentage of integer variables that have to be fixable
    constexpr Param<double> MINFIXINGRATE { "heuristics/dins/minfixingrate" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/dins/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/dins/copycuts" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/dins/useuct" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/dins/bestsollimit" };
}
//! Parameters with prefix heuristics/distributiondiving
namespace HEURISTICS::DISTRIBUTIONDIVING {
    //! priority of heuristic \<distributiondiving\>
    constexpr Param<int> PRIORITY { "heuristics/distributiondiving/priority" };
    //! frequency for calling primal heuristic \<distributiondiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/distributiondiving/freq" };
    //! frequency offset for calling primal heuristic \<distributiondiving\>
    constexpr Param<int> FREQOFS { "heuristics/distributiondiving/freqofs" };
    //! maximal depth level to call primal heuristic \<distributiondiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/distributiondiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/distributiondiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/distributiondiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/distributiondiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/distributiondiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/distributiondiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/distributiondiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/distributiondiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/distributiondiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/distributiondiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/distributiondiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/distributiondiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/distributiondiving/onlylpbranchcands" };
    //! the score;largest 'd'ifference, 'l'owest cumulative probability,'h'ighest c.p., 'v'otes lowest c.p., votes
    //! highest c.p.('w'), 'r'evolving
    constexpr Param<char> SCOREPARAM { "heuristics/distributiondiving/scoreparam" };
}
//! Parameters with prefix heuristics/dps
namespace HEURISTICS::DPS {
    //! priority of heuristic \<dps\>
    constexpr Param<int> PRIORITY { "heuristics/dps/priority" };
    //! frequency for calling primal heuristic \<dps\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/dps/freq" };
    //! frequency offset for calling primal heuristic \<dps\>
    constexpr Param<int> FREQOFS { "heuristics/dps/freqofs" };
    //! maximal depth level to call primal heuristic \<dps\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/dps/maxdepth" };
    //! maximal number of iterations
    constexpr Param<int> MAXITERATIONS { "heuristics/dps/maxiterations" };
    //! maximal linking score of used decomposition (equivalent to percentage of linking constraints)
    constexpr Param<double> MAXLINKSCORE { "heuristics/dps/maxlinkscore" };
    //! multiplier for absolute increase of penalty parameters (0: no increase)
    constexpr Param<double> PENALTY { "heuristics/dps/penalty" };
    //! should the problem get reoptimized with the original objective function?
    constexpr Param<bool> REOPTIMIZE { "heuristics/dps/reoptimize" };
    //! should solutions get reused in subproblems?
    constexpr Param<bool> REUSE { "heuristics/dps/reuse" };
}
//! Parameters with prefix heuristics/dualval
namespace HEURISTICS::DUALVAL {
    //! priority of heuristic \<dualval\>
    constexpr Param<int> PRIORITY { "heuristics/dualval/priority" };
    //! frequency for calling primal heuristic \<dualval\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/dualval/freq" };
    //! frequency offset for calling primal heuristic \<dualval\>
    constexpr Param<int> FREQOFS { "heuristics/dualval/freqofs" };
    //! maximal depth level to call primal heuristic \<dualval\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/dualval/maxdepth" };
    //! exit if objective doesn't improve
    constexpr Param<bool> FORCEIMPROVEMENTS { "heuristics/dualval/forceimprovements" };
    //! add constraint to ensure that discrete vars are improving
    constexpr Param<bool> ONLYCHEAPER { "heuristics/dualval/onlycheaper" };
    //! disable the heuristic if it was not called at a leaf of the B&B tree
    constexpr Param<bool> ONLYLEAVES { "heuristics/dualval/onlyleaves" };
    //! relax the indicator variables by introducing continuous copies
    constexpr Param<bool> RELAXINDICATORS { "heuristics/dualval/relaxindicators" };
    //! relax the continous variables
    constexpr Param<bool> RELAXCONTVARS { "heuristics/dualval/relaxcontvars" };
    //! verblevel of the heuristic, default is 0 to display nothing
    constexpr Param<int> HEURVERBLEVEL { "heuristics/dualval/heurverblevel" };
    //! verblevel of the nlp solver, can be 0 or 1
    constexpr Param<int> NLPVERBLEVEL { "heuristics/dualval/nlpverblevel" };
    //! number of ranks that should be displayed when the heuristic is called
    constexpr Param<int> RANKVALUE { "heuristics/dualval/rankvalue" };
    //! maximal number of recursive calls of the heuristic (if dynamicdepth is off)
    constexpr Param<int> MAXCALLS { "heuristics/dualval/maxcalls" };
    //! says if and how the recursion depth is computed at runtime
    constexpr Param<int> DYNAMICDEPTH { "heuristics/dualval/dynamicdepth" };
    //! maximal number of variables that may have maximal rank, quit if there are more, turn off by setting -1
    constexpr Param<int> MAXEQUALRANKS { "heuristics/dualval/maxequalranks" };
    //! minimal gap for which we still run the heuristic, if gap is less we return without doing anything
    constexpr Param<double> MINGAP { "heuristics/dualval/mingap" };
    //! value added to objective of slack variables, must not be zero
    constexpr Param<double> LAMBDASLACK { "heuristics/dualval/lambdaslack" };
    //! scaling factor for the objective function
    constexpr Param<double> LAMBDAOBJ { "heuristics/dualval/lambdaobj" };
}
//! Parameters with prefix heuristics/farkasdiving
namespace HEURISTICS::FARKASDIVING {
    //! priority of heuristic \<farkasdiving\>
    constexpr Param<int> PRIORITY { "heuristics/farkasdiving/priority" };
    //! frequency for calling primal heuristic \<farkasdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/farkasdiving/freq" };
    //! frequency offset for calling primal heuristic \<farkasdiving\>
    constexpr Param<int> FREQOFS { "heuristics/farkasdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<farkasdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/farkasdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/farkasdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/farkasdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/farkasdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/farkasdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/farkasdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/farkasdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/farkasdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/farkasdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/farkasdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/farkasdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/farkasdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/farkasdiving/onlylpbranchcands" };
    //! should diving candidates be checked before running?
    constexpr Param<bool> CHECKCANDS { "heuristics/farkasdiving/checkcands" };
    //! should the score be scaled?
    constexpr Param<bool> SCALESCORE { "heuristics/farkasdiving/scalescore" };
    //! should the heuristic only run within the tree if at least one solution was found at the root node?
    constexpr Param<bool> ROOTSUCCESS { "heuristics/farkasdiving/rootsuccess" };
    //! maximal occurance factor of an objective coefficient
    constexpr Param<double> MAXOBJOCC { "heuristics/farkasdiving/maxobjocc" };
    //! minimal objective dynamism (log) to run
    constexpr Param<double> OBJDYNAMISM { "heuristics/farkasdiving/objdynamism" };
    //! scale score by [f]ractionality or [i]mpact on farkasproof
    constexpr Param<char> SCALETYPE { "heuristics/farkasdiving/scaletype" };
}
//! Parameters with prefix heuristics/feaspump
namespace HEURISTICS::FEASPUMP {
    //! priority of heuristic \<feaspump\>
    constexpr Param<int> PRIORITY { "heuristics/feaspump/priority" };
    //! frequency for calling primal heuristic \<feaspump\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/feaspump/freq" };
    //! frequency offset for calling primal heuristic \<feaspump\>
    constexpr Param<int> FREQOFS { "heuristics/feaspump/freqofs" };
    //! maximal depth level to call primal heuristic \<feaspump\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/feaspump/maxdepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/feaspump/maxlpiterquot" };
    //! factor by which the regard of the objective is decreased in each round, 1.0 for dynamic
    constexpr Param<double> OBJFACTOR { "heuristics/feaspump/objfactor" };
    //! initial weight of the objective function in the convex combination
    constexpr Param<double> ALPHA { "heuristics/feaspump/alpha" };
    //! threshold difference for the convex parameter to perform perturbation
    constexpr Param<double> ALPHADIFF { "heuristics/feaspump/alphadiff" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/feaspump/maxlpiterofs" };
    //! total number of feasible solutions found up to which heuristic is called (-1: no limit)
    constexpr Param<int> MAXSOLS { "heuristics/feaspump/maxsols" };
    //! maximal number of pumping loops (-1: no limit)
    constexpr Param<int> MAXLOOPS { "heuristics/feaspump/maxloops" };
    //! maximal number of pumping rounds without fractionality improvement (-1: no limit)
    constexpr Param<int> MAXSTALLLOOPS { "heuristics/feaspump/maxstallloops" };
    //! minimum number of random variables to flip, if a 1-cycle is encountered
    constexpr Param<int> MINFLIPS { "heuristics/feaspump/minflips" };
    //! maximum length of cycles to be checked explicitly in each round
    constexpr Param<int> CYCLELENGTH { "heuristics/feaspump/cyclelength" };
    //! number of iterations until a random perturbation is forced
    constexpr Param<int> PERTURBFREQ { "heuristics/feaspump/perturbfreq" };
    //! radius (using Manhattan metric) of the neighborhood to be searched in stage 3
    constexpr Param<int> NEIGHBORHOODSIZE { "heuristics/feaspump/neighborhoodsize" };
    //! should the feasibility pump be called at root node before cut separation?
    constexpr Param<bool> BEFORECUTS { "heuristics/feaspump/beforecuts" };
    //! should an iterative round-and-propagate scheme be used to find the integral points?
    constexpr Param<bool> USEFP20 { "heuristics/feaspump/usefp20" };
    //! should a random perturbation be performed if a feasible solution was found?
    constexpr Param<bool> PERTSOLFOUND { "heuristics/feaspump/pertsolfound" };
    //! should we solve a local branching sub-MIP if no solution could be found?
    constexpr Param<bool> STAGE3 { "heuristics/feaspump/stage3" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/feaspump/copycuts" };
}
//! Parameters with prefix heuristics/fixandinfer
namespace HEURISTICS::FIXANDINFER {
    //! priority of heuristic \<fixandinfer\>
    constexpr Param<int> PRIORITY { "heuristics/fixandinfer/priority" };
    //! frequency for calling primal heuristic \<fixandinfer\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/fixandinfer/freq" };
    //! frequency offset for calling primal heuristic \<fixandinfer\>
    constexpr Param<int> FREQOFS { "heuristics/fixandinfer/freqofs" };
    //! maximal depth level to call primal heuristic \<fixandinfer\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/fixandinfer/maxdepth" };
    //! maximal number of propagation rounds in probing subproblems (-1: no limit, 0: auto)
    constexpr Param<int> PROPROUNDS { "heuristics/fixandinfer/proprounds" };
    //! minimal number of fixings to apply before dive may be aborted
    constexpr Param<int> MINFIXINGS { "heuristics/fixandinfer/minfixings" };
}
//! Parameters with prefix heuristics/fracdiving
namespace HEURISTICS::FRACDIVING {
    //! priority of heuristic \<fracdiving\>
    constexpr Param<int> PRIORITY { "heuristics/fracdiving/priority" };
    //! frequency for calling primal heuristic \<fracdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/fracdiving/freq" };
    //! frequency offset for calling primal heuristic \<fracdiving\>
    constexpr Param<int> FREQOFS { "heuristics/fracdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<fracdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/fracdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/fracdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/fracdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/fracdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/fracdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/fracdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/fracdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/fracdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/fracdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/fracdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/fracdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/fracdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/fracdiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/gins
namespace HEURISTICS::GINS {
    //! priority of heuristic \<gins\>
    constexpr Param<int> PRIORITY { "heuristics/gins/priority" };
    //! frequency for calling primal heuristic \<gins\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/gins/freq" };
    //! frequency offset for calling primal heuristic \<gins\>
    constexpr Param<int> FREQOFS { "heuristics/gins/freqofs" };
    //! maximal depth level to call primal heuristic \<gins\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/gins/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/gins/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/gins/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/gins/minnodes" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<int> NWAITINGNODES { "heuristics/gins/nwaitingnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/gins/nodesquot" };
    //! percentage of integer variables that have to be fixed
    constexpr Param<double> MINFIXINGRATE { "heuristics/gins/minfixingrate" };
    //! factor by which gins should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/gins/minimprove" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/gins/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/gins/copycuts" };
    //! should continuous variables outside the neighborhoods be fixed?
    constexpr Param<bool> FIXCONTVARS { "heuristics/gins/fixcontvars" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/gins/bestsollimit" };
    //! maximum distance to selected variable to enter the subproblem, or -1 to select the distance that best
    //! approximates the minimum fixing rate from below
    constexpr Param<int> MAXDISTANCE { "heuristics/gins/maxdistance" };
    //! the reference point to compute the neighborhood potential: (r)oot, (l)ocal lp, or (p)seudo solution
    constexpr Param<char> POTENTIAL { "heuristics/gins/potential" };
    //! should the heuristic solve a sequence of sub-MIP's around the first selected variable
    constexpr Param<bool> USEROLLINGHORIZON { "heuristics/gins/userollinghorizon" };
    //! should dense constraints (at least as dense as 1 - minfixingrate) be ignored by connectivity graph?
    constexpr Param<bool> RELAXDENSECONSS { "heuristics/gins/relaxdenseconss" };
    //! limiting percentage for variables already used in sub-SCIPs to terminate rolling horizon approach
    constexpr Param<double> ROLLHORIZONLIMFAC { "heuristics/gins/rollhorizonlimfac" };
    //! overlap of blocks between runs - 0.0: no overlap, 1.0: shift by only 1 block
    constexpr Param<double> OVERLAP { "heuristics/gins/overlap" };
    //! should user decompositions be considered, if available?
    constexpr Param<bool> USEDECOMP { "heuristics/gins/usedecomp" };
    //! should user decompositions be considered for initial selection in rolling horizon, if available?
    constexpr Param<bool> USEDECOMPROLLHORIZON { "heuristics/gins/usedecomprollhorizon" };
    //! should random initial variable selection be used if decomposition was not successful?
    constexpr Param<bool> USESELFALLBACK { "heuristics/gins/useselfallback" };
    //! should blocks be treated consecutively (sorted by ascending label?)
    constexpr Param<bool> CONSECUTIVEBLOCKS { "heuristics/gins/consecutiveblocks" };
}
//! Parameters with prefix heuristics/guideddiving
namespace HEURISTICS::GUIDEDDIVING {
    //! priority of heuristic \<guideddiving\>
    constexpr Param<int> PRIORITY { "heuristics/guideddiving/priority" };
    //! frequency for calling primal heuristic \<guideddiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/guideddiving/freq" };
    //! frequency offset for calling primal heuristic \<guideddiving\>
    constexpr Param<int> FREQOFS { "heuristics/guideddiving/freqofs" };
    //! maximal depth level to call primal heuristic \<guideddiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/guideddiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/guideddiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/guideddiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/guideddiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/guideddiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/guideddiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/guideddiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/guideddiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/guideddiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/guideddiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/guideddiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/guideddiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/guideddiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/indicator
namespace HEURISTICS::INDICATOR {
    //! priority of heuristic \<indicator\>
    constexpr Param<int> PRIORITY { "heuristics/indicator/priority" };
    //! frequency for calling primal heuristic \<indicator\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/indicator/freq" };
    //! frequency offset for calling primal heuristic \<indicator\>
    constexpr Param<int> FREQOFS { "heuristics/indicator/freqofs" };
    //! maximal depth level to call primal heuristic \<indicator\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/indicator/maxdepth" };
    //! whether the one-opt heuristic should be started
    constexpr Param<bool> ONEOPT { "heuristics/indicator/oneopt" };
    //! Try to improve other solutions by one-opt?
    constexpr Param<bool> IMPROVESOLS { "heuristics/indicator/improvesols" };
}
//! Parameters with prefix heuristics/intdiving
namespace HEURISTICS::INTDIVING {
    //! priority of heuristic \<intdiving\>
    constexpr Param<int> PRIORITY { "heuristics/intdiving/priority" };
    //! frequency for calling primal heuristic \<intdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/intdiving/freq" };
    //! frequency offset for calling primal heuristic \<intdiving\>
    constexpr Param<int> FREQOFS { "heuristics/intdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<intdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/intdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/intdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/intdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/intdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/intdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/intdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/intdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/intdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/intdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/intdiving/backtrack" };
}
//! Parameters with prefix heuristics/intshifting
namespace HEURISTICS::INTSHIFTING {
    //! priority of heuristic \<intshifting\>
    constexpr Param<int> PRIORITY { "heuristics/intshifting/priority" };
    //! frequency for calling primal heuristic \<intshifting\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/intshifting/freq" };
    //! frequency offset for calling primal heuristic \<intshifting\>
    constexpr Param<int> FREQOFS { "heuristics/intshifting/freqofs" };
    //! maximal depth level to call primal heuristic \<intshifting\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/intshifting/maxdepth" };
}
//! Parameters with prefix heuristics/linesearchdiving
namespace HEURISTICS::LINESEARCHDIVING {
    //! priority of heuristic \<linesearchdiving\>
    constexpr Param<int> PRIORITY { "heuristics/linesearchdiving/priority" };
    //! frequency for calling primal heuristic \<linesearchdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/linesearchdiving/freq" };
    //! frequency offset for calling primal heuristic \<linesearchdiving\>
    constexpr Param<int> FREQOFS { "heuristics/linesearchdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<linesearchdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/linesearchdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/linesearchdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/linesearchdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/linesearchdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/linesearchdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/linesearchdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/linesearchdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/linesearchdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/linesearchdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/linesearchdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/linesearchdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/linesearchdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/linesearchdiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/localbranching
namespace HEURISTICS::LOCALBRANCHING {
    //! priority of heuristic \<localbranching\>
    constexpr Param<int> PRIORITY { "heuristics/localbranching/priority" };
    //! frequency for calling primal heuristic \<localbranching\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/localbranching/freq" };
    //! frequency offset for calling primal heuristic \<localbranching\>
    constexpr Param<int> FREQOFS { "heuristics/localbranching/freqofs" };
    //! maximal depth level to call primal heuristic \<localbranching\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/localbranching/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/localbranching/nodesofs" };
    //! radius (using Manhattan metric) of the incumbent's neighborhood to be searched
    constexpr Param<int> NEIGHBORHOODSIZE { "heuristics/localbranching/neighborhoodsize" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/localbranching/nodesquot" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/localbranching/lplimfac" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/localbranching/minnodes" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/localbranching/maxnodes" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<int> NWAITINGNODES { "heuristics/localbranching/nwaitingnodes" };
    //! factor by which localbranching should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/localbranching/minimprove" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/localbranching/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/localbranching/copycuts" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/localbranching/bestsollimit" };
}
//! Parameters with prefix heuristics/locks
namespace HEURISTICS::LOCKS {
    //! priority of heuristic \<locks\>
    constexpr Param<int> PRIORITY { "heuristics/locks/priority" };
    //! frequency for calling primal heuristic \<locks\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/locks/freq" };
    //! frequency offset for calling primal heuristic \<locks\>
    constexpr Param<int> FREQOFS { "heuristics/locks/freqofs" };
    //! maximal depth level to call primal heuristic \<locks\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/locks/maxdepth" };
    //! maximum number of propagation rounds to be performed in each propagation call (-1: no limit, -2: parameter
    //! settings)
    constexpr Param<int> MAXPROPROUNDS { "heuristics/locks/maxproprounds" };
    //! minimum percentage of integer variables that have to be fixable
    constexpr Param<double> MINFIXINGRATE { "heuristics/locks/minfixingrate" };
    //! probability for rounding a variable up in case of ties
    constexpr Param<double> ROUNDUPPROBABILITY { "heuristics/locks/roundupprobability" };
    //! should a final sub-MIP be solved to costruct a feasible solution if the LP was not roundable?
    constexpr Param<bool> USEFINALSUBMIP { "heuristics/locks/usefinalsubmip" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/locks/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/locks/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/locks/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/locks/nodesquot" };
    //! factor by which locks heuristic should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/locks/minimprove" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/locks/copycuts" };
    //! should the locks be updated based on LP rows?
    constexpr Param<bool> UPDATELOCKS { "heuristics/locks/updatelocks" };
    //! minimum fixing rate over all variables (including continuous) to solve LP
    constexpr Param<double> MINFIXINGRATELP { "heuristics/locks/minfixingratelp" };
}
//! Parameters with prefix heuristics/lpface
namespace HEURISTICS::LPFACE {
    //! priority of heuristic \<lpface\>
    constexpr Param<int> PRIORITY { "heuristics/lpface/priority" };
    //! frequency for calling primal heuristic \<lpface\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/lpface/freq" };
    //! frequency offset for calling primal heuristic \<lpface\>
    constexpr Param<int> FREQOFS { "heuristics/lpface/freqofs" };
    //! maximal depth level to call primal heuristic \<lpface\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/lpface/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/lpface/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/lpface/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/lpface/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/lpface/nodesquot" };
    //! required percentage of fixed integer variables in sub-MIP to run
    constexpr Param<double> MINFIXINGRATE { "heuristics/lpface/minfixingrate" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/lpface/lplimfac" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/lpface/uselprows" };
    //! should dually nonbasic rows be turned into equations?
    constexpr Param<bool> DUALBASISEQUATIONS { "heuristics/lpface/dualbasisequations" };
    //! should the heuristic continue solving the same sub-SCIP?
    constexpr Param<bool> KEEPSUBSCIP { "heuristics/lpface/keepsubscip" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/lpface/copycuts" };
    //! objective function in the sub-SCIP: (z)ero, (r)oot-LP-difference, (i)nference, LP (f)ractionality, (o)riginal
    constexpr Param<char> SUBSCIPOBJECTIVE { "heuristics/lpface/subscipobjective" };
    //! the minimum active search tree path length along which lower bound hasn't changed before heuristic becomes
    //! active
    constexpr Param<int> MINPATHLEN { "heuristics/lpface/minpathlen" };
}
//! Parameters with prefix heuristics/mpec
namespace HEURISTICS::MPEC {
    //! priority of heuristic \<mpec\>
    constexpr Param<int> PRIORITY { "heuristics/mpec/priority" };
    //! frequency for calling primal heuristic \<mpec\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/mpec/freq" };
    //! frequency offset for calling primal heuristic \<mpec\>
    constexpr Param<int> FREQOFS { "heuristics/mpec/freqofs" };
    //! maximal depth level to call primal heuristic \<mpec\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/mpec/maxdepth" };
    //! initial regularization right-hand side value
    constexpr Param<double> INITTHETA { "heuristics/mpec/inittheta" };
    //! regularization update factor
    constexpr Param<double> SIGMA { "heuristics/mpec/sigma" };
    //! maximum number of NLP iterations per solve
    constexpr Param<double> SUBNLPTRIGGER { "heuristics/mpec/subnlptrigger" };
    //! maximum cost available for solving NLPs per call of the heuristic
    constexpr Param<double> MAXNLPCOST { "heuristics/mpec/maxnlpcost" };
    //! factor by which heuristic should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/mpec/minimprove" };
    //! minimum amount of gap left in order to call the heuristic
    constexpr Param<double> MINGAPLEFT { "heuristics/mpec/mingapleft" };
    //! maximum number of iterations of the MPEC loop
    constexpr Param<int> MAXITER { "heuristics/mpec/maxiter" };
    //! maximum number of NLP iterations per solve
    constexpr Param<int> MAXNLPITER { "heuristics/mpec/maxnlpiter" };
    //! maximum number of consecutive calls for which the heuristic did not find an improving solution
    constexpr Param<int> MAXNUNSUCC { "heuristics/mpec/maxnunsucc" };
}
//! Parameters with prefix heuristics/multistart
namespace HEURISTICS::MULTISTART {
    //! priority of heuristic \<multistart\>
    constexpr Param<int> PRIORITY { "heuristics/multistart/priority" };
    //! frequency for calling primal heuristic \<multistart\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/multistart/freq" };
    //! frequency offset for calling primal heuristic \<multistart\>
    constexpr Param<int> FREQOFS { "heuristics/multistart/freqofs" };
    //! maximal depth level to call primal heuristic \<multistart\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/multistart/maxdepth" };
    //! number of random points generated per execution call
    constexpr Param<int> NRNDPOINTS { "heuristics/multistart/nrndpoints" };
    //! maximum variable domain size for unbounded variables
    constexpr Param<double> MAXBOUNDSIZE { "heuristics/multistart/maxboundsize" };
    //! number of iterations to reduce the maximum violation of a point
    constexpr Param<int> MAXITER { "heuristics/multistart/maxiter" };
    //! minimum required improving factor to proceed in improvement of a single point
    constexpr Param<double> MINIMPRFAC { "heuristics/multistart/minimprfac" };
    //! number of iteration when checking the minimum improvement
    constexpr Param<int> MINIMPRITER { "heuristics/multistart/minimpriter" };
    //! maximum distance between two points in the same cluster
    constexpr Param<double> MAXRELDIST { "heuristics/multistart/maxreldist" };
    //! limit for gradient computations for all improvePoint() calls (0 for no limit)
    constexpr Param<double> GRADLIMIT { "heuristics/multistart/gradlimit" };
    //! maximum number of considered clusters per heuristic call
    constexpr Param<int> MAXNCLUSTER { "heuristics/multistart/maxncluster" };
    //! should the heuristic run only on continuous problems?
    constexpr Param<bool> ONLYNLPS { "heuristics/multistart/onlynlps" };
}
//! Parameters with prefix heuristics/mutation
namespace HEURISTICS::MUTATION {
    //! priority of heuristic \<mutation\>
    constexpr Param<int> PRIORITY { "heuristics/mutation/priority" };
    //! frequency for calling primal heuristic \<mutation\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/mutation/freq" };
    //! frequency offset for calling primal heuristic \<mutation\>
    constexpr Param<int> FREQOFS { "heuristics/mutation/freqofs" };
    //! maximal depth level to call primal heuristic \<mutation\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/mutation/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/mutation/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/mutation/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/mutation/minnodes" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<int> NWAITINGNODES { "heuristics/mutation/nwaitingnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/mutation/nodesquot" };
    //! percentage of integer variables that have to be fixed
    constexpr Param<double> MINFIXINGRATE { "heuristics/mutation/minfixingrate" };
    //! factor by which mutation should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/mutation/minimprove" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/mutation/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/mutation/copycuts" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/mutation/bestsollimit" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/mutation/useuct" };
}
//! Parameters with prefix heuristics/nlpdiving
namespace HEURISTICS::NLPDIVING {
    //! priority of heuristic \<nlpdiving\>
    constexpr Param<int> PRIORITY { "heuristics/nlpdiving/priority" };
    //! frequency for calling primal heuristic \<nlpdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/nlpdiving/freq" };
    //! frequency offset for calling primal heuristic \<nlpdiving\>
    constexpr Param<int> FREQOFS { "heuristics/nlpdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<nlpdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/nlpdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/nlpdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/nlpdiving/maxreldepth" };
    //! minimial absolute number of allowed NLP iterations
    constexpr Param<int> MAXNLPITERABS { "heuristics/nlpdiving/maxnlpiterabs" };
    //! additional allowed number of NLP iterations relative to successfully found solutions
    constexpr Param<int> MAXNLPITERREL { "heuristics/nlpdiving/maxnlpiterrel" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/nlpdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/nlpdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/nlpdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/nlpdiving/maxdiveavgquotnosol" };
    //! maximal number of NLPs with feasible solution to solve during one dive
    constexpr Param<int> MAXFEASNLPS { "heuristics/nlpdiving/maxfeasnlps" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/nlpdiving/backtrack" };
    //! should the LP relaxation be solved before the NLP relaxation?
    constexpr Param<bool> LP { "heuristics/nlpdiving/lp" };
    //! prefer variables that are also fractional in LP solution?
    constexpr Param<bool> PREFERLPFRACS { "heuristics/nlpdiving/preferlpfracs" };
    //! heuristic will not run if less then this percentage of calls succeeded (0.0: no limit)
    constexpr Param<double> MINSUCCQUOT { "heuristics/nlpdiving/minsuccquot" };
    //! percentage of fractional variables that should be fixed before the next NLP solve
    constexpr Param<double> FIXQUOT { "heuristics/nlpdiving/fixquot" };
    //! should variables in a minimal cover be preferred?
    constexpr Param<bool> PREFERCOVER { "heuristics/nlpdiving/prefercover" };
    //! should a sub-MIP be solved if all cover variables are fixed?
    constexpr Param<bool> SOLVESUBMIP { "heuristics/nlpdiving/solvesubmip" };
    //! should the NLP solver stop early if it converges slow?
    constexpr Param<bool> NLPFASTFAIL { "heuristics/nlpdiving/nlpfastfail" };
    //! which point should be used as starting point for the NLP solver? ('n'one, last 'f'easible, from dive's'tart)
    constexpr Param<char> NLPSTART { "heuristics/nlpdiving/nlpstart" };
    //! which variable selection should be used? ('f'ractionality, 'c'oefficient, 'p'seudocost, 'g'uided, 'd'ouble,
    //! 'v'eclen)
    constexpr Param<char> VARSELRULE { "heuristics/nlpdiving/varselrule" };
}
//! Parameters with prefix heuristics/objpscostdiving
namespace HEURISTICS::OBJPSCOSTDIVING {
    //! priority of heuristic \<objpscostdiving\>
    constexpr Param<int> PRIORITY { "heuristics/objpscostdiving/priority" };
    //! frequency for calling primal heuristic \<objpscostdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/objpscostdiving/freq" };
    //! frequency offset for calling primal heuristic \<objpscostdiving\>
    constexpr Param<int> FREQOFS { "heuristics/objpscostdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<objpscostdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/objpscostdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/objpscostdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/objpscostdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to total iteration number
    constexpr Param<double> MAXLPITERQUOT { "heuristics/objpscostdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/objpscostdiving/maxlpiterofs" };
    //! total number of feasible solutions found up to which heuristic is called (-1: no limit)
    constexpr Param<int> MAXSOLS { "heuristics/objpscostdiving/maxsols" };
    //! maximal diving depth: number of binary/integer variables times depthfac
    constexpr Param<double> DEPTHFAC { "heuristics/objpscostdiving/depthfac" };
    //! maximal diving depth factor if no feasible solution was found yet
    constexpr Param<double> DEPTHFACNOSOL { "heuristics/objpscostdiving/depthfacnosol" };
}
//! Parameters with prefix heuristics/octane
namespace HEURISTICS::OCTANE {
    //! priority of heuristic \<octane\>
    constexpr Param<int> PRIORITY { "heuristics/octane/priority" };
    //! frequency for calling primal heuristic \<octane\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/octane/freq" };
    //! frequency offset for calling primal heuristic \<octane\>
    constexpr Param<int> FREQOFS { "heuristics/octane/freqofs" };
    //! maximal depth level to call primal heuristic \<octane\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/octane/maxdepth" };
    //! number of 0-1-points to be tested as possible solutions by OCTANE
    constexpr Param<int> FMAX { "heuristics/octane/fmax" };
    //! number of 0-1-points to be tested at first whether they violate a common row
    constexpr Param<int> FFIRST { "heuristics/octane/ffirst" };
    //! execute OCTANE only in the space of fractional variables (TRUE) or in the full space?
    constexpr Param<bool> USEFRACSPACE { "heuristics/octane/usefracspace" };
    //! should the inner normal of the objective be used as one ray direction?
    constexpr Param<bool> USEOBJRAY { "heuristics/octane/useobjray" };
    //! should the average of the basic cone be used as one ray direction?
    constexpr Param<bool> USEAVGRAY { "heuristics/octane/useavgray" };
    //! should the difference between the root solution and the current LP solution be used as one ray direction?
    constexpr Param<bool> USEDIFFRAY { "heuristics/octane/usediffray" };
    //! should the weighted average of the basic cone be used as one ray direction?
    constexpr Param<bool> USEAVGWGTRAY { "heuristics/octane/useavgwgtray" };
    //! should the weighted average of the nonbasic cone be used as one ray direction?
    constexpr Param<bool> USEAVGNBRAY { "heuristics/octane/useavgnbray" };
}
//! Parameters with prefix heuristics/ofins
namespace HEURISTICS::OFINS {
    //! priority of heuristic \<ofins\>
    constexpr Param<int> PRIORITY { "heuristics/ofins/priority" };
    //! frequency for calling primal heuristic \<ofins\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/ofins/freq" };
    //! frequency offset for calling primal heuristic \<ofins\>
    constexpr Param<int> FREQOFS { "heuristics/ofins/freqofs" };
    //! maximal depth level to call primal heuristic \<ofins\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/ofins/maxdepth" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/ofins/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/ofins/minnodes" };
    //! maximal rate of changed coefficients
    constexpr Param<double> MAXCHANGERATE { "heuristics/ofins/maxchangerate" };
    //! maximal rate of change per coefficient to get fixed
    constexpr Param<double> MAXCHANGE { "heuristics/ofins/maxchange" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/ofins/copycuts" };
    //! should all subproblem solutions be added to the original SCIP?
    constexpr Param<bool> ADDALLSOLS { "heuristics/ofins/addallsols" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/ofins/nodesofs" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/ofins/nodesquot" };
    //! factor by which RENS should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/ofins/minimprove" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/ofins/lplimfac" };
}
//! Parameters with prefix heuristics/oneopt
namespace HEURISTICS::ONEOPT {
    //! priority of heuristic \<oneopt\>
    constexpr Param<int> PRIORITY { "heuristics/oneopt/priority" };
    //! frequency for calling primal heuristic \<oneopt\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/oneopt/freq" };
    //! frequency offset for calling primal heuristic \<oneopt\>
    constexpr Param<int> FREQOFS { "heuristics/oneopt/freqofs" };
    //! maximal depth level to call primal heuristic \<oneopt\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/oneopt/maxdepth" };
    //! should the objective be weighted with the potential shifting value when sorting the shifting candidates?
    constexpr Param<bool> WEIGHTEDOBJ { "heuristics/oneopt/weightedobj" };
    //! should the heuristic be called before and during the root node?
    constexpr Param<bool> DURINGROOT { "heuristics/oneopt/duringroot" };
    //! should the construction of the LP be forced even if LP solving is deactivated?
    constexpr Param<bool> FORCELPCONSTRUCTION { "heuristics/oneopt/forcelpconstruction" };
    //! should the heuristic be called before presolving?
    constexpr Param<bool> BEFOREPRESOL { "heuristics/oneopt/beforepresol" };
    //! should the heuristic continue to run as long as improvements are found?
    constexpr Param<bool> USELOOP { "heuristics/oneopt/useloop" };
}
//! Parameters with prefix heuristics/padm
namespace HEURISTICS::PADM {
    //! priority of heuristic \<padm\>
    constexpr Param<int> PRIORITY { "heuristics/padm/priority" };
    //! frequency for calling primal heuristic \<padm\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/padm/freq" };
    //! frequency offset for calling primal heuristic \<padm\>
    constexpr Param<int> FREQOFS { "heuristics/padm/freqofs" };
    //! maximal depth level to call primal heuristic \<padm\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/padm/maxdepth" };
    //! maximum number of nodes to regard in all subproblems
    constexpr Param<long long> MAXNODES { "heuristics/padm/maxnodes" };
    //! minimum number of nodes to regard in one subproblem
    constexpr Param<long long> MINNODES { "heuristics/padm/minnodes" };
    //! factor to control nodelimits of subproblems
    constexpr Param<double> NODEFAC { "heuristics/padm/nodefac" };
    //! maximal number of ADM iterations in each penalty loop
    constexpr Param<int> ADMITERATIONS { "heuristics/padm/admiterations" };
    //! maximal number of penalty iterations
    constexpr Param<int> PENALTYITERATIONS { "heuristics/padm/penaltyiterations" };
    //! mipgap at start
    constexpr Param<double> GAP { "heuristics/padm/gap" };
    //! should the problem get reoptimized with the original objective function?
    constexpr Param<bool> REOPTIMIZE { "heuristics/padm/reoptimize" };
    //! enable sigmoid rescaling of penalty parameters
    constexpr Param<bool> SCALING { "heuristics/padm/scaling" };
    //! should linking constraints be assigned?
    constexpr Param<bool> ASSIGNLINKING { "heuristics/padm/assignlinking" };
    //! should the original problem be used? This is only for testing and not recommended!
    constexpr Param<bool> ORIGINAL { "heuristics/padm/original" };
    //! should the heuristic run before or after the processing of the node? (0: before, 1: after, 2: both)
    constexpr Param<int> TIMING { "heuristics/padm/timing" };
}
//! Parameters with prefix heuristics/proximity
namespace HEURISTICS::PROXIMITY {
    //! priority of heuristic \<proximity\>
    constexpr Param<int> PRIORITY { "heuristics/proximity/priority" };
    //! frequency for calling primal heuristic \<proximity\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/proximity/freq" };
    //! frequency offset for calling primal heuristic \<proximity\>
    constexpr Param<int> FREQOFS { "heuristics/proximity/freqofs" };
    //! maximal depth level to call primal heuristic \<proximity\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/proximity/maxdepth" };
    //! should subproblem be constructed based on LP row information?
    constexpr Param<bool> USELPROWS { "heuristics/proximity/uselprows" };
    //! should the heuristic immediately run again on its newly found solution?
    constexpr Param<bool> RESTART { "heuristics/proximity/restart" };
    //! should the heuristic solve a final LP in case of continuous objective variables?
    constexpr Param<bool> USEFINALLP { "heuristics/proximity/usefinallp" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/proximity/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/proximity/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/proximity/minnodes" };
    //! maximum number of LP iterations to be performed in the subproblem
    constexpr Param<long long> MAXLPITERS { "heuristics/proximity/maxlpiters" };
    //! minimum number of LP iterations performed in subproblem
    constexpr Param<long long> MINLPITERS { "heuristics/proximity/minlpiters" };
    //! waiting nodes since last incumbent before heuristic is executed
    constexpr Param<long long> WAITINGNODES { "heuristics/proximity/waitingnodes" };
    //! factor by which proximity should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/proximity/minimprove" };
    //! sub-MIP node limit w.r.t number of original nodes
    constexpr Param<double> NODESQUOT { "heuristics/proximity/nodesquot" };
    //! threshold for percentage of binary variables required to start
    constexpr Param<double> BINVARQUOT { "heuristics/proximity/binvarquot" };
    //! quotient of sub-MIP LP iterations with respect to LP iterations so far
    constexpr Param<double> LPITERSQUOT { "heuristics/proximity/lpitersquot" };
    //! minimum primal-dual gap for which the heuristic is executed
    constexpr Param<double> MINGAP { "heuristics/proximity/mingap" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/proximity/useuct" };
}
//! Parameters with prefix heuristics/pscostdiving
namespace HEURISTICS::PSCOSTDIVING {
    //! priority of heuristic \<pscostdiving\>
    constexpr Param<int> PRIORITY { "heuristics/pscostdiving/priority" };
    //! frequency for calling primal heuristic \<pscostdiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/pscostdiving/freq" };
    //! frequency offset for calling primal heuristic \<pscostdiving\>
    constexpr Param<int> FREQOFS { "heuristics/pscostdiving/freqofs" };
    //! maximal depth level to call primal heuristic \<pscostdiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/pscostdiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/pscostdiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/pscostdiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/pscostdiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/pscostdiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/pscostdiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/pscostdiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/pscostdiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/pscostdiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/pscostdiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/pscostdiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/pscostdiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/pscostdiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/randrounding
namespace HEURISTICS::RANDROUNDING {
    //! priority of heuristic \<randrounding\>
    constexpr Param<int> PRIORITY { "heuristics/randrounding/priority" };
    //! frequency for calling primal heuristic \<randrounding\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/randrounding/freq" };
    //! frequency offset for calling primal heuristic \<randrounding\>
    constexpr Param<int> FREQOFS { "heuristics/randrounding/freqofs" };
    //! maximal depth level to call primal heuristic \<randrounding\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/randrounding/maxdepth" };
    //! should the heuristic only be called once per node?
    constexpr Param<bool> ONCEPERNODE { "heuristics/randrounding/oncepernode" };
    //! should the heuristic apply the variable lock strategy of simple rounding, if possible?
    constexpr Param<bool> USESIMPLEROUNDING { "heuristics/randrounding/usesimplerounding" };
    //! should the probing part of the heuristic be applied exclusively at the root node?
    constexpr Param<bool> PROPAGATEONLYROOT { "heuristics/randrounding/propagateonlyroot" };
    //! limit of rounds for each propagation call
    constexpr Param<int> MAXPROPROUNDS { "heuristics/randrounding/maxproprounds" };
}
//! Parameters with prefix heuristics/rens
namespace HEURISTICS::RENS {
    //! priority of heuristic \<rens\>
    constexpr Param<int> PRIORITY { "heuristics/rens/priority" };
    //! frequency for calling primal heuristic \<rens\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/rens/freq" };
    //! frequency offset for calling primal heuristic \<rens\>
    constexpr Param<int> FREQOFS { "heuristics/rens/freqofs" };
    //! maximal depth level to call primal heuristic \<rens\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/rens/maxdepth" };
    //! minimum percentage of integer variables that have to be fixable
    constexpr Param<double> MINFIXINGRATE { "heuristics/rens/minfixingrate" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/rens/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/rens/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/rens/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/rens/nodesquot" };
    //! factor by which RENS should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/rens/minimprove" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/rens/lplimfac" };
    //! solution that is used for fixing values ('l'p relaxation, 'n'lp relaxation)
    constexpr Param<char> STARTSOL { "heuristics/rens/startsol" };
    //! should general integers get binary bounds [floor(.),ceil(.)] ?
    constexpr Param<bool> BINARYBOUNDS { "heuristics/rens/binarybounds" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/rens/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/rens/copycuts" };
    //! should the RENS sub-CIP get its own full time limit? This is only for testing and not recommended!
    constexpr Param<bool> EXTRATIME { "heuristics/rens/extratime" };
    //! should all subproblem solutions be added to the original SCIP?
    constexpr Param<bool> ADDALLSOLS { "heuristics/rens/addallsols" };
    //! should the RENS sub-CIP be solved with cuts, conflicts, strong branching,... This is only for testing and not
    //! recommended!
    constexpr Param<bool> FULLSCALE { "heuristics/rens/fullscale" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/rens/bestsollimit" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/rens/useuct" };
}
//! Parameters with prefix heuristics/reoptsols
namespace HEURISTICS::REOPTSOLS {
    //! priority of heuristic \<reoptsols\>
    constexpr Param<int> PRIORITY { "heuristics/reoptsols/priority" };
    //! frequency for calling primal heuristic \<reoptsols\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/reoptsols/freq" };
    //! frequency offset for calling primal heuristic \<reoptsols\>
    constexpr Param<int> FREQOFS { "heuristics/reoptsols/freqofs" };
    //! maximal depth level to call primal heuristic \<reoptsols\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/reoptsols/maxdepth" };
    //! maximal number solutions which should be checked. (-1: all)
    constexpr Param<int> MAXSOLS { "heuristics/reoptsols/maxsols" };
    //! check solutions of the last k runs. (-1: all)
    constexpr Param<int> MAXRUNS { "heuristics/reoptsols/maxruns" };
}
//! Parameters with prefix heuristics/repair
namespace HEURISTICS::REPAIR {
    //! priority of heuristic \<repair\>
    constexpr Param<int> PRIORITY { "heuristics/repair/priority" };
    //! frequency for calling primal heuristic \<repair\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/repair/freq" };
    //! frequency offset for calling primal heuristic \<repair\>
    constexpr Param<int> FREQOFS { "heuristics/repair/freqofs" };
    //! maximal depth level to call primal heuristic \<repair\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/repair/maxdepth" };
    //! file name of a solution to be used as infeasible starting point, [-] if not available
    constexpr Param<std::string> FILENAME { "heuristics/repair/filename" };
    //! True : fractional variables which are not fractional in the given solution are rounded, FALSE : solving process
    //! of this heuristic is stopped.
    constexpr Param<bool> ROUNDIT { "heuristics/repair/roundit" };
    //! should a scaled objective function for original variables be used in repair subproblem?
    constexpr Param<bool> USEOBJFACTOR { "heuristics/repair/useobjfactor" };
    //! should variable fixings be used in repair subproblem?
    constexpr Param<bool> USEVARFIX { "heuristics/repair/usevarfix" };
    //! should slack variables be used in repair subproblem?
    constexpr Param<bool> USESLACKVARS { "heuristics/repair/useslackvars" };
    //! factor for the potential of var fixings
    constexpr Param<double> ALPHA { "heuristics/repair/alpha" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/repair/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/repair/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/repair/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/repair/nodesquot" };
    //! minimum percentage of integer variables that have to be fixed
    constexpr Param<double> MINFIXINGRATE { "heuristics/repair/minfixingrate" };
}
//! Parameters with prefix heuristics/rins
namespace HEURISTICS::RINS {
    //! priority of heuristic \<rins\>
    constexpr Param<int> PRIORITY { "heuristics/rins/priority" };
    //! frequency for calling primal heuristic \<rins\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/rins/freq" };
    //! frequency offset for calling primal heuristic \<rins\>
    constexpr Param<int> FREQOFS { "heuristics/rins/freqofs" };
    //! maximal depth level to call primal heuristic \<rins\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/rins/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/rins/nodesofs" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/rins/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/rins/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/rins/nodesquot" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<int> NWAITINGNODES { "heuristics/rins/nwaitingnodes" };
    //! factor by which rins should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/rins/minimprove" };
    //! minimum percentage of integer variables that have to be fixed
    constexpr Param<double> MINFIXINGRATE { "heuristics/rins/minfixingrate" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/rins/lplimfac" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/rins/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/rins/copycuts" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/rins/useuct" };
}
//! Parameters with prefix heuristics/rootsoldiving
namespace HEURISTICS::ROOTSOLDIVING {
    //! priority of heuristic \<rootsoldiving\>
    constexpr Param<int> PRIORITY { "heuristics/rootsoldiving/priority" };
    //! frequency for calling primal heuristic \<rootsoldiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/rootsoldiving/freq" };
    //! frequency offset for calling primal heuristic \<rootsoldiving\>
    constexpr Param<int> FREQOFS { "heuristics/rootsoldiving/freqofs" };
    //! maximal depth level to call primal heuristic \<rootsoldiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/rootsoldiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/rootsoldiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/rootsoldiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/rootsoldiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/rootsoldiving/maxlpiterofs" };
    //! total number of feasible solutions found up to which heuristic is called (-1: no limit)
    constexpr Param<int> MAXSOLS { "heuristics/rootsoldiving/maxsols" };
    //! maximal diving depth: number of binary/integer variables times depthfac
    constexpr Param<double> DEPTHFAC { "heuristics/rootsoldiving/depthfac" };
    //! maximal diving depth factor if no feasible solution was found yet
    constexpr Param<double> DEPTHFACNOSOL { "heuristics/rootsoldiving/depthfacnosol" };
    //! soft rounding factor to fade out objective coefficients
    constexpr Param<double> ALPHA { "heuristics/rootsoldiving/alpha" };
}
//! Parameters with prefix heuristics/rounding
namespace HEURISTICS::ROUNDING {
    //! priority of heuristic \<rounding\>
    constexpr Param<int> PRIORITY { "heuristics/rounding/priority" };
    //! frequency for calling primal heuristic \<rounding\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/rounding/freq" };
    //! frequency offset for calling primal heuristic \<rounding\>
    constexpr Param<int> FREQOFS { "heuristics/rounding/freqofs" };
    //! maximal depth level to call primal heuristic \<rounding\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/rounding/maxdepth" };
    //! number of calls per found solution that are considered as standard success, a higher factor causes the heuristic
    //! to be called more often
    constexpr Param<int> SUCCESSFACTOR { "heuristics/rounding/successfactor" };
    //! should the heuristic only be called once per node?
    constexpr Param<bool> ONCEPERNODE { "heuristics/rounding/oncepernode" };
}
//! Parameters with prefix heuristics/shiftandpropagate
namespace HEURISTICS::SHIFTANDPROPAGATE {
    //! priority of heuristic \<shiftandpropagate\>
    constexpr Param<int> PRIORITY { "heuristics/shiftandpropagate/priority" };
    //! frequency for calling primal heuristic \<shiftandpropagate\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/shiftandpropagate/freq" };
    //! frequency offset for calling primal heuristic \<shiftandpropagate\>
    constexpr Param<int> FREQOFS { "heuristics/shiftandpropagate/freqofs" };
    //! maximal depth level to call primal heuristic \<shiftandpropagate\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/shiftandpropagate/maxdepth" };
    //! The number of propagation rounds used for each propagation
    constexpr Param<int> NPROPROUNDS { "heuristics/shiftandpropagate/nproprounds" };
    //! Should continuous variables be relaxed?
    constexpr Param<bool> RELAX { "heuristics/shiftandpropagate/relax" };
    //! Should domains be reduced by probing?
    constexpr Param<bool> PROBING { "heuristics/shiftandpropagate/probing" };
    //! Should heuristic only be executed if no primal solution was found, yet?
    constexpr Param<bool> ONLYWITHOUTSOL { "heuristics/shiftandpropagate/onlywithoutsol" };
    //! The number of cutoffs before heuristic stops
    constexpr Param<int> CUTOFFBREAKER { "heuristics/shiftandpropagate/cutoffbreaker" };
    //! the key for variable sorting: (n)orms down, norms (u)p, (v)iolations down, viola(t)ions up, or (r)andom
    constexpr Param<char> SORTKEY { "heuristics/shiftandpropagate/sortkey" };
    //! Should variables be sorted for the heuristic?
    constexpr Param<bool> SORTVARS { "heuristics/shiftandpropagate/sortvars" };
    //! should variable statistics be collected during probing?
    constexpr Param<bool> COLLECTSTATS { "heuristics/shiftandpropagate/collectstats" };
    //! Should the heuristic stop calculating optimal shift values when no more rows are violated?
    constexpr Param<bool> STOPAFTERFEASIBLE { "heuristics/shiftandpropagate/stopafterfeasible" };
    //! Should binary variables be shifted first?
    constexpr Param<bool> PREFERBINARIES { "heuristics/shiftandpropagate/preferbinaries" };
    //! should variables with a zero shifting value be delayed instead of being fixed?
    constexpr Param<bool> NOZEROFIXING { "heuristics/shiftandpropagate/nozerofixing" };
    //! should binary variables with no locks in one direction be fixed to that direction?
    constexpr Param<bool> FIXBINLOCKS { "heuristics/shiftandpropagate/fixbinlocks" };
    //! should binary variables with no locks be preferred in the ordering?
    constexpr Param<bool> BINLOCKSFIRST { "heuristics/shiftandpropagate/binlocksfirst" };
    //! should coefficients and left/right hand sides be normalized by max row coeff?
    constexpr Param<bool> NORMALIZE { "heuristics/shiftandpropagate/normalize" };
    //! should row weight be increased every time the row is violated?
    constexpr Param<bool> UPDATEWEIGHTS { "heuristics/shiftandpropagate/updateweights" };
    //! should implicit integer variables be treated as continuous variables?
    constexpr Param<bool> IMPLISCONTINUOUS { "heuristics/shiftandpropagate/impliscontinuous" };
    //! should the heuristic choose the best candidate in every round? (set to FALSE for static order)?
    constexpr Param<bool> SELECTBEST { "heuristics/shiftandpropagate/selectbest" };
    //! maximum percentage of allowed cutoffs before stopping the heuristic
    constexpr Param<double> MAXCUTOFFQUOT { "heuristics/shiftandpropagate/maxcutoffquot" };
    //! minimum fixing rate over all variables (including continuous) to solve LP
    constexpr Param<double> MINFIXINGRATELP { "heuristics/shiftandpropagate/minfixingratelp" };
}
//! Parameters with prefix heuristics/shifting
namespace HEURISTICS::SHIFTING {
    //! priority of heuristic \<shifting\>
    constexpr Param<int> PRIORITY { "heuristics/shifting/priority" };
    //! frequency for calling primal heuristic \<shifting\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/shifting/freq" };
    //! frequency offset for calling primal heuristic \<shifting\>
    constexpr Param<int> FREQOFS { "heuristics/shifting/freqofs" };
    //! maximal depth level to call primal heuristic \<shifting\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/shifting/maxdepth" };
}
//! Parameters with prefix heuristics/simplerounding
namespace HEURISTICS::SIMPLEROUNDING {
    //! priority of heuristic \<simplerounding\>
    constexpr Param<int> PRIORITY { "heuristics/simplerounding/priority" };
    //! frequency for calling primal heuristic \<simplerounding\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/simplerounding/freq" };
    //! frequency offset for calling primal heuristic \<simplerounding\>
    constexpr Param<int> FREQOFS { "heuristics/simplerounding/freqofs" };
    //! maximal depth level to call primal heuristic \<simplerounding\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/simplerounding/maxdepth" };
    //! should the heuristic only be called once per node?
    constexpr Param<bool> ONCEPERNODE { "heuristics/simplerounding/oncepernode" };
}
//! Parameters with prefix heuristics/subnlp
namespace HEURISTICS::SUBNLP {
    //! priority of heuristic \<subnlp\>
    constexpr Param<int> PRIORITY { "heuristics/subnlp/priority" };
    //! frequency for calling primal heuristic \<subnlp\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/subnlp/freq" };
    //! frequency offset for calling primal heuristic \<subnlp\>
    constexpr Param<int> FREQOFS { "heuristics/subnlp/freqofs" };
    //! maximal depth level to call primal heuristic \<subnlp\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/subnlp/maxdepth" };
    //! verbosity level of NLP solver
    constexpr Param<int> NLPVERBLEVEL { "heuristics/subnlp/nlpverblevel" };
    //! number of nodes added to the current number of nodes when computing itercontingent (higher value runs heuristic
    //! more often in early search)
    constexpr Param<int> NODESOFFSET { "heuristics/subnlp/nodesoffset" };
    //! factor on number of nodes in SCIP (plus nodesoffset) to compute itercontingent (higher value runs heuristics
    //! more frequently)
    constexpr Param<double> NODESFACTOR { "heuristics/subnlp/nodesfactor" };
    //! exponent for power of success rate to be multiplied with itercontingent (lower value decreases impact of success
    //! rate)
    constexpr Param<double> SUCCESSRATEEXP { "heuristics/subnlp/successrateexp" };
    //! number of iterations used for initial NLP solves
    constexpr Param<int> ITERINIT { "heuristics/subnlp/iterinit" };
    //! number of successful NLP solves until switching to iterlimit guess and using success rate
    constexpr Param<int> NINITSOLVES { "heuristics/subnlp/ninitsolves" };
    //! minimal number of iterations for NLP solves
    constexpr Param<int> ITERMIN { "heuristics/subnlp/itermin" };
    //! absolute optimality tolerance to use for NLP solves
    constexpr Param<double> OPTTOL { "heuristics/subnlp/opttol" };
    //! factor on SCIP feasibility tolerance for NLP solves if resolving when NLP solution not feasible in CIP
    constexpr Param<double> FEASTOLFACTOR { "heuristics/subnlp/feastolfactor" };
    //! limit on number of presolve rounds in sub-SCIP (-1 for unlimited, 0 for no presolve)
    constexpr Param<int> MAXPRESOLVEROUNDS { "heuristics/subnlp/maxpresolverounds" };
    //! presolve emphasis in sub-SCIP (0: default, 1: aggressive, 2: fast, 3: off)
    constexpr Param<int> PRESOLVEEMPHASIS { "heuristics/subnlp/presolveemphasis" };
    //! whether to set cutoff in sub-SCIP to current primal bound
    constexpr Param<bool> SETCUTOFF { "heuristics/subnlp/setcutoff" };
    //! whether to add constraints that forbid specific fixings that turned out to be infeasible
    constexpr Param<bool> FORBIDFIXINGS { "heuristics/subnlp/forbidfixings" };
    //! whether to keep SCIP copy or to create new copy each time heuristic is applied
    constexpr Param<bool> KEEPCOPY { "heuristics/subnlp/keepcopy" };
    //! percentage of NLP solves with infeasible status required to tell NLP solver to expect an infeasible NLP
    constexpr Param<double> EXPECTINFEAS { "heuristics/subnlp/expectinfeas" };
}
//! Parameters with prefix heuristics/trivial
namespace HEURISTICS::TRIVIAL {
    //! priority of heuristic \<trivial\>
    constexpr Param<int> PRIORITY { "heuristics/trivial/priority" };
    //! frequency for calling primal heuristic \<trivial\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/trivial/freq" };
    //! frequency offset for calling primal heuristic \<trivial\>
    constexpr Param<int> FREQOFS { "heuristics/trivial/freqofs" };
    //! maximal depth level to call primal heuristic \<trivial\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/trivial/maxdepth" };
}
//! Parameters with prefix heuristics/trivialnegation
namespace HEURISTICS::TRIVIALNEGATION {
    //! priority of heuristic \<trivialnegation\>
    constexpr Param<int> PRIORITY { "heuristics/trivialnegation/priority" };
    //! frequency for calling primal heuristic \<trivialnegation\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/trivialnegation/freq" };
    //! frequency offset for calling primal heuristic \<trivialnegation\>
    constexpr Param<int> FREQOFS { "heuristics/trivialnegation/freqofs" };
    //! maximal depth level to call primal heuristic \<trivialnegation\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/trivialnegation/maxdepth" };
}
//! Parameters with prefix heuristics/trustregion
namespace HEURISTICS::TRUSTREGION {
    //! priority of heuristic \<trustregion\>
    constexpr Param<int> PRIORITY { "heuristics/trustregion/priority" };
    //! frequency for calling primal heuristic \<trustregion\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/trustregion/freq" };
    //! frequency offset for calling primal heuristic \<trustregion\>
    constexpr Param<int> FREQOFS { "heuristics/trustregion/freqofs" };
    //! maximal depth level to call primal heuristic \<trustregion\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/trustregion/maxdepth" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<int> NODESOFS { "heuristics/trustregion/nodesofs" };
    //! the number of binary variables necessary to run the heuristic
    constexpr Param<int> MINBINVARS { "heuristics/trustregion/minbinvars" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/trustregion/nodesquot" };
    //! factor by which the limit on the number of LP depends on the node limit
    constexpr Param<double> LPLIMFAC { "heuristics/trustregion/lplimfac" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<int> MINNODES { "heuristics/trustregion/minnodes" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<int> MAXNODES { "heuristics/trustregion/maxnodes" };
    //! number of nodes without incumbent change that heuristic should wait
    constexpr Param<int> NWAITINGNODES { "heuristics/trustregion/nwaitingnodes" };
    //! should subproblem be created out of the rows in the LP rows?
    constexpr Param<bool> USELPROWS { "heuristics/trustregion/uselprows" };
    //! if uselprows == FALSE, should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/trustregion/copycuts" };
    //! limit on number of improving incumbent solutions in sub-CIP
    constexpr Param<int> BESTSOLLIMIT { "heuristics/trustregion/bestsollimit" };
    //! the penalty for each change in the binary variables from the candidate solution
    constexpr Param<double> VIOLPENALTY { "heuristics/trustregion/violpenalty" };
    //! the minimum absolute improvement in the objective function value
    constexpr Param<double> OBJMINIMPROVE { "heuristics/trustregion/objminimprove" };
}
//! Parameters with prefix heuristics/trysol
namespace HEURISTICS::TRYSOL {
    //! priority of heuristic \<trysol\>
    constexpr Param<int> PRIORITY { "heuristics/trysol/priority" };
    //! frequency for calling primal heuristic \<trysol\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/trysol/freq" };
    //! frequency offset for calling primal heuristic \<trysol\>
    constexpr Param<int> FREQOFS { "heuristics/trysol/freqofs" };
    //! maximal depth level to call primal heuristic \<trysol\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/trysol/maxdepth" };
}
//! Parameters with prefix heuristics/twoopt
namespace HEURISTICS::TWOOPT {
    //! priority of heuristic \<twoopt\>
    constexpr Param<int> PRIORITY { "heuristics/twoopt/priority" };
    //! frequency for calling primal heuristic \<twoopt\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/twoopt/freq" };
    //! frequency offset for calling primal heuristic \<twoopt\>
    constexpr Param<int> FREQOFS { "heuristics/twoopt/freqofs" };
    //! maximal depth level to call primal heuristic \<twoopt\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/twoopt/maxdepth" };
    //! Should Integer-2-Optimization be applied or not?
    constexpr Param<bool> INTOPT { "heuristics/twoopt/intopt" };
    //! user parameter to determine number of nodes to wait after last best solution before calling heuristic
    constexpr Param<int> WAITINGNODES { "heuristics/twoopt/waitingnodes" };
    //! maximum number of slaves for one master variable
    constexpr Param<int> MAXNSLAVES { "heuristics/twoopt/maxnslaves" };
    //! parameter to determine the percentage of rows two variables have to share before they are considered equal
    constexpr Param<double> MATCHINGRATE { "heuristics/twoopt/matchingrate" };
}
//! Parameters with prefix heuristics/undercover
namespace HEURISTICS::UNDERCOVER {
    //! priority of heuristic \<undercover\>
    constexpr Param<int> PRIORITY { "heuristics/undercover/priority" };
    //! frequency for calling primal heuristic \<undercover\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/undercover/freq" };
    //! frequency offset for calling primal heuristic \<undercover\>
    constexpr Param<int> FREQOFS { "heuristics/undercover/freqofs" };
    //! maximal depth level to call primal heuristic \<undercover\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/undercover/maxdepth" };
    //! prioritized sequence of fixing values used ('l'p relaxation, 'n'lp relaxation, 'i'ncumbent solution)
    constexpr Param<std::string> FIXINGALTS { "heuristics/undercover/fixingalts" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/undercover/maxnodes" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/undercover/minnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/undercover/nodesofs" };
    //! weight for conflict score in fixing order
    constexpr Param<double> CONFLICTWEIGHT { "heuristics/undercover/conflictweight" };
    //! weight for cutoff score in fixing order
    constexpr Param<double> CUTOFFWEIGHT { "heuristics/undercover/cutoffweight" };
    //! weight for inference score in fixing order
    constexpr Param<double> INFERENCEWEIGHT { "heuristics/undercover/inferenceweight" };
    //! maximum coversize (as fraction of total number of variables)
    constexpr Param<double> MAXCOVERSIZEVARS { "heuristics/undercover/maxcoversizevars" };
    //! maximum coversize (as ratio to the percentage of non-affected constraints)
    constexpr Param<double> MAXCOVERSIZECONSS { "heuristics/undercover/maxcoversizeconss" };
    //! minimum percentage of nonlinear constraints in the original problem
    constexpr Param<double> MINCOVEREDREL { "heuristics/undercover/mincoveredrel" };
    //! factor by which the heuristic should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/undercover/minimprove" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/undercover/nodesquot" };
    //! fraction of covering variables in the last cover which need to change their value when recovering
    constexpr Param<double> RECOVERDIV { "heuristics/undercover/recoverdiv" };
    //! minimum number of nonlinear constraints in the original problem
    constexpr Param<int> MINCOVEREDABS { "heuristics/undercover/mincoveredabs" };
    //! maximum number of backtracks in fix-and-propagate
    constexpr Param<int> MAXBACKTRACKS { "heuristics/undercover/maxbacktracks" };
    //! maximum number of recoverings
    constexpr Param<int> MAXRECOVERS { "heuristics/undercover/maxrecovers" };
    //! maximum number of reorderings of the fixing order
    constexpr Param<int> MAXREORDERS { "heuristics/undercover/maxreorders" };
    //! objective function of the covering problem (influenced nonlinear 'c'onstraints/'t'erms, 'd'omain size, 'l'ocks,
    //! 'm'in of up/down locks, 'u'nit penalties)
    constexpr Param<char> COVERINGOBJ { "heuristics/undercover/coveringobj" };
    //! order in which variables should be fixed (increasing 'C'onflict score, decreasing 'c'onflict score, increasing
    //! 'V'ariable index, decreasing 'v'ariable index
    constexpr Param<char> FIXINGORDER { "heuristics/undercover/fixingorder" };
    //! should the heuristic be called at root node before cut separation?
    constexpr Param<bool> BEFORECUTS { "heuristics/undercover/beforecuts" };
    //! should integer variables in the cover be fixed first?
    constexpr Param<bool> FIXINTFIRST { "heuristics/undercover/fixintfirst" };
    //! shall LP values for integer vars be rounded according to locks?
    constexpr Param<bool> LOCKSROUNDING { "heuristics/undercover/locksrounding" };
    //! should we only fix variables in order to obtain a convex problem?
    constexpr Param<bool> ONLYCONVEXIFY { "heuristics/undercover/onlyconvexify" };
    //! should the NLP heuristic be called to polish a feasible solution?
    constexpr Param<bool> POSTNLP { "heuristics/undercover/postnlp" };
    //! should bounddisjunction constraints be covered (or just copied)?
    constexpr Param<bool> COVERBD { "heuristics/undercover/coverbd" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/undercover/copycuts" };
    //! shall the cover be reused if a conflict was added after an infeasible subproblem?
    constexpr Param<bool> REUSECOVER { "heuristics/undercover/reusecover" };
}
//! Parameters with prefix heuristics/vbounds
namespace HEURISTICS::VBOUNDS {
    //! priority of heuristic \<vbounds\>
    constexpr Param<int> PRIORITY { "heuristics/vbounds/priority" };
    //! frequency for calling primal heuristic \<vbounds\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/vbounds/freq" };
    //! frequency offset for calling primal heuristic \<vbounds\>
    constexpr Param<int> FREQOFS { "heuristics/vbounds/freqofs" };
    //! maximal depth level to call primal heuristic \<vbounds\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/vbounds/maxdepth" };
    //! minimum percentage of integer variables that have to be fixed
    constexpr Param<double> MININTFIXINGRATE { "heuristics/vbounds/minintfixingrate" };
    //! minimum percentage of variables that have to be fixed within sub-SCIP (integer and continuous)
    constexpr Param<double> MINMIPFIXINGRATE { "heuristics/vbounds/minmipfixingrate" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/vbounds/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/vbounds/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/vbounds/minnodes" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/vbounds/nodesquot" };
    //! factor by which vbounds heuristic should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/vbounds/minimprove" };
    //! maximum number of propagation rounds during probing (-1 infinity)
    constexpr Param<int> MAXPROPROUNDS { "heuristics/vbounds/maxproprounds" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "heuristics/vbounds/copycuts" };
    //! should more variables be fixed based on variable locks if the fixing rate was not reached?
    constexpr Param<bool> USELOCKFIXINGS { "heuristics/vbounds/uselockfixings" };
    //! maximum number of backtracks during the fixing process
    constexpr Param<int> MAXBACKTRACKS { "heuristics/vbounds/maxbacktracks" };
    //! which variants of the vbounds heuristic that try to stay feasible should be called? (0: off, 1: w/o looking at
    //! obj, 2: only fix to best bound, 4: only fix to worst bound
    constexpr Param<int> FEASVARIANT { "heuristics/vbounds/feasvariant" };
    //! which tightening variants of the vbounds heuristic should be called? (0: off, 1: w/o looking at obj, 2: only fix
    //! to best bound, 4: only fix to worst bound
    constexpr Param<int> TIGHTENVARIANT { "heuristics/vbounds/tightenvariant" };
}
//! Parameters with prefix heuristics/veclendiving
namespace HEURISTICS::VECLENDIVING {
    //! priority of heuristic \<veclendiving\>
    constexpr Param<int> PRIORITY { "heuristics/veclendiving/priority" };
    //! frequency for calling primal heuristic \<veclendiving\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/veclendiving/freq" };
    //! frequency offset for calling primal heuristic \<veclendiving\>
    constexpr Param<int> FREQOFS { "heuristics/veclendiving/freqofs" };
    //! maximal depth level to call primal heuristic \<veclendiving\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/veclendiving/maxdepth" };
    //! minimal relative depth to start diving
    constexpr Param<double> MINRELDEPTH { "heuristics/veclendiving/minreldepth" };
    //! maximal relative depth to start diving
    constexpr Param<double> MAXRELDEPTH { "heuristics/veclendiving/maxreldepth" };
    //! maximal fraction of diving LP iterations compared to node LP iterations
    constexpr Param<double> MAXLPITERQUOT { "heuristics/veclendiving/maxlpiterquot" };
    //! additional number of allowed LP iterations
    constexpr Param<int> MAXLPITEROFS { "heuristics/veclendiving/maxlpiterofs" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEUBQUOT { "heuristics/veclendiving/maxdiveubquot" };
    //! maximal quotient (curlowerbound - lowerbound)/(avglowerbound - lowerbound) where diving is performed (0.0: no
    //! limit)
    constexpr Param<double> MAXDIVEAVGQUOT { "heuristics/veclendiving/maxdiveavgquot" };
    //! maximal UBQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEUBQUOTNOSOL { "heuristics/veclendiving/maxdiveubquotnosol" };
    //! maximal AVGQUOT when no solution was found yet (0.0: no limit)
    constexpr Param<double> MAXDIVEAVGQUOTNOSOL { "heuristics/veclendiving/maxdiveavgquotnosol" };
    //! use one level of backtracking if infeasibility is encountered?
    constexpr Param<bool> BACKTRACK { "heuristics/veclendiving/backtrack" };
    //! percentage of immediate domain changes during probing to trigger LP resolve
    constexpr Param<double> LPRESOLVEDOMCHGQUOT { "heuristics/veclendiving/lpresolvedomchgquot" };
    //! LP solve frequency for diving heuristics (0: only after enough domain changes have been found)
    constexpr Param<int> LPSOLVEFREQ { "heuristics/veclendiving/lpsolvefreq" };
    //! should only LP branching candidates be considered instead of the slower but more general constraint handler
    //! diving variable selection?
    constexpr Param<bool> ONLYLPBRANCHCANDS { "heuristics/veclendiving/onlylpbranchcands" };
}
//! Parameters with prefix heuristics/zeroobj
namespace HEURISTICS::ZEROOBJ {
    //! priority of heuristic \<zeroobj\>
    constexpr Param<int> PRIORITY { "heuristics/zeroobj/priority" };
    //! frequency for calling primal heuristic \<zeroobj\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/zeroobj/freq" };
    //! frequency offset for calling primal heuristic \<zeroobj\>
    constexpr Param<int> FREQOFS { "heuristics/zeroobj/freqofs" };
    //! maximal depth level to call primal heuristic \<zeroobj\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/zeroobj/maxdepth" };
    //! maximum number of nodes to regard in the subproblem
    constexpr Param<long long> MAXNODES { "heuristics/zeroobj/maxnodes" };
    //! number of nodes added to the contingent of the total nodes
    constexpr Param<long long> NODESOFS { "heuristics/zeroobj/nodesofs" };
    //! minimum number of nodes required to start the subproblem
    constexpr Param<long long> MINNODES { "heuristics/zeroobj/minnodes" };
    //! maximum number of LP iterations to be performed in the subproblem
    constexpr Param<long long> MAXLPITERS { "heuristics/zeroobj/maxlpiters" };
    //! contingent of sub problem nodes in relation to the number of nodes of the original problem
    constexpr Param<double> NODESQUOT { "heuristics/zeroobj/nodesquot" };
    //! factor by which zeroobj should at least improve the incumbent
    constexpr Param<double> MINIMPROVE { "heuristics/zeroobj/minimprove" };
    //! should all subproblem solutions be added to the original SCIP?
    constexpr Param<bool> ADDALLSOLS { "heuristics/zeroobj/addallsols" };
    //! should heuristic only be executed if no primal solution was found, yet?
    constexpr Param<bool> ONLYWITHOUTSOL { "heuristics/zeroobj/onlywithoutsol" };
    //! should uct node selection be used at the beginning of the search?
    constexpr Param<bool> USEUCT { "heuristics/zeroobj/useuct" };
}
//! Parameters with prefix heuristics/zirounding
namespace HEURISTICS::ZIROUNDING {
    //! priority of heuristic \<zirounding\>
    constexpr Param<int> PRIORITY { "heuristics/zirounding/priority" };
    //! frequency for calling primal heuristic \<zirounding\> (-1: never, 0: only at depth freqofs)
    constexpr Param<int> FREQ { "heuristics/zirounding/freq" };
    //! frequency offset for calling primal heuristic \<zirounding\>
    constexpr Param<int> FREQOFS { "heuristics/zirounding/freqofs" };
    //! maximal depth level to call primal heuristic \<zirounding\> (-1: no limit)
    constexpr Param<int> MAXDEPTH { "heuristics/zirounding/maxdepth" };
    //! determines maximum number of rounding loops
    constexpr Param<int> MAXROUNDINGLOOPS { "heuristics/zirounding/maxroundingloops" };
    //! flag to determine if Zirounding is deactivated after a certain percentage of unsuccessful calls
    constexpr Param<bool> STOPZIROUND { "heuristics/zirounding/stopziround" };
    //! if percentage of found solutions falls below this parameter, Zirounding will be deactivated
    constexpr Param<double> STOPPERCENTAGE { "heuristics/zirounding/stoppercentage" };
    //! determines the minimum number of calls before percentage-based deactivation of Zirounding is applied
    constexpr Param<int> MINSTOPNCALLS { "heuristics/zirounding/minstopncalls" };
}
//! Parameters with prefix history
namespace HISTORY {
    //! should statistics be collected for variable domain value pairs?
    constexpr Param<bool> VALUEBASED { "history/valuebased" };
    //! should variable histories be merged from sub-SCIPs whenever possible?
    constexpr Param<bool> ALLOWMERGE { "history/allowmerge" };
    //! should variable histories be transferred to initialize SCIP copies?
    constexpr Param<bool> ALLOWTRANSFER { "history/allowtransfer" };
}
//! Parameters with prefix limits
namespace LIMITS {
    //! maximal time in seconds to run
    constexpr Param<double> TIME { "limits/time" };
    //! maximal number of nodes to process (-1: no limit)
    constexpr Param<long long> NODES { "limits/nodes" };
    //! maximal number of total nodes (incl. restarts) to process (-1: no limit)
    constexpr Param<long long> TOTALNODES { "limits/totalnodes" };
    //! solving stops, if the given number of nodes was processed since the last improvement of the primal solution
    //! value (-1: no limit)
    constexpr Param<long long> STALLNODES { "limits/stallnodes" };
    //! maximal memory usage in MB; reported memory usage is lower than real memory usage!
    constexpr Param<double> MEMORY { "limits/memory" };
    //! solving stops, if the relative gap = |primal - dual|/MIN(|dual|,|primal|) is below the given value, the gap is
    //! 'Infinity', if primal and dual bound have opposite signs
    constexpr Param<double> GAP { "limits/gap" };
    //! solving stops, if the absolute gap = |primalbound - dualbound| is below the given value
    constexpr Param<double> ABSGAP { "limits/absgap" };
    //! solving stops, if the given number of solutions were found (-1: no limit)
    constexpr Param<int> SOLUTIONS { "limits/solutions" };
    //! solving stops, if the given number of solution improvements were found (-1: no limit)
    constexpr Param<int> BESTSOL { "limits/bestsol" };
    //! maximal number of solutions to store in the solution storage
    constexpr Param<int> MAXSOL { "limits/maxsol" };
    //! maximal number of solutions candidates to store in the solution storage of the original problem
    constexpr Param<int> MAXORIGSOL { "limits/maxorigsol" };
    //! solving stops, if the given number of restarts was triggered (-1: no limit)
    constexpr Param<int> RESTARTS { "limits/restarts" };
    //! if solve exceeds this number of nodes for the first time, an automatic restart is triggered (-1: no automatic
    //! restart)
    constexpr Param<int> AUTORESTARTNODES { "limits/autorestartnodes" };
    //! soft time limit which should be applied after first solution was found (-1.0: disabled)
    constexpr Param<double> SOFTTIME { "limits/softtime" };
}
//! Parameters with prefix lp
namespace LP {
    //! frequency for solving LP at the nodes (-1: never; 0: only root LP)
    constexpr Param<int> SOLVEFREQ { "lp/solvefreq" };
    //! iteration limit for each single LP solve (-1: no limit)
    constexpr Param<long long> ITERLIM { "lp/iterlim" };
    //! iteration limit for initial root LP solve (-1: no limit)
    constexpr Param<long long> ROOTITERLIM { "lp/rootiterlim" };
    //! maximal depth for solving LP at the nodes (-1: no depth limit)
    constexpr Param<int> SOLVEDEPTH { "lp/solvedepth" };
    //! LP algorithm for solving initial LP relaxations (automatic 's'implex, 'p'rimal simplex, 'd'ual simplex,
    //! 'b'arrier, barrier with 'c'rossover)
    constexpr Param<char> INITALGORITHM { "lp/initalgorithm" };
    //! LP algorithm for resolving LP relaxations if a starting basis exists (automatic 's'implex, 'p'rimal simplex,
    //! 'd'ual simplex, 'b'arrier, barrier with 'c'rossover)
    constexpr Param<char> RESOLVEALGORITHM { "lp/resolvealgorithm" };
    //! LP pricing strategy ('l'pi default, 'a'uto, 'f'ull pricing, 'p'artial, 's'teepest edge pricing, 'q'uickstart
    //! steepest edge pricing, 'd'evex pricing)
    constexpr Param<char> PRICING { "lp/pricing" };
    //! should lp state be cleared at the end of probing mode when lp was initially unsolved, e.g., when called right
    //! after presolving?
    constexpr Param<bool> CLEARINITIALPROBINGLP { "lp/clearinitialprobinglp" };
    //! should the LP be resolved to restore the state at start of diving (if FALSE we buffer the solution values)?
    constexpr Param<bool> RESOLVERESTORE { "lp/resolverestore" };
    //! should the buffers for storing LP solution values during diving be freed at end of diving?
    constexpr Param<bool> FREESOLVALBUFFERS { "lp/freesolvalbuffers" };
    //! maximum age a dynamic column can reach before it is deleted from the LP (-1: don't delete columns due to aging)
    constexpr Param<int> COLAGELIMIT { "lp/colagelimit" };
    //! maximum age a dynamic row can reach before it is deleted from the LP (-1: don't delete rows due to aging)
    constexpr Param<int> ROWAGELIMIT { "lp/rowagelimit" };
    //! should new non-basic columns be removed after LP solving?
    constexpr Param<bool> CLEANUPCOLS { "lp/cleanupcols" };
    //! should new non-basic columns be removed after root LP solving?
    constexpr Param<bool> CLEANUPCOLSROOT { "lp/cleanupcolsroot" };
    //! should new basic rows be removed after LP solving?
    constexpr Param<bool> CLEANUPROWS { "lp/cleanuprows" };
    //! should new basic rows be removed after root LP solving?
    constexpr Param<bool> CLEANUPROWSROOT { "lp/cleanuprowsroot" };
    //! should LP solver's return status be checked for stability?
    constexpr Param<bool> CHECKSTABILITY { "lp/checkstability" };
    //! maximum condition number of LP basis counted as stable (-1.0: no limit)
    constexpr Param<double> CONDITIONLIMIT { "lp/conditionlimit" };
    //! minimal Markowitz threshold to control sparsity/stability in LU factorization
    constexpr Param<double> MINMARKOWITZ { "lp/minmarkowitz" };
    //! should LP solutions be checked for primal feasibility, resolving LP when numerical troubles occur?
    constexpr Param<bool> CHECKPRIMFEAS { "lp/checkprimfeas" };
    //! should LP solutions be checked for dual feasibility, resolving LP when numerical troubles occur?
    constexpr Param<bool> CHECKDUALFEAS { "lp/checkdualfeas" };
    //! should infeasibility proofs from the LP be checked?
    constexpr Param<bool> CHECKFARKAS { "lp/checkfarkas" };
    //! which FASTMIP setting of LP solver should be used? 0: off, 1: low
    constexpr Param<int> FASTMIP { "lp/fastmip" };
    //! LP scaling (0: none, 1: normal, 2: aggressive)
    constexpr Param<int> SCALING { "lp/scaling" };
    //! should presolving of LP solver be used?
    constexpr Param<bool> PRESOLVING { "lp/presolving" };
    //! should the lexicographic dual algorithm be used?
    constexpr Param<bool> LEXDUALALGO { "lp/lexdualalgo" };
    //! should the lexicographic dual algorithm be applied only at the root node
    constexpr Param<bool> LEXDUALROOTONLY { "lp/lexdualrootonly" };
    //! maximum number of rounds in the lexicographic dual algorithm (-1: unbounded)
    constexpr Param<int> LEXDUALMAXROUNDS { "lp/lexdualmaxrounds" };
    //! choose fractional basic variables in lexicographic dual algorithm?
    constexpr Param<bool> LEXDUALBASIC { "lp/lexdualbasic" };
    //! turn on the lex dual algorithm only when stalling?
    constexpr Param<bool> LEXDUALSTALLING { "lp/lexdualstalling" };
    //! disable the cutoff bound in the LP solver? (0: enabled, 1: disabled, 2: auto)
    constexpr Param<int> DISABLECUTOFF { "lp/disablecutoff" };
    //! simplex algorithm shall use row representation of the basis if number of rows divided by number of columns
    //! exceeds this value (-1.0 to disable row representation)
    constexpr Param<double> ROWREPSWITCH { "lp/rowrepswitch" };
    //! number of threads used for solving the LP (0: automatic)
    constexpr Param<int> THREADS { "lp/threads" };
    //! factor of average LP iterations that is used as LP iteration limit for LP resolve (-1: unlimited)
    constexpr Param<double> RESOLVEITERFAC { "lp/resolveiterfac" };
    //! minimum number of iterations that are allowed for LP resolve
    constexpr Param<int> RESOLVEITERMIN { "lp/resolveitermin" };
    //! LP solution polishing method (0: disabled, 1: only root, 2: always, 3: auto)
    constexpr Param<int> SOLUTIONPOLISHING { "lp/solutionpolishing" };
    //! LP refactorization interval (0: auto)
    constexpr Param<int> REFACTORINTERVAL { "lp/refactorinterval" };
    //! should the Farkas duals always be collected when an LP is found to be infeasible?
    constexpr Param<bool> ALWAYSGETDUALS { "lp/alwaysgetduals" };
}
//! Parameters with prefix memory
namespace MEMORY {
    //! fraction of maximal memory usage resulting in switch to memory saving mode
    constexpr Param<double> SAVEFAC { "memory/savefac" };
    //! memory growing factor for dynamically allocated arrays
    constexpr Param<double> ARRAYGROWFAC { "memory/arraygrowfac" };
    //! initial size of dynamically allocated arrays
    constexpr Param<int> ARRAYGROWINIT { "memory/arraygrowinit" };
    //! memory growing factor for tree array
    constexpr Param<double> TREEGROWFAC { "memory/treegrowfac" };
    //! initial size of tree array
    constexpr Param<int> TREEGROWINIT { "memory/treegrowinit" };
    //! memory growing factor for path array
    constexpr Param<double> PATHGROWFAC { "memory/pathgrowfac" };
    //! initial size of path array
    constexpr Param<int> PATHGROWINIT { "memory/pathgrowinit" };
}
//! Parameters with prefix misc
namespace MISC {
    //! should the CTRL-C interrupt be caught by SCIP?
    constexpr Param<bool> CATCHCTRLC { "misc/catchctrlc" };
    //! should a hashtable be used to map from variable names to variables?
    constexpr Param<bool> USEVARTABLE { "misc/usevartable" };
    //! should a hashtable be used to map from constraint names to constraints?
    constexpr Param<bool> USECONSTABLE { "misc/useconstable" };
    //! should smaller hashtables be used? yields better performance for small problems with about 100 variables
    constexpr Param<bool> USESMALLTABLES { "misc/usesmalltables" };
    //! should the statistics be reset if the transformed problem is freed (in case of a Benders' decomposition this
    //! parameter should be set to FALSE)
    constexpr Param<bool> RESETSTAT { "misc/resetstat" };
    //! should only solutions be checked which improve the primal bound
    constexpr Param<bool> IMPROVINGSOLS { "misc/improvingsols" };
    //! should the reason be printed if a given start solution is infeasible
    constexpr Param<bool> PRINTREASON { "misc/printreason" };
    //! should the usage of external memory be estimated?
    constexpr Param<bool> ESTIMEXTERNMEM { "misc/estimexternmem" };
    //! try to avoid running into memory limit by restricting plugins like heuristics?
    constexpr Param<bool> AVOIDMEMOUT { "misc/avoidmemout" };
    //! should SCIP try to transfer original solutions to the transformed space (after presolving)?
    constexpr Param<bool> TRANSORIGSOLS { "misc/transorigsols" };
    //! should SCIP try to transfer transformed solutions to the original space (after solving)?
    constexpr Param<bool> TRANSSOLSORIG { "misc/transsolsorig" };
    //! should SCIP calculate the primal dual integral value?
    constexpr Param<bool> CALCINTEGRAL { "misc/calcintegral" };
    //! should SCIP try to remove infinite fixings from solutions copied to the solution store?
    constexpr Param<bool> FINITESOLUTIONSTORE { "misc/finitesolutionstore" };
    //! should the best solution be transformed to the orignal space and be output in command line run?
    constexpr Param<bool> OUTPUTORIGSOL { "misc/outputorigsol" };
    //! should strong dual reductions be allowed in propagation and presolving?
    constexpr Param<bool> ALLOWSTRONGDUALREDS { "misc/allowstrongdualreds" };
    //! should weak dual reductions be allowed in propagation and presolving?
    constexpr Param<bool> ALLOWWEAKDUALREDS { "misc/allowweakdualreds" };
    //! should the objective function be scaled so that it is always integer?
    constexpr Param<bool> SCALEOBJ { "misc/scaleobj" };
    //! should detailed statistics for diving heuristics be shown?
    constexpr Param<bool> SHOWDIVINGSTATS { "misc/showdivingstats" };
    //! objective value for reference purposes
    constexpr Param<double> REFERENCEVALUE { "misc/referencevalue" };
    //! bitset describing used symmetry handling technique (0: off; 1: polyhedral (orbitopes and/or symresacks); 2:
    //! orbital fixing; 3: orbitopes and orbital fixing; 4: Schreier Sims cuts; 5: Schreier Sims cuts and orbitopes); 6:
    //! Schreier Sims cuts and orbital fixing; 7: Schreier Sims cuts, orbitopes, and orbital fixing, see
    //! type_symmetry.h.
    constexpr Param<int> USESYMMETRY { "misc/usesymmetry" };
}
//! Parameters with prefix nlhdlr/bilinear
namespace NLHDLR::BILINEAR {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/bilinear/enabled" };
    //! whether to use the interval evaluation callback of the nlhdlr
    constexpr Param<bool> USEINTEVAL { "nlhdlr/bilinear/useinteval" };
    //! whether to use the reverse propagation callback of the nlhdlr
    constexpr Param<bool> USEREVERSEPROP { "nlhdlr/bilinear/usereverseprop" };
    //! maximum number of separation rounds in the root node
    constexpr Param<int> MAXSEPAROUNDSROOT { "nlhdlr/bilinear/maxseparoundsroot" };
    //! maximum number of separation rounds in a local node
    constexpr Param<int> MAXSEPAROUNDS { "nlhdlr/bilinear/maxseparounds" };
    //! maximum depth to apply separation
    constexpr Param<int> MAXSEPADEPTH { "nlhdlr/bilinear/maxsepadepth" };
}
//! Parameters with prefix nlhdlr/concave
namespace NLHDLR::CONCAVE {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/concave/enabled" };
    //! whether to run convexity detection when the root of an expression is a sum
    constexpr Param<bool> DETECTSUM { "nlhdlr/concave/detectsum" };
    //! whether to use convexity check on quadratics
    constexpr Param<bool> CVXQUADRATIC { "nlhdlr/concave/cvxquadratic" };
    //! whether to use convexity check on signomials
    constexpr Param<bool> CVXSIGNOMIAL { "nlhdlr/concave/cvxsignomial" };
    //! whether to use convexity check on product composition f(h)*h
    constexpr Param<bool> CVXPRODCOMP { "nlhdlr/concave/cvxprodcomp" };
    //! whether to also handle trivial convex expressions
    constexpr Param<bool> HANDLETRIVIAL { "nlhdlr/concave/handletrivial" };
}
//! Parameters with prefix nlhdlr/convex
namespace NLHDLR::CONVEX {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/convex/enabled" };
    //! whether to run convexity detection when the root of an expression is a non-quadratic sum
    constexpr Param<bool> DETECTSUM { "nlhdlr/convex/detectsum" };
    //! whether to create extended formulations instead of looking for maximal convex expressions
    constexpr Param<bool> EXTENDEDFORM { "nlhdlr/convex/extendedform" };
    //! whether to use convexity check on quadratics
    constexpr Param<bool> CVXQUADRATIC { "nlhdlr/convex/cvxquadratic" };
    //! whether to use convexity check on signomials
    constexpr Param<bool> CVXSIGNOMIAL { "nlhdlr/convex/cvxsignomial" };
    //! whether to use convexity check on product composition f(h)*h
    constexpr Param<bool> CVXPRODCOMP { "nlhdlr/convex/cvxprodcomp" };
    //! whether to also handle trivial convex expressions
    constexpr Param<bool> HANDLETRIVIAL { "nlhdlr/convex/handletrivial" };
}
//! Parameters with prefix nlhdlr/default
namespace NLHDLR::DEFAULT {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/default/enabled" };
}
//! Parameters with prefix nlhdlr/perspective
namespace NLHDLR::PERSPECTIVE {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/perspective/enabled" };
    //! maximal number of propagation rounds in probing
    constexpr Param<int> MAXPROPROUNDS { "nlhdlr/perspective/maxproprounds" };
    //! minimal relative reduction in a variable's domain for applying probing
    constexpr Param<double> MINDOMREDUCTION { "nlhdlr/perspective/mindomreduction" };
    //! minimal violation w.r.t. auxiliary variables for applying probing
    constexpr Param<double> MINVIOLPROBING { "nlhdlr/perspective/minviolprobing" };
    //! whether to do probing only in separation
    constexpr Param<bool> PROBINGONLYINSEPA { "nlhdlr/perspective/probingonlyinsepa" };
    //! probing frequency (-1 - no probing, 0 - root node only)
    constexpr Param<int> PROBINGFREQ { "nlhdlr/perspective/probingfreq" };
    //! whether perspective cuts are added only for convex expressions
    constexpr Param<bool> CONVEXONLY { "nlhdlr/perspective/convexonly" };
    //! whether variable semicontinuity is used to tighten variable bounds
    constexpr Param<bool> TIGHTENBOUNDS { "nlhdlr/perspective/tightenbounds" };
    //! whether to adjust the reference point
    constexpr Param<bool> ADJREFPOINT { "nlhdlr/perspective/adjrefpoint" };
}
//! Parameters with prefix nlhdlr/quadratic
namespace NLHDLR::QUADRATIC {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/quadratic/enabled" };
    //! whether to use intersection cuts for quadratic constraints to separate
    constexpr Param<bool> USEINTERSECTIONCUTS { "nlhdlr/quadratic/useintersectioncuts" };
    //! whether the strengthening should be used
    constexpr Param<bool> USESTRENGTHENING { "nlhdlr/quadratic/usestrengthening" };
    //! use bounds of variables in quadratic as rays for intersection cuts
    constexpr Param<bool> USEBOUNDSASRAYS { "nlhdlr/quadratic/useboundsasrays" };
    //! limit for number of cuts generated consecutively
    constexpr Param<int> NCUTSLIMIT { "nlhdlr/quadratic/ncutslimit" };
    //! limit for number of cuts generated at root node
    constexpr Param<int> NCUTSLIMITROOT { "nlhdlr/quadratic/ncutslimitroot" };
    //! maximal rank a slackvar can have
    constexpr Param<int> MAXRANK { "nlhdlr/quadratic/maxrank" };
    //! minimal cut violation the generated cuts must fulfill to be added to the LP
    constexpr Param<double> MINCUTVIOLATION { "nlhdlr/quadratic/mincutviolation" };
    //! minimal violation the constraint must fulfill such that a cut is generated
    constexpr Param<double> MINVIOLATION { "nlhdlr/quadratic/minviolation" };
    //! determines at which nodes cut is used (if it's -1, it's used only at the root node, if it's n \>= 0, it's used
    //! at every multiple of n
    constexpr Param<int> ATWHICHNODES { "nlhdlr/quadratic/atwhichnodes" };
    //! limit for number of rays we do the strengthening for
    constexpr Param<int> NSTRENGTHLIMIT { "nlhdlr/quadratic/nstrengthlimit" };
    //! should cut be generated even with bad numerics when restricting to ray?
    constexpr Param<bool> IGNOREBADRAYRESTRICTION { "nlhdlr/quadratic/ignorebadrayrestriction" };
    //! should cut be added even when range / efficacy is large?
    constexpr Param<bool> IGNORENHIGHRE { "nlhdlr/quadratic/ignorenhighre" };
}
//! Parameters with prefix nlhdlr/quotient
namespace NLHDLR::QUOTIENT {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/quotient/enabled" };
}
//! Parameters with prefix nlhdlr/soc
namespace NLHDLR::SOC {
    //! should this nonlinear handler be used
    constexpr Param<bool> ENABLED { "nlhdlr/soc/enabled" };
    //! Minimum efficacy which a cut needs in order to be added.
    constexpr Param<double> MINCUTEFFICACY { "nlhdlr/soc/mincutefficacy" };
    //! Should Eigenvalue computations be done to detect complex cases in quadratic constraints?
    constexpr Param<bool> COMPEIGENVALUES { "nlhdlr/soc/compeigenvalues" };
}
//! Parameters with prefix nlp
namespace NLP {
    //! solver to use for solving NLPs; leave empty to select NLPI with highest priority
    constexpr Param<std::string> SOLVER { "nlp/solver" };
    //! should the NLP relaxation be always disabled (also for NLPs/MINLPs)?
    constexpr Param<bool> DISABLE { "nlp/disable" };
}
//! Parameters with prefix nodeselection
namespace NODESELECTION {
    //! child selection rule ('d'own, 'u'p, 'p'seudo costs, 'i'nference, 'l'p value, 'r'oot LP value difference,
    //! 'h'ybrid inference/root LP value difference)
    constexpr Param<char> CHILDSEL { "nodeselection/childsel" };
}
//! Parameters with prefix nodeselection/bfs
namespace NODESELECTION::BFS {
    //! priority of node selection rule \<bfs\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/bfs/stdpriority" };
    //! priority of node selection rule \<bfs\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/bfs/memsavepriority" };
    //! minimal plunging depth, before new best node may be selected (-1 for dynamic setting)
    constexpr Param<int> MINPLUNGEDEPTH { "nodeselection/bfs/minplungedepth" };
    //! maximal plunging depth, before new best node is forced to be selected (-1 for dynamic setting)
    constexpr Param<int> MAXPLUNGEDEPTH { "nodeselection/bfs/maxplungedepth" };
    //! maximal quotient (curlowerbound - lowerbound)/(cutoffbound - lowerbound) where plunging is performed
    constexpr Param<double> MAXPLUNGEQUOT { "nodeselection/bfs/maxplungequot" };
}
//! Parameters with prefix nodeselection/breadthfirst
namespace NODESELECTION::BREADTHFIRST {
    //! priority of node selection rule \<breadthfirst\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/breadthfirst/stdpriority" };
    //! priority of node selection rule \<breadthfirst\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/breadthfirst/memsavepriority" };
}
//! Parameters with prefix nodeselection/dfs
namespace NODESELECTION::DFS {
    //! priority of node selection rule \<dfs\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/dfs/stdpriority" };
    //! priority of node selection rule \<dfs\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/dfs/memsavepriority" };
}
//! Parameters with prefix nodeselection/estimate
namespace NODESELECTION::ESTIMATE {
    //! priority of node selection rule \<estimate\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/estimate/stdpriority" };
    //! priority of node selection rule \<estimate\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/estimate/memsavepriority" };
    //! minimal plunging depth, before new best node may be selected (-1 for dynamic setting)
    constexpr Param<int> MINPLUNGEDEPTH { "nodeselection/estimate/minplungedepth" };
    //! maximal plunging depth, before new best node is forced to be selected (-1 for dynamic setting)
    constexpr Param<int> MAXPLUNGEDEPTH { "nodeselection/estimate/maxplungedepth" };
    //! maximal quotient (estimate - lowerbound)/(cutoffbound - lowerbound) where plunging is performed
    constexpr Param<double> MAXPLUNGEQUOT { "nodeselection/estimate/maxplungequot" };
    //! frequency at which the best node instead of the best estimate is selected (0: never)
    constexpr Param<int> BESTNODEFREQ { "nodeselection/estimate/bestnodefreq" };
    //! depth until breadth-first search is applied
    constexpr Param<int> BREADTHFIRSTDEPTH { "nodeselection/estimate/breadthfirstdepth" };
    //! number of nodes before doing plunging the first time
    constexpr Param<int> PLUNGEOFFSET { "nodeselection/estimate/plungeoffset" };
}
//! Parameters with prefix nodeselection/hybridestim
namespace NODESELECTION::HYBRIDESTIM {
    //! priority of node selection rule \<hybridestim\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/hybridestim/stdpriority" };
    //! priority of node selection rule \<hybridestim\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/hybridestim/memsavepriority" };
    //! minimal plunging depth, before new best node may be selected (-1 for dynamic setting)
    constexpr Param<int> MINPLUNGEDEPTH { "nodeselection/hybridestim/minplungedepth" };
    //! maximal plunging depth, before new best node is forced to be selected (-1 for dynamic setting)
    constexpr Param<int> MAXPLUNGEDEPTH { "nodeselection/hybridestim/maxplungedepth" };
    //! maximal quotient (estimate - lowerbound)/(cutoffbound - lowerbound) where plunging is performed
    constexpr Param<double> MAXPLUNGEQUOT { "nodeselection/hybridestim/maxplungequot" };
    //! frequency at which the best node instead of the hybrid best estimate / best bound is selected (0: never)
    constexpr Param<int> BESTNODEFREQ { "nodeselection/hybridestim/bestnodefreq" };
    //! weight of estimate value in node selection score (0: pure best bound search, 1: pure best estimate search)
    constexpr Param<double> ESTIMWEIGHT { "nodeselection/hybridestim/estimweight" };
}
//! Parameters with prefix nodeselection/restartdfs
namespace NODESELECTION::RESTARTDFS {
    //! priority of node selection rule \<restartdfs\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/restartdfs/stdpriority" };
    //! priority of node selection rule \<restartdfs\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/restartdfs/memsavepriority" };
    //! frequency for selecting the best node instead of the deepest one
    constexpr Param<int> SELECTBESTFREQ { "nodeselection/restartdfs/selectbestfreq" };
    //! count only leaf nodes (otherwise all nodes)?
    constexpr Param<bool> COUNTONLYLEAVES { "nodeselection/restartdfs/countonlyleaves" };
}
//! Parameters with prefix nodeselection/uct
namespace NODESELECTION::UCT {
    //! priority of node selection rule \<uct\> in standard mode
    constexpr Param<int> STDPRIORITY { "nodeselection/uct/stdpriority" };
    //! priority of node selection rule \<uct\> in memory saving mode
    constexpr Param<int> MEMSAVEPRIORITY { "nodeselection/uct/memsavepriority" };
    //! maximum number of nodes before switching to default rule
    constexpr Param<int> NODELIMIT { "nodeselection/uct/nodelimit" };
    //! weight for visit quotient of node selection rule
    constexpr Param<double> WEIGHT { "nodeselection/uct/weight" };
    //! should the estimate (TRUE) or lower bound of a node be used for UCT score?
    constexpr Param<bool> USEESTIMATE { "nodeselection/uct/useestimate" };
}
//! Parameters with prefix numerics
namespace NUMERICS {
    //! values larger than this are considered infinity
    constexpr Param<double> INFINITY { "numerics/infinity" };
    //! absolute values smaller than this are considered zero
    constexpr Param<double> EPSILON { "numerics/epsilon" };
    //! absolute values of sums smaller than this are considered zero
    constexpr Param<double> SUMEPSILON { "numerics/sumepsilon" };
    //! feasibility tolerance for constraints
    constexpr Param<double> FEASTOL { "numerics/feastol" };
    //! feasibility tolerance factor; for checking the feasibility of the best solution
    constexpr Param<double> CHECKFEASTOLFAC { "numerics/checkfeastolfac" };
    //! factor w.r.t. primal feasibility tolerance that determines default (and maximal) primal feasibility tolerance of
    //! LP solver
    constexpr Param<double> LPFEASTOLFACTOR { "numerics/lpfeastolfactor" };
    //! feasibility tolerance for reduced costs in LP solution
    constexpr Param<double> DUALFEASTOL { "numerics/dualfeastol" };
    //! LP convergence tolerance used in barrier algorithm
    constexpr Param<double> BARRIERCONVTOL { "numerics/barrierconvtol" };
    //! minimal relative improve for strengthening bounds
    constexpr Param<double> BOUNDSTREPS { "numerics/boundstreps" };
    //! minimal variable distance value to use for branching pseudo cost updates
    constexpr Param<double> PSEUDOCOSTEPS { "numerics/pseudocosteps" };
    //! minimal objective distance value to use for branching pseudo cost updates
    constexpr Param<double> PSEUDOCOSTDELTA { "numerics/pseudocostdelta" };
    //! minimal decrease factor that causes the recomputation of a value (e.g., pseudo objective) instead of an update
    constexpr Param<double> RECOMPUTEFAC { "numerics/recomputefac" };
    //! values larger than this are considered huge and should be handled separately (e.g., in activity computation)
    constexpr Param<double> HUGEVAL { "numerics/hugeval" };
}
//! Parameters with prefix parallel
namespace PARALLEL {
    //! parallel optimisation mode, 0: opportunistic or 1: deterministic.
    constexpr Param<int> MODE { "parallel/mode" };
    //! the minimum number of threads used during parallel solve
    constexpr Param<int> MINNTHREADS { "parallel/minnthreads" };
    //! the maximum number of threads used during parallel solve
    constexpr Param<int> MAXNTHREADS { "parallel/maxnthreads" };
}
//! Parameters with prefix presolving
namespace PRESOLVING {
    //! maximal number of presolving rounds (-1: unlimited, 0: off)
    constexpr Param<int> MAXROUNDS { "presolving/maxrounds" };
    //! abort presolve, if at most this fraction of the problem was changed in last presolve round
    constexpr Param<double> ABORTFAC { "presolving/abortfac" };
    //! maximal number of restarts (-1: unlimited)
    constexpr Param<int> MAXRESTARTS { "presolving/maxrestarts" };
    //! fraction of integer variables that were fixed in the root node triggering a restart with preprocessing after
    //! root node evaluation
    constexpr Param<double> RESTARTFAC { "presolving/restartfac" };
    //! limit on number of entries in clique table relative to number of problem nonzeros
    constexpr Param<double> CLQTABLEFAC { "presolving/clqtablefac" };
    //! fraction of integer variables that were fixed in the root node triggering an immediate restart with
    //! preprocessing
    constexpr Param<double> IMMRESTARTFAC { "presolving/immrestartfac" };
    //! fraction of integer variables that were globally fixed during the solving process triggering a restart with
    //! preprocessing
    constexpr Param<double> SUBRESTARTFAC { "presolving/subrestartfac" };
    //! minimal fraction of integer variables removed after restart to allow for an additional restart
    constexpr Param<double> RESTARTMINRED { "presolving/restartminred" };
    //! should multi-aggregation of variables be forbidden?
    constexpr Param<bool> DONOTMULTAGGR { "presolving/donotmultaggr" };
    //! should aggregation of variables be forbidden?
    constexpr Param<bool> DONOTAGGR { "presolving/donotaggr" };
}
//! Parameters with prefix presolving/boundshift
namespace PRESOLVING::BOUNDSHIFT {
    //! priority of presolver \<boundshift\>
    constexpr Param<int> PRIORITY { "presolving/boundshift/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/boundshift/maxrounds" };
    //! timing mask of presolver \<boundshift\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/boundshift/timing" };
    //! absolute value of maximum shift
    constexpr Param<long long> MAXSHIFT { "presolving/boundshift/maxshift" };
    //! is flipping allowed (multiplying with -1)?
    constexpr Param<bool> FLIPPING { "presolving/boundshift/flipping" };
    //! shift only integer ranges?
    constexpr Param<bool> INTEGER { "presolving/boundshift/integer" };
}
//! Parameters with prefix presolving/convertinttobin
namespace PRESOLVING::CONVERTINTTOBIN {
    //! priority of presolver \<convertinttobin\>
    constexpr Param<int> PRIORITY { "presolving/convertinttobin/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/convertinttobin/maxrounds" };
    //! timing mask of presolver \<convertinttobin\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/convertinttobin/timing" };
    //! absolute value of maximum domain size for converting an integer variable to binaries variables
    constexpr Param<long long> MAXDOMAINSIZE { "presolving/convertinttobin/maxdomainsize" };
    //! should only integer variables with a domain size of 2^p - 1 be converted(, there we don't need an
    //! knapsack-constraint for restricting the sum of the binaries)
    constexpr Param<bool> ONLYPOWEROFTWO { "presolving/convertinttobin/onlypoweroftwo" };
    //! should only integer variables with uplocks equals downlocks be converted
    constexpr Param<bool> SAMELOCKSINBOTHDIRECTIONS { "presolving/convertinttobin/samelocksinbothdirections" };
}
//! Parameters with prefix presolving/domcol
namespace PRESOLVING::DOMCOL {
    //! priority of presolver \<domcol\>
    constexpr Param<int> PRIORITY { "presolving/domcol/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/domcol/maxrounds" };
    //! timing mask of presolver \<domcol\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/domcol/timing" };
    //! minimal number of pair comparisons
    constexpr Param<int> NUMMINPAIRS { "presolving/domcol/numminpairs" };
    //! maximal number of pair comparisons
    constexpr Param<int> NUMMAXPAIRS { "presolving/domcol/nummaxpairs" };
    //! should predictive bound strengthening be applied?
    constexpr Param<bool> PREDBNDSTR { "presolving/domcol/predbndstr" };
    //! should reductions for continuous variables be performed?
    constexpr Param<bool> CONTINUOUSRED { "presolving/domcol/continuousred" };
}
//! Parameters with prefix presolving/dualagg
namespace PRESOLVING::DUALAGG {
    //! priority of presolver \<dualagg\>
    constexpr Param<int> PRIORITY { "presolving/dualagg/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/dualagg/maxrounds" };
    //! timing mask of presolver \<dualagg\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/dualagg/timing" };
}
//! Parameters with prefix presolving/dualcomp
namespace PRESOLVING::DUALCOMP {
    //! priority of presolver \<dualcomp\>
    constexpr Param<int> PRIORITY { "presolving/dualcomp/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/dualcomp/maxrounds" };
    //! timing mask of presolver \<dualcomp\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/dualcomp/timing" };
    //! should only discrete variables be compensated?
    constexpr Param<bool> COMPONLYDISVARS { "presolving/dualcomp/componlydisvars" };
}
//! Parameters with prefix presolving/dualinfer
namespace PRESOLVING::DUALINFER {
    //! priority of presolver \<dualinfer\>
    constexpr Param<int> PRIORITY { "presolving/dualinfer/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/dualinfer/maxrounds" };
    //! timing mask of presolver \<dualinfer\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/dualinfer/timing" };
    //! use convex combination of columns for determining dual bounds
    constexpr Param<bool> TWOCOLCOMBINE { "presolving/dualinfer/twocolcombine" };
    //! maximal number of dual bound strengthening loops
    constexpr Param<int> MAXDUALBNDLOOPS { "presolving/dualinfer/maxdualbndloops" };
    //! maximal number of considered non-zeros within one column (-1: no limit)
    constexpr Param<int> MAXCONSIDEREDNONZEROS { "presolving/dualinfer/maxconsiderednonzeros" };
    //! maximal number of consecutive useless hashtable retrieves
    constexpr Param<int> MAXRETRIEVEFAILS { "presolving/dualinfer/maxretrievefails" };
    //! maximal number of consecutive useless column combines
    constexpr Param<int> MAXCOMBINEFAILS { "presolving/dualinfer/maxcombinefails" };
    //! Maximum number of hashlist entries as multiple of number of columns in the problem (-1: no limit)
    constexpr Param<int> MAXHASHFAC { "presolving/dualinfer/maxhashfac" };
    //! Maximum number of processed column pairs as multiple of the number of columns in the problem (-1: no limit)
    constexpr Param<int> MAXPAIRFAC { "presolving/dualinfer/maxpairfac" };
    //! Maximum number of row's non-zeros for changing inequality to equality
    constexpr Param<int> MAXROWSUPPORT { "presolving/dualinfer/maxrowsupport" };
}
//! Parameters with prefix presolving/dualsparsify
namespace PRESOLVING::DUALSPARSIFY {
    //! priority of presolver \<dualsparsify\>
    constexpr Param<int> PRIORITY { "presolving/dualsparsify/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/dualsparsify/maxrounds" };
    //! timing mask of presolver \<dualsparsify\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/dualsparsify/timing" };
    //! should dualsparsify presolver be copied to sub-SCIPs?
    constexpr Param<bool> ENABLECOPY { "presolving/dualsparsify/enablecopy" };
    //! should we forbid cancellations that destroy integer coefficients?
    constexpr Param<bool> PRESERVEINTCOEFS { "presolving/dualsparsify/preserveintcoefs" };
    //! should we preserve good locked properties of variables (at most one lock in one direction)?
    constexpr Param<bool> PRESERVEGOODLOCKS { "presolving/dualsparsify/preservegoodlocks" };
    //! maximal fillin for continuous variables (-1: unlimited)
    constexpr Param<int> MAXCONTFILLIN { "presolving/dualsparsify/maxcontfillin" };
    //! maximal fillin for binary variables (-1: unlimited)
    constexpr Param<int> MAXBINFILLIN { "presolving/dualsparsify/maxbinfillin" };
    //! maximal fillin for integer variables including binaries (-1: unlimited)
    constexpr Param<int> MAXINTFILLIN { "presolving/dualsparsify/maxintfillin" };
    //! maximal number of considered nonzeros within one column (-1: no limit)
    constexpr Param<int> MAXCONSIDEREDNONZEROS { "presolving/dualsparsify/maxconsiderednonzeros" };
    //! minimal eliminated nonzeros within one column if we need to add a constraint to the problem
    constexpr Param<int> MINELIMINATEDNONZEROS { "presolving/dualsparsify/mineliminatednonzeros" };
    //! limit on the number of useless vs. useful hashtable retrieves as a multiple of the number of constraints
    constexpr Param<double> MAXRETRIEVEFAC { "presolving/dualsparsify/maxretrievefac" };
    //! number of calls to wait until next execution as a multiple of the number of useless calls
    constexpr Param<double> WAITINGFAC { "presolving/dualsparsify/waitingfac" };
}
//! Parameters with prefix presolving/gateextraction
namespace PRESOLVING::GATEEXTRACTION {
    //! priority of presolver \<gateextraction\>
    constexpr Param<int> PRIORITY { "presolving/gateextraction/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/gateextraction/maxrounds" };
    //! timing mask of presolver \<gateextraction\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/gateextraction/timing" };
    //! should we only try to extract set-partitioning constraints and no and-constraints
    constexpr Param<bool> ONLYSETPART { "presolving/gateextraction/onlysetpart" };
    //! should we try to extract set-partitioning constraint out of one logicor and one corresponding set-packing
    //! constraint
    constexpr Param<bool> SEARCHEQUATIONS { "presolving/gateextraction/searchequations" };
    //! order logicor contraints to extract big-gates before smaller ones (-1), do not order them (0) or order them to
    //! extract smaller gates at first (1)
    constexpr Param<int> SORTING { "presolving/gateextraction/sorting" };
}
//! Parameters with prefix presolving/implics
namespace PRESOLVING::IMPLICS {
    //! priority of presolver \<implics\>
    constexpr Param<int> PRIORITY { "presolving/implics/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/implics/maxrounds" };
    //! timing mask of presolver \<implics\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/implics/timing" };
}
//! Parameters with prefix presolving/inttobinary
namespace PRESOLVING::INTTOBINARY {
    //! priority of presolver \<inttobinary\>
    constexpr Param<int> PRIORITY { "presolving/inttobinary/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/inttobinary/maxrounds" };
    //! timing mask of presolver \<inttobinary\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/inttobinary/timing" };
}
//! Parameters with prefix presolving/qpkktref
namespace PRESOLVING::QPKKTREF {
    //! priority of presolver \<qpkktref\>
    constexpr Param<int> PRIORITY { "presolving/qpkktref/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/qpkktref/maxrounds" };
    //! timing mask of presolver \<qpkktref\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/qpkktref/timing" };
    //! if TRUE then allow binary variables for KKT update
    constexpr Param<bool> ADDKKTBINARY { "presolving/qpkktref/addkktbinary" };
    //! if TRUE then only apply the update to QPs with bounded variables; if the variables are not bounded then a finite
    //! optimal solution might not exist and the KKT conditions would then be invalid
    constexpr Param<bool> UPDATEQUADBOUNDED { "presolving/qpkktref/updatequadbounded" };
    //! if TRUE then apply quadratic constraint update even if the quadratic constraint matrix is known to be indefinite
    constexpr Param<bool> UPDATEQUADINDEF { "presolving/qpkktref/updatequadindef" };
}
//! Parameters with prefix presolving/redvub
namespace PRESOLVING::REDVUB {
    //! priority of presolver \<redvub\>
    constexpr Param<int> PRIORITY { "presolving/redvub/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/redvub/maxrounds" };
    //! timing mask of presolver \<redvub\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/redvub/timing" };
}
//! Parameters with prefix presolving/sparsify
namespace PRESOLVING::SPARSIFY {
    //! priority of presolver \<sparsify\>
    constexpr Param<int> PRIORITY { "presolving/sparsify/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/sparsify/maxrounds" };
    //! timing mask of presolver \<sparsify\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/sparsify/timing" };
    //! should sparsify presolver be copied to sub-SCIPs?
    constexpr Param<bool> ENABLECOPY { "presolving/sparsify/enablecopy" };
    //! should we cancel nonzeros in constraints of the linear constraint handler?
    constexpr Param<bool> CANCELLINEAR { "presolving/sparsify/cancellinear" };
    //! should we forbid cancellations that destroy integer coefficients?
    constexpr Param<bool> PRESERVEINTCOEFS { "presolving/sparsify/preserveintcoefs" };
    //! maximal fillin for continuous variables (-1: unlimited)
    constexpr Param<int> MAXCONTFILLIN { "presolving/sparsify/maxcontfillin" };
    //! maximal fillin for binary variables (-1: unlimited)
    constexpr Param<int> MAXBINFILLIN { "presolving/sparsify/maxbinfillin" };
    //! maximal fillin for integer variables including binaries (-1: unlimited)
    constexpr Param<int> MAXINTFILLIN { "presolving/sparsify/maxintfillin" };
    //! maximal support of one equality to be used for cancelling (-1: no limit)
    constexpr Param<int> MAXNONZEROS { "presolving/sparsify/maxnonzeros" };
    //! maximal number of considered non-zeros within one row (-1: no limit)
    constexpr Param<int> MAXCONSIDEREDNONZEROS { "presolving/sparsify/maxconsiderednonzeros" };
    //! order in which to process inequalities ('n'o sorting, 'i'ncreasing nonzeros, 'd'ecreasing nonzeros)
    constexpr Param<char> ROWSORT { "presolving/sparsify/rowsort" };
    //! limit on the number of useless vs. useful hashtable retrieves as a multiple of the number of constraints
    constexpr Param<double> MAXRETRIEVEFAC { "presolving/sparsify/maxretrievefac" };
    //! number of calls to wait until next execution as a multiple of the number of useless calls
    constexpr Param<double> WAITINGFAC { "presolving/sparsify/waitingfac" };
}
//! Parameters with prefix presolving/stuffing
namespace PRESOLVING::STUFFING {
    //! priority of presolver \<stuffing\>
    constexpr Param<int> PRIORITY { "presolving/stuffing/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/stuffing/maxrounds" };
    //! timing mask of presolver \<stuffing\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/stuffing/timing" };
}
//! Parameters with prefix presolving/trivial
namespace PRESOLVING::TRIVIAL {
    //! priority of presolver \<trivial\>
    constexpr Param<int> PRIORITY { "presolving/trivial/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/trivial/maxrounds" };
    //! timing mask of presolver \<trivial\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/trivial/timing" };
}
//! Parameters with prefix presolving/tworowbnd
namespace PRESOLVING::TWOROWBND {
    //! priority of presolver \<tworowbnd\>
    constexpr Param<int> PRIORITY { "presolving/tworowbnd/priority" };
    //! maximal number of presolving rounds the presolver participates in (-1: no limit)
    constexpr Param<int> MAXROUNDS { "presolving/tworowbnd/maxrounds" };
    //! timing mask of presolver \<tworowbnd\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> TIMING { "presolving/tworowbnd/timing" };
    //! should tworowbnd presolver be copied to sub-SCIPs?
    constexpr Param<bool> ENABLECOPY { "presolving/tworowbnd/enablecopy" };
    //! maximal number of considered non-zeros within one row (-1: no limit)
    constexpr Param<int> MAXCONSIDEREDNONZEROS { "presolving/tworowbnd/maxconsiderednonzeros" };
    //! maximal number of consecutive useless hashtable retrieves
    constexpr Param<int> MAXRETRIEVEFAILS { "presolving/tworowbnd/maxretrievefails" };
    //! maximal number of consecutive useless row combines
    constexpr Param<int> MAXCOMBINEFAILS { "presolving/tworowbnd/maxcombinefails" };
    //! Maximum number of hashlist entries as multiple of number of rows in the problem (-1: no limit)
    constexpr Param<int> MAXHASHFAC { "presolving/tworowbnd/maxhashfac" };
    //! Maximum number of processed row pairs as multiple of the number of rows in the problem (-1: no limit)
    constexpr Param<int> MAXPAIRFAC { "presolving/tworowbnd/maxpairfac" };
}
//! Parameters with prefix pricing
namespace PRICING {
    //! maximal number of variables priced in per pricing round
    constexpr Param<int> MAXVARS { "pricing/maxvars" };
    //! maximal number of priced variables at the root node
    constexpr Param<int> MAXVARSROOT { "pricing/maxvarsroot" };
    //! pricing is aborted, if fac * pricing/maxvars pricing candidates were found
    constexpr Param<double> ABORTFAC { "pricing/abortfac" };
    //! should variables created at the current node be deleted when the node is solved in case they are not present in
    //! the LP anymore?
    constexpr Param<bool> DELVARS { "pricing/delvars" };
    //! should variables created at the root node be deleted when the root is solved in case they are not present in the
    //! LP anymore?
    constexpr Param<bool> DELVARSROOT { "pricing/delvarsroot" };
}
//! Parameters with prefix propagating
namespace PROPAGATING {
    //! maximal number of propagation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "propagating/maxrounds" };
    //! maximal number of propagation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "propagating/maxroundsroot" };
    //! should propagation be aborted immediately? setting this to FALSE could help conflict analysis to produce more
    //! conflict constraints
    constexpr Param<bool> ABORTONCUTOFF { "propagating/abortoncutoff" };
}
//! Parameters with prefix propagating/dualfix
namespace PROPAGATING::DUALFIX {
    //! priority of propagator \<dualfix\>
    constexpr Param<int> PRIORITY { "propagating/dualfix/priority" };
    //! frequency for calling propagator \<dualfix\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/dualfix/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/dualfix/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/dualfix/timingmask" };
    //! presolving priority of propagator \<dualfix\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/dualfix/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/dualfix/maxprerounds" };
    //! timing mask of the presolving method of propagator \<dualfix\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/dualfix/presoltiming" };
}
//! Parameters with prefix propagating/genvbounds
namespace PROPAGATING::GENVBOUNDS {
    //! priority of propagator \<genvbounds\>
    constexpr Param<int> PRIORITY { "propagating/genvbounds/priority" };
    //! frequency for calling propagator \<genvbounds\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/genvbounds/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/genvbounds/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/genvbounds/timingmask" };
    //! presolving priority of propagator \<genvbounds\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/genvbounds/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/genvbounds/maxprerounds" };
    //! timing mask of the presolving method of propagator \<genvbounds\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/genvbounds/presoltiming" };
    //! apply global propagation?
    constexpr Param<bool> GLOBAL { "propagating/genvbounds/global" };
    //! apply genvbounds in root node if no new incumbent was found?
    constexpr Param<bool> PROPINROOTNODE { "propagating/genvbounds/propinrootnode" };
    //! sort genvbounds and wait for bound change events?
    constexpr Param<bool> SORT { "propagating/genvbounds/sort" };
    //! should genvbounds be transformed to (linear) constraints?
    constexpr Param<bool> PROPASCONSS { "propagating/genvbounds/propasconss" };
}
//! Parameters with prefix propagating/nlobbt
namespace PROPAGATING::NLOBBT {
    //! priority of propagator \<nlobbt\>
    constexpr Param<int> PRIORITY { "propagating/nlobbt/priority" };
    //! frequency for calling propagator \<nlobbt\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/nlobbt/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/nlobbt/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/nlobbt/timingmask" };
    //! presolving priority of propagator \<nlobbt\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/nlobbt/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/nlobbt/maxprerounds" };
    //! timing mask of the presolving method of propagator \<nlobbt\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/nlobbt/presoltiming" };
    //! factor for NLP feasibility tolerance
    constexpr Param<double> FEASTOLFAC { "propagating/nlobbt/feastolfac" };
    //! factor for NLP relative objective tolerance
    constexpr Param<double> RELOBJTOLFAC { "propagating/nlobbt/relobjtolfac" };
    //! (\#convex nlrows)/(\#nonconvex nlrows) threshold to apply propagator
    constexpr Param<double> MINNONCONVEXFRAC { "propagating/nlobbt/minnonconvexfrac" };
    //! minimum (\#convex nlrows)/(\#linear nlrows) threshold to apply propagator
    constexpr Param<double> MINLINEARFRAC { "propagating/nlobbt/minlinearfrac" };
    //! should non-initial LP rows be used?
    constexpr Param<bool> ADDLPROWS { "propagating/nlobbt/addlprows" };
    //! iteration limit of NLP solver; 0 for no limit
    constexpr Param<int> NLPITERLIMIT { "propagating/nlobbt/nlpiterlimit" };
    //! time limit of NLP solver; 0.0 for no limit
    constexpr Param<double> NLPTIMELIMIT { "propagating/nlobbt/nlptimelimit" };
    //! verbosity level of NLP solver
    constexpr Param<int> NLPVERBLEVEL { "propagating/nlobbt/nlpverblevel" };
    //! LP iteration limit for nlobbt will be this factor times total LP iterations in root node
    constexpr Param<double> ITLIMITFACTOR { "propagating/nlobbt/itlimitfactor" };
}
//! Parameters with prefix propagating/obbt
namespace PROPAGATING::OBBT {
    //! priority of propagator \<obbt\>
    constexpr Param<int> PRIORITY { "propagating/obbt/priority" };
    //! frequency for calling propagator \<obbt\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/obbt/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/obbt/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/obbt/timingmask" };
    //! presolving priority of propagator \<obbt\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/obbt/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/obbt/maxprerounds" };
    //! timing mask of the presolving method of propagator \<obbt\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/obbt/presoltiming" };
    //! should obbt try to provide genvbounds if possible?
    constexpr Param<bool> CREATEGENVBOUNDS { "propagating/obbt/creategenvbounds" };
    //! should coefficients in filtering be normalized w.r.t. the domains sizes?
    constexpr Param<bool> NORMALIZE { "propagating/obbt/normalize" };
    //! try to filter bounds in so-called filter rounds by solving auxiliary LPs?
    constexpr Param<bool> APPLYFILTERROUNDS { "propagating/obbt/applyfilterrounds" };
    //! try to filter bounds with the LP solution after each solve?
    constexpr Param<bool> APPLYTRIVIALFILTER { "propagating/obbt/applytrivialfilter" };
    //! should we try to generate genvbounds during trivial and aggressive filtering?
    constexpr Param<bool> GENVBDSDURINGFILTER { "propagating/obbt/genvbdsduringfilter" };
    //! try to create genvbounds during separation process?
    constexpr Param<bool> GENVBDSDURINGSEPA { "propagating/obbt/genvbdsduringsepa" };
    //! minimal number of filtered bounds to apply another filter round
    constexpr Param<int> MINFILTER { "propagating/obbt/minfilter" };
    //! multiple of root node LP iterations used as total LP iteration limit for obbt (\<= 0: no limit )
    constexpr Param<double> ITLIMITFACTOR { "propagating/obbt/itlimitfactor" };
    //! multiple of OBBT LP limit used as total LP iteration limit for solving bilinear inequality LPs (\< 0 for no
    //! limit)
    constexpr Param<double> ITLIMITFACTORBILIN { "propagating/obbt/itlimitfactorbilin" };
    //! minimum absolute value of nonconvex eigenvalues for a bilinear term
    constexpr Param<double> MINNONCONVEXITY { "propagating/obbt/minnonconvexity" };
    //! minimum LP iteration limit
    constexpr Param<long long> MINITLIMIT { "propagating/obbt/minitlimit" };
    //! feasibility tolerance for reduced costs used in obbt; this value is used if SCIP's dual feastol is greater
    constexpr Param<double> DUALFEASTOL { "propagating/obbt/dualfeastol" };
    //! maximum condition limit used in LP solver (-1.0: no limit)
    constexpr Param<double> CONDITIONLIMIT { "propagating/obbt/conditionlimit" };
    //! minimal relative improve for strengthening bounds
    constexpr Param<double> BOUNDSTREPS { "propagating/obbt/boundstreps" };
    //! only apply obbt on non-convex variables
    constexpr Param<bool> ONLYNONCONVEXVARS { "propagating/obbt/onlynonconvexvars" };
    //! should integral bounds be tightened during the probing mode?
    constexpr Param<bool> TIGHTINTBOUNDSPROBING { "propagating/obbt/tightintboundsprobing" };
    //! should continuous bounds be tightened during the probing mode?
    constexpr Param<bool> TIGHTCONTBOUNDSPROBING { "propagating/obbt/tightcontboundsprobing" };
    //! solve auxiliary LPs in order to find valid inequalities for bilinear terms?
    constexpr Param<bool> CREATEBILININEQS { "propagating/obbt/createbilinineqs" };
    //! create linear constraints from inequalities for bilinear terms?
    constexpr Param<bool> CREATELINCONS { "propagating/obbt/createlincons" };
    //! select the type of ordering algorithm which should be used (0: no special ordering, 1: greedy, 2: greedy
    //! reverse)
    constexpr Param<int> ORDERINGALGO { "propagating/obbt/orderingalgo" };
    //! should the obbt LP solution be separated?
    constexpr Param<bool> SEPARATESOL { "propagating/obbt/separatesol" };
    //! minimum number of iteration spend to separate an obbt LP solution
    constexpr Param<int> SEPAMINITER { "propagating/obbt/sepaminiter" };
    //! maximum number of iteration spend to separate an obbt LP solution
    constexpr Param<int> SEPAMAXITER { "propagating/obbt/sepamaxiter" };
    //! trigger a propagation round after that many bound tightenings (0: no propagation)
    constexpr Param<int> PROPAGATEFREQ { "propagating/obbt/propagatefreq" };
}
//! Parameters with prefix propagating/probing
namespace PROPAGATING::PROBING {
    //! priority of propagator \<probing\>
    constexpr Param<int> PRIORITY { "propagating/probing/priority" };
    //! frequency for calling propagator \<probing\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/probing/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/probing/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/probing/timingmask" };
    //! presolving priority of propagator \<probing\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/probing/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/probing/maxprerounds" };
    //! timing mask of the presolving method of propagator \<probing\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/probing/presoltiming" };
    //! maximal number of runs, probing participates in (-1: no limit)
    constexpr Param<int> MAXRUNS { "propagating/probing/maxruns" };
    //! maximal number of propagation rounds in probing subproblems (-1: no limit, 0: auto)
    constexpr Param<int> PROPROUNDS { "propagating/probing/proprounds" };
    //! maximal number of fixings found, until probing is interrupted (0: don't iterrupt)
    constexpr Param<int> MAXFIXINGS { "propagating/probing/maxfixings" };
    //! maximal number of successive probings without fixings, until probing is aborted (0: don't abort)
    constexpr Param<int> MAXUSELESS { "propagating/probing/maxuseless" };
    //! maximal number of successive probings without fixings, bound changes, and implications, until probing is aborted
    //! (0: don't abort)
    constexpr Param<int> MAXTOTALUSELESS { "propagating/probing/maxtotaluseless" };
    //! maximal number of probings without fixings, until probing is aborted (0: don't abort)
    constexpr Param<int> MAXSUMUSELESS { "propagating/probing/maxsumuseless" };
    //! maximal depth until propagation is executed(-1: no limit)
    constexpr Param<int> MAXDEPTH { "propagating/probing/maxdepth" };
}
//! Parameters with prefix propagating/pseudoobj
namespace PROPAGATING::PSEUDOOBJ {
    //! priority of propagator \<pseudoobj\>
    constexpr Param<int> PRIORITY { "propagating/pseudoobj/priority" };
    //! frequency for calling propagator \<pseudoobj\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/pseudoobj/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/pseudoobj/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/pseudoobj/timingmask" };
    //! presolving priority of propagator \<pseudoobj\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/pseudoobj/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/pseudoobj/maxprerounds" };
    //! timing mask of the presolving method of propagator \<pseudoobj\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/pseudoobj/presoltiming" };
    //! minimal number of successive non-binary variable propagations without a bound reduction before aborted
    constexpr Param<int> MINUSELESS { "propagating/pseudoobj/minuseless" };
    //! maximal fraction of non-binary variables with non-zero objective without a bound reduction before aborted
    constexpr Param<double> MAXVARSFRAC { "propagating/pseudoobj/maxvarsfrac" };
    //! whether to propagate all non-binary variables when we are propagating the root node
    constexpr Param<bool> PROPFULLINROOT { "propagating/pseudoobj/propfullinroot" };
    //! propagate new cutoff bound directly globally
    constexpr Param<bool> PROPCUTOFFBOUND { "propagating/pseudoobj/propcutoffbound" };
    //! should the propagator be forced even if active pricer are present?
    constexpr Param<bool> FORCE { "propagating/pseudoobj/force" };
    //! number of variables added after the propagator is reinitialized?
    constexpr Param<int> MAXNEWVARS { "propagating/pseudoobj/maxnewvars" };
    //! use implications to strengthen the propagation of binary variable (increasing the objective change)?
    constexpr Param<bool> PROPUSEIMPLICS { "propagating/pseudoobj/propuseimplics" };
    //! use implications to strengthen the resolve propagation of binary variable (increasing the objective change)?
    constexpr Param<bool> RESPROPUSEIMPLICS { "propagating/pseudoobj/respropuseimplics" };
    //! maximum number of binary variables the implications are used if turned on (-1: unlimited)?
    constexpr Param<int> MAXIMPLVARS { "propagating/pseudoobj/maximplvars" };
}
//! Parameters with prefix propagating/redcost
namespace PROPAGATING::REDCOST {
    //! priority of propagator \<redcost\>
    constexpr Param<int> PRIORITY { "propagating/redcost/priority" };
    //! frequency for calling propagator \<redcost\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/redcost/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/redcost/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/redcost/timingmask" };
    //! presolving priority of propagator \<redcost\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/redcost/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/redcost/maxprerounds" };
    //! timing mask of the presolving method of propagator \<redcost\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/redcost/presoltiming" };
    //! should reduced cost fixing be also applied to continuous variables?
    constexpr Param<bool> CONTINUOUS { "propagating/redcost/continuous" };
    //! should implications be used to strength the reduced cost for binary variables?
    constexpr Param<bool> USEIMPLICS { "propagating/redcost/useimplics" };
    //! should the propagator be forced even if active pricer are present?
    constexpr Param<bool> FORCE { "propagating/redcost/force" };
}
//! Parameters with prefix propagating/rootredcost
namespace PROPAGATING::ROOTREDCOST {
    //! priority of propagator \<rootredcost\>
    constexpr Param<int> PRIORITY { "propagating/rootredcost/priority" };
    //! frequency for calling propagator \<rootredcost\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/rootredcost/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/rootredcost/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/rootredcost/timingmask" };
    //! presolving priority of propagator \<rootredcost\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/rootredcost/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/rootredcost/maxprerounds" };
    //! timing mask of the presolving method of propagator \<rootredcost\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/rootredcost/presoltiming" };
    //! should only binary variables be propagated?
    constexpr Param<bool> ONLYBINARY { "propagating/rootredcost/onlybinary" };
    //! should the propagator be forced even if active pricer are present?
    constexpr Param<bool> FORCE { "propagating/rootredcost/force" };
}
//! Parameters with prefix propagating/symmetry
namespace PROPAGATING::SYMMETRY {
    //! priority of propagator \<symmetry\>
    constexpr Param<int> PRIORITY { "propagating/symmetry/priority" };
    //! frequency for calling propagator \<symmetry\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/symmetry/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/symmetry/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/symmetry/timingmask" };
    //! presolving priority of propagator \<symmetry\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/symmetry/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/symmetry/maxprerounds" };
    //! timing mask of the presolving method of propagator \<symmetry\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/symmetry/presoltiming" };
    //! limit on the number of generators that should be produced within symmetry detection (0 = no limit)
    constexpr Param<int> MAXGENERATORS { "propagating/symmetry/maxgenerators" };
    //! Should all symmetries be checked after computation?
    constexpr Param<bool> CHECKSYMMETRIES { "propagating/symmetry/checksymmetries" };
    //! Should the number of variables affected by some symmetry be displayed?
    constexpr Param<bool> DISPLAYNORBITVARS { "propagating/symmetry/displaynorbitvars" };
    //! Double equations to positive/negative version?
    constexpr Param<bool> DOUBLEEQUATIONS { "propagating/symmetry/doubleequations" };
    //! Should the symmetry breaking constraints be added to the LP?
    constexpr Param<bool> CONSSADDLP { "propagating/symmetry/conssaddlp" };
    //! Add inequalities for symresacks for each generator?
    constexpr Param<bool> ADDSYMRESACKS { "propagating/symmetry/addsymresacks" };
    //! Should we check whether the components of the symmetry group can be handled by orbitopes?
    constexpr Param<bool> DETECTORBITOPES { "propagating/symmetry/detectorbitopes" };
    //! Should we try to detect symmetric subgroups of the symmetry group on binary variables?
    constexpr Param<bool> DETECTSUBGROUPS { "propagating/symmetry/detectsubgroups" };
    //! Should we add weak SBCs for enclosing orbit of symmetric subgroups?
    constexpr Param<bool> ADDWEAKSBCS { "propagating/symmetry/addweaksbcs" };
    //! timing of adding constraints (0 = before presolving, 1 = during presolving, 2 = after presolving)
    constexpr Param<int> ADDCONSSTIMING { "propagating/symmetry/addconsstiming" };
    //! timing of symmetry computation for orbital fixing (0 = before presolving, 1 = during presolving, 2 = at first
    //! call)
    constexpr Param<int> OFSYMCOMPTIMING { "propagating/symmetry/ofsymcomptiming" };
    //! run orbital fixing during presolving?
    constexpr Param<bool> PERFORMPRESOLVING { "propagating/symmetry/performpresolving" };
    //! recompute symmetries after a restart has occured? (0 = never, 1 = always, 2 = if OF found reduction)
    constexpr Param<int> RECOMPUTERESTART { "propagating/symmetry/recomputerestart" };
    //! Should non-affected variables be removed from permutation to save memory?
    constexpr Param<bool> COMPRESSSYMMETRIES { "propagating/symmetry/compresssymmetries" };
    //! Compression is used if percentage of moved vars is at most the threshold.
    constexpr Param<double> COMPRESSTHRESHOLD { "propagating/symmetry/compressthreshold" };
    //! Should the number of conss a variable is contained in be exploited in symmetry detection?
    constexpr Param<bool> USECOLUMNSPARSITY { "propagating/symmetry/usecolumnsparsity" };
    //! maximum number of constraints up to which subgroup structures are detected
    constexpr Param<int> MAXNCONSSSUBGROUP { "propagating/symmetry/maxnconsssubgroup" };
    //! whether dynamic propagation should be used for full orbitopes
    constexpr Param<bool> USEDYNAMICPROP { "propagating/symmetry/usedynamicprop" };
    //! Should strong SBCs for enclosing orbit of symmetric subgroups be added if orbitopes are not used?
    constexpr Param<bool> ADDSTRONGSBCS { "propagating/symmetry/addstrongsbcs" };
    //! rule to select the orbit in Schreier Sims inequalities (variable in 0: minimum size orbit; 1: maximum size
    //! orbit; 2: orbit with most variables in conflict with leader)
    constexpr Param<int> SSTTIEBREAKRULE { "propagating/symmetry/ssttiebreakrule" };
    //! rule to select the leader in an orbit (0: first var; 1: last var; 2: var having most conflicting vars in orbit;
    //! 3: var having most conflicting vars in problem)
    constexpr Param<int> SSTLEADERRULE { "propagating/symmetry/sstleaderrule" };
    //! bitset encoding which variable types can be leaders (1: binary; 2: integer; 4: impl. int; 8: continuous);if
    //! multiple types are allowed, take the one with most affected vars
    constexpr Param<int> SSTLEADERVARTYPE { "propagating/symmetry/sstleadervartype" };
    //! Should Schreier Sims constraints be added if we use a conflict based rule?
    constexpr Param<bool> ADDCONFLICTCUTS { "propagating/symmetry/addconflictcuts" };
    //! Should Schreier Sims constraints be added?
    constexpr Param<bool> SSTADDCUTS { "propagating/symmetry/sstaddcuts" };
    //! Should Schreier Sims constraints be added if a symmetry component contains variables of different types?
    constexpr Param<bool> SSTMIXEDCOMPONENTS { "propagating/symmetry/sstmixedcomponents" };
    //! Whether all non-binary variables shall be not affected by symmetries if OF is active?
    constexpr Param<bool> SYMFIXNONBINARYVARS { "propagating/symmetry/symfixnonbinaryvars" };
    //! Is only symmetry on binary variables used?
    constexpr Param<bool> ONLYBINARYSYMMETRY { "propagating/symmetry/onlybinarysymmetry" };
    //! Shall orbitopes with less rows be preferred in detection?
    constexpr Param<bool> PREFERLESSROWS { "propagating/symmetry/preferlessrows" };
}
//! Parameters with prefix propagating/vbounds
namespace PROPAGATING::VBOUNDS {
    //! priority of propagator \<vbounds\>
    constexpr Param<int> PRIORITY { "propagating/vbounds/priority" };
    //! frequency for calling propagator \<vbounds\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "propagating/vbounds/freq" };
    //! should propagator be delayed, if other propagators found reductions?
    constexpr Param<bool> DELAY { "propagating/vbounds/delay" };
    //! timing when propagator should be called (1:BEFORELP, 2:DURINGLPLOOP, 4:AFTERLPLOOP, 15:ALWAYS))
    constexpr Param<int> TIMINGMASK { "propagating/vbounds/timingmask" };
    //! presolving priority of propagator \<vbounds\>
    constexpr Param<int> PRESOLPRIORITY { "propagating/vbounds/presolpriority" };
    //! maximal number of presolving rounds the propagator participates in (-1: no limit)
    constexpr Param<int> MAXPREROUNDS { "propagating/vbounds/maxprerounds" };
    //! timing mask of the presolving method of propagator \<vbounds\> (4:FAST, 8:MEDIUM, 16:EXHAUSTIVE, 32:FINAL)
    constexpr Param<int> PRESOLTIMING { "propagating/vbounds/presoltiming" };
    //! should bound widening be used to initialize conflict analysis?
    constexpr Param<bool> USEBDWIDENING { "propagating/vbounds/usebdwidening" };
    //! should implications be propagated?
    constexpr Param<bool> USEIMPLICS { "propagating/vbounds/useimplics" };
    //! should cliques be propagated?
    constexpr Param<bool> USECLIQUES { "propagating/vbounds/usecliques" };
    //! should vbounds be propagated?
    constexpr Param<bool> USEVBOUNDS { "propagating/vbounds/usevbounds" };
    //! should the bounds be topologically sorted in advance?
    constexpr Param<bool> DOTOPOSORT { "propagating/vbounds/dotoposort" };
    //! should cliques be regarded for the topological sort?
    constexpr Param<bool> SORTCLIQUES { "propagating/vbounds/sortcliques" };
    //! should cycles in the variable bound graph be identified?
    constexpr Param<bool> DETECTCYCLES { "propagating/vbounds/detectcycles" };
    //! minimum percentage of new cliques to trigger another clique table analysis
    constexpr Param<double> MINNEWCLIQUES { "propagating/vbounds/minnewcliques" };
    //! maximum number of cliques per variable to run clique table analysis in medium presolving
    constexpr Param<double> MAXCLIQUESMEDIUM { "propagating/vbounds/maxcliquesmedium" };
    //! maximum number of cliques per variable to run clique table analysis in exhaustive presolving
    constexpr Param<double> MAXCLIQUESEXHAUSTIVE { "propagating/vbounds/maxcliquesexhaustive" };
}
//! Parameters with prefix randomization
namespace RANDOMIZATION {
    //! global shift of all random seeds in the plugins and the LP random seed
    constexpr Param<int> RANDOMSEEDSHIFT { "randomization/randomseedshift" };
    //! seed value for permuting the problem after reading/transformation (0: no permutation)
    constexpr Param<int> PERMUTATIONSEED { "randomization/permutationseed" };
    //! should order of constraints be permuted (depends on permutationseed)?
    constexpr Param<bool> PERMUTECONSS { "randomization/permuteconss" };
    //! should order of variables be permuted (depends on permutationseed)?
    constexpr Param<bool> PERMUTEVARS { "randomization/permutevars" };
    //! random seed for LP solver, e.g. for perturbations in the simplex (0: LP default)
    constexpr Param<int> LPSEED { "randomization/lpseed" };
}
//! Parameters with prefix reading
namespace READING {
    //! should model constraints be marked as initial?
    constexpr Param<bool> INITIALCONSS { "reading/initialconss" };
    //! should model constraints be subject to aging?
    constexpr Param<bool> DYNAMICCONSS { "reading/dynamicconss" };
    //! should columns be added and removed dynamically to the LP?
    constexpr Param<bool> DYNAMICCOLS { "reading/dynamiccols" };
    //! should rows be added and removed dynamically to the LP?
    constexpr Param<bool> DYNAMICROWS { "reading/dynamicrows" };
}
//! Parameters with prefix reading/bndreader
namespace READING::BNDREADER {
    //! only use improving bounds
    constexpr Param<bool> IMPROVEONLY { "reading/bndreader/improveonly" };
}
//! Parameters with prefix reading/cipreader
namespace READING::CIPREADER {
    //! should fixed and aggregated variables be printed (if not, re-parsing might fail)
    constexpr Param<bool> WRITEFIXEDVARS { "reading/cipreader/writefixedvars" };
}
//! Parameters with prefix reading/cnfreader
namespace READING::CNFREADER {
    //! should an artificial objective, depending on the number of clauses a variable appears in, be used?
    constexpr Param<bool> USEOBJ { "reading/cnfreader/useobj" };
}
//! Parameters with prefix reading/gmsreader
namespace READING::GMSREADER {
    //! have integer variables no upper bound by default (depending on GAMS version)?
    constexpr Param<bool> FREEINTS { "reading/gmsreader/freeints" };
    //! shall characters '\#', '*', '+', '/', and '-' in variable and constraint names be replaced by '_'?
    constexpr Param<bool> REPLACEFORBIDDENCHARS { "reading/gmsreader/replaceforbiddenchars" };
    //! default M value for big-M reformulation of indicator constraints in case no bound on slack variable is given
    constexpr Param<double> BIGMDEFAULT { "reading/gmsreader/bigmdefault" };
    //! which reformulation to use for indicator constraints: 'b'ig-M, 's'os1
    constexpr Param<char> INDICATORREFORM { "reading/gmsreader/indicatorreform" };
    //! is it allowed to use the gams function signpower(x,a)?
    constexpr Param<bool> SIGNPOWER { "reading/gmsreader/signpower" };
}
//! Parameters with prefix reading/lpreader
namespace READING::LPREADER {
    //! should possible "and" constraint be linearized when writing the lp file?
    constexpr Param<bool> LINEARIZE_AND_CONSTRAINTS { "reading/lpreader/linearize-and-constraints" };
    //! should an aggregated linearization for and constraints be used?
    constexpr Param<bool> AGGRLINEARIZATION_ANDS { "reading/lpreader/aggrlinearization-ands" };
}
//! Parameters with prefix reading/mpsreader
namespace READING::MPSREADER {
    //! should possible "and" constraint be linearized when writing the mps file?
    constexpr Param<bool> LINEARIZE_AND_CONSTRAINTS { "reading/mpsreader/linearize-and-constraints" };
    //! should an aggregated linearization for and constraints be used?
    constexpr Param<bool> AGGRLINEARIZATION_ANDS { "reading/mpsreader/aggrlinearization-ands" };
}
//! Parameters with prefix reading/opbreader
namespace READING::OPBREADER {
    //! should model constraints be subject to aging?
    constexpr Param<bool> DYNAMICCONSS { "reading/opbreader/dynamicconss" };
    //! use '*' between coefficients and variables by writing to problem?
    constexpr Param<bool> MULTISYMBOL { "reading/opbreader/multisymbol" };
}
//! Parameters with prefix reading/pbmreader
namespace READING::PBMREADER {
    //! should the output format be binary(P4) (otherwise plain(P1) format)
    constexpr Param<bool> BINARY { "reading/pbmreader/binary" };
    //! maximum number of rows in the scaled picture (-1 for no limit)
    constexpr Param<int> MAXROWS { "reading/pbmreader/maxrows" };
    //! maximum number of columns in the scaled picture (-1 for no limit)
    constexpr Param<int> MAXCOLS { "reading/pbmreader/maxcols" };
}
//! Parameters with prefix reading/ppmreader
namespace READING::PPMREADER {
    //! should the coloring values be relativ or absolute
    constexpr Param<bool> RGBRELATIV { "reading/ppmreader/rgbrelativ" };
    //! should the output format be binary(P6) (otherwise plain(P3) format)
    constexpr Param<bool> RGBASCII { "reading/ppmreader/rgbascii" };
    //! splitting coefficients in this number of intervals
    constexpr Param<int> COEFFICIENTLIMIT { "reading/ppmreader/coefficientlimit" };
    //! maximal color value
    constexpr Param<int> RGBLIMIT { "reading/ppmreader/rgblimit" };
}
//! Parameters with prefix reading/storeader
namespace READING::STOREADER {
    //! should Benders' decomposition be used?
    constexpr Param<bool> USEBENDERS { "reading/storeader/usebenders" };
}
//! Parameters with prefix reoptimization
namespace REOPTIMIZATION {
    //! should reoptimization used?
    constexpr Param<bool> ENABLE { "reoptimization/enable" };
    //! maximal number of saved nodes
    constexpr Param<int> MAXSAVEDNODES { "reoptimization/maxsavednodes" };
    //! maximal number of bound changes between two stored nodes on one path
    constexpr Param<int> MAXDIFFOFNODES { "reoptimization/maxdiffofnodes" };
    //! separate the optimal solution, i.e., for constrained shortest path
    constexpr Param<bool> SEPABESTSOL { "reoptimization/sepabestsol" };
    //! use variable history of the previous solve if the objctive function has changed only slightly
    constexpr Param<bool> STOREVARHISTORY { "reoptimization/storevarhistory" };
    //! re-use pseudo costs if the objective function changed only slightly
    constexpr Param<bool> USEPSCOST { "reoptimization/usepscost" };
    //! at which reopttype should the LP be solved? (1: transit, 3: strong branched, 4: w/ added logicor, 5: only
    //! leafs).
    constexpr Param<int> SOLVELP { "reoptimization/solvelp" };
    //! maximal number of bound changes at node to skip solving the LP
    constexpr Param<int> SOLVELPDIFF { "reoptimization/solvelpdiff" };
    //! number of best solutions which should be saved for the following runs. (-1: save all)
    constexpr Param<int> SAVESOLS { "reoptimization/savesols" };
    //! similarity of two sequential objective function to disable solving the root LP.
    constexpr Param<double> OBJSIMROOTLP { "reoptimization/objsimrootLP" };
    //! similarity of two objective functions to re-use stored solutions
    constexpr Param<double> OBJSIMSOL { "reoptimization/objsimsol" };
    //! minimum similarity for using reoptimization of the search tree.
    constexpr Param<double> DELAY { "reoptimization/delay" };
    //! time limit over all reoptimization rounds?.
    constexpr Param<bool> COMMONTIMELIMIT { "reoptimization/commontimelimit" };
    //! replace branched inner nodes by their child nodes, if the number of bound changes is not to large
    constexpr Param<bool> SHRINKINNER { "reoptimization/shrinkinner" };
    //! try to fix variables at the root node before reoptimizing by probing like strong branching
    constexpr Param<bool> STRONGBRANCHINGINIT { "reoptimization/strongbranchinginit" };
    //! delete stored nodes which were not reoptimized
    constexpr Param<bool> REDUCETOFRONTIER { "reoptimization/reducetofrontier" };
    //! force a restart if the last n optimal solutions were found by heuristic reoptsols
    constexpr Param<int> FORCEHEURRESTART { "reoptimization/forceheurrestart" };
    //! save constraint propagations
    constexpr Param<bool> SAVECONSPROP { "reoptimization/saveconsprop" };
    //! use constraints to reconstruct the subtree pruned be dual reduction when reactivating the node
    constexpr Param<bool> USESPLITCONS { "reoptimization/usesplitcons" };
    //! use 'd'efault, 'r'andom or a variable ordering based on 'i'nference score for interdiction branching used during
    //! reoptimization
    constexpr Param<char> VARORDERINTERDICTION { "reoptimization/varorderinterdiction" };
    //! reoptimize cuts found at the root node
    constexpr Param<bool> USECUTS { "reoptimization/usecuts" };
    //! maximal age of a cut to be use for reoptimization
    constexpr Param<int> MAXCUTAGE { "reoptimization/maxcutage" };
}
//! Parameters with prefix reoptimization/globalcons
namespace REOPTIMIZATION::GLOBALCONS {
    //! save global constraints to separate infeasible subtrees.
    constexpr Param<bool> SEPAINFSUBTREES { "reoptimization/globalcons/sepainfsubtrees" };
}
//! Parameters with prefix separating
namespace SEPARATING {
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separation (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/maxbounddist" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying local separation (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXLOCALBOUNDDIST { "separating/maxlocalbounddist" };
    //! maximal ratio between coefficients in strongcg, cmir, and flowcover cuts
    constexpr Param<double> MAXCOEFRATIO { "separating/maxcoefratio" };
    //! maximal ratio between coefficients (as factor of 1/feastol) to ensure in rowprep cleanup
    constexpr Param<double> MAXCOEFRATIOFACROWPREP { "separating/maxcoefratiofacrowprep" };
    //! minimal efficacy for a cut to enter the LP
    constexpr Param<double> MINEFFICACY { "separating/minefficacy" };
    //! minimal efficacy for a cut to enter the LP in the root node
    constexpr Param<double> MINEFFICACYROOT { "separating/minefficacyroot" };
    //! minimum cut activity quotient to convert cuts into constraints during a restart (0.0: all cuts are converted)
    constexpr Param<double> MINACTIVITYQUOT { "separating/minactivityquot" };
    //! function used for calc. scalar prod. in orthogonality test ('e'uclidean, 'd'iscrete)
    constexpr Param<char> ORTHOFUNC { "separating/orthofunc" };
    //! row norm to use for efficacy calculation ('e'uclidean, 'm'aximum, 's'um, 'd'iscrete)
    constexpr Param<char> EFFICACYNORM { "separating/efficacynorm" };
    //! cut selection during restart ('a'ge, activity 'q'uotient)
    constexpr Param<char> CUTSELRESTART { "separating/cutselrestart" };
    //! cut selection for sub SCIPs ('a'ge, activity 'q'uotient)
    constexpr Param<char> CUTSELSUBSCIP { "separating/cutselsubscip" };
    //! should cutpool separate only cuts with high relative efficacy?
    constexpr Param<bool> FILTERCUTPOOLREL { "separating/filtercutpoolrel" };
    //! maximal number of runs for which separation is enabled (-1: unlimited)
    constexpr Param<int> MAXRUNS { "separating/maxruns" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/maxrounds" };
    //! maximal number of separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/maxroundsroot" };
    //! maximal number of separation rounds in the root node of a subsequent run (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOTSUBRUN { "separating/maxroundsrootsubrun" };
    //! maximal additional number of separation rounds in subsequent price-and-cut loops (-1: no additional restriction)
    constexpr Param<int> MAXADDROUNDS { "separating/maxaddrounds" };
    //! maximal number of consecutive separation rounds without objective or integrality improvement in local nodes (-1:
    //! no additional restriction)
    constexpr Param<int> MAXSTALLROUNDS { "separating/maxstallrounds" };
    //! maximal number of consecutive separation rounds without objective or integrality improvement in the root node
    //! (-1: no additional restriction)
    constexpr Param<int> MAXSTALLROUNDSROOT { "separating/maxstallroundsroot" };
    //! maximal number of cuts separated per separation round (0: disable local separation)
    constexpr Param<int> MAXCUTS { "separating/maxcuts" };
    //! maximal number of separated cuts at the root node (0: disable root node separation)
    constexpr Param<int> MAXCUTSROOT { "separating/maxcutsroot" };
    //! maximum age a cut can reach before it is deleted from the global cut pool, or -1 to keep all cuts
    constexpr Param<int> CUTAGELIMIT { "separating/cutagelimit" };
    //! separation frequency for the global cut pool (-1: disable global cut pool, 0: only separate pool at the root)
    constexpr Param<int> POOLFREQ { "separating/poolfreq" };
}
//! Parameters with prefix separating/aggregation
namespace SEPARATING::AGGREGATION {
    //! priority of separator \<aggregation\>
    constexpr Param<int> PRIORITY { "separating/aggregation/priority" };
    //! frequency for calling separator \<aggregation\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/aggregation/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<aggregation\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/aggregation/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/aggregation/delay" };
    //! base for exponential increase of frequency at which separator \<aggregation\> is called (1: call at each
    //! multiple of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/aggregation/expbackoff" };
    //! maximal number of cmir separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/aggregation/maxrounds" };
    //! maximal number of cmir separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/aggregation/maxroundsroot" };
    //! maximal number of rows to start aggregation with per separation round (-1: unlimited)
    constexpr Param<int> MAXTRIES { "separating/aggregation/maxtries" };
    //! maximal number of rows to start aggregation with per separation round in the root node (-1: unlimited)
    constexpr Param<int> MAXTRIESROOT { "separating/aggregation/maxtriesroot" };
    //! maximal number of consecutive unsuccessful aggregation tries (-1: unlimited)
    constexpr Param<int> MAXFAILS { "separating/aggregation/maxfails" };
    //! maximal number of consecutive unsuccessful aggregation tries in the root node (-1: unlimited)
    constexpr Param<int> MAXFAILSROOT { "separating/aggregation/maxfailsroot" };
    //! maximal number of aggregations for each row per separation round
    constexpr Param<int> MAXAGGRS { "separating/aggregation/maxaggrs" };
    //! maximal number of aggregations for each row per separation round in the root node
    constexpr Param<int> MAXAGGRSROOT { "separating/aggregation/maxaggrsroot" };
    //! maximal number of cmir cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/aggregation/maxsepacuts" };
    //! maximal number of cmir cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "separating/aggregation/maxsepacutsroot" };
    //! maximal slack of rows to be used in aggregation
    constexpr Param<double> MAXSLACK { "separating/aggregation/maxslack" };
    //! maximal slack of rows to be used in aggregation in the root node
    constexpr Param<double> MAXSLACKROOT { "separating/aggregation/maxslackroot" };
    //! weight of row density in the aggregation scoring of the rows
    constexpr Param<double> DENSITYSCORE { "separating/aggregation/densityscore" };
    //! weight of slack in the aggregation scoring of the rows
    constexpr Param<double> SLACKSCORE { "separating/aggregation/slackscore" };
    //! maximal density of aggregated row
    constexpr Param<double> MAXAGGDENSITY { "separating/aggregation/maxaggdensity" };
    //! maximal density of row to be used in aggregation
    constexpr Param<double> MAXROWDENSITY { "separating/aggregation/maxrowdensity" };
    //! additional number of variables allowed in row on top of density
    constexpr Param<int> DENSITYOFFSET { "separating/aggregation/densityoffset" };
    //! maximal row aggregation factor
    constexpr Param<double> MAXROWFAC { "separating/aggregation/maxrowfac" };
    //! maximal number of different deltas to try (-1: unlimited)
    constexpr Param<int> MAXTESTDELTA { "separating/aggregation/maxtestdelta" };
    //! tolerance for bound distances used to select continuous variable in current aggregated constraint to be
    //! eliminated
    constexpr Param<double> AGGRTOL { "separating/aggregation/aggrtol" };
    //! should negative values also be tested in scaling?
    constexpr Param<bool> TRYNEGSCALING { "separating/aggregation/trynegscaling" };
    //! should an additional variable be complemented if f0 = 0?
    constexpr Param<bool> FIXINTEGRALRHS { "separating/aggregation/fixintegralrhs" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/aggregation/dynamiccuts" };
}
//! Parameters with prefix separating/cgmip
namespace SEPARATING::CGMIP {
    //! priority of separator \<cgmip\>
    constexpr Param<int> PRIORITY { "separating/cgmip/priority" };
    //! frequency for calling separator \<cgmip\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/cgmip/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<cgmip\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/cgmip/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/cgmip/delay" };
    //! base for exponential increase of frequency at which separator \<cgmip\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/cgmip/expbackoff" };
    //! maximal number of cgmip separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/cgmip/maxrounds" };
    //! maximal number of cgmip separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/cgmip/maxroundsroot" };
    //! maximal depth at which the separator is applied (-1: unlimited)
    constexpr Param<int> MAXDEPTH { "separating/cgmip/maxdepth" };
    //! Use decision tree to turn separation on/off?
    constexpr Param<bool> DECISIONTREE { "separating/cgmip/decisiontree" };
    //! time limit for sub-MIP
    constexpr Param<double> TIMELIMIT { "separating/cgmip/timelimit" };
    //! memory limit for sub-MIP
    constexpr Param<double> MEMORYLIMIT { "separating/cgmip/memorylimit" };
    //! minimum number of nodes considered for sub-MIP (-1: unlimited)
    constexpr Param<long long> MINNODELIMIT { "separating/cgmip/minnodelimit" };
    //! maximum number of nodes considered for sub-MIP (-1: unlimited)
    constexpr Param<long long> MAXNODELIMIT { "separating/cgmip/maxnodelimit" };
    //! bounds on the values of the coefficients in the CG-cut
    constexpr Param<double> CUTCOEFBND { "separating/cgmip/cutcoefbnd" };
    //! Use only active rows to generate cuts?
    constexpr Param<bool> ONLYACTIVEROWS { "separating/cgmip/onlyactiverows" };
    //! maximal age of rows to consider if onlyactiverows is false
    constexpr Param<int> MAXROWAGE { "separating/cgmip/maxrowage" };
    //! Separate only rank 1 inequalities w.r.t. CG-MIP separator?
    constexpr Param<bool> ONLYRANKONE { "separating/cgmip/onlyrankone" };
    //! Generate cuts for problems with only integer variables?
    constexpr Param<bool> ONLYINTVARS { "separating/cgmip/onlyintvars" };
    //! Convert some integral variables to be continuous to reduce the size of the sub-MIP?
    constexpr Param<bool> CONTCONVERT { "separating/cgmip/contconvert" };
    //! fraction of integral variables converted to be continuous (if contconvert)
    constexpr Param<double> CONTCONVFRAC { "separating/cgmip/contconvfrac" };
    //! minimum number of integral variables before some are converted to be continuous
    constexpr Param<int> CONTCONVMIN { "separating/cgmip/contconvmin" };
    //! Convert some integral variables attaining fractional values to have integral value?
    constexpr Param<bool> INTCONVERT { "separating/cgmip/intconvert" };
    //! fraction of frac. integral variables converted to have integral value (if intconvert)
    constexpr Param<double> INTCONVFRAC { "separating/cgmip/intconvfrac" };
    //! minimum number of integral variables before some are converted to have integral value
    constexpr Param<int> INTCONVMIN { "separating/cgmip/intconvmin" };
    //! Skip the upper bounds on the multipliers in the sub-MIP?
    constexpr Param<bool> SKIPMULTBOUNDS { "separating/cgmip/skipmultbounds" };
    //! Should the objective of the sub-MIP minimize the l1-norm of the multipliers?
    constexpr Param<bool> OBJLONE { "separating/cgmip/objlone" };
    //! weight used for the row combination coefficient in the sub-MIP objective
    constexpr Param<double> OBJWEIGHT { "separating/cgmip/objweight" };
    //! Weight each row by its size?
    constexpr Param<bool> OBJWEIGHTSIZE { "separating/cgmip/objweightsize" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/cgmip/dynamiccuts" };
    //! use CMIR-generator (otherwise add cut directly)?
    constexpr Param<bool> USECMIR { "separating/cgmip/usecmir" };
    //! use strong CG-function to strengthen cut?
    constexpr Param<bool> USESTRONGCG { "separating/cgmip/usestrongcg" };
    //! tell CMIR-generator which bounds to used in rounding?
    constexpr Param<bool> CMIROWNBOUNDS { "separating/cgmip/cmirownbounds" };
    //! use cutpool to store CG-cuts even if the are not efficient?
    constexpr Param<bool> USECUTPOOL { "separating/cgmip/usecutpool" };
    //! only separate cuts that are tight for the best feasible solution?
    constexpr Param<bool> PRIMALSEPARATION { "separating/cgmip/primalseparation" };
    //! terminate separation if a violated (but possibly sub-optimal) cut has been found?
    constexpr Param<bool> EARLYTERM { "separating/cgmip/earlyterm" };
    //! add constraint to subscip that only allows violated cuts (otherwise add obj. limit)?
    constexpr Param<bool> ADDVIOLATIONCONS { "separating/cgmip/addviolationcons" };
    //! add constraint handler to filter out violated cuts?
    constexpr Param<bool> ADDVIOLCONSHDLR { "separating/cgmip/addviolconshdlr" };
    //! should the violation constraint handler use the norm of a cut to check for feasibility?
    constexpr Param<bool> CONSHDLRUSENORM { "separating/cgmip/conshdlrusenorm" };
    //! Use upper bound on objective function (via primal solution)?
    constexpr Param<bool> USEOBJUB { "separating/cgmip/useobjub" };
    //! Use lower bound on objective function (via primal solution)?
    constexpr Param<bool> USEOBJLB { "separating/cgmip/useobjlb" };
    //! Should the settings for the sub-MIP be optimized for speed?
    constexpr Param<bool> SUBSCIPFAST { "separating/cgmip/subscipfast" };
    //! Should information about the sub-MIP and cuts be displayed?
    constexpr Param<bool> OUTPUT { "separating/cgmip/output" };
    //! Try to generate primal solutions from Gomory cuts?
    constexpr Param<bool> GENPRIMALSOLS { "separating/cgmip/genprimalsols" };
}
//! Parameters with prefix separating/clique
namespace SEPARATING::CLIQUE {
    //! priority of separator \<clique\>
    constexpr Param<int> PRIORITY { "separating/clique/priority" };
    //! frequency for calling separator \<clique\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/clique/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<clique\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/clique/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/clique/delay" };
    //! base for exponential increase of frequency at which separator \<clique\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/clique/expbackoff" };
    //! factor for scaling weights
    constexpr Param<double> SCALEVAL { "separating/clique/scaleval" };
    //! maximal number of nodes in branch and bound tree (-1: no limit)
    constexpr Param<int> MAXTREENODES { "separating/clique/maxtreenodes" };
    //! frequency for premature backtracking up to tree level 1 (0: no backtracking)
    constexpr Param<int> BACKTRACKFREQ { "separating/clique/backtrackfreq" };
    //! maximal number of clique cuts separated per separation round (-1: no limit)
    constexpr Param<int> MAXSEPACUTS { "separating/clique/maxsepacuts" };
    //! maximal number of zero-valued variables extending the clique (-1: no limit)
    constexpr Param<int> MAXZEROEXTENSIONS { "separating/clique/maxzeroextensions" };
    //! maximal memory size of dense clique table (in kb)
    constexpr Param<double> CLIQUETABLEMEM { "separating/clique/cliquetablemem" };
    //! minimal density of cliques to use a dense clique table
    constexpr Param<double> CLIQUEDENSITY { "separating/clique/cliquedensity" };
}
//! Parameters with prefix separating/closecuts
namespace SEPARATING::CLOSECUTS {
    //! priority of separator \<closecuts\>
    constexpr Param<int> PRIORITY { "separating/closecuts/priority" };
    //! frequency for calling separator \<closecuts\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/closecuts/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<closecuts\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/closecuts/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/closecuts/delay" };
    //! base for exponential increase of frequency at which separator \<closecuts\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/closecuts/expbackoff" };
    //! generate close cuts w.r.t. relative interior point (best solution otherwise)?
    constexpr Param<bool> SEPARELINT { "separating/closecuts/separelint" };
    //! convex combination value for close cuts
    constexpr Param<double> SEPACOMBVALUE { "separating/closecuts/sepacombvalue" };
    //! threshold on number of generated cuts below which the ordinary separation is started
    constexpr Param<int> CLOSETHRES { "separating/closecuts/closethres" };
    //! include an objective cutoff when computing the relative interior?
    constexpr Param<bool> INCLOBJCUTOFF { "separating/closecuts/inclobjcutoff" };
    //! recompute relative interior point in each separation call?
    constexpr Param<bool> RECOMPUTERELINT { "separating/closecuts/recomputerelint" };
    //! turn off separation in current node after unsuccessful calls (-1 never turn off)
    constexpr Param<int> MAXUNSUCCESSFUL { "separating/closecuts/maxunsuccessful" };
    //! factor for maximal LP iterations in relative interior computation compared to node LP iterations (negative for
    //! no limit)
    constexpr Param<double> MAXLPITERFACTOR { "separating/closecuts/maxlpiterfactor" };
}
//! Parameters with prefix separating/cmir
namespace SEPARATING::CMIR {
    //! priority of separator \<cmir\>
    constexpr Param<int> PRIORITY { "separating/cmir/priority" };
    //! frequency for calling separator \<cmir\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/cmir/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<cmir\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/cmir/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/cmir/delay" };
    //! base for exponential increase of frequency at which separator \<cmir\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/cmir/expbackoff" };
}
//! Parameters with prefix separating/convexproj
namespace SEPARATING::CONVEXPROJ {
    //! priority of separator \<convexproj\>
    constexpr Param<int> PRIORITY { "separating/convexproj/priority" };
    //! frequency for calling separator \<convexproj\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/convexproj/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<convexproj\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/convexproj/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/convexproj/delay" };
    //! base for exponential increase of frequency at which separator \<convexproj\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/convexproj/expbackoff" };
    //! maximal depth at which the separator is applied (-1: unlimited)
    constexpr Param<int> MAXDEPTH { "separating/convexproj/maxdepth" };
    //! iteration limit of NLP solver; 0 for no limit
    constexpr Param<int> NLPITERLIMIT { "separating/convexproj/nlpiterlimit" };
}
//! Parameters with prefix separating/disjunctive
namespace SEPARATING::DISJUNCTIVE {
    //! priority of separator \<disjunctive\>
    constexpr Param<int> PRIORITY { "separating/disjunctive/priority" };
    //! frequency for calling separator \<disjunctive\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/disjunctive/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<disjunctive\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/disjunctive/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/disjunctive/delay" };
    //! base for exponential increase of frequency at which separator \<disjunctive\> is called (1: call at each
    //! multiple of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/disjunctive/expbackoff" };
    //! strengthen cut if integer variables are present.
    constexpr Param<bool> STRENGTHEN { "separating/disjunctive/strengthen" };
    //! node depth of separating bipartite disjunctive cuts (-1: no limit)
    constexpr Param<int> MAXDEPTH { "separating/disjunctive/maxdepth" };
    //! maximal number of separation rounds per iteration in a branching node (-1: no limit)
    constexpr Param<int> MAXROUNDS { "separating/disjunctive/maxrounds" };
    //! maximal number of separation rounds in the root node (-1: no limit)
    constexpr Param<int> MAXROUNDSROOT { "separating/disjunctive/maxroundsroot" };
    //! maximal number of cuts investigated per iteration in a branching node
    constexpr Param<int> MAXINVCUTS { "separating/disjunctive/maxinvcuts" };
    //! maximal number of cuts investigated per iteration in the root node
    constexpr Param<int> MAXINVCUTSROOT { "separating/disjunctive/maxinvcutsroot" };
    //! delay separation if number of conflict graph edges is larger than predefined value (-1: no limit)
    constexpr Param<int> MAXCONFSDELAY { "separating/disjunctive/maxconfsdelay" };
    //! maximal rank of a disj. cut that could not be scaled to integral coefficients (-1: unlimited)
    constexpr Param<int> MAXRANK { "separating/disjunctive/maxrank" };
    //! maximal rank of a disj. cut that could be scaled to integral coefficients (-1: unlimited)
    constexpr Param<int> MAXRANKINTEGRAL { "separating/disjunctive/maxrankintegral" };
    //! maximal valid range max(|weights|)/min(|weights|) of row weights
    constexpr Param<double> MAXWEIGHTRANGE { "separating/disjunctive/maxweightrange" };
}
//! Parameters with prefix separating/eccuts
namespace SEPARATING::ECCUTS {
    //! priority of separator \<eccuts\>
    constexpr Param<int> PRIORITY { "separating/eccuts/priority" };
    //! frequency for calling separator \<eccuts\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/eccuts/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<eccuts\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/eccuts/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/eccuts/delay" };
    //! base for exponential increase of frequency at which separator \<eccuts\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/eccuts/expbackoff" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/eccuts/dynamiccuts" };
    //! maximal number of eccuts separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/eccuts/maxrounds" };
    //! maximal number of eccuts separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/eccuts/maxroundsroot" };
    //! maximal depth at which the separator is applied (-1: unlimited)
    constexpr Param<int> MAXDEPTH { "separating/eccuts/maxdepth" };
    //! maximal number of edge-concave cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/eccuts/maxsepacuts" };
    //! maximal number of edge-concave cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "separating/eccuts/maxsepacutsroot" };
    //! maximal coef. range of a cut (max coef. divided by min coef.) in order to be added to LP relaxation
    constexpr Param<double> CUTMAXRANGE { "separating/eccuts/cutmaxrange" };
    //! minimal violation of an edge-concave cut to be separated
    constexpr Param<double> MINVIOLATION { "separating/eccuts/minviolation" };
    //! search for edge-concave aggregations of at least this size
    constexpr Param<int> MINAGGRSIZE { "separating/eccuts/minaggrsize" };
    //! search for edge-concave aggregations of at most this size
    constexpr Param<int> MAXAGGRSIZE { "separating/eccuts/maxaggrsize" };
    //! maximum number of bilinear terms allowed to be in a quadratic constraint
    constexpr Param<int> MAXBILINTERMS { "separating/eccuts/maxbilinterms" };
    //! maximum number of unsuccessful rounds in the edge-concave aggregation search
    constexpr Param<int> MAXSTALLROUNDS { "separating/eccuts/maxstallrounds" };
}
//! Parameters with prefix separating/flowcover
namespace SEPARATING::FLOWCOVER {
    //! priority of separator \<flowcover\>
    constexpr Param<int> PRIORITY { "separating/flowcover/priority" };
    //! frequency for calling separator \<flowcover\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/flowcover/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<flowcover\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/flowcover/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/flowcover/delay" };
    //! base for exponential increase of frequency at which separator \<flowcover\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/flowcover/expbackoff" };
}
//! Parameters with prefix separating/gauge
namespace SEPARATING::GAUGE {
    //! priority of separator \<gauge\>
    constexpr Param<int> PRIORITY { "separating/gauge/priority" };
    //! frequency for calling separator \<gauge\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/gauge/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<gauge\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/gauge/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/gauge/delay" };
    //! base for exponential increase of frequency at which separator \<gauge\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/gauge/expbackoff" };
    //! iteration limit of NLP solver; 0 for no limit
    constexpr Param<int> NLPITERLIMIT { "separating/gauge/nlpiterlimit" };
}
//! Parameters with prefix separating/gomory
namespace SEPARATING::GOMORY {
    //! priority of separator \<gomory\>
    constexpr Param<int> PRIORITY { "separating/gomory/priority" };
    //! frequency for calling separator \<gomory\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/gomory/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<gomory\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/gomory/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/gomory/delay" };
    //! base for exponential increase of frequency at which separator \<gomory\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/gomory/expbackoff" };
    //! maximal number of gomory separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/gomory/maxrounds" };
    //! maximal number of gomory separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/gomory/maxroundsroot" };
    //! maximal number of gomory cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/gomory/maxsepacuts" };
    //! maximal number of gomory cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "separating/gomory/maxsepacutsroot" };
    //! maximal rank of a gomory cut that could not be scaled to integral coefficients (-1: unlimited)
    constexpr Param<int> MAXRANK { "separating/gomory/maxrank" };
    //! maximal rank of a gomory cut that could be scaled to integral coefficients (-1: unlimited)
    constexpr Param<int> MAXRANKINTEGRAL { "separating/gomory/maxrankintegral" };
    //! minimal integrality violation of a basis variable in order to try Gomory cut
    constexpr Param<double> AWAY { "separating/gomory/away" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/gomory/dynamiccuts" };
    //! try to scale cuts to integral coefficients
    constexpr Param<bool> MAKEINTEGRAL { "separating/gomory/makeintegral" };
    //! if conversion to integral coefficients failed still consider the cut
    constexpr Param<bool> FORCECUTS { "separating/gomory/forcecuts" };
    //! separate rows with integral slack
    constexpr Param<bool> SEPARATEROWS { "separating/gomory/separaterows" };
    //! should cuts be added to the delayed cut pool?
    constexpr Param<bool> DELAYEDCUTS { "separating/gomory/delayedcuts" };
    //! choose side types of row (lhs/rhs) based on basis information?
    constexpr Param<bool> SIDETYPEBASIS { "separating/gomory/sidetypebasis" };
    //! try to generate strengthened Chvatal-Gomory cuts?
    constexpr Param<bool> TRYSTRONGCG { "separating/gomory/trystrongcg" };
    //! Should both Gomory and strong CG cuts be generated (otherwise take best)?
    constexpr Param<bool> GENBOTHGOMSCG { "separating/gomory/genbothgomscg" };
}
//! Parameters with prefix separating/gomorymi
namespace SEPARATING::GOMORYMI {
    //! priority of separator \<gomorymi\>
    constexpr Param<int> PRIORITY { "separating/gomorymi/priority" };
    //! frequency for calling separator \<gomorymi\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/gomorymi/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<gomorymi\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/gomorymi/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/gomorymi/delay" };
    //! base for exponential increase of frequency at which separator \<gomorymi\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/gomorymi/expbackoff" };
}
//! Parameters with prefix separating/impliedbounds
namespace SEPARATING::IMPLIEDBOUNDS {
    //! priority of separator \<impliedbounds\>
    constexpr Param<int> PRIORITY { "separating/impliedbounds/priority" };
    //! frequency for calling separator \<impliedbounds\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/impliedbounds/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<impliedbounds\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/impliedbounds/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/impliedbounds/delay" };
    //! base for exponential increase of frequency at which separator \<impliedbounds\> is called (1: call at each
    //! multiple of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/impliedbounds/expbackoff" };
    //! should violated inequalities for cliques with 2 variables be separated?
    constexpr Param<bool> USETWOSIZECLIQUES { "separating/impliedbounds/usetwosizecliques" };
}
//! Parameters with prefix separating/interminor
namespace SEPARATING::INTERMINOR {
    //! priority of separator \<interminor\>
    constexpr Param<int> PRIORITY { "separating/interminor/priority" };
    //! frequency for calling separator \<interminor\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/interminor/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<interminor\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/interminor/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/interminor/delay" };
    //! base for exponential increase of frequency at which separator \<interminor\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/interminor/expbackoff" };
    //! whether to use strengthened intersection cuts to separate minors
    constexpr Param<bool> USESTRENGTHENING { "separating/interminor/usestrengthening" };
    //! whether to also enforce nonegativity bounds of principle minors
    constexpr Param<bool> USEBOUNDS { "separating/interminor/usebounds" };
    //! minimum required violation of a cut
    constexpr Param<double> MINCUTVIOL { "separating/interminor/mincutviol" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/interminor/maxrounds" };
    //! maximal number of separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/interminor/maxroundsroot" };
}
//! Parameters with prefix separating/intobj
namespace SEPARATING::INTOBJ {
    //! priority of separator \<intobj\>
    constexpr Param<int> PRIORITY { "separating/intobj/priority" };
    //! frequency for calling separator \<intobj\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/intobj/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<intobj\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/intobj/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/intobj/delay" };
    //! base for exponential increase of frequency at which separator \<intobj\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/intobj/expbackoff" };
}
//! Parameters with prefix separating/knapsackcover
namespace SEPARATING::KNAPSACKCOVER {
    //! priority of separator \<knapsackcover\>
    constexpr Param<int> PRIORITY { "separating/knapsackcover/priority" };
    //! frequency for calling separator \<knapsackcover\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/knapsackcover/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<knapsackcover\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/knapsackcover/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/knapsackcover/delay" };
    //! base for exponential increase of frequency at which separator \<knapsackcover\> is called (1: call at each
    //! multiple of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/knapsackcover/expbackoff" };
}
//! Parameters with prefix separating/mcf
namespace SEPARATING::MCF {
    //! priority of separator \<mcf\>
    constexpr Param<int> PRIORITY { "separating/mcf/priority" };
    //! frequency for calling separator \<mcf\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/mcf/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<mcf\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/mcf/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/mcf/delay" };
    //! base for exponential increase of frequency at which separator \<mcf\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/mcf/expbackoff" };
    //! number of clusters to generate in the shrunken network -- default separation
    constexpr Param<int> NCLUSTERS { "separating/mcf/nclusters" };
    //! maximal valid range max(|weights|)/min(|weights|) of row weights
    constexpr Param<double> MAXWEIGHTRANGE { "separating/mcf/maxweightrange" };
    //! maximal number of different deltas to try (-1: unlimited) -- default separation
    constexpr Param<int> MAXTESTDELTA { "separating/mcf/maxtestdelta" };
    //! should negative values also be tested in scaling?
    constexpr Param<bool> TRYNEGSCALING { "separating/mcf/trynegscaling" };
    //! should an additional variable be complemented if f0 = 0?
    constexpr Param<bool> FIXINTEGRALRHS { "separating/mcf/fixintegralrhs" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/mcf/dynamiccuts" };
    //! model type of network (0: auto, 1:directed, 2:undirected)
    constexpr Param<int> MODELTYPE { "separating/mcf/modeltype" };
    //! maximal number of mcf cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/mcf/maxsepacuts" };
    //! maximal number of mcf cuts separated per separation round in the root node -- default separation
    constexpr Param<int> MAXSEPACUTSROOT { "separating/mcf/maxsepacutsroot" };
    //! maximum inconsistency ratio for separation at all
    constexpr Param<double> MAXINCONSISTENCYRATIO { "separating/mcf/maxinconsistencyratio" };
    //! maximum inconsistency ratio of arcs not to be deleted
    constexpr Param<double> MAXARCINCONSISTENCYRATIO { "separating/mcf/maxarcinconsistencyratio" };
    //! should we separate only if the cuts shores are connected?
    constexpr Param<bool> CHECKCUTSHORECONNECTIVITY { "separating/mcf/checkcutshoreconnectivity" };
    //! should we separate inequalities based on single-node cuts?
    constexpr Param<bool> SEPARATESINGLENODECUTS { "separating/mcf/separatesinglenodecuts" };
    //! should we separate flowcutset inequalities on the network cuts?
    constexpr Param<bool> SEPARATEFLOWCUTSET { "separating/mcf/separateflowcutset" };
    //! should we separate knapsack cover inequalities on the network cuts?
    constexpr Param<bool> SEPARATEKNAPSACK { "separating/mcf/separateknapsack" };
}
//! Parameters with prefix separating/minor
namespace SEPARATING::MINOR {
    //! priority of separator \<minor\>
    constexpr Param<int> PRIORITY { "separating/minor/priority" };
    //! frequency for calling separator \<minor\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/minor/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<minor\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/minor/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/minor/delay" };
    //! base for exponential increase of frequency at which separator \<minor\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/minor/expbackoff" };
    //! constant for the maximum number of minors, i.e., max(const, fac * \# quadratic terms)
    constexpr Param<int> MAXMINORSCONST { "separating/minor/maxminorsconst" };
    //! factor for the maximum number of minors, i.e., max(const, fac * \# quadratic terms)
    constexpr Param<double> MAXMINORSFAC { "separating/minor/maxminorsfac" };
    //! minimum required violation of a cut
    constexpr Param<double> MINCUTVIOL { "separating/minor/mincutviol" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/minor/maxrounds" };
    //! maximal number of separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/minor/maxroundsroot" };
    //! whether to ignore circle packing constraints during minor detection
    constexpr Param<bool> IGNOREPACKINGCONSS { "separating/minor/ignorepackingconss" };
}
//! Parameters with prefix separating/mixing
namespace SEPARATING::MIXING {
    //! priority of separator \<mixing\>
    constexpr Param<int> PRIORITY { "separating/mixing/priority" };
    //! frequency for calling separator \<mixing\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/mixing/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<mixing\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/mixing/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/mixing/delay" };
    //! base for exponential increase of frequency at which separator \<mixing\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/mixing/expbackoff" };
    //! Should local bounds be used?
    constexpr Param<bool> USELOCALBOUNDS { "separating/mixing/uselocalbounds" };
    //! Should general integer variables be used to generate cuts?
    constexpr Param<bool> ISCUTSONINTS { "separating/mixing/iscutsonints" };
    //! maximal number of mixing separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/mixing/maxrounds" };
    //! maximal number of mixing separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/mixing/maxroundsroot" };
    //! maximal number of consecutive unsuccessful iterations
    constexpr Param<int> MAXNUNSUCCESSFUL { "separating/mixing/maxnunsuccessful" };
}
//! Parameters with prefix separating/oddcycle
namespace SEPARATING::ODDCYCLE {
    //! priority of separator \<oddcycle\>
    constexpr Param<int> PRIORITY { "separating/oddcycle/priority" };
    //! frequency for calling separator \<oddcycle\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/oddcycle/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<oddcycle\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/oddcycle/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/oddcycle/delay" };
    //! base for exponential increase of frequency at which separator \<oddcycle\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/oddcycle/expbackoff" };
    //! Should the search method by Groetschel, Lovasz, Schrijver be used? Otherwise use levelgraph method by Hoffman,
    //! Padberg.
    constexpr Param<bool> USEGLS { "separating/oddcycle/usegls" };
    //! Should odd cycle cuts be lifted?
    constexpr Param<bool> LIFTODDCYCLES { "separating/oddcycle/liftoddcycles" };
    //! maximal number of oddcycle cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/oddcycle/maxsepacuts" };
    //! maximal number of oddcycle cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "separating/oddcycle/maxsepacutsroot" };
    //! maximal number of oddcycle separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/oddcycle/maxrounds" };
    //! maximal number of oddcycle separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/oddcycle/maxroundsroot" };
    //! factor for scaling of the arc-weights
    constexpr Param<int> SCALINGFACTOR { "separating/oddcycle/scalingfactor" };
    //! add links between a variable and its negated
    constexpr Param<bool> ADDSELFARCS { "separating/oddcycle/addselfarcs" };
    //! try to repair violated cycles with double appearance of a variable
    constexpr Param<bool> REPAIRCYCLES { "separating/oddcycle/repaircycles" };
    //! separate triangles found as 3-cycles or repaired larger cycles
    constexpr Param<bool> INCLUDETRIANGLES { "separating/oddcycle/includetriangles" };
    //! Even if a variable is already covered by a cut, still try it as start node for a cycle search?
    constexpr Param<bool> MULTIPLECUTS { "separating/oddcycle/multiplecuts" };
    //! Even if a variable is already covered by a cut, still allow another cut to cover it too?
    constexpr Param<bool> ALLOWMULTIPLECUTS { "separating/oddcycle/allowmultiplecuts" };
    //! Choose lifting candidate by coef*lpvalue or only by coef?
    constexpr Param<bool> LPLIFTCOEF { "separating/oddcycle/lpliftcoef" };
    //! Calculate lifting coefficient of every candidate in every step (or only if its chosen)?
    constexpr Param<bool> RECALCLIFTCOEF { "separating/oddcycle/recalcliftcoef" };
    //! use sorted variable array (unsorted(0), maxlp(1), minlp(2), maxfrac(3), minfrac(4))
    constexpr Param<int> SORTSWITCH { "separating/oddcycle/sortswitch" };
    //! sort level of the root neighbors by fractionality (maxfrac)
    constexpr Param<bool> SORTROOTNEIGHBORS { "separating/oddcycle/sortrootneighbors" };
    //! percentage of variables to try the chosen method on [0-100]
    constexpr Param<int> PERCENTTESTVARS { "separating/oddcycle/percenttestvars" };
    //! offset of variables to try the chosen method on (additional to the percentage of testvars)
    constexpr Param<int> OFFSETTESTVARS { "separating/oddcycle/offsettestvars" };
    //! percentage of nodes allowed in the same level of the level graph [0-100]
    constexpr Param<int> MAXPERNODESLEVEL { "separating/oddcycle/maxpernodeslevel" };
    //! offset of nodes allowed in the same level of the level graph (additional to the percentage of levelnodes)
    constexpr Param<int> OFFSETNODESLEVEL { "separating/oddcycle/offsetnodeslevel" };
    //! maximal number of levels in level graph
    constexpr Param<int> MAXNLEVELS { "separating/oddcycle/maxnlevels" };
    //! maximal number of oddcycle cuts generated per chosen variable as root of the level graph
    constexpr Param<int> MAXCUTSROOT { "separating/oddcycle/maxcutsroot" };
    //! maximal number of oddcycle cuts generated in every level of the level graph
    constexpr Param<int> MAXCUTSLEVEL { "separating/oddcycle/maxcutslevel" };
    //! minimal weight on an edge (in level graph or bipartite graph)
    constexpr Param<int> MAXREFERENCE { "separating/oddcycle/maxreference" };
    //! number of unsuccessful calls at current node
    constexpr Param<int> MAXUNSUCESSFULL { "separating/oddcycle/maxunsucessfull" };
    //! maximal number of other cuts s.t. separation is applied (-1 for direct call)
    constexpr Param<int> CUTTHRESHOLD { "separating/oddcycle/cutthreshold" };
}
//! Parameters with prefix separating/rapidlearning
namespace SEPARATING::RAPIDLEARNING {
    //! priority of separator \<rapidlearning\>
    constexpr Param<int> PRIORITY { "separating/rapidlearning/priority" };
    //! frequency for calling separator \<rapidlearning\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/rapidlearning/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<rapidlearning\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/rapidlearning/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/rapidlearning/delay" };
    //! base for exponential increase of frequency at which separator \<rapidlearning\> is called (1: call at each
    //! multiple of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/rapidlearning/expbackoff" };
    //! should the found conflicts be applied in the original SCIP?
    constexpr Param<bool> APPLYCONFLICTS { "separating/rapidlearning/applyconflicts" };
    //! should the found global bound deductions be applied in the original SCIP?
    constexpr Param<bool> APPLYBDCHGS { "separating/rapidlearning/applybdchgs" };
    //! should the inference values be used as initialization in the original SCIP?
    constexpr Param<bool> APPLYINFERVALS { "separating/rapidlearning/applyinfervals" };
    //! should the inference values only be used when rapidlearning found other reductions?
    constexpr Param<bool> REDUCEDINFER { "separating/rapidlearning/reducedinfer" };
    //! should the incumbent solution be copied to the original SCIP?
    constexpr Param<bool> APPLYPRIMALSOL { "separating/rapidlearning/applyprimalsol" };
    //! should a solved status be copied to the original SCIP?
    constexpr Param<bool> APPLYSOLVED { "separating/rapidlearning/applysolved" };
    //! should local LP degeneracy be checked?
    constexpr Param<bool> CHECKDEGENERACY { "separating/rapidlearning/checkdegeneracy" };
    //! should the progress on the dual bound be checked?
    constexpr Param<bool> CHECKDUALBOUND { "separating/rapidlearning/checkdualbound" };
    //! should the ratio of leaves proven to be infeasible and exceeding the cutoff bound be checked?
    constexpr Param<bool> CHECKLEAVES { "separating/rapidlearning/checkleaves" };
    //! check whether rapid learning should be executed
    constexpr Param<bool> CHECKEXEC { "separating/rapidlearning/checkexec" };
    //! should the (local) objective function be checked?
    constexpr Param<bool> CHECKOBJ { "separating/rapidlearning/checkobj" };
    //! should the number of solutions found so far be checked?
    constexpr Param<bool> CHECKNSOLS { "separating/rapidlearning/checknsols" };
    //! should rapid learning be applied when there are continuous variables?
    constexpr Param<bool> CONTVARS { "separating/rapidlearning/contvars" };
    //! maximal portion of continuous variables to apply rapid learning
    constexpr Param<double> CONTVARSQUOT { "separating/rapidlearning/contvarsquot" };
    //! maximal fraction of LP iterations compared to node LP iterations
    constexpr Param<double> LPITERQUOT { "separating/rapidlearning/lpiterquot" };
    //! minimal degeneracy threshold to allow local rapid learning
    constexpr Param<double> MINDEGENERACY { "separating/rapidlearning/mindegeneracy" };
    //! minimal threshold of inf/obj leaves to allow local rapid learning
    constexpr Param<double> MININFLPRATIO { "separating/rapidlearning/mininflpratio" };
    //! minimal ratio of unfixed variables in relation to basis size to allow local rapid learning
    constexpr Param<double> MINVARCONSRATIO { "separating/rapidlearning/minvarconsratio" };
    //! maximum problem size (variables) for which rapid learning will be called
    constexpr Param<int> MAXNVARS { "separating/rapidlearning/maxnvars" };
    //! maximum problem size (constraints) for which rapid learning will be called
    constexpr Param<int> MAXNCONSS { "separating/rapidlearning/maxnconss" };
    //! maximum number of overall calls
    constexpr Param<int> MAXCALLS { "separating/rapidlearning/maxcalls" };
    //! maximum number of nodes considered in rapid learning run
    constexpr Param<int> MAXNODES { "separating/rapidlearning/maxnodes" };
    //! minimum number of nodes considered in rapid learning run
    constexpr Param<int> MINNODES { "separating/rapidlearning/minnodes" };
    //! number of nodes that should be processed before rapid learning is executed locally based on the progress of the
    //! dualbound
    constexpr Param<long long> NWAITINGNODES { "separating/rapidlearning/nwaitingnodes" };
    //! should all active cuts from cutpool be copied to constraints in subproblem?
    constexpr Param<bool> COPYCUTS { "separating/rapidlearning/copycuts" };
}
//! Parameters with prefix separating/rlt
namespace SEPARATING::RLT {
    //! priority of separator \<rlt\>
    constexpr Param<int> PRIORITY { "separating/rlt/priority" };
    //! frequency for calling separator \<rlt\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/rlt/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<rlt\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/rlt/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/rlt/delay" };
    //! base for exponential increase of frequency at which separator \<rlt\> is called (1: call at each multiple of
    //! frequency)
    constexpr Param<int> EXPBACKOFF { "separating/rlt/expbackoff" };
    //! maximal number of rlt-cuts that are added per round (-1: unlimited)
    constexpr Param<int> MAXNCUTS { "separating/rlt/maxncuts" };
    //! maximal number of unknown bilinear terms a row is still used with (-1: unlimited)
    constexpr Param<int> MAXUNKNOWNTERMS { "separating/rlt/maxunknownterms" };
    //! maximal number of variables used to compute rlt cuts (-1: unlimited)
    constexpr Param<int> MAXUSEDVARS { "separating/rlt/maxusedvars" };
    //! maximal number of separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/rlt/maxrounds" };
    //! maximal number of separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/rlt/maxroundsroot" };
    //! if set to true, only equality rows are used for rlt cuts
    constexpr Param<bool> ONLYEQROWS { "separating/rlt/onlyeqrows" };
    //! if set to true, only continuous rows are used for rlt cuts
    constexpr Param<bool> ONLYCONTROWS { "separating/rlt/onlycontrows" };
    //! if set to true, only original rows and variables are used
    constexpr Param<bool> ONLYORIGINAL { "separating/rlt/onlyoriginal" };
    //! if set to true, rlt is also used in sub-scips
    constexpr Param<bool> USEINSUBSCIP { "separating/rlt/useinsubscip" };
    //! if set to true, projected rows are checked first
    constexpr Param<bool> USEPROJECTION { "separating/rlt/useprojection" };
    //! if set to true, hidden products are detected and separated by McCormick cuts
    constexpr Param<bool> DETECTHIDDEN { "separating/rlt/detecthidden" };
    //! whether RLT cuts (TRUE) or only McCormick inequalities (FALSE) should be added for hidden products
    constexpr Param<bool> HIDDENRLT { "separating/rlt/hiddenrlt" };
    //! if set to true, globally valid RLT cuts are added to the global cut pool
    constexpr Param<bool> ADDTOPOOL { "separating/rlt/addtopool" };
    //! threshold for score of cut relative to best score to be considered good, so that less strict filtering is
    //! applied
    constexpr Param<double> GOODSCORE { "separating/rlt/goodscore" };
    //! threshold for score of cut relative to best score to be discarded
    constexpr Param<double> BADSCORE { "separating/rlt/badscore" };
    //! weight of objective parallelism in cut score calculation
    constexpr Param<double> OBJPARALWEIGHT { "separating/rlt/objparalweight" };
    //! weight of efficacy in cut score calculation
    constexpr Param<double> EFFICACYWEIGHT { "separating/rlt/efficacyweight" };
    //! weight of directed cutoff distance in cut score calculation
    constexpr Param<double> DIRCUTOFFDISTWEIGHT { "separating/rlt/dircutoffdistweight" };
    //! maximum parallelism for good cuts
    constexpr Param<double> GOODMAXPARALL { "separating/rlt/goodmaxparall" };
    //! maximum parallelism for non-good cuts
    constexpr Param<double> MAXPARALL { "separating/rlt/maxparall" };
}
//! Parameters with prefix separating/strongcg
namespace SEPARATING::STRONGCG {
    //! priority of separator \<strongcg\>
    constexpr Param<int> PRIORITY { "separating/strongcg/priority" };
    //! frequency for calling separator \<strongcg\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/strongcg/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<strongcg\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/strongcg/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/strongcg/delay" };
    //! base for exponential increase of frequency at which separator \<strongcg\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/strongcg/expbackoff" };
}
//! Parameters with prefix separating/zerohalf
namespace SEPARATING::ZEROHALF {
    //! priority of separator \<zerohalf\>
    constexpr Param<int> PRIORITY { "separating/zerohalf/priority" };
    //! frequency for calling separator \<zerohalf\> (-1: never, 0: only in root node)
    constexpr Param<int> FREQ { "separating/zerohalf/freq" };
    //! maximal relative distance from current node's dual bound to primal bound compared to best node's dual bound for
    //! applying separator \<zerohalf\> (0.0: only on current best node, 1.0: on all nodes)
    constexpr Param<double> MAXBOUNDDIST { "separating/zerohalf/maxbounddist" };
    //! should separator be delayed, if other separators found cuts?
    constexpr Param<bool> DELAY { "separating/zerohalf/delay" };
    //! base for exponential increase of frequency at which separator \<zerohalf\> is called (1: call at each multiple
    //! of frequency)
    constexpr Param<int> EXPBACKOFF { "separating/zerohalf/expbackoff" };
    //! maximal number of zerohalf separation rounds per node (-1: unlimited)
    constexpr Param<int> MAXROUNDS { "separating/zerohalf/maxrounds" };
    //! maximal number of zerohalf separation rounds in the root node (-1: unlimited)
    constexpr Param<int> MAXROUNDSROOT { "separating/zerohalf/maxroundsroot" };
    //! maximal number of zerohalf cuts separated per separation round
    constexpr Param<int> MAXSEPACUTS { "separating/zerohalf/maxsepacuts" };
    //! initial seed used for random tie-breaking in cut selection
    constexpr Param<int> INITSEED { "separating/zerohalf/initseed" };
    //! maximal number of zerohalf cuts separated per separation round in the root node
    constexpr Param<int> MAXSEPACUTSROOT { "separating/zerohalf/maxsepacutsroot" };
    //! maximal number of zerohalf cuts considered per separation round
    constexpr Param<int> MAXCUTCANDS { "separating/zerohalf/maxcutcands" };
    //! maximal slack of rows to be used in aggregation
    constexpr Param<double> MAXSLACK { "separating/zerohalf/maxslack" };
    //! maximal slack of rows to be used in aggregation in the root node
    constexpr Param<double> MAXSLACKROOT { "separating/zerohalf/maxslackroot" };
    //! threshold for score of cut relative to best score to be considered good, so that less strict filtering is
    //! applied
    constexpr Param<double> GOODSCORE { "separating/zerohalf/goodscore" };
    //! threshold for score of cut relative to best score to be discarded
    constexpr Param<double> BADSCORE { "separating/zerohalf/badscore" };
    //! weight of objective parallelism in cut score calculation
    constexpr Param<double> OBJPARALWEIGHT { "separating/zerohalf/objparalweight" };
    //! weight of efficacy in cut score calculation
    constexpr Param<double> EFFICACYWEIGHT { "separating/zerohalf/efficacyweight" };
    //! weight of directed cutoff distance in cut score calculation
    constexpr Param<double> DIRCUTOFFDISTWEIGHT { "separating/zerohalf/dircutoffdistweight" };
    //! maximum parallelism for good cuts
    constexpr Param<double> GOODMAXPARALL { "separating/zerohalf/goodmaxparall" };
    //! maximum parallelism for non-good cuts
    constexpr Param<double> MAXPARALL { "separating/zerohalf/maxparall" };
    //! minimal violation to generate zerohalfcut for
    constexpr Param<double> MINVIOL { "separating/zerohalf/minviol" };
    //! should generated cuts be removed from the LP if they are no longer tight?
    constexpr Param<bool> DYNAMICCUTS { "separating/zerohalf/dynamiccuts" };
    //! maximal density of row to be used in aggregation
    constexpr Param<double> MAXROWDENSITY { "separating/zerohalf/maxrowdensity" };
    //! additional number of variables allowed in row on top of density
    constexpr Param<int> DENSITYOFFSET { "separating/zerohalf/densityoffset" };
}
//! Parameters with prefix solvingphases
namespace SOLVINGPHASES {
    //! should the event handler adapt the solver behavior?
    constexpr Param<bool> ENABLED { "solvingphases/enabled" };
    //! should the event handler test all phase transitions?
    constexpr Param<bool> TESTMODE { "solvingphases/testmode" };
    //! settings file for feasibility phase -- precedence over emphasis settings
    constexpr Param<std::string> FEASSETNAME { "solvingphases/feassetname" };
    //! settings file for improvement phase -- precedence over emphasis settings
    constexpr Param<std::string> IMPROVESETNAME { "solvingphases/improvesetname" };
    //! settings file for proof phase -- precedence over emphasis settings
    constexpr Param<std::string> PROOFSETNAME { "solvingphases/proofsetname" };
    //! node offset for rank-1 and estimate transitions
    constexpr Param<long long> NODEOFFSET { "solvingphases/nodeoffset" };
    //! should the event handler fall back from optimal phase?
    constexpr Param<bool> FALLBACK { "solvingphases/fallback" };
    //! transition method: Possible options are 'e'stimate,'l'ogarithmic regression,'o'ptimal-value based,'r'ank-1
    constexpr Param<char> TRANSITIONMETHOD { "solvingphases/transitionmethod" };
    //! should the event handler interrupt the solving process after optimal solution was found?
    constexpr Param<bool> INTERRUPTOPTIMAL { "solvingphases/interruptoptimal" };
    //! should a restart be applied between the feasibility and improvement phase?
    constexpr Param<bool> USERESTART1TO2 { "solvingphases/userestart1to2" };
    //! should a restart be applied between the improvement and the proof phase?
    constexpr Param<bool> USERESTART2TO3 { "solvingphases/userestart2to3" };
    //! optimal solution value for problem
    constexpr Param<double> OPTIMALVALUE { "solvingphases/optimalvalue" };
    //! x-type for logarithmic regression - (t)ime, (n)odes, (l)p iterations
    constexpr Param<char> XTYPE { "solvingphases/xtype" };
    //! should emphasis settings for the solving phases be used, or settings files?
    constexpr Param<bool> USEEMPHSETTINGS { "solvingphases/useemphsettings" };
}
//! Parameters with prefix table/benders
namespace TABLE::BENDERS {
    //! is statistics table \<benders\> active
    constexpr Param<bool> ACTIVE { "table/benders/active" };
}
//! Parameters with prefix table/branchrules
namespace TABLE::BRANCHRULES {
    //! is statistics table \<branchrules\> active
    constexpr Param<bool> ACTIVE { "table/branchrules/active" };
}
//! Parameters with prefix table/compression
namespace TABLE::COMPRESSION {
    //! is statistics table \<compression\> active
    constexpr Param<bool> ACTIVE { "table/compression/active" };
}
//! Parameters with prefix table/concurrentsolver
namespace TABLE::CONCURRENTSOLVER {
    //! is statistics table \<concurrentsolver\> active
    constexpr Param<bool> ACTIVE { "table/concurrentsolver/active" };
}
//! Parameters with prefix table/conflict
namespace TABLE::CONFLICT {
    //! is statistics table \<conflict\> active
    constexpr Param<bool> ACTIVE { "table/conflict/active" };
}
//! Parameters with prefix table/constiming
namespace TABLE::CONSTIMING {
    //! is statistics table \<constiming\> active
    constexpr Param<bool> ACTIVE { "table/constiming/active" };
}
//! Parameters with prefix table/constraint
namespace TABLE::CONSTRAINT {
    //! is statistics table \<constraint\> active
    constexpr Param<bool> ACTIVE { "table/constraint/active" };
}
//! Parameters with prefix table/cons_nonlinear
namespace TABLE::CONS_NONLINEAR {
    //! is statistics table \<cons_nonlinear\> active
    constexpr Param<bool> ACTIVE { "table/cons_nonlinear/active" };
}
//! Parameters with prefix table/cutsel
namespace TABLE::CUTSEL {
    //! is statistics table \<cutsel\> active
    constexpr Param<bool> ACTIVE { "table/cutsel/active" };
}
//! Parameters with prefix table/estim
namespace TABLE::ESTIM {
    //! is statistics table \<estim\> active
    constexpr Param<bool> ACTIVE { "table/estim/active" };
}
//! Parameters with prefix table/exprhdlr
namespace TABLE::EXPRHDLR {
    //! is statistics table \<exprhdlr\> active
    constexpr Param<bool> ACTIVE { "table/exprhdlr/active" };
}
//! Parameters with prefix table/heuristics
namespace TABLE::HEURISTICS {
    //! is statistics table \<heuristics\> active
    constexpr Param<bool> ACTIVE { "table/heuristics/active" };
}
//! Parameters with prefix table/lp
namespace TABLE::LP {
    //! is statistics table \<lp\> active
    constexpr Param<bool> ACTIVE { "table/lp/active" };
}
//! Parameters with prefix table/neighborhood
namespace TABLE::NEIGHBORHOOD {
    //! is statistics table \<neighborhood\> active
    constexpr Param<bool> ACTIVE { "table/neighborhood/active" };
}
//! Parameters with prefix table/nlhdlr
namespace TABLE::NLHDLR {
    //! is statistics table \<nlhdlr\> active
    constexpr Param<bool> ACTIVE { "table/nlhdlr/active" };
}
//! Parameters with prefix table/nlhdlr_bilinear
namespace TABLE::NLHDLR_BILINEAR {
    //! is statistics table \<nlhdlr_bilinear\> active
    constexpr Param<bool> ACTIVE { "table/nlhdlr_bilinear/active" };
}
//! Parameters with prefix table/nlhdlr_quadratic
namespace TABLE::NLHDLR_QUADRATIC {
    //! is statistics table \<nlhdlr_quadratic\> active
    constexpr Param<bool> ACTIVE { "table/nlhdlr_quadratic/active" };
}
//! Parameters with prefix table/nlp
namespace TABLE::NLP {
    //! is statistics table \<nlp\> active
    constexpr Param<bool> ACTIVE { "table/nlp/active" };
}
//! Parameters with prefix table/nlpi
namespace TABLE::NLPI {
    //! is statistics table \<nlpi\> active
    constexpr Param<bool> ACTIVE { "table/nlpi/active" };
}
//! Parameters with prefix table/orbitalfixing
namespace TABLE::ORBITALFIXING {
    //! is statistics table \<orbitalfixing\> active
    constexpr Param<bool> ACTIVE { "table/orbitalfixing/active" };
}
//! Parameters with prefix table/origprob
namespace TABLE::ORIGPROB {
    //! is statistics table \<origprob\> active
    constexpr Param<bool> ACTIVE { "table/origprob/active" };
}
//! Parameters with prefix table/presolvedprob
namespace TABLE::PRESOLVEDPROB {
    //! is statistics table \<presolvedprob\> active
    constexpr Param<bool> ACTIVE { "table/presolvedprob/active" };
}
//! Parameters with prefix table/presolver
namespace TABLE::PRESOLVER {
    //! is statistics table \<presolver\> active
    constexpr Param<bool> ACTIVE { "table/presolver/active" };
}
//! Parameters with prefix table/pricer
namespace TABLE::PRICER {
    //! is statistics table \<pricer\> active
    constexpr Param<bool> ACTIVE { "table/pricer/active" };
}
//! Parameters with prefix table/propagator
namespace TABLE::PROPAGATOR {
    //! is statistics table \<propagator\> active
    constexpr Param<bool> ACTIVE { "table/propagator/active" };
}
//! Parameters with prefix table/relaxator
namespace TABLE::RELAXATOR {
    //! is statistics table \<relaxator\> active
    constexpr Param<bool> ACTIVE { "table/relaxator/active" };
}
//! Parameters with prefix table/root
namespace TABLE::ROOT {
    //! is statistics table \<root\> active
    constexpr Param<bool> ACTIVE { "table/root/active" };
}
//! Parameters with prefix table/separator
namespace TABLE::SEPARATOR {
    //! is statistics table \<separator\> active
    constexpr Param<bool> ACTIVE { "table/separator/active" };
}
//! Parameters with prefix table/solution
namespace TABLE::SOLUTION {
    //! is statistics table \<solution\> active
    constexpr Param<bool> ACTIVE { "table/solution/active" };
}
//! Parameters with prefix table/status
namespace TABLE::STATUS {
    //! is statistics table \<status\> active
    constexpr Param<bool> ACTIVE { "table/status/active" };
}
//! Parameters with prefix table/timing
namespace TABLE::TIMING {
    //! is statistics table \<timing\> active
    constexpr Param<bool> ACTIVE { "table/timing/active" };
}
//! Parameters with prefix table/tree
namespace TABLE::TREE {
    //! is statistics table \<tree\> active
    constexpr Param<bool> ACTIVE { "table/tree/active" };
}
//! Parameters with prefix timing
namespace TIMING {
    //! default clock type (1: CPU user seconds, 2: wall clock time)
    constexpr Param<int> CLOCKTYPE { "timing/clocktype" };
    //! is timing enabled?
    constexpr Param<bool> ENABLED { "timing/enabled" };
    //! belongs reading time to solving time?
    constexpr Param<bool> READING { "timing/reading" };
    //! should clock checks of solving time be performed less frequently (note: time limit could be exceeded slightly)
    constexpr Param<bool> RARECLOCKCHECK { "timing/rareclockcheck" };
    //! should timing for statistic output be performed?
    constexpr Param<bool> STATISTICTIMING { "timing/statistictiming" };
    //! should time for evaluation in NLP solves be measured?
    constexpr Param<bool> NLPIEVAL { "timing/nlpieval" };
}
//! Parameters with prefix visual
namespace VISUAL {
    //! name of the VBC tool output file, or - if no VBC tool output should be created
    constexpr Param<std::string> VBCFILENAME { "visual/vbcfilename" };
    //! name of the BAK tool output file, or - if no BAK tool output should be created
    constexpr Param<std::string> BAKFILENAME { "visual/bakfilename" };
    //! should the real solving time be used instead of a time step counter in visualization?
    constexpr Param<bool> REALTIME { "visual/realtime" };
    //! should the node where solutions are found be visualized?
    constexpr Param<bool> DISPSOLS { "visual/dispsols" };
    //! should lower bound information be visualized?
    constexpr Param<bool> DISPLB { "visual/displb" };
    //! should be output the external value of the objective?
    constexpr Param<bool> OBJEXTERN { "visual/objextern" };
}
//! Parameters with prefix write
namespace WRITE {
    //! should all constraints be written (including the redundant constraints)?
    constexpr Param<bool> ALLCONSS { "write/allconss" };
    //! should variables set to zero be printed?
    constexpr Param<bool> PRINTZEROS { "write/printzeros" };
    //! when writing a generic problem the index for the first variable should start with?
    constexpr Param<int> GENERICNAMESOFFSET { "write/genericnamesoffset" };
}

}
