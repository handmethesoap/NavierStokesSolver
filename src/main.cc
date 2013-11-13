#include "Array.hh"
#include "FileReader.hh"
#include "Debug.hh"
#include "SORSolver.hh"
#include "StaggeredGrid.hh"
#include "initialisers.hh"
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
    
    read.readFile(parameterfile);
    read.printParameters();

    StaggeredGrid grid(read);
    
    grid.initialiseP(x_function);
    grid.initialiseRHS(sinx_function);
    
    grid.p().print();
    SORSolver solver(read);
    
    solver.solve(grid);
    
    
    grid.p().print();
    grid.rhs().print();
    
//     Array testArray( read.getIntParameter("width"), read.getIntParameter("height") );
//     testArray.fill( read.getRealParameter("initial") );
//     testArray( read.getIntParameter("x"), read.getIntParameter("y") ) = 2.0*testArray( read.getIntParameter("x"), read.getIntParameter("y") );
//     
//     testArray.print();

    return 0;
}
