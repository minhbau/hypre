
#include <HYPRE_config.h>

#include "HYPRE_parcsr_ls.h"

#ifndef hypre_PARCSR_LS_HEADER
#define hypre_PARCSR_LS_HEADER

#include "utilities.h"
#include "krylov.h"
#include "seq_matrix_vector.h"
#include "parcsr_matrix_vector.h"

#ifdef __cplusplus
extern "C" {
#endif


/* HYPRE_parcsr_Euclid.c */
int HYPRE_ParCSREuclidCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSREuclidDestroy( HYPRE_Solver solver );
int HYPRE_ParCSREuclidSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSREuclidSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector bb , HYPRE_ParVector xx );
int HYPRE_ParCSREuclidSetParams( HYPRE_Solver solver , int argc , char *argv []);
int HYPRE_ParCSREuclidSetParamsFromFile( HYPRE_Solver solver , char *filename );
int HYPRE_ParCSREuclidPrintParams( HYPRE_Solver solver );
int HYPRE_ParCSREuclidReadRho( HYPRE_Solver solver , double *rho );
int HYPRE_ParCSREuclidSetLogging( HYPRE_Solver solver , int logging );

/* HYPRE_parcsr_ParaSails.c */
int HYPRE_ParCSRParaSailsCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRParaSailsDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRParaSailsSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRParaSailsSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRParaSailsSetParams( HYPRE_Solver solver , double thresh , int nlevels );
int HYPRE_ParCSRParaSailsSetFilter( HYPRE_Solver solver , double filter );
int HYPRE_ParCSRParaSailsSetSym( HYPRE_Solver solver , int sym );
int HYPRE_ParCSRParaSailsSetLoadbal( HYPRE_Solver solver , double loadbal );
int HYPRE_ParCSRParaSailsSetReuse( HYPRE_Solver solver , int reuse );
int HYPRE_ParCSRParaSailsSetLogging( HYPRE_Solver solver , int logging );

