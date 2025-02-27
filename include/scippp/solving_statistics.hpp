#pragma once

#include "scippp/statistics.hpp"

#include <scip/scip_solvingstats.h>

// the content of this file is auto-generated by extract_solvingstats.py
// updated for SCIP 9.2.0

namespace scippp::statistics {

//! number of branch and bound runs performed, including the current run
static const Statistic<int> N_RUNS { &SCIPgetNRuns };
//! number of reoptimization runs performed, including the current run
static const Statistic<int> N_REOPT_RUNS { &SCIPgetNReoptRuns };
//! number of processed nodes in current run, including the focus node
static const Statistic<SCIP_Longint> N_NODES { &SCIPgetNNodes };
//! total number of processed nodes in all runs, including the focus node
static const Statistic<SCIP_Longint> N_TOTAL_NODES { &SCIPgetNTotalNodes };
//! number of leaf nodes processed with feasible relaxation solution
static const Statistic<SCIP_Longint> N_FEASIBLE_LEAVES { &SCIPgetNFeasibleLeaves };
//! number of infeasible leaf nodes processed
static const Statistic<SCIP_Longint> N_INFEASIBLE_LEAVES { &SCIPgetNInfeasibleLeaves };
//! number of processed leaf nodes that hit LP objective limit
static const Statistic<SCIP_Longint> N_OBJLIM_LEAVES { &SCIPgetNObjlimLeaves };
//! number of global bound changes
static const Statistic<int> N_ROOTBOUND_CHGS { &SCIPgetNRootboundChgs };
//! number of global bound changes
static const Statistic<int> N_ROOTBOUND_CHGS_RUN { &SCIPgetNRootboundChgsRun };
//! number of times a selected node was from a cut off subtree
static const Statistic<SCIP_Longint> N_DELAYED_CUTOFFS { &SCIPgetNDelayedCutoffs };
//! total number of LPs solved so far
static const Statistic<SCIP_Longint> N_L_PS { &SCIPgetNLPs };
//! total number of iterations used so far in primal and dual simplex and barrier algorithm
static const Statistic<SCIP_Longint> N_LP_ITERATIONS { &SCIPgetNLPIterations };
//! number of active non-zeros in the current transformed problem
static const Statistic<SCIP_Longint> N_N_ZS { &SCIPgetNNZs };
//! total number of iterations used so far in primal and dual simplex and barrier algorithm for the root node
static const Statistic<SCIP_Longint> N_ROOT_LP_ITERATIONS { &SCIPgetNRootLPIterations };
//! total number of iterations used in primal and dual simplex and barrier algorithm for the first root LP
static const Statistic<SCIP_Longint> N_ROOT_FIRST_LP_ITERATIONS { &SCIPgetNRootFirstLPIterations };
//! total number of primal LPs solved so far
static const Statistic<SCIP_Longint> N_PRIMAL_L_PS { &SCIPgetNPrimalLPs };
//! total number of iterations used so far in primal simplex
static const Statistic<SCIP_Longint> N_PRIMAL_LP_ITERATIONS { &SCIPgetNPrimalLPIterations };
//! total number of dual LPs solved so far
static const Statistic<SCIP_Longint> N_DUAL_L_PS { &SCIPgetNDualLPs };
//! total number of iterations used so far in dual simplex
static const Statistic<SCIP_Longint> N_DUAL_LP_ITERATIONS { &SCIPgetNDualLPIterations };
//! total number of barrier LPs solved so far
static const Statistic<SCIP_Longint> N_BARRIER_L_PS { &SCIPgetNBarrierLPs };
//! total number of iterations used so far in barrier algorithm
static const Statistic<SCIP_Longint> N_BARRIER_LP_ITERATIONS { &SCIPgetNBarrierLPIterations };
//! total number of LPs solved so far that were resolved from an advanced start basis
static const Statistic<SCIP_Longint> N_RESOLVE_L_PS { &SCIPgetNResolveLPs };
//! total number of simplex iterations used so far in primal and dual simplex calls where an advanced start
static const Statistic<SCIP_Longint> N_RESOLVE_LP_ITERATIONS { &SCIPgetNResolveLPIterations };
//! total number of primal LPs solved so far that were resolved from an advanced start basis
static const Statistic<SCIP_Longint> N_PRIMAL_RESOLVE_L_PS { &SCIPgetNPrimalResolveLPs };
//! total number of simplex iterations used so far in primal simplex calls where an advanced start
static const Statistic<SCIP_Longint> N_PRIMAL_RESOLVE_LP_ITERATIONS { &SCIPgetNPrimalResolveLPIterations };
//! total number of dual LPs solved so far that were resolved from an advanced start basis
static const Statistic<SCIP_Longint> N_DUAL_RESOLVE_L_PS { &SCIPgetNDualResolveLPs };
//! total number of simplex iterations used so far in dual simplex calls where an advanced start
static const Statistic<SCIP_Longint> N_DUAL_RESOLVE_LP_ITERATIONS { &SCIPgetNDualResolveLPIterations };
//! total number of LPs solved so far for node relaxations
static const Statistic<SCIP_Longint> N_NODE_L_PS { &SCIPgetNNodeLPs };
//! total number of LPs solved with 0 iteratins for node relaxations
static const Statistic<SCIP_Longint> N_NODE_ZERO_ITERATION_L_PS { &SCIPgetNNodeZeroIterationLPs };
//! total number of simplex iterations used so far for node relaxations
static const Statistic<SCIP_Longint> N_NODE_LP_ITERATIONS { &SCIPgetNNodeLPIterations };
//! total number of LPs solved so far for initial LP in node relaxations
static const Statistic<SCIP_Longint> N_NODE_INIT_L_PS { &SCIPgetNNodeInitLPs };
//! total number of simplex iterations used so far for initial LP in node relaxations
static const Statistic<SCIP_Longint> N_NODE_INIT_LP_ITERATIONS { &SCIPgetNNodeInitLPIterations };
//! total number of LPs solved so far during diving and probing
static const Statistic<SCIP_Longint> N_DIVING_L_PS { &SCIPgetNDivingLPs };
//! total number of simplex iterations used so far during diving and probing
static const Statistic<SCIP_Longint> N_DIVING_LP_ITERATIONS { &SCIPgetNDivingLPIterations };
//! total number of times, strong branching was called (each call represents solving two LPs)
static const Statistic<SCIP_Longint> N_STRONGBRANCHS { &SCIPgetNStrongbranchs };
//! total number of simplex iterations used so far in strong branching
static const Statistic<SCIP_Longint> N_STRONGBRANCH_LP_ITERATIONS { &SCIPgetNStrongbranchLPIterations };
//! total number of times, strong branching was called at the root node (each call represents solving two LPs)
static const Statistic<SCIP_Longint> N_ROOT_STRONGBRANCHS { &SCIPgetNRootStrongbranchs };
//! total number of simplex iterations used so far in strong branching at the root node
static const Statistic<SCIP_Longint> N_ROOT_STRONGBRANCH_LP_ITERATIONS { &SCIPgetNRootStrongbranchLPIterations };
//! number of pricing rounds performed so far at the current node
static const Statistic<int> N_PRICE_ROUNDS { &SCIPgetNPriceRounds };
//! current number of variables in the pricing store
static const Statistic<int> N_PRICEVARS { &SCIPgetNPricevars };
//! total number of pricing variables found so far
static const Statistic<int> N_PRICEVARS_FOUND { &SCIPgetNPricevarsFound };
//! total number of pricing variables applied to the LPs
static const Statistic<int> N_PRICEVARS_APPLIED { &SCIPgetNPricevarsApplied };
//! number of separation rounds performed so far at the current node
static const Statistic<int> N_SEPA_ROUNDS { &SCIPgetNSepaRounds };
//! total number of cuts found so far
static const Statistic<int> N_CUTS_FOUND { &SCIPgetNCutsFound };
//! number of cuts found so far in current separation round
static const Statistic<int> N_CUTS_FOUND_ROUND { &SCIPgetNCutsFoundRound };
//! total number of cuts applied to the LPs
static const Statistic<int> N_CUTS_APPLIED { &SCIPgetNCutsApplied };
//! total number of constraints found in conflict analysis (conflict and reconvergence constraints)
static const Statistic<SCIP_Longint> N_CONFLICT_CONSS_FOUND { &SCIPgetNConflictConssFound };
//! number of conflict constraints found so far at the current node
static const Statistic<int> N_CONFLICT_CONSS_FOUND_NODE { &SCIPgetNConflictConssFoundNode };
//! total number of conflict constraints added to the problem
static const Statistic<SCIP_Longint> N_CONFLICT_CONSS_APPLIED { &SCIPgetNConflictConssApplied };
//! total number of dual proof constraints added to the problem
static const Statistic<SCIP_Longint> N_CONFLICT_DUALPROOFS_APPLIED { &SCIPgetNConflictDualproofsApplied };
//! maximal depth of all processed nodes in current branch and bound run (excluding probing nodes)
static const Statistic<int> MAX_DEPTH { &SCIPgetMaxDepth };
//! maximal depth of all processed nodes over all branch and bound runs
static const Statistic<int> MAX_TOTAL_DEPTH { &SCIPgetMaxTotalDepth };
//! total number of backtracks, i.e. number of times, the new node was selected from the leaves queue
static const Statistic<SCIP_Longint> N_BACKTRACKS { &SCIPgetNBacktracks };
//! total number of active constraints at the current node
static const Statistic<int> N_ACTIVE_CONSS { &SCIPgetNActiveConss };
//! total number of enabled constraints at the current node
static const Statistic<int> N_ENABLED_CONSS { &SCIPgetNEnabledConss };
//! average dual bound of all unprocessed nodes for original problem
static const Statistic<SCIP_Real> AVG_DUALBOUND { &SCIPgetAvgDualbound };
//! average lower (dual) bound of all unprocessed nodes in transformed problem
static const Statistic<SCIP_Real> AVG_LOWERBOUND { &SCIPgetAvgLowerbound };
//! global dual bound
static const Statistic<SCIP_Real> DUALBOUND { &SCIPgetDualbound };
//! global lower (dual) bound in transformed problem
static const Statistic<SCIP_Real> LOWERBOUND { &SCIPgetLowerbound };
//! dual bound of the root node for the original problem
static const Statistic<SCIP_Real> DUALBOUND_ROOT { &SCIPgetDualboundRoot };
//! lower (dual) bound in transformed problem of the root node
static const Statistic<SCIP_Real> LOWERBOUND_ROOT { &SCIPgetLowerboundRoot };
//! dual bound for the original problem of the first LP solve at the root node
static const Statistic<SCIP_Real> FIRST_LP_DUALBOUND_ROOT { &SCIPgetFirstLPDualboundRoot };
//! lower (dual) bound in transformed problem obtained by first LP solve at the root node
static const Statistic<SCIP_Real> FIRST_LP_LOWERBOUND_ROOT { &SCIPgetFirstLPLowerboundRoot };
//! primal bound of the very first solution
static const Statistic<SCIP_Real> FIRST_PRIMAL_BOUND { &SCIPgetFirstPrimalBound };
//! global primal bound (objective value of best solution or user objective limit) for the original problem
static const Statistic<SCIP_Real> PRIMALBOUND { &SCIPgetPrimalbound };
//! global upper (primal) bound in transformed problem (objective value of best solution or user objective limit)
static const Statistic<SCIP_Real> UPPERBOUND { &SCIPgetUpperbound };
//! global cutoff bound in transformed problem
static const Statistic<SCIP_Real> CUTOFFBOUND { &SCIPgetCutoffbound };
//! current gap |(primalbound - dualbound)/min(|primalbound|,|dualbound|)| if both bounds have same sign,
static const Statistic<SCIP_Real> GAP { &SCIPgetGap };
//! current gap |(upperbound - lowerbound)/min(|upperbound|,|lowerbound|)| in transformed problem if both bounds
static const Statistic<SCIP_Real> TRANS_GAP { &SCIPgetTransGap };
//! number of feasible primal solutions found so far
static const Statistic<SCIP_Longint> N_SOLS_FOUND { &SCIPgetNSolsFound };
//! number of feasible primal solutions respecting the objective limit found so far
static const Statistic<SCIP_Longint> N_LIM_SOLS_FOUND { &SCIPgetNLimSolsFound };
//! number of feasible primal solutions found so far, that improved the primal bound at the time they were found
static const Statistic<SCIP_Longint> N_BEST_SOLS_FOUND { &SCIPgetNBestSolsFound };
//! average pseudo cost score value over all variables, assuming a fractionality of 0.5
static const Statistic<SCIP_Real> AVG_PSEUDOCOST_SCORE { &SCIPgetAvgPseudocostScore };
//! average pseudo cost score value over all variables, assuming a fractionality of 0.5,
static const Statistic<SCIP_Real> AVG_PSEUDOCOST_SCORE_CURRENT_RUN { &SCIPgetAvgPseudocostScoreCurrentRun };
//! average conflict score value over all variables
static const Statistic<SCIP_Real> AVG_CONFLICT_SCORE { &SCIPgetAvgConflictScore };
//! average conflict score value over all variables, only using the conflict information of the current run
static const Statistic<SCIP_Real> AVG_CONFLICT_SCORE_CURRENT_RUN { &SCIPgetAvgConflictScoreCurrentRun };
//! average inference score value over all variables
static const Statistic<SCIP_Real> AVG_CONFLICTLENGTH_SCORE { &SCIPgetAvgConflictlengthScore };
//! average conflictlength score value over all variables, only using the conflictlength information of the
static const Statistic<SCIP_Real> AVG_CONFLICTLENGTH_SCORE_CURRENT_RUN { &SCIPgetAvgConflictlengthScoreCurrentRun };
//! average inference score value over all variables
static const Statistic<SCIP_Real> AVG_INFERENCE_SCORE { &SCIPgetAvgInferenceScore };
//! average inference score value over all variables, only using the inference information of the
static const Statistic<SCIP_Real> AVG_INFERENCE_SCORE_CURRENT_RUN { &SCIPgetAvgInferenceScoreCurrentRun };
//! average cutoff score value over all variables
static const Statistic<SCIP_Real> AVG_CUTOFF_SCORE { &SCIPgetAvgCutoffScore };
//! average cutoff score value over all variables, only using the cutoff information of the current run
static const Statistic<SCIP_Real> AVG_CUTOFF_SCORE_CURRENT_RUN { &SCIPgetAvgCutoffScoreCurrentRun };
//! average normalized efficacy of a GMI cut over all variables
static const Statistic<SCIP_Real> AVG_G_M_IEFF { &SCIPgetAvgGMIeff };
//! total number of LPs solved so far
static const Statistic<SCIP_Real> DETERMINISTIC_TIME { &SCIPgetDeterministicTime };
//! total number of implications between variables that are stored in the implication graph
static const Statistic<int> N_IMPLICATIONS { &SCIPgetNImplications };
//! recomputes and returns the primal dual gap stored in the stats
static const Statistic<SCIP_Real> PRIMAL_DUAL_INTEGRAL { &SCIPgetPrimalDualIntegral };

}
