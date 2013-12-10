
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
  
  read.readFile("parameterfiles/sortest.par");

  // Create staggered grid
  StaggeredGrid grid ( read );


  // create solver
  SORSolver solver ( read );

  std::cout << "########## SOR SOLVER TEST #########" << std::endl << std::endl;
  
  //Test solver with sin(y) function
  std::cout << "+ Testing SOR solution of sin(x) matrix" << std::endl << "     ";
  
  initGridSetup1( grid );
  bool result = solver.solve( grid );
  
  CHECK_MSG( result == 1, "     FAILED: SOR solver not working in x direction" );
  
  std::cout << "     PASSED" << std::endl;
  
  //Test solver with sin(x) function
  std::cout << "+ Testing SOR solution of sin(y) matrix" << std::endl << "     ";
  
  initGridSetup2( grid );
  result = solver.solve( grid );
  
  CHECK_MSG( result == 1, "     FAILED: SOR solver not working in y direction" );
  std::cout << "     PASSED" << std::endl;
  
  
  std::cout << "+ Testing normalization of P matrix" << std::endl;
  
  double sum = 0.0;
  grid.normalizeP();
    
  for( int x = 1; x < grid.p().getSize(0) - 1; ++x ){
    for( int y = 1; y < grid.p().getSize(1) -1; ++y ){
      sum += grid.p()(x,y);
    }
  }
  
  CHECK_MSG( sum < 0.00000001, "     FAILED: Normalization not operating correctly" );
  std::cout << "     PASSED" << std::endl;
  
  std::cout << std::endl << "########## SOR SOLVER TEST PASSED ##########" << std::endl << std::endl;
  
  return 0;
}