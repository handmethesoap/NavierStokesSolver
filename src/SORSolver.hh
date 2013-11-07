#ifndef SOR_SOLVER_HH
#define SOR_SOLVER_HH

#include "StaggeredGrid.hh"


class SORSolver
{
public:
   // Constructor to manually create SORSolver
   SORSolver ( int xSize, int ySize, real dxx, real dyy ) : grid_(xSize, ySize, dxx, dyy){}

   // Constructor to create a SORSolver from a parsed configuration file
   SORSolver ( const FileReader & configuration ) : grid_(configuration){}


   // solve the pressure equation on the staggered grid
   bool solve( StaggeredGrid & grid );

private:
   StaggeredGrid grid_;
};






#endif //SOR_SOLVER_HH




