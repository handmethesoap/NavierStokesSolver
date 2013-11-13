#ifndef STAGGERED_GRID_HH
#define STAGGERED_GRID_HH


#include "Types.hh"
#include "Array.hh"
#include "FileReader.hh"

//*******************************************************************************************************************
/*! Class for storing all arrays required for the simulation
*
* For now it only contains an array for the pressure and another array for the
* right hand side of the pressure equation.
* In following assignments this will be extended and also contain
* arrays for x/y velocity and some arrays for intermediate values.
*
* Feel free to add member functions or variables to this class, but please don't
* delete or rename any existing functions, since future skeletons rely on these functions.
*
*/
//*******************************************************************************************************************
class StaggeredGrid
{
public:
   // Constructors to manually create staggered grid
   StaggeredGrid ( int xSize, int ySize, real dxx, real dyy ) : p_((xSize + 2),(ySize + 2)), rhs_(xSize, ySize), dx_(dxx), dy_(dyy) {}

   // Constructor to create a staggered grid from a parsed configuration file
   StaggeredGrid ( const FileReader & configuration ) : p_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax") + 2)), 
							rhs_(configuration.getIntParameter("imax"), configuration.getIntParameter("jmax")), 
							dx_(double(configuration.getIntParameter("xlength")) / double(configuration.getIntParameter("imax"))),
							dy_(double(configuration.getIntParameter("ylength")) / double(configuration.getIntParameter("jmax"))){}


   // Getters / Setters for member variables
   Array & p()    { return p_;    }
   Array & rhs()  { return rhs_;  }

   const Array & p()   const { return p_;   }
   const Array & rhs() const { return rhs_; }

   real dx() const { return dx_; }
   real dy() const { return dy_; }
   
   void initialiseP(real(* initialiser)(real, real));
   void initialiseRHS(real(* initialiser)(real, real));
  

protected:
   Array p_;   //< pressure field
   Array rhs_; //< right hand side of the pressure equation

   real dx_;   //< distance between two grid points in x direction
   real dy_;   //< distance between two grid points in y direction
};



#endif //STAGGERED_GRID_HH

