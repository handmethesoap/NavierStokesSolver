#include "FluidSimulator.hh"
#include "Debug.hh"
#include <cmath>
#include <iostream>
#include <vector>

void FluidSimulator:: simulate( real duration ){
  
  real time = 0.0;
  int n = 0;
  real const & limit = 1.0;
  
  while( time < duration ){
  
    determineNextDT(limit);
    refreshBoundaries();
    computeFG();
    composeRHS();
    solve_.solve(grid_);
    updateVelocities();
    time = time + dt_;
    ++n;
    if(n%normalizationfrequency_ == 0)
    {
	grid_.p().normalize();
    }
    
  }
}

void FluidSimulator:: simulateTimeStepCount( unsigned int nrOfTimeSteps ){
  
  real const & limit = 1.0;
  
  for(unsigned int steps = 0; steps < nrOfTimeSteps; ++steps){
  
    determineNextDT(limit);
    refreshBoundaries();
    computeFG();
    composeRHS();
    solve_.solve(grid_);
    updateVelocities();
    
    if(steps%normalizationfrequency_ == 0)
    {
	grid_.p().normalize();
    }
    
  }
  
}

void FluidSimulator::computeFG(){
  
  real d2udx2;
  real d2udy2;
  real du2dx;
  real duvdy;
  real d2vdx2;
  real d2vdy2;
  real dv2dy;
  real duvdx;
  
  real dx2 = grid_.dx()*grid_.dx();
  real dy2 = grid_.dy()*grid_.dy();

  //set boundary values of f
  for(int j = 0; j < grid_.f().getSize(1); ++j){
    grid_.f()(0,j) = grid_.u()(0,j);
    grid_.f()(grid_.f().getSize(0)-1,j) = grid_.u()(grid_.f().getSize(0)-1,j);
  }
  //calculate f
  for(int i = 1; i < grid_.f().getSize(0)-1; ++i){
    for(int j = 1; j < grid_.f().getSize(1)+1; ++j){
      
      //calculate d2u/dx2
      d2udx2 = ( grid_.u()(i+1,j) - 2.0*grid_.u()(i,j) + grid_.u()(i-1,j) ) / dx2;
      
      //calculate d2u/dy2
      d2udy2 = ( grid_.u()(i,j+1) - 2.0*grid_.u()(i,j) + grid_.u()(i,j-1) ) / dy2;
      
      //calculate du2dx
      du2dx =  ( 1.0/grid_.dx() )     * (    (grid_.u()(i,j) + grid_.u()(i+1,j))
					   * (grid_.u()(i,j) + grid_.u()(i+1,j)) 
					   / 4.0
					   - (grid_.u()(i-1,j) + grid_.u()(i,j))
					   * (grid_.u()(i-1,j) + grid_.u()(i,j)) 
					   / 4.0 
					 )
	     + ( gamma_*1.0/grid_.dx() ) * (   std::abs( (grid_.u()(i,j) + grid_.u()(i+1,j)) )
					   *             (grid_.u()(i,j) - grid_.u()(i+1,j)) 
					   / 4.0
					   - std::abs( (grid_.u()(i-1,j) + grid_.u()(i,j)) )
					   *           (grid_.u()(i-1,j) - grid_.u()(i,j)) 
					   / 4.0 
					 );
	     
      //calculate duv/dy
      duvdy =  ( 1.0/grid_.dy() )     * (    (grid_.v()(i,j) + grid_.v()(i+1,j))
					   * (grid_.u()(i,j) + grid_.u()(i,j+1)) 
					   / 4.0
					   - (grid_.v()(i,j-1) + grid_.v()(i+1,j-1))
					   * (grid_.u()(i,j-1) + grid_.u()(i,j)) 
					   / 4.0 
					 )
	     + ( gamma_*1.0/grid_.dy() ) * (   std::abs( (grid_.v()(i,j) + grid_.v()(i+1,j)) )
					   *             (grid_.u()(i,j) - grid_.u()(i,j+1)) 
					   / 4.0
					   - std::abs( (grid_.v()(i,j-1) + grid_.v()(i+1,j-1)) )
					   *           (grid_.u()(i,j-1) - grid_.u()(i,j)) 
					   / 4.0 
					 );
	     
      grid_.f()(i,j-1) = grid_.u()(i,j) + dt_*( 1.0/Re_*(d2udx2 + d2udy2) - du2dx - duvdy + gx_);
    }
  }
  
  //set boundary values of g
  for(int i = 0; i < grid_.g().getSize(0); ++i){
    grid_.g()(i,0) = grid_.v()(i,0);
    grid_.g()(i,grid_.g().getSize(1)-1) = grid_.v()(i, grid_.g().getSize(1)-1);
  }
  //calculate g
  for(int i = 1; i < grid_.g().getSize(0) + 1; ++i){
    for(int j = 1; j < grid_.g().getSize(1) - 1; ++j){//     fluid.grid().u().print();
//     fluid.grid().v().print();
         
      //calculate d2v/dx2
      d2vdx2 = ( grid_.v()(i+1,j) - 2.0*grid_.v()(i,j) + grid_.v()(i-1,j) ) / dx2;
      
      //calculate d2v/dy2
      d2vdy2 = ( grid_.v()(i,j+1) - 2.0*grid_.v()(i,j) + grid_.v()(i,j-1) ) / dy2;
      
      //calculate duv/dx
      duvdx =  ( 1.0/grid_.dx() )     * (    (grid_.u()(i,j) + grid_.u()(i,j+1))
					   * (grid_.v()(i,j) + grid_.v()(i+1,j)) 
					   / 4.0
					   - (grid_.u()(i-1,j) + grid_.u()(i-1,j+1))
					   * (grid_.v()(i-1,j) + grid_.v()(i,j)) 
					   / 4.0 
					 )
	     + ( gamma_*1.0/grid_.dx() ) * (   std::abs( (grid_.u()(i,j) + grid_.u()(i,j+1)) )
					   *             (grid_.v()(i,j) - grid_.v()(i+1,j)) 
					   / 4.0
					   - std::abs( (grid_.u()(i-1,j) + grid_.u()(i-1,j+1)) )
					   *           (grid_.v()(i-1,j) - grid_.v()(i,j)) 
					   / 4.0 
					 );
    
      //calculate dv2/dy
      dv2dy =  ( 1.0/grid_.dy() )      * (   (grid_.v()(i,j) + grid_.v()(i,j+1))
					   * (grid_.v()(i,j) + grid_.v()(i,j+1)) 
					   / 4.0
					   - (grid_.v()(i,j-1) + grid_.v()(i,j))
					   * (grid_.v()(i,j-1) + grid_.v()(i,j)) 
					   / 4.0 
					 )
	     + ( gamma_*1.0/grid_.dy() ) * (   std::abs( (grid_.v()(i,j) + grid_.v()(i,j+1)) )
					   *             (grid_.v()(i,j) - grid_.v()(i,j+1)) 
					   / 4.0
					   - std::abs( (grid_.v()(i,j-1) + grid_.v()(i,j)) )
					   *           (grid_.v()(i,j-1) - grid_.v()(i,j)) 
					   / 4.0 
					 );
	     
      grid_.g()(i-1,j) = grid_.v()(i,j) + dt_*( 1.0/Re_*(d2vdx2 + d2vdy2) - dv2dy - duvdx + gx_);
    }
  }
  
}

