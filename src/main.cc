#include "Array.hh"
#include "FileReader.hh"
#include "Debug.hh"
#include "SORSolver.hh"
#include "StaggeredGrid.hh"
#include "initialisers.hh"
#include "FluidSimulator.hh"
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>


int main( int argc, char** argv )
{
    CHECK_MSG(argc == 2,"The command line requires a single input of the parameter file name");

    std::string parameterfile = argv[1];
    
    timeval start;
    timeval end;
    gettimeofday(&start, NULL);

    long int operation_time = 0;
    
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
    read.registerIntParameter("outputinterval");

    CHECK_MSG( read.readFile(parameterfile), "Could not read config file");
    read.printParameters();    
    
    FluidSimulator fluid(read);
    
    fluid.simulate(read.getRealParameter("dt")*(double(read.getIntParameter("timesteps"))));
    
    gettimeofday(&end, NULL);
    operation_time = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
    std::cout << "Operating time (us): " << operation_time << std::endl;

    return 0;
}
