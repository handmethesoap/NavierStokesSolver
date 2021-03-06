#ifndef SOR_SOLVER_HH
#define SOR_SOLVER_HH

#include "StaggeredGrid.hh"
#include "Debug.hh"


class SORSolver
{
public:
   // Constructor to manually create SORSolver
   SORSolver ( int itermax, real eps, real omg, int checkfrequency ) :	itermax_(itermax), 
									eps_(eps), 
									omg_(omg),
									checkfrequency_(checkfrequency){}

   // Constructor to create a SORSolver from a parsed configuration file
   SORSolver ( const FileReader & configuration ) : itermax_(configuration.getIntParameter("itermax")),
						    eps_(configuration.getRealParameter("eps")),
						    omg_(configuration.getRealParameter("omg")),
						    checkfrequency_(configuration.getIntParameter("checkfrequency")){
						      
    CHECK_MSG(itermax_ > 0, "the program will not perform any iterations unless intermax is set greater than zero");
  }


   // solve the pressure equation on the staggered grid
   bool solve( StaggeredGrid & grid );
   void fillBoundary( StaggeredGrid & grid );
   real calcResidual( StaggeredGrid & grid );

private:
   int itermax_;
   real eps_;
   real omg_;
   int checkfrequency_;
};






#endif //SOR_SOLVER_HH




