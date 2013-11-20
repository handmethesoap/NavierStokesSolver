#include "FluidSimulator.hh"
#include "FileReader.hh"
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
    read.registerRealParameter("U_init");
    read.registerRealParameter("V_init");
    read.registerRealParameter("P_init");
    read.registerRealParameter("dt");
    read.registerIntParameter("timesteps");
    read.registerIntParameter("checkfrequency");
    read.registerIntParameter("normalizationfrequency");
    
    read.readFile("dcavity.par");
    
    FluidSimulator fluid(read);
    
    fluid.computeFG();
    
    //For u an array of a single constant F equals this constant
    for(int i = 0; i < fluid.grid().f().getSize(0); ++i){
      for(int j = 0; j < fluid.grid().f().getSize(1); ++j){
	CHECK_MSG(fluid.grid().f()(i,j) == read.getRealParameter("U_init"), "F calculated incorrectly");
      }
    }
    
    //For v an array of a single constant G equals this constant
    for(int i = 0; i < fluid.grid().g().getSize(0); ++i){
      for(int j = 0; j < fluid.grid().g().getSize(1); ++j){
	CHECK_MSG(fluid.grid().g()(i,j) == read.getRealParameter("V_init"), "G calculated incorrectly");
      }
    }
    
    std::cout << "Test passed" << std::endl;
}
