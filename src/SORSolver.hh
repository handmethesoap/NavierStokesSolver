#ifndef SOR_SOLVER_HH
#define SOR_SOLVER_HH

#include "StaggeredGrid.hh"
#include "Debug.hh"


class SORSolver
{
public:
   // Constructor to manually create SORSolver
   SORSolver ( int xSize, int ySize, real dxx, real dyy, int itermax, real eps, real omg ) :	xSize_(xSize), 
												ySize_(ySize), 
												dx_(dxx), 
												dy_(dyy), 
												itermax_(itermax), 
												eps_(eps), 
												omg_(omg){}

   // Constructor to create a SORSolver from a parsed configuration file
   SORSolver ( const FileReader & configuration ) : xSize_(configuration.getIntParameter("imax")),
						    ySize_(configuration.getIntParameter("jmax")),
						    dx_(configuration.getIntParameter("xlength") / configuration.getIntParameter("imax")),
						    dy_(configuration.getIntParameter("ylength") / configuration.getIntParameter("jmax")),
						    itermax_(configuration.getIntParameter("itermax")),
						    eps_(configuration.getRealParameter("eps")),
						    omg_(configuration.getRealParameter("omg")){}


   // solve the pressure equation on the staggered grid
   bool solve( StaggeredGrid & grid );
   void fillBoundary( StaggeredGrid & grid );

private:
   int xSize_;
   int ySize_;
   real dx_;
   real dy_;
   int itermax_;
   real eps_;
   real omg_;
};






#endif //SOR_SOLVER_HH




