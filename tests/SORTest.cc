
#include "SORSolver.hh"
#include "StaggeredGrid.hh"
#include "initialisers.hh"



void initGridSetup1( StaggeredGrid & grid )
{
   // Setup 1:
   grid.initialiseP( rand_function );
   grid.initialiseRHS( zero_function );
}

void initGridSetup2( StaggeredGrid & grid )
{
   // Setup 2:
   grid.initialiseP( zero_function );
   grid.initialiseRHS( sinx_function );
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
  //solver.solve( grid );
  //CHECK( solver.calcResidual( grid ) < read.getRealParameter("eps") );


  initGridSetup2( grid );
  grid.p().print();
  solver.solve( grid );
  //CHECK( solver.calcResidual( grid ) < read.getRealParameter("eps") );
  
  grid.p().print();
  grid.rhs().print();


   return 0;
}
