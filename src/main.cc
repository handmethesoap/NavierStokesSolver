#include "Array.hh"
#include "FileReader.hh"
#include "Debug.hh"
#include "SORSolver.hh"
#include "StaggeredGrid.hh"
#include "initialisers.hh"
#include "FluidSimulator.hh"
#include <iostream>


int main( int argc, char** argv )
{
    CHECK_MSG(argc == 2,"The command line requires a single input of the parameter file name");

    std::string parameterfile = argv[1];

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
    read.registerRealParameter("safetyfactor");

    CHECK_MSG( read.readFile(parameterfile), "Could not read config file");
    read.printParameters();
    
    FluidSimulator fluid(read);
    //fluid.grid().initialiseU(x_function);
    //fluid.grid().initialiseV(y_function);
    
    
    fluid.simulate(1.0);
    
//     fluid.grid().u().print();
//     fluid.grid().v().print();
//     fluid.grid().f().print();
//     fluid.grid().g().print();
//     fluid.grid().rhs().print();

    


    return 0;
}
