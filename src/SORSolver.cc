#include "SORSolver.hh"
#include <iostream>
#include <cmath>


bool SORSolver::solve( StaggeredGrid & grid ){ 
  
  real dx2 = 1.0/(grid.dx()*grid.dx());
  real dy2 = 1.0/(grid.dy()*grid.dy());
  real sorConst = 1.0/(2.0*dx2 + 2.0*dy2);
  real r = 0.0;
  int i;
  real sum = 0.0;
  //copy points of border of grid p to ghost layer
  fillBoundary( grid );
  r = calcResidual( grid );
  
  //sum over rhs to check if solution exists
  for( int x = 0; x < grid.rhs().getSize(0); ++x ){
    for( int y = 0; y < grid.rhs().getSize(1); ++y ){
      if(grid.isFluid(x+1,y+1)){
	sum += grid.rhs()(x,y);
      }
    }
  }
  std::cout << "Sum over rhs = " << sum << std::endl;
  
  for( i = 0; i < itermax_; ++i){
    
    
    //one iteration of the SOR solver
    for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
      for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
	if(grid.isFluid(x,y)){
	  grid.p()(x,y) = (1.0 - omg_)*grid.p()(x,y)
			  + omg_*sorConst*( (grid.p(x+1,y, WEST) + grid.p(x-1,y, EAST))*dx2 +
					    (grid.p(x,y+1, SOUTH) + grid.p(x,y-1, NORTH))*dy2 -
					    grid.rhs()(x-1,y-1) );
	}
	else{
	  grid.p()(x,y) = 0.0;
	}
      }
    }
    
    
    //copy points of border of grid p to ghost layer
    fillBoundary( grid );
    
    if( i%checkfrequency_ == 0 ){
      //calculate residual
      r = calcResidual( grid );
    }
    
    if(r < eps_){
      std::cout << "TOTAL ITERATIONS: " << i << "; final residual = " << r << std::endl;
      return 1;
    }
      
  }
  std::cout << "TOTAL ITERATIONS: " << i << "; final residual = " << r << std::endl;
  return 0;
}

void SORSolver::fillBoundary( StaggeredGrid & grid ){
  
  for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
    grid.p()(0,y) = grid.p()(1,y);
    grid.p()(grid.p().getSize(0)-1,y) = grid.p()(grid.p().getSize(0)-2,y);
  }
  for( int x = 1; x < grid.p().getSize(0) - 1; ++x){
    grid.p()(x,0) = grid.p()(x,1);
    grid.p()(x,grid.p().getSize(1)-1) = grid.p()(x,grid.p().getSize(1)-2);
  }
  
  //fill corner points to make me feel better
  grid.p()(0,0) = grid.p()(1,1);
  grid.p()(0, grid.p().getSize(1) - 1) = grid.p()(1,grid.p().getSize(1) - 2);
  grid.p()(grid.p().getSize(0) - 1, grid.p().getSize(1) - 1) = grid.p()(grid.p().getSize(0) - 2,grid.p().getSize(1) - 2);
  grid.p()(grid.p().getSize(0) - 1, 0) = grid.p()(grid.p().getSize(0) - 2, 1);
  
}
  
real SORSolver:: calcResidual( StaggeredGrid & grid ){
  
  real r = 0.0;
  real rtemp = 0.0;
  static real dxdx = 1.0/(grid.dx()*grid.dx());
  static real dydy = 1.0/(grid.dy()*grid.dy());
  
  for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
    for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
      if(grid.isFluid(x,y)){
	rtemp =   (grid.rhs()(x-1,y-1)) 
		- (grid.p(x+1,y, WEST) - 2*grid.p()(x,y) + grid.p(x-1,y, EAST))*dxdx
		- (grid.p(x,y+1, SOUTH) - 2*grid.p()(x,y) + grid.p(x,y-1, NORTH))*dydy;
	r += rtemp*rtemp;
      }
    }
  }
  
  return sqrt(r/(double(grid.getNumFluid())));

}

  