#include "Array.hh"
#include <iostream>
#include <iomanip>


//===================================================================================================================
//
//  Constructors
//
//===================================================================================================================


Array::Array( int xSize ) : xSize_(xSize), ySize_(1), zSize_(1)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");

   array_ = new real[ xSize ];
}

Array::Array( int xSize, int ySize ) : xSize_(xSize), ySize_(ySize), zSize_(1)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");
  CHECK_MSG(ySize >= 0, "the y dimension of the array cannot be negative");

   array_ = new real[ xSize*ySize ];
}

Array::Array( int xSize, int ySize, int zSize ) : xSize_(xSize), ySize_(ySize), zSize_(zSize)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");
  CHECK_MSG(ySize >= 0, "the y dimension of the array cannot be negative");
  CHECK_MSG(zSize >= 0, "the z dimension of the array cannot be negative");

   array_ = new real[ xSize*ySize*zSize ];
}

Array::Array(const Array& s) : xSize_(s.xSize_), ySize_(s.ySize_), zSize_(s.zSize_)
{
  array_ = new real[ s.xSize_*s.ySize_*s.zSize_ ];
  for( int i = 0; i < s.xSize_*s.ySize_*s.zSize_; ++i )
  {
    array_[i] = s.array_[i];
  }
}

Array& Array::operator= (const Array& s)
{
  Array tmp( s );
  
  std::swap( xSize_, tmp.xSize_ );
  std::swap( ySize_, tmp.ySize_ );
  std::swap( zSize_, tmp.zSize_ );
  std::swap( array_, tmp.array_ );
  
  return *this;
}



Array::~Array()
{
  delete [] array_;
}


//===================================================================================================================
//
//  Convenience Functions
//
//===================================================================================================================


//initialize the whole array with a constant value
void Array::fill( real value )
{
   // you might want to use std::fill() here
  std::fill(array_, array_ + this->getSize(), value);
}

void Array::incrementFill()
{
  for( int i = 0; i < this->getSize(); ++i )
  {
    this->array_[i] = i;
  }
}

// Print the whole array (for debugging purposes)
void Array::print()
{
   // For 2D Arrays the positive x-coordinate goes to the right
   //                   positive y-coordinate goes upwards
   //      -> the line with highest y-value should be printed first
  for( int z = 0; z < zSize_; ++z )
  {
    for( int y = ySize_ - 1; y >= 0; --y )
    {
      for( int x = 0; x < xSize_; ++x ) 
      {
	std::cout << std::left << std::setw(13) << (*this)(x, y, z);
      }
      std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
  }
}

void Array::normalize()
{
  
  real sum = 0.0;
  real average;
  
  for( int z = 0; z < zSize_; ++z )
  {
    for( int y = ySize_ - 1; y >= 0; --y )
    {
      for( int x = 0; x < xSize_; ++x ) 
      {
	sum += (*this)(x, y, z);
      }
    }
  }
  
  average = sum / (zSize_*ySize_*xSize_);
  
  for( int z = 0; z < zSize_; ++z )
  {
    for( int y = ySize_ - 1; y >= 0; --y )
    {
      for( int x = 0; x < xSize_; ++x ) 
      {
	(*this)(x, y, z) = (*this)(x, y, z) - average;
      }
    }
  }
}

int Array::getSize( int dimension ) const
{
   if( dimension == 0 )
   {
     return xSize_;
   }
   else if( dimension == 1 )
   {
     return ySize_;
   }
   else if( dimension == 2 )
   {
     return zSize_;
   }
   else
   {
     return 0;
   }
}

//return total size of the array
int Array::getSize() const
{
   return xSize_*ySize_*zSize_;
}
