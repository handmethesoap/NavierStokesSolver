
#include "SORSolver.hh"
#include "StaggeredGrid.hh"
#include "initialisers.hh"
#include <iostream>



void initGridSetup1( StaggeredGrid & grid )
{
   // Setup 1:
   grid.initialiseP( rand_function );
   grid.initialiseRHS( sinx_function );
}

void initGridSetup2( StaggeredGrid & grid )
{
   // Setup 2:
   grid.initialiseP( rand_function );
   grid.initialiseRHS( siny_function );
}



int main()
{
  srand (u_int(time(NULL)));
  FileReader read;
    
  read.registerIntParameter("xlength");
  read.registerIntParameter("ylength");
  read.registerIntParameter("imax");
  read.registerIntParameter("jmax");
  read.registerRealParameter("eps");
  read.registerRealParameter("omg");
  read.registerIntParameter("itermax");
  read.registerIntParameter("checkfrequency");
  
  read.readFile("poisson.par");

  // Create staggered grid
  StaggeredGrid grid ( read );


  // create solver
  SORSolver solver ( read );


  initGridSetup1( grid );
  solver.solve( grid );
  
  Array temprhs(grid.rhs());
  real sum = 0.0;
  
  for( int i = 0; i < temprhs.getSize(0); ++i ){
    for( int j = 0; j < temprhs.getSize(1); ++j ){
      temprhs(i,j) = (1.0/grid.dx())*(grid.p()(i,j+1) - 2*grid.p()(i+1,j+1) + grid.p()(i+2,j+1));
      sum += std::abs(temprhs(i,j) - grid.rhs()(i,j))*std::abs(temprhs(i,j) - grid.rhs()(i,j));
    }
  }
  
  sum = sqrt(sum/(double(temprhs.getSize(0))*double(temprhs.getSize(1))));

  std::cout << sum << std::endl;
  CHECK( sum < 1.0 );


  initGridSetup2( grid );
  solver.solve( grid );
  
  real sum2 = 0.0;
  
  for( int i = 0; i < temprhs.getSize(0); ++i ){
    for( int j = 0; j < temprhs.getSize(1); ++j ){
      temprhs(i,j) = (1.0/grid.dy())*(grid.p()(i+1,j) - 2*grid.p()(i+1,j+1) + grid.p()(i+1,j+2));
      sum2 += std::abs(temprhs(i,j) - grid.rhs()(i,j))*std::abs(temprhs(i,j) - grid.rhs()(i,j));
    }
  }
  sum2 = sqrt(sum/(double(temprhs.getSize(0))*double(temprhs.getSize(1))));

  std::cout << sum2 << std::endl;
  CHECK( sum < 1.0 );



   return 0;
}
