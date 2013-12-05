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
    read.registerRealParameter("U_INIT");
    read.registerRealParameter("V_INIT");
    read.registerRealParameter("P_INIT");
    read.registerRealParameter("dt");
    read.registerIntParameter("timesteps");
    read.registerIntParameter("checkfrequency");
    read.registerRealParameter("safetyfactor");
    read.registerRealParameter("boundary_velocity_N");
    read.registerRealParameter("boundary_velocity_S");
    read.registerRealParameter("boundary_velocity_E");
    read.registerIntParameter("normalizationfrequency");
    read.registerIntParameter("checkfrequency");

    CHECK_MSG( read.readFile(parameterfile), "Could not read config file");
    read.printParameters();    
    
    FluidSimulator fluid(read);
    
    fluid.simulate(read.getRealParameter("dt")*(double(read.getIntParameter("timesteps"))));

    return 0;
}
