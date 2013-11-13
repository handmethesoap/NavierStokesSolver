#include "SORSolver.hh"
#include <iostream>
#include <cmath>


bool SORSolver::solve( StaggeredGrid & grid ){ 
  
  real dx2 = grid.dx()*grid.dx();
  real dy2 = grid.dy()*grid.dy();
  real sorConst = 1.0/(2.0/dx2 + 2.0/dy2);
  real r = 0.0;
  real rtemp = 0.0;
  
  //copy points of border of grid p to ghost layer
  fillBoundary( grid );
  
  //STATUS("dd " << grid.p()(2,1) << " + " << grid.p()(0,1) << " / " << dx2 << " + " << grid.p()(1,2) << " + " << grid.p()(1,0) << " / " << dy2 << " - " << grid.rhs()(0,0) << " = " << omg_*sorConst*((grid.p()(1+1,1) + grid.p()(1-1,1))/dx2 
				     // + (grid.p()(1,1+1) + grid.p()(1,1-1))/dy2 
				      //- grid.rhs()(1-1,1-1)));  
  for(int i = 0; i < itermax_; ++i){
    
    //one iteration of the SOR solver
    for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
      for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
	grid.p()(x,y) = (1.0 - omg_)*grid.p()(x,y)
			+ omg_*sorConst*( (grid.p()(x+1,y) + grid.p()(x-1,y))/dx2 
					+ (grid.p()(x,y+1) + grid.p()(x,y-1))/dy2 
					- grid.rhs()(x-1,y-1) );
      }
    }
    
    fillBoundary( grid );
    
    //calculate residual
    r = 0.0;
    for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
      for( int y = 1; y < grid.p().getSize(1) - 1; ++y){
	rtemp =   (grid.rhs()(x-1,y-1)) 
		- (grid.p()(x+1,y) - 2*grid.p()(x,y) + grid.p()(x-1,y))/dx2
		- (grid.p()(x,y+1) - 2*grid.p()(x,y) + grid.p()(x,y-1))/dy2;
	r += rtemp*rtemp;
      }
    }
    
    r = sqrt(r/(double(grid.p().getSize(0)*grid.p().getSize(1))));
    std::cout << "r = " << r << std::endl;
    
    if(r < eps_){
      std::cout << "PASSED" << std::endl;
      return 1;
    }
      
  }
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
  