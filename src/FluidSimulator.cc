#include "FluidSimulator.hh"
#include <cmath>
#include <iostream>

void FluidSimulator:: simulate             ( real duration              ){
//   computeFG();
//   composeRHS();
//   solve_.solve(grid_);
//   updateVelocities();
  real const & limit = 1.0;
  determineNextDT(limit);
  
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
    for(int j = 1; j < grid_.g().getSize(1) - 1; ++j){
         
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
	if( std::abs(grid_.v()(i,j)) > v_max ){
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
  
  std::cout << dt_ << std::endl;
}

void FluidSimulator:: refreshBoundaries(void){
  
  
  
}





















