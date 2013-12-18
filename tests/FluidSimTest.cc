#include "FluidSimulator.hh"
#include "FileReader.hh"
#include "initialisers.hh"
#include "Debug.hh"
#include <iostream>

int main()
{
    FileReader read;
    
    read.registerRealParameter("xlength");
    read.registerRealParameter("ylength");
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
    read.registerRealParameter("boundary_velocity_N");
    read.registerRealParameter("boundary_velocity_S");
    read.registerRealParameter("boundary_velocity_E");
    read.registerIntParameter("normalizationfrequency");
    read.registerIntParameter("checkfrequency");
    read.registerIntParameter("outputinterval");
    
    read.readFile("parameterfiles/fluidsimtest.par");
    
    FluidSimulator fluid(read);
    
    std::cout << "########## FLUID SIMULATION TEST #########" << std::endl << std::endl;
    
    fluid.grid().initialiseU(xy_function);
    fluid.grid().initialiseV(xy_function);
    fluid.grid().initialiseP(x_function);
    
//     fluid.grid().u().print();
//     fluid.grid().v().print();
    
    fluid.computeFG();
    
//     fluid.grid().f().print();
//     fluid.grid().g().print();
    
    //Test F matrix
    std::cout << "+ Testing calculation of F matrix" << std::endl;
    
    CHECK_MSG(fluid.grid().f()(0,0) == 2, "     FAILED: F calculated incorrectly at position (0,0)");
    CHECK_MSG(fluid.grid().f()(0,1) == 3, "     FAILED: F calculated incorrectly at position (0,1)");
    CHECK_MSG(fluid.grid().f()(1,0) == 2.778, "     FAILED: F calculated incorrectly at position (1,0)");
    CHECK_MSG(fluid.grid().f()(1,1) == 3.698, "     FAILED: F calculated incorrectly at position (1,1)");
    CHECK_MSG(fluid.grid().f()(2,0) == 4, "     FAILED: F calculated incorrectly at position (2,0)");
    CHECK_MSG(fluid.grid().f()(2,1) == 5, "     FAILED: F calculated incorrectly at position (2,1)");
    
    std::cout << "     PASSED" << std::endl;
    
    //Test G matrix
    std::cout << "+ Testing calculation of G matrix" << std::endl;
    
    CHECK_MSG(fluid.grid().g()(0,0) == 2, "     FAILED: G calculated incorrectly at position (0,0)");
    CHECK_MSG(fluid.grid().g()(0,1) == 2.778, "     FAILED: G calculated incorrectly at position (0,1)");
    CHECK_MSG(fluid.grid().g()(0,2) == 4, "     FAILED: G calculated incorrectly at position (0,2)");
    CHECK_MSG(fluid.grid().g()(1,0) == 3, "     FAILED: G calculated incorrectly at position (1,0)");
    CHECK_MSG(fluid.grid().g()(1,1) == 3.698, "     FAILED: G calculated incorrectly at position (1,1)");
    CHECK_MSG(fluid.grid().g()(1,2) == 5, "     FAILED: G calculated incorrectly at position (1,2)");
    
    std::cout << "     PASSED" << std::endl;
    
    
    //Test rhs matrix
    std::cout << "+ Testing calculation of rhs matrix" << std::endl;
    
    fluid.composeRHS();
    
//     fluid.grid().rhs().print();
    
    CHECK_MSG(fluid.grid().rhs()(0,0) == 77.8, "     FAILED: rhs calculated incorrectly at position (0,0)");
    CHECK_MSG(fluid.grid().rhs()(0,1) == 96, "     FAILED: rhs calculated incorrectly at position (0,1)");
    CHECK_MSG(fluid.grid().rhs()(1,1) == (130.2 + 2.84217e-14), "     FAILED: rhs calculated incorrectly at position (1,1)");
    CHECK_MSG(fluid.grid().rhs()(1,0) == 96, "     FAILED: rhs calculated incorrectly at position (1,0)");
    /*
    fluid.grid().p().print();*/
    
    std::cout << "     PASSED" << std::endl;
    
    //Test velocity matrices matrix
    std::cout << "+ Testing update of velocity matrices" << std::endl;
    
    fluid.updateVelocities();
    
    CHECK_MSG(fluid.grid().u()(1,1) == 2.758, "     FAILED: u calculated incorrectly at position (1,1)");
    CHECK_MSG(fluid.grid().u()(1,2) == 3.678, "     FAILED: u calculated incorrectly at position (1,2)");
    CHECK_MSG(fluid.grid().v()(1,1) == 2.778, "     FAILED: v calculated incorrectly at position (1,1)");
    CHECK_MSG(fluid.grid().v()(2,1) == 3.698, "     FAILED: v calculated incorrectly at position (2,1)");
    
    std::cout << "     PASSED" << std::endl;
    
//     fluid.grid().u().print();
//     fluid.grid().v().print();
    
    
    std::cout << std::endl << "########## FLUID SIMULATION TEST PASSED ##########" << std::endl << std::endl;
}