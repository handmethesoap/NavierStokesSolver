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
   StaggeredGrid ( int _xSize, int _ySize, real dxx, real dyy ) : p_((_xSize + 2),(_ySize + 2)), 
								rhs_(_xSize, _ySize), 
								u_((_xSize + 1),(_ySize + 2)),
								v_((_xSize + 2),(_ySize + 1)),
								f_((_xSize + 1),(_ySize)),
								g_((_xSize),(_ySize + 1)),
								dx_(dxx), 
								dy_(dyy),
								xSize_(_xSize),
								ySize_(_ySize){

      CHECK_MSG(_xSize > 0.0, "The x dimension must be positive");
      CHECK_MSG(_ySize > 0.0, "the y dimension must be positive");
      CHECK_MSG(dxx > 0.0, "the size of the element must be positive in the x dimension");
      CHECK_MSG(dyy > 0.0, "the size of the element must be positive in the y dimension");
   }

   // Constructor to create a staggered grid from a parsed configuration file
   StaggeredGrid ( const FileReader & configuration ) : p_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax") + 2)), 
							rhs_(configuration.getIntParameter("imax"), configuration.getIntParameter("jmax")),
							u_((configuration.getIntParameter("imax") + 1), (configuration.getIntParameter("jmax") + 2)), 
							v_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax") + 1)), 
							f_((configuration.getIntParameter("imax") + 1), (configuration.getIntParameter("jmax"))), 
							g_((configuration.getIntParameter("imax")), (configuration.getIntParameter("jmax") + 1)), 
							dx_(double(configuration.getIntParameter("xlength")) / double(configuration.getIntParameter("imax"))),
							dy_(double(configuration.getIntParameter("ylength")) / double(configuration.getIntParameter("jmax"))),
							xSize_(configuration.getIntParameter("imax")),
							ySize_(configuration.getIntParameter("jmax")){
      
	CHECK_MSG(configuration.getIntParameter("imax") > 0, "the number of elements in the x direction must be greater than zero");
	CHECK_MSG(configuration.getIntParameter("jmax") > 0, "the number of elements in the y direction must be greater than zero");
	CHECK_MSG(configuration.getIntParameter("xlength") > 0.0, "the length in the x direction must exceed 0.0");
	CHECK_MSG(configuration.getIntParameter("ylength") > 0.0, "the length in the y direction must exceed 0.0");
    }


   // Getters / Setters for member variables
   Array & p()    { return p_;    }
   Array & rhs()  { return rhs_;  }
   Array & u()    { return u_;  }
   Array & v()    { return v_;  }
   Array & f()    { return f_;  }
   Array & g()    { return g_;  }

   const Array & p()   const { return p_;   }
   const Array & rhs() const { return rhs_; }
   const Array & u() const { return u_; }
   const Array & v() const { return v_; }
   const Array & f() const { return f_; }
   const Array & g() const { return g_; }

   real dx() const { return dx_; }
   real dy() const { return dy_; }
   
   int xSize() const { return xSize_; }
   int ySize() const { return ySize_; }
   
   void initialiseP(real(* initialiser)(real, real));
   void initialiseRHS(real(* initialiser)(real, real));
   void initialiseU(real(* initialiser)(real, real));
   void initialiseV(real(* initialiser)(real, real));
   void initialiseF(real(* initialiser)(real, real));
   void initialiseG(real(* initialiser)(real, real));
   
   void initialiseP(real value);
   void initialiseRHS(real value);
   void initialiseU(real value);
   void initialiseV(real value);
   void initialiseF(real value);
   void initialiseG(real value);
  

protected:
   Array p_;   //< pressure field
   Array rhs_; //< right hand side of the pressure equation
   Array u_;	//< Horizontal velocity
   Array v_;	//< vertical velocity
   Array f_;
   Array g_;

   real dx_;   //< distance between two grid points in x direction
   real dy_;   //< distance between two grid points in y direction
   
   int xSize_;
   int ySize_;
};



#endif //STAGGERED_GRID_HH

