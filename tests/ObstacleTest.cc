

#include "StaggeredGrid.hh"
#include <iostream>
#include "initialisers.hh"
#include "FluidSimulator.hh"

int main()
{
  srand (u_int(time(NULL)));
  FileReader read;
    
  read.registerRealParameter("xlength");
  read.registerRealParameter("ylength");
  read.registerIntParameter("imax");
  read.registerIntParameter("jmax");
  read.registerRealParameter("eps");
  read.registerRealParameter("omg");
  read.registerIntParameter("itermax");
  read.registerRealParameter("gamma");
  read.registerRealParameter("GX");
  read.registerRealParameter("GY");
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
  
//   fluid.grid().setCellToObstacle(3,3);
//   fluid.grid().setCellToObstacle(3,4);
//   fluid.grid().setCellToObstacle(4,3);
//   fluid.grid().setCellToObstacle(4,4);
  //fluid.grid().createCircle(10,10,7);
  //fluid.grid().createRectangle(3,3,4,4);
  fluid.grid().readPNG("test.png");
  fluid.grid().initialiseU(xy_function);
  fluid.grid().initialiseV(xy_function);
  fluid.grid().initialiseP(xy_function);
  
//   fluid.grid().flags().print();
  
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
  
  std::cout << "+ Testing Velocity Update" << std::endl;
  
  std::cout << fluid.grid().getNumFluid() << std::endl;
  fluid.composeRHS();
//   fluid.grid().rhs().print();
//   
//   fluid.grid().p().print();
  for(int i = 1; i < fluid.grid().p().getSize(0) - 1; ++i){
    for(int j = 1; j < fluid.grid().p().getSize(1) - 1; ++j){
      fluid.grid().p()(i,j) = fluid.grid().p(i+1,j, WEST);
    }
  }
//   fluid.grid().p().print();
  
  fluid.updateVelocities();
//   fluid.grid().u().print();
//   fluid.grid().v().print();
    
  
  std::cout << "     PASSED" << std::endl;
//   fluid.grid().u().print();
//   fluid.grid().v().print();
//   fluid.grid().f().print();
//   fluid.grid().g().print();
  
  std::cout << fluid.grid().isFluid(1,1) << " " << fluid.grid().getNumFluid() << std::endl;

  std::cout << std::endl << "########## OBSTACLE TEST PASSED ##########" << std::endl << std::endl;
  
  fluid.grid().writePNG("test.png");
  
  return 0;
}