/* HYPRE_parcsr_amg.c */
int HYPRE_BoomerAMGCreate( HYPRE_Solver *solver );
int HYPRE_BoomerAMGDestroy( HYPRE_Solver solver );
int HYPRE_BoomerAMGSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_BoomerAMGSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_BoomerAMGSolveT( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_BoomerAMGSetRestriction( HYPRE_Solver solver , int restr_par );
int HYPRE_BoomerAMGSetMaxLevels( HYPRE_Solver solver , int max_levels );
int HYPRE_BoomerAMGSetStrongThreshold( HYPRE_Solver solver , double strong_threshold );
int HYPRE_BoomerAMGSetMaxRowSum( HYPRE_Solver solver , double max_row_sum );
int HYPRE_BoomerAMGSetTruncFactor( HYPRE_Solver solver , double trunc_factor );
int HYPRE_BoomerAMGSetInterpType( HYPRE_Solver solver , int interp_type );
int HYPRE_BoomerAMGSetMinIter( HYPRE_Solver solver , int min_iter );
int HYPRE_BoomerAMGSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_BoomerAMGSetCoarsenType( HYPRE_Solver solver , int coarsen_type );
int HYPRE_BoomerAMGSetMeasureType( HYPRE_Solver solver , int measure_type );
int HYPRE_BoomerAMGSetSetupType( HYPRE_Solver solver , int setup_type );
int HYPRE_BoomerAMGSetCycleType( HYPRE_Solver solver , int cycle_type );
int HYPRE_BoomerAMGSetTol( HYPRE_Solver solver , double tol );
int HYPRE_BoomerAMGSetNumGridSweeps( HYPRE_Solver solver , int *num_grid_sweeps );
int HYPRE_BoomerAMGInitGridRelaxation( int **num_grid_sweeps_ptr , int **grid_relax_type_ptr , int ***grid_relax_points_ptr , int coarsen_type , double **relax_weights_ptr , int max_levels );
int HYPRE_BoomerAMGSetGridRelaxType( HYPRE_Solver solver , int *grid_relax_type );
int HYPRE_BoomerAMGSetGridRelaxPoints( HYPRE_Solver solver , int **grid_relax_points );
int HYPRE_BoomerAMGSetRelaxWeight( HYPRE_Solver solver , double *relax_weight );
int HYPRE_BoomerAMGSetIOutDat( HYPRE_Solver solver , int ioutdat );
int HYPRE_BoomerAMGSetLogFileName( HYPRE_Solver solver , char *log_file_name );
int HYPRE_BoomerAMGSetLogging( HYPRE_Solver solver , int ioutdat , char *log_file_name );
int HYPRE_BoomerAMGSetDebugFlag( HYPRE_Solver solver , int debug_flag );
int HYPRE_BoomerAMGGetNumIterations( HYPRE_Solver solver , int *num_iterations );
int HYPRE_BoomerAMGGetFinalRelativeResidualNorm( HYPRE_Solver solver , double *rel_resid_norm );
int HYPRE_BoomerAMGSetNumFunctions( HYPRE_Solver solver , int num_functions );
int HYPRE_BoomerAMGSetDofFunc( HYPRE_Solver solver , int *dof_func );

/* HYPRE_parcsr_bicgstab.c */
int HYPRE_ParCSRBiCGSTABCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRBiCGSTABDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRBiCGSTABSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRBiCGSTABSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRBiCGSTABSetTol( HYPRE_Solver solver , double tol );
int HYPRE_ParCSRBiCGSTABSetMinIter( HYPRE_Solver solver , int min_iter );
int HYPRE_ParCSRBiCGSTABSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_ParCSRBiCGSTABSetStopCrit( HYPRE_Solver solver , int stop_crit );
int HYPRE_ParCSRBiCGSTABSetPrecond( HYPRE_Solver solver , HYPRE_PtrToSolverFcn precond , HYPRE_PtrToSolverFcn precond_setup , HYPRE_Solver precond_solver );
int HYPRE_ParCSRBiCGSTABGetPrecond( HYPRE_Solver solver , HYPRE_Solver *precond_data_ptr );
int HYPRE_ParCSRBiCGSTABSetLogging( HYPRE_Solver solver , int logging );
int HYPRE_ParCSRBiCGSTABGetNumIterations( HYPRE_Solver solver , int *num_iterations );
int HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm( HYPRE_Solver solver , double *norm );

/* HYPRE_parcsr_cgnr.c */
int HYPRE_ParCSRCGNRCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRCGNRDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRCGNRSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRCGNRSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRCGNRSetTol( HYPRE_Solver solver , double tol );
int HYPRE_ParCSRCGNRSetMinIter( HYPRE_Solver solver , int min_iter );
int HYPRE_ParCSRCGNRSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_ParCSRCGNRSetStopCrit( HYPRE_Solver solver , int stop_crit );
int HYPRE_ParCSRCGNRSetPrecond( HYPRE_Solver solver , HYPRE_PtrToSolverFcn precond , HYPRE_PtrToSolverFcn precondT , HYPRE_PtrToSolverFcn precond_setup , HYPRE_Solver precond_solver );
int HYPRE_ParCSRCGNRGetPrecond( HYPRE_Solver solver , HYPRE_Solver *precond_data_ptr );
int HYPRE_ParCSRCGNRSetLogging( HYPRE_Solver solver , int logging );
int HYPRE_ParCSRCGNRGetNumIterations( HYPRE_Solver solver , int *num_iterations );
int HYPRE_ParCSRCGNRGetFinalRelativeResidualNorm( HYPRE_Solver solver , double *norm );

/* HYPRE_parcsr_gmres.c */
int HYPRE_ParCSRGMRESCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRGMRESDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRGMRESSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRGMRESSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRGMRESSetKDim( HYPRE_Solver solver , int k_dim );
int HYPRE_ParCSRGMRESSetTol( HYPRE_Solver solver , double tol );
int HYPRE_ParCSRGMRESSetMinIter( HYPRE_Solver solver , int min_iter );
int HYPRE_ParCSRGMRESSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_ParCSRGMRESSetStopCrit( HYPRE_Solver solver , int stop_crit );
int HYPRE_ParCSRGMRESSetPrecond( HYPRE_Solver solver , HYPRE_PtrToSolverFcn precond , HYPRE_PtrToSolverFcn precond_setup , HYPRE_Solver precond_solver );
int HYPRE_ParCSRGMRESGetPrecond( HYPRE_Solver solver , HYPRE_Solver *precond_data_ptr );
int HYPRE_ParCSRGMRESSetLogging( HYPRE_Solver solver , int logging );
int HYPRE_ParCSRGMRESGetNumIterations( HYPRE_Solver solver , int *num_iterations );
int HYPRE_ParCSRGMRESGetFinalRelativeResidualNorm( HYPRE_Solver solver , double *norm );

/* HYPRE_parcsr_pcg.c */
int HYPRE_ParCSRPCGCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRPCGDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRPCGSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRPCGSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRPCGSetTol( HYPRE_Solver solver , double tol );
int HYPRE_ParCSRPCGSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_ParCSRPCGSetStopCrit( HYPRE_Solver solver , int stop_crit );
int HYPRE_ParCSRPCGSetTwoNorm( HYPRE_Solver solver , int two_norm );
int HYPRE_ParCSRPCGSetRelChange( HYPRE_Solver solver , int rel_change );
int HYPRE_ParCSRPCGSetPrecond( HYPRE_Solver solver , HYPRE_PtrToSolverFcn precond , HYPRE_PtrToSolverFcn precond_setup , HYPRE_Solver precond_solver );
int HYPRE_ParCSRPCGGetPrecond( HYPRE_Solver solver , HYPRE_Solver *precond_data_ptr );
int HYPRE_ParCSRPCGSetLogging( HYPRE_Solver solver , int logging );
int HYPRE_ParCSRPCGGetNumIterations( HYPRE_Solver solver , int *num_iterations );
int HYPRE_ParCSRPCGGetFinalRelativeResidualNorm( HYPRE_Solver solver , double *norm );
int HYPRE_ParCSRDiagScaleSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector y , HYPRE_ParVector x );
int HYPRE_ParCSRDiagScale( HYPRE_Solver solver , HYPRE_ParCSRMatrix HA , HYPRE_ParVector Hy , HYPRE_ParVector Hx );

