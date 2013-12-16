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
    read.registerRealParameter("safetyfactor");
    read.registerStringParameter("boundary_condition_W");
    read.registerRealParameter("boundary_velocity_W");
    read.registerStringParameter("boundary_condition_E");
    read.registerIntParameter("normalizationfrequency");
    read.registerIntParameter("checkfrequency");
    read.registerIntParameter("outputinterval");
    read.registerRealParameter("RectangleX1");
    read.registerRealParameter("RectangleY1");
    read.registerRealParameter("RectangleX2");
    read.registerRealParameter("RectangleY2");
    CHECK_MSG( read.readFile(parameterfile), "Could not read config file");
    read.printParameters();    
    
    FluidSimulator fluid(read);
    
    std::cout << int( read.getRealParameter("RectangleX1")/(read.getRealParameter("xlength")/read.getIntParameter("imax")) + 1.5) <<  " " 
	      << int( read.getRealParameter("RectangleY1")/(read.getRealParameter("ylength")/read.getIntParameter("jmax")) + 1.5) <<  " " 
	      << int( read.getRealParameter("RectangleX2")/(read.getRealParameter("xlength")/read.getIntParameter("imax")) + 1.5) <<   " " 
	      << int( read.getRealParameter("RectangleY2")/(read.getRealParameter("ylength")/read.getIntParameter("jmax")) + 1.5) << std::endl;
    
    fluid.grid().createRectangle( int( read.getRealParameter("RectangleX1")/(read.getRealParameter("xlength")/read.getIntParameter("imax")) + 1.5),
				  int( read.getRealParameter("RectangleY1")/(read.getRealParameter("ylength")/read.getIntParameter("jmax")) + 1.5),
				  int( read.getRealParameter("RectangleX2")/(read.getRealParameter("xlength")/read.getIntParameter("imax")) + 1.5),
				  int( read.getRealParameter("RectangleY2")/(read.getRealParameter("ylength")/read.getIntParameter("jmax")) + 1.5) );
    
    fluid.grid().flags().print();
    
    fluid.grid().initialiseU(halfU);
    
//     fluid.grid().u().print();
			   
    
    fluid.simulate(read.getRealParameter("dt")*(double(read.getIntParameter("timesteps"))));
    
    gettimeofday(&end, NULL);
    operation_time = (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec;
    std::cout << "Operating time (us): " << operation_time << std::endl;

    return 0;
}
