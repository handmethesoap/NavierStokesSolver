#include "FluidSimulator.hh"
#include "FileReader.hh"
#include "initialisers.hh"
#include "Debug.hh"
#include <iostream>

int main()
{
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
    read.registerRealParameter("boundary_velocity_N");
    read.registerRealParameter("boundary_velocity_S");
    read.registerRealParameter("boundary_velocity_E");
    read.registerIntParameter("normalizationfrequency");
    read.registerIntParameter("checkfrequency");
    
    read.readFile("fluidsimtest.par");
    
    FluidSimulator fluid(read);
    
    fluid.grid().initialiseU(xy_function);
    fluid.grid().initialiseV(xy_function);
    fluid.grid().initialiseP(x_function);
    
    fluid.grid().u().print();
    fluid.grid().v().print();
    
    fluid.computeFG();
    
    fluid.grid().f().print();
    fluid.grid().g().print();
    
    fluid.composeRHS();
    
    fluid.grid().p().print();
    
    fluid.updateVelocities();
    fluid.grid().u().print();
    fluid.grid().v().print();
    
//     
//     //For u an array of a single constant F equals this constant
// //     for(int i = 0; i < fluid.grid().f().getSize(0); ++i){
// //       for(int j = 0; j < fluid.grid().f().getSize(1); ++j){
// // 	CHECK_MSG(fluid.grid().f()(i,j) == read.getRealParameter("U_init"), "F calculated incorrectly");
// //       }
// //     }
//     
//     fluid.grid().u().print();
//     
//     fluid.grid().v().print();
//     fluid.grid().f().print();
//     
//     //For v an array of a single constant G equals this constant
//     for(int i = 0; i < fluid.grid().g().getSize(0); ++i){
//       for(int j = 0; j < fluid.grid().g().getSize(1); ++j){
// 	CHECK_MSG(fluid.grid().g()(i,j) == read.getRealParameter("V_INIT"), "G calculated incorrectly");
//       }
//     }
//     
//     
//     std::cout << " Test passed " <<  std::endl;
}
