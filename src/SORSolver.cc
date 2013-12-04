#include "SORSolver.hh"
#include <iostream>
#include <cmath>


bool SORSolver::solve( StaggeredGrid & grid ){ 
  
  real dx2 = grid.dx()*grid.dx();
  real dy2 = grid.dy()*grid.dy();
  real sorConst = 1.0/(2.0/dx2 + 2.0/dy2);
  real r = 0.0;
  int i;
  //copy points of border of grid p to ghost layer
  fillBoundary( grid );
  r = calcResidual( grid );
  Array p_new(grid.p().getSize(0),grid.p().getSize(1));
  
  for( i = 0; i < itermax_; ++i){
    
    
    //one iteration of the SOR solver
    for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
      for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
	real old = grid.p()(x,y);
	grid.p()(x,y) = (1.0 - omg_)*old
			+ omg_*sorConst*( (grid.p()(x+1,y) + grid.p()(x-1,y))/dx2 +
					  (grid.p()(x,y+1) + grid.p()(x,y-1))/dy2 -
					   grid.rhs()(x-1,y-1) );
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

  
}
  
real SORSolver:: calcResidual( StaggeredGrid & grid ){
  
  real r = 0.0;
  real rtemp = 0.0;
  
  for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
    for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
      rtemp =   (grid.rhs()(x-1,y-1)) 
	      - (grid.p()(x+1,y) - 2*grid.p()(x,y) + grid.p()(x-1,y))/(grid.dx()*grid.dx())
	      - (grid.p()(x,y+1) - 2*grid.p()(x,y) + grid.p()(x,y-1))/(grid.dy()*grid.dy());
      r += rtemp*rtemp;
    }
  }
  
  return sqrt(r/(double(grid.p().getSize(0)*grid.p().getSize(1))));

}

  