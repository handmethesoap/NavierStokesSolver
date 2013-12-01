#ifndef ARRAY_HH
#define ARRAY_HH


#include <Types.hh>
#include "Debug.hh"


//*******************************************************************************************************************
/*!  Array class for 1,2 and 3 dimensions
*
*    - all elements should be stored in a contiguous chunk of memory ( no vector<vector> ! )
*/
//*******************************************************************************************************************
class Array
{
public:
   // Constructors for 1D,2D and 3D
   Array( int xSize );
   Array( int xSize, int ySize );
   Array( int xSize, int ySize, int zSize );


   // Depending on your implementation you might need the following:
   ~Array();
   Array(const Array& s);
   Array& operator= (const Array& s);


   // Access Operators for 1D, 2D and 3D
   inline real & operator () ( int i );
   inline real & operator () ( int i ,int j );
   inline real & operator () ( int i, int j, int k );

   // for const Arrays the following access operators are required
   inline const real & operator () ( int i ) const;
   inline const real & operator () ( int i ,int j ) const;
   inline const real & operator () ( int i, int j, int k ) const;



   // initialize the whole array with a constant value
   void fill( real value );
   
   // initialise the array with an incrementing value
   void incrementFill( void );


   // return total size of the array
   int getSize() const;

   // return xSize for dimension==0, ySize for dimension==1 and zSize for dimension==2
   // other dimension values are not allowed
   int getSize( int dimension ) const;


   // Print the whole array ( for debugging purposes )
   void print();

private:

    real* array_;
    int xSize_;
    int ySize_;
    int zSize_;

};


//===================================================================================================================
//
//  Inline Access Operators and Sizes
//
//===================================================================================================================


// Operator() 1D
inline real& Array::operator ()(int i)
{
  
  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  
   return array_[i];
}

// Operator() 2D
inline real& Array::operator ()(int i,int j)
{
    
  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(j < ySize_, "You have attempted to access an array element larger than the upper bound in the y dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  ASSERT_MSG(j >= 0, "You have attempted to access an array element smaller than the lower bound in the y dimension");
 
   return array_[i + j*xSize_];
}

// Operator() 3D
inline real& Array::operator ()(int i, int j, int k)
{  
  
  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(j < ySize_, "You have attempted to access an array element larger than the upper bound in the y dimension");
  ASSERT_MSG(k < zSize_, "You have attempted to access an array element larger than the upper bound in the z dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  ASSERT_MSG(j >= 0, "You have attempted to access an array element smaller than the lower bound in the y dimension");
  ASSERT_MSG(k >= 0, "You have attempted to access an array element smaller than the lower bound in the z dimension");
 
   return array_[i + j*xSize_ + k*xSize_*ySize_];
}

inline const real & Array::operator () ( int i ) const
{

  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  
   return array_[i];
}

inline const real & Array::operator () ( int i ,int j ) const
{
 
  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(j < ySize_, "You have attempted to access an array element larger than the upper bound in the y dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  ASSERT_MSG(j >= 0, "You have attempted to access an array element smaller than the lower bound in the y dimension");
  
   return array_[i + j*xSize_];
}

inline const real & Array::operator () ( int i, int j, int k ) const
{
  
  ASSERT_MSG(i < xSize_, "You have attempted to access an array element larger than the upper bound in the x dimension");
  ASSERT_MSG(j < ySize_, "You have attempted to access an array element larger than the upper bound in the y dimension");
  ASSERT_MSG(k < zSize_, "You have attempted to access an array element larger than the upper bound in the z dimension");
  ASSERT_MSG(i >= 0, "You have attempted to access an array element smaller than the lower bound in the x dimension");
  ASSERT_MSG(j >= 0, "You have attempted to access an array element smaller than the lower bound in the y dimension");
  ASSERT_MSG(k >= 0, "You have attempted to access an array element smaller than the lower bound in the z dimension");
  
   return array_[i + j*xSize_ + k*xSize_*ySize_];
}


#endif //ARRAY_HH