void FluidSimulator:: composeRHS(){
  
  for( int i = 0; i < grid_.rhs().getSize(0); ++i ){
    for( int j = 0; j < grid_.rhs().getSize(1); ++j ){
      grid_.rhs()(i,j) = ( 1.0/dt_ ) * ( ( grid_.f()(i+1,j) - grid_.f()(i,j) ) / grid_.dx() + ( grid_.g()(i,j+1) - grid_.g()(i,j) ) / grid_.dy() );
    }
  }

}

void FluidSimulator:: updateVelocities(){

  for( int i = 1; i < (grid_.u().getSize(0) - 1); ++i ){
      for( int j = 1; j <  (grid_.u().getSize(1) - 1); ++j ){
	grid_.u()(i,j) = grid_.f()(i,j-1) - (dt_/grid_.dx())*( grid_.p()(i+1,j) - grid_.p()(i,j) );
      }
  }

  for( int i = 1; i < (grid_.v().getSize(0) - 1); ++i ){
      for( int j = 1; j <  (grid_.v().getSize(1) - 1); ++j ){
	grid_.v()(i,j) = grid_.g()(i-1,j) - (dt_/grid_.dy())*( grid_.p()(i,j+1) - grid_.p()(i,j) );
      }
  }
  
}

void FluidSimulator:: determineNextDT( real const & limit ){
  
  real min;
  real u_max = 0.0;
  real v_max = 0.0;
  
  if(safetyfactor_ > 0.0)
  {
    min = (Re_/2.0)*(1.0/(1.0/(grid_.dx()*grid_.dx()) + 1.0/(1.0/(grid_.dy()*grid_.dy()))));
    
    std::cout << "min = " << min << std::endl;
    
    for( int i = 0; i < grid_.u().getSize(0); ++i ){
      for( int j = 0; j < grid_.u().getSize(1); ++j){
	if( std::abs(grid_.u()(i,j)) > u_max ){
	  u_max = std::abs(grid_.u()(i,j));
	}
      }
    }
    std::cout << "u_max = " << u_max << std::endl;
    
    if( grid_.dx()/u_max < min ){
      min =  grid_.dx()/u_max;
    }
    
    for( int i = 0; i < grid_.v().getSize(0); ++i ){
      for( int j = 0; j < grid_.v().getSize(1); ++j){
	if( std::abs(grid_.v()(i,j)) > v_max )void refreshBoundaries();{
	  v_max = std::abs(grid_.v()(i,j));
	}
      }
    }
    std::cout << "vmax = " << v_max << std::endl;
    
    if( grid_.dy()/v_max < min ){
      min =  grid_.dy()/v_max;
    } 
    
    dt_ = safetyfactor_*min;
  }
}

