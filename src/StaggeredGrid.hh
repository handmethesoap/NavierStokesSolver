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
								flags_((_xSize),(_ySize)),
								dx_(dxx), 
								dy_(dyy),
								xSize_(_xSize),
								ySize_(_ySize){

      CHECK_MSG(_xSize > 0.0, "The x dimension must be positive");
      CHECK_MSG(_ySize > 0.0, "the y dimension must be positive");
      CHECK_MSG(dxx > 0.0, "the size of the element must be positive in the x dimension");
      CHECK_MSG(dyy > 0.0, "the size of the element must be positive in the y dimension");
      
      initialiseFlags(1);
   }

   // Constructor to create a staggered grid from a parsed configuration file
   StaggeredGrid ( const FileReader & configuration ) : p_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax") + 2)), 
							rhs_(configuration.getIntParameter("imax"), configuration.getIntParameter("jmax")),
							u_((configuration.getIntParameter("imax") + 1), (configuration.getIntParameter("jmax") + 2)), 
							v_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax") + 1)), 
							f_((configuration.getIntParameter("imax") + 1), (configuration.getIntParameter("jmax"))), 
							g_((configuration.getIntParameter("imax")), (configuration.getIntParameter("jmax") + 1)), 
							flags_((configuration.getIntParameter("imax") + 2), (configuration.getIntParameter("jmax")) + 2),
							dx_(double(configuration.getRealParameter("xlength")) / double(configuration.getIntParameter("imax"))),
							dy_(double(configuration.getRealParameter("ylength")) / double(configuration.getIntParameter("jmax"))),
							xSize_(configuration.getIntParameter("imax")),
							ySize_(configuration.getIntParameter("jmax")){
      
	CHECK_MSG(configuration.getIntParameter("imax") > 0, "the number of elements in the x direction must be greater than zero");
	CHECK_MSG(configuration.getIntParameter("jmax") > 0, "the number of elements in the y direction must be greater than zero");
	CHECK_MSG(configuration.getRealParameter("xlength") > 0.0, "the length in the x direction must exceed 0.0");
	CHECK_MSG(configuration.getRealParameter("ylength") > 0.0, "the length in the y direction must exceed 0.0");
	
	initialiseFlags(1);
      
    }


   // Getters / Setters for member variables
   Array<real> & p()    { return p_;    }
   Array<real> & rhs()  { return rhs_;  }
   Array<real> & u()    { return u_;  }
   Array<real> & v()    { return v_;  }
   Array<real> & f()    { return f_;  }
   Array<real> & g()    { return g_;  }
   Array<bool> & flags()    { return flags_;  }

   const Array<real> & p()   const { return p_;   }
   const Array<real> & rhs() const { return rhs_; }
   const Array<real> & u() const { return u_; }
   const Array<real> & v() const { return v_; }
   const Array<real> & f() const { return f_; }
   const Array<real> & g() const { return g_; }
   const Array<bool> & flags() const { return flags_; }

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
   void initialiseFlags(bool value);
      
   void normalizeP(void);
   void normalizeRHS(void);
   
   inline bool isFluid(const int x, const int y){ return flags_(x,y); };
   inline int getNumFluid();
   
   inline real u(const int x, const int y, Direction dir);
   inline real v(const int x, const int y, Direction dir);
   inline real p(const int x, const int y, Direction dir);
   
   inline real u(const int x, const int y);
   inline real v(const int x, const int y);
   
   void setCellToObstacle(int x, int y){ flags_(x,y) = 0; };
   void createRectangle( int x1, int y1, int x2, int y2 );
   void createCircle( int x, int y, int r);
   
   void readPNG(const std::string & pngFilename);
   void writePNG(const std::string & pngFilename);
  
protected:
   Array<real> p_;   //< pressure field
   Array<real> rhs_; //< right hand side of the pressure equation
   Array<real> u_;	//< Horizontal velocity
   Array<real> v_;	//< vertical velocity
   Array<real> f_;
   Array<real> g_;
   Array<bool> flags_;

   real dx_;   //< distance between two grid points in x direction
   real dy_;   //< distance between two grid points in y direction
   
   int xSize_;
   int ySize_;
};