/* HYPRE_parcsr_pilut.c */
int HYPRE_ParCSRPilutCreate( MPI_Comm comm , HYPRE_Solver *solver );
int HYPRE_ParCSRPilutDestroy( HYPRE_Solver solver );
int HYPRE_ParCSRPilutSetup( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRPilutSolve( HYPRE_Solver solver , HYPRE_ParCSRMatrix A , HYPRE_ParVector b , HYPRE_ParVector x );
int HYPRE_ParCSRPilutSetMaxIter( HYPRE_Solver solver , int max_iter );
int HYPRE_ParCSRPilutSetDropTolerance( HYPRE_Solver solver , double tol );
int HYPRE_ParCSRPilutSetFactorRowSize( HYPRE_Solver solver , int size );

/* driver.c */
int main( int argc , char *argv []);
int BuildParFromFile( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );
int BuildParLaplacian( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );
int BuildParDifConv( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );
int BuildParFromOneFile( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );
int BuildRhsParFromOneFile( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix A , HYPRE_ParVector *b_ptr );
int BuildParLaplacian9pt( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );
int BuildParLaplacian27pt( int argc , char *argv [], int arg_index , HYPRE_ParCSRMatrix *A_ptr );

/* par_amg.c */
void *hypre_BoomerAMGCreate( void );
int hypre_BoomerAMGDestroy( void *data );
int hypre_BoomerAMGSetRestriction( void *data , int restr_par );
int hypre_BoomerAMGSetMaxLevels( void *data , int max_levels );
int hypre_BoomerAMGSetStrongThreshold( void *data , double strong_threshold );
int hypre_BoomerAMGSetMaxRowSum( void *data , double max_row_sum );
int hypre_BoomerAMGSetTruncFactor( void *data , double trunc_factor );
int hypre_BoomerAMGSetInterpType( void *data , int interp_type );
int hypre_BoomerAMGSetMinIter( void *data , int min_iter );
int hypre_BoomerAMGSetMaxIter( void *data , int max_iter );
int hypre_BoomerAMGSetCoarsenType( void *data , int coarsen_type );
int hypre_BoomerAMGSetMeasureType( void *data , int measure_type );
int hypre_BoomerAMGSetSetupType( void *data , int setup_type );
int hypre_BoomerAMGSetCycleType( void *data , int cycle_type );
int hypre_BoomerAMGSetTol( void *data , double tol );
int hypre_BoomerAMGSetNumGridSweeps( void *data , int *num_grid_sweeps );
int hypre_BoomerAMGSetGridRelaxType( void *data , int *grid_relax_type );
int hypre_BoomerAMGSetGridRelaxPoints( void *data , int **grid_relax_points );
int hypre_BoomerAMGSetRelaxWeight( void *data , double *relax_weight );
int hypre_BoomerAMGSetIOutDat( void *data , int ioutdat );
int hypre_BoomerAMGSetLogFileName( void *data , char *log_file_name );
int hypre_BoomerAMGSetNumIterations( void *data , int num_iterations );
int hypre_BoomerAMGSetLogging( void *data , int ioutdat , char *log_file_name );
int hypre_BoomerAMGSetDebugFlag( void *data , int debug_flag );
int hypre_BoomerAMGSetNumFunctions( void *data , int num_functions );
int hypre_BoomerAMGSetNumPoints( void *data , int num_points );
int hypre_BoomerAMGSetDofFunc( void *data , int *dof_func );
int hypre_BoomerAMGSetPointDofMap( void *data , int *point_dof_map );
int hypre_BoomerAMGSetDofPoint( void *data , int *dof_point );
int hypre_BoomerAMGGetNumIterations( void *data , int *num_iterations );
int hypre_BoomerAMGGetRelResidualNorm( void *data , double *rel_resid_norm );

/* par_amg_setup.c */
int hypre_BoomerAMGSetup( void *amg_vdata , hypre_ParCSRMatrix *A , hypre_ParVector *f , hypre_ParVector *u );

/* par_amg_solve.c */
int hypre_BoomerAMGSolve( void *amg_vdata , hypre_ParCSRMatrix *A , hypre_ParVector *f , hypre_ParVector *u );

/* par_amg_solveT.c */
int hypre_BoomerAMGSolveT( void *amg_vdata , hypre_ParCSRMatrix *A , hypre_ParVector *f , hypre_ParVector *u );
int hypre_BoomerAMGCycleT( void *amg_vdata , hypre_ParVector **F_array , hypre_ParVector **U_array );
int hypre_BoomerAMGRelaxT( hypre_ParCSRMatrix *A , hypre_ParVector *f , int *cf_marker , int relax_type , int relax_points , double relax_weight , hypre_ParVector *u , hypre_ParVector *Vtemp );

/* par_coarse_parms.c */
int hypre_BoomerAMGCoarseParms( MPI_Comm comm , int local_num_variables , int local_coarse_size , int num_functions , int *dof_func , int *CF_marker , int **coarse_dof_func_ptr , int **coarse_pnts_global_ptr );

/* par_coarsen.c */
int hypre_BoomerAMGCoarsen( hypre_ParCSRMatrix *S , hypre_ParCSRMatrix *A , int CF_init , int debug_flag , int **CF_marker_ptr , int *coarse_size_ptr );
int hypre_BoomerAMGCoarsenRuge( hypre_ParCSRMatrix *S , hypre_ParCSRMatrix *A , int measure_type , int coarsen_type , int debug_flag , int **CF_marker_ptr , int *coarse_size_ptr );
int hypre_BoomerAMGCoarsenFalgout( hypre_ParCSRMatrix *S , hypre_ParCSRMatrix *A , int measure_type , int debug_flag , int **CF_marker_ptr , int *coarse_size_ptr );

/* par_cycle.c */
int hypre_BoomerAMGCycle( void *amg_vdata , hypre_ParVector **F_array , hypre_ParVector **U_array );

/* par_difconv.c */
HYPRE_ParCSRMatrix GenerateDifConv( MPI_Comm comm , int nx , int ny , int nz , int P , int Q , int R , int p , int q , int r , double *value );

/* par_indepset.c */
int hypre_BoomerAMGIndepSetInit( hypre_ParCSRMatrix *S , double *measure_array );
int hypre_BoomerAMGIndepSet( hypre_ParCSRMatrix *S , hypre_CSRMatrix *S_ext , double *measure_array , int *graph_array , int graph_array_size , int *graph_array_offd , int graph_array_offd_size , int *IS_marker , int *IS_marker_offd );

/* par_interp.c */
int hypre_BoomerAMGBuildInterp( hypre_ParCSRMatrix *A , int *CF_marker , hypre_ParCSRMatrix *S , int *num_cpts_global , int num_functions , int *dof_func , int debug_flag , double trunc_factor , hypre_ParCSRMatrix **P_ptr );

/* par_laplace.c */
HYPRE_ParCSRMatrix GenerateLaplacian( MPI_Comm comm , int nx , int ny , int nz , int P , int Q , int R , int p , int q , int r , double *value );
int map( int ix , int iy , int iz , int p , int q , int r , int P , int Q , int R , int *nx_part , int *ny_part , int *nz_part , int *global_part );

/* par_laplace_27pt.c */
HYPRE_ParCSRMatrix GenerateLaplacian27pt( MPI_Comm comm , int nx , int ny , int nz , int P , int Q , int R , int p , int q , int r , double *value );
int map3( int ix , int iy , int iz , int p , int q , int r , int P , int Q , int R , int *nx_part , int *ny_part , int *nz_part , int *global_part );

/* par_laplace_9pt.c */
HYPRE_ParCSRMatrix GenerateLaplacian9pt( MPI_Comm comm , int nx , int ny , int P , int Q , int p , int q , double *value );
int map2( int ix , int iy , int p , int q , int P , int Q , int *nx_part , int *ny_part , int *global_part );

/* par_rap.c */
hypre_CSRMatrix *hypre_ExchangeRAPData( hypre_CSRMatrix *RAP_int , hypre_ParCSRCommPkg *comm_pkg_RT );
int hypre_BoomerAMGBuildCoarseOperator( hypre_ParCSRMatrix *RT , hypre_ParCSRMatrix *A , hypre_ParCSRMatrix *P , hypre_ParCSRMatrix **RAP_ptr );

/* par_rap_communication.c */
int hypre_GetCommPkgRTFromCommPkgA( hypre_ParCSRMatrix *RT , hypre_ParCSRMatrix *A );
int hypre_GenerateSendMapAndCommPkg( MPI_Comm comm , int num_sends , int num_recvs , int *recv_procs , int *send_procs , int *recv_vec_starts , hypre_ParCSRMatrix *A );
int hypre_GenerateRAPCommPkg( hypre_ParCSRMatrix *RAP , hypre_ParCSRMatrix *A );

/* par_relax.c */
int hypre_BoomerAMGRelax( hypre_ParCSRMatrix *A , hypre_ParVector *f , int *cf_marker , int relax_type , int relax_points , double relax_weight , hypre_ParVector *u , hypre_ParVector *Vtemp );
int gselim( double *A , double *x , int n );

/* par_scaled_matnorm.c */
int hypre_ParCSRMatrixScaledNorm( hypre_ParCSRMatrix *A , double *scnorm );

/* par_stats.c */
int hypre_BoomerAMGSetupStats( void *amg_vdata , hypre_ParCSRMatrix *A );
int hypre_BoomerAMGWriteSolverParams( void *data );

/* par_strength.c */
int hypre_BoomerAMGCreateS( hypre_ParCSRMatrix *A , double strength_threshold , double max_row_sum , int num_functions , int *dof_func , hypre_ParCSRMatrix **S_ptr );

/* pcg_par.c */
char *hypre_ParKrylovCAlloc( int count , int elt_size );
int hypre_ParKrylovFree( char *ptr );
void *hypre_ParKrylovCreateVector( void *vvector );
void *hypre_ParKrylovCreateVectorArray( int n , void *vvector );
int hypre_ParKrylovDestroyVector( void *vvector );
void *hypre_ParKrylovMatvecCreate( void *A , void *x );
int hypre_ParKrylovMatvec( void *matvec_data , double alpha , void *A , void *x , double beta , void *y );
int hypre_ParKrylovMatvecT( void *matvec_data , double alpha , void *A , void *x , double beta , void *y );
int hypre_ParKrylovMatvecDestroy( void *matvec_data );
double hypre_ParKrylovInnerProd( void *x , void *y );
int hypre_ParKrylovCopyVector( void *x , void *y );
int hypre_ParKrylovClearVector( void *x );
int hypre_ParKrylovScaleVector( double alpha , void *x );
int hypre_ParKrylovAxpy( double alpha , void *x , void *y );
int hypre_ParKrylovCommInfo( void *A , int *my_id , int *num_procs );
int hypre_ParKrylovIdentitySetup( void *vdata , void *A , void *b , void *x );
int hypre_ParKrylovIdentity( void *vdata , void *A , void *b , void *x );

/* transpose.c */
int hypre_CSRMatrixTranspose( hypre_CSRMatrix *A , hypre_CSRMatrix **AT );


#ifdef __cplusplus
}
#endif

#endif