void FluidSimulator:: refreshBoundaries(void){
  
  static const int NORTH = 0;
  static const int EAST = 1;
  static const int SOUTH = 2;
  static const int WEST = 3;
  
  static const std::vector< std::string> boundary_condition_labels = {"boundary_condition_N", "boundary_condition_E", "boundary_condition_S", "boundary_condition_W"};
  static const std::vector< std::string> boundary_velocity_labels = {"boundary_velocity_N", "boundary_velocity_E", "boundary_velocity_S", "boundary_velocity_W"};

  
  std::vector<real> tangential_velocities (4); //tangential_velocity_N, tangential_velocity_E, tangential_velocity_S, tangential_velocity_W;
  std::vector<real> normal_velocities (4); //normal_velocity_N, normal_velocity_E, normal_velocity_S, normal_velocity_W;
  
  std::vector<real> outflow_constants (4); //outflow_constant_N, outflow_constant_E, outflow_constant_S, outflow_constant_W;
  std::vector<real> averaging_constants (4); //real averaging_constant_N, averaging_constant_E, averaging_constant_S, averaging_constant_W;
  
  for( int direction = 0; direction < 4; ++direction ){
  
    if( !conf_.checkStringParameterExists(boundary_condition_labels[direction]) || (conf_.getStringParameter(boundary_condition_labels[direction]) == "noslip") ){
      
      normal_velocities[direction] = 0.0;
      averaging_constants[direction] = -1.0;
      outflow_constants[direction] = 0.0;
      
      if( !conf_.checkRealParameterExists(boundary_velocity_labels[direction]) ){
	tangential_velocities[direction] = 0.0;
      }
      else{
	tangential_velocities[direction] = conf_.getRealParameter(boundary_velocity_labels[direction]);
	std::cout << tangential_velocities[direction] << std::endl;
      }
      
    }
    else if( conf_.getStringParameter(boundary_condition_labels[direction]) == "inflow" ){
      
      tangential_velocities[direction] = 0.0;
      averaging_constants[direction] = -1.0;
      outflow_constants[direction] = 0.0;
      
      if( !conf_.checkRealParameterExists(boundary_velocity_labels[direction]) ){
	normal_velocities[direction] = 0.0;
      }
      else{
	normal_velocities[direction] = conf_.getRealParameter(boundary_velocity_labels[direction]);
      }
    }
    
    else if( conf_.getStringParameter(boundary_condition_labels[direction]) == "outflow" ){
    
      CHECK_MSG( !conf_.checkRealParameterExists(boundary_velocity_labels[direction]), "Boundary velocity provided for northern outflow boundary.  Check your configuration" );
      
      normal_velocities[direction] = 0.0;
      tangential_velocities[direction] = 0.0;
      outflow_constants[direction] = 1.0;
      averaging_constants[direction] = 1.0;
      
    }
    else{
      
      CHECK_MSG(0, "Unknown boundary condition provided for " << boundary_condition_labels[direction] << " parameter");
      
    }
  }
    
  
  for( int i = 1; i < grid_.u().getSize(0); ++i){
    grid_.v()(i,0) = normal_velocities[SOUTH] + outflow_constants[SOUTH] * grid_.v()(i,1);								//set normal velocity on southern border
    grid_.v()(i,grid_.v().getSize(1)-1) = normal_velocities[NORTH] + outflow_constants[NORTH] * grid_.v()(i,grid_.v().getSize(1)-2);			//set normal velocity on northern border
  }
  for( int j = 1; j < grid_.v().getSize(1); ++j){
    grid_.u()(0,j) = normal_velocities[WEST] + outflow_constants[WEST] * grid_.u()(1,j);								//set normal velocity on western border
    grid_.u()(grid_.u().getSize(0)-1, j) = normal_velocities[EAST] + outflow_constants[EAST] * grid_.u()(grid_.u().getSize(0)-2,j);			//set normal velocity on eastern border
  }
  for( int i = 1; i < grid_.u().getSize(0); ++i){
    grid_.u()(i,0) = 2*tangential_velocities[SOUTH] + averaging_constants[SOUTH] * grid_.u()(i,1);							//set tangential velocity on southern border
    grid_.u()(i,grid_.u().getSize(1)-1) = 2*tangential_velocities[NORTH] + averaging_constants[NORTH] * grid_.u()(i,grid_.u().getSize(1)-2);		//set tangential velocity on northern border
  }
  for( int j = 1; j < grid_.v().getSize(1); ++j){
    grid_.v()(0,j) = 2*tangential_velocities[WEST] + averaging_constants[WEST] * grid_.v()(1,j);							//set tangential velocity on western border
    grid_.v()(grid_.v().getSize(0)-1, j) = 2*tangential_velocities[EAST] + averaging_constants[EAST] * grid_.v()(grid_.v().getSize(0)-2,j);		//set tangential velocity on eastern border
  }
  
  
}





