inline int StaggeredGrid::getNumFluid(){
  int sum = 0;
  for(int x = 1; x < flags_.getSize(0) - 1; ++x){
    for(int y = 1; y < flags_.getSize(1) - 1; ++y){
      sum += int(flags_(x,y));
    }
  }
  return sum;
}

inline real StaggeredGrid::u(const int x, const int y, Direction dir){
  
  //if cells to either side of u are both fluid then return velocity as normal
  if(isFluid(x,y) && isFluid(x+1,y)){
    return u_(x,y);
  }
  //if cell on one side is fluid and cell on other is not then return velocity zero
  else if( (isFluid(x,y) || isFluid(x+1,y)) ){
    return 0.0;
  }
  //else if cells on both sides are not fluid return according to neumann boundary 
  else{
    if( dir == NORTH ){
      return -u_(x,y+1);
    }
    else if( dir == EAST ){
      CHECK_MSG(0, "Accessing unncessary u velocity from the east");
      return 0;
    }
    else if( dir == SOUTH ){
      return -u_(x,y-1);
    }
    else if( dir == WEST ){
      CHECK_MSG(0, "Accessing unncessary u velocity at position (" << x << ", " << y << ") from the west " << isFluid(x,y) << isFluid(x+1,y));
      return 0;
    }
    else{
      CHECK_MSG(0, "Unknown direction " << dir );
      return 0;
    }
  }
}

inline real StaggeredGrid::v(const int x, const int y, Direction dir){
  
  //if cells to either side of v are both fluid then return velocity as normal
  if(isFluid(x,y) && isFluid(x,y+1)){
    return v_(x,y);
  }
  //if cell on one side is fluid and cell on other is not then return velocity zero
  else if( (isFluid(x,y) || isFluid(x,y+1)) ){
    return 0.0;
  }
  //else if cells on both sides are not fluid return according to neumann boundary 
  else{
    if( dir == NORTH ){
      CHECK_MSG(0, "Accessing unncessary v velocity from the north");
      return 0;
    }
    else if( dir == EAST ){
      return -v_(x+1,y);
    }
    else if( dir == SOUTH ){
      CHECK_MSG(0, "Accessing unncessary v velocity from the south");
      return 0;
    }
    else if( dir == WEST ){
      return -v_(x-1,y);
    }
    else{
      CHECK_MSG(0, "Unknown direction " << dir );
      return 0;
    }
  }
}

inline real StaggeredGrid::p(const int x, const int y, Direction dir){
  if(isFluid(x,y))
  {
    return p_(x,y);
  }
  else{
    if( dir == NORTH ){
      return p_(x,y+1);
    }
    else if( dir == EAST ){
      return p_(x+1,y);
    }
    else if( dir == SOUTH ){
      return p_(x,y-1);
    }
    else if( dir == WEST ){
      return p_(x-1,y);
    }
    else{
      CHECK_MSG(0, "Unknown direction " << dir );
      return 0;
    }
  }
}

inline real StaggeredGrid::u(const int x, const int y){
  //if cells to either side of u are both fluid then return velocity as normal
  if(isFluid(x,y) && isFluid(x+1,y)){
    return u_(x,y);
  }
  else if(!isFluid(x,y) && !isFluid(x+1,y)){
    CHECK_MSG(0, "Accessing unncessary u velocity directly");
    return 0;
  }
  else{
    return 0.0;
  }
}

inline real StaggeredGrid::v(const int x, const int y){
  //if cells to either side of v are both fluid then return velocity as normal
  if(isFluid(x,y) && isFluid(x,y+1)){
    return v_(x,y);
  }
  else if(!isFluid(x,y) && !isFluid(x,y+1)){
    CHECK_MSG(0, "Accessing unncessary v velocity directly");
    return 0;
  }
  else{
    return 0.0;
  }
}  


#endif //STAGGERED_GRID_HH

