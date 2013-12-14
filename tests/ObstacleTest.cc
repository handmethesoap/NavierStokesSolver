

#include "StaggeredGrid.hh"
#include <iostream>
#include "initialisers.hh"
#include "FluidSimulator.hh"

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
  read.registerRealParameter("gamma");
  read.registerRealParameter("gx");
  read.registerRealParameter("gy");
  read.registerRealParameter("Re");
  read.registerRealParameter("U_INIT");
  read.registerRealParameter("V_INIT");
  read.registerRealParameter("P_INIT");
  read.registerRealParameter("dt");
  read.registerIntParameter("timesteps");
  read.registerIntParameter("checkfrequency");
  read.registerIntParameter("normalizationfrequency");
  read.registerRealParameter("safetyfactor");
  read.registerIntParameter("normalizationfrequency");
  read.registerIntParameter("checkfrequency");
  read.registerIntParameter("outputinterval");
  
  read.readFile("parameterfiles/obstacletest.par");
  
  std::cout << "########## OBSTACLE TEST #########" << std::endl << std::endl;
  
  // Create staggered grid
  FluidSimulator fluid ( read );
  
  fluid.grid().setCellToObstacle(3,3);
  fluid.grid().setCellToObstacle(3,4);
  fluid.grid().setCellToObstacle(4,3);
  fluid.grid().setCellToObstacle(4,4);
  fluid.grid().initialiseU(xy_function);
  fluid.grid().initialiseV(xy_function);
  
  //fluid.grid().flags().print();
  
  fluid.refreshBoundaries();
  std::cout << "+ Testing computation of F and G" << std::endl;
  
  fluid.computeFG();
  
  CHECK_MSG(fluid.grid().f()(1,0) == 2.5635, "     FAILED: F calculated incorrectly at position (1,0)");
  CHECK_MSG(fluid.grid().f()(1,4) == 5.684, "     FAILED: F calculated incorrectly at position (1,4)");
  CHECK_MSG(fluid.grid().f()(5,4) == 11.506, "     FAILED: F calculated incorrectly at position (1,4)");
  CHECK_MSG(fluid.grid().f()(4,1) == 6.9675, "     FAILED: F calculated incorrectly at position (1,4)");
  
  CHECK_MSG(fluid.grid().g()(0,1) == 2.5635, "     FAILED: G calculated incorrectly at position (0,1)");
  CHECK_MSG(fluid.grid().g()(1,4) == 6.9675, "     FAILED: G calculated incorrectly at position (1,4)");
  CHECK_MSG(fluid.grid().g()(4,1) == 5.684, "     FAILED: G calculated incorrectly at position (4,1)");
  CHECK_MSG(fluid.grid().g()(4,5) == 11.506, "     FAILED: G calculated incorrectly at position (4,5)");
  
  std::cout << "     PASSED" << std::endl;
  
  std::cout << "+ Testing computation of RHS" << std::endl;
  
  std::cout << fluid.grid().getNumFluid() << std::endl;
  fluid.composeRHS();
  fluid.grid().rhs().print();
  
  std::cout << "     PASSED" << std::endl;
//   fluid.grid().u().print();
//   fluid.grid().v().print();
//   fluid.grid().f().print();
//   fluid.grid().g().print();
  
  std::cout << fluid.grid().isFluid(1,1) << " " << fluid.grid().getNumFluid() << std::endl;

  std::cout << std::endl << "########## OBSTACLE TEST PASSED ##########" << std::endl << std::endl;
  
  return 0;
}