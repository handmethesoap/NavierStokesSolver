#include "Array.hh"
#include <iostream>
#include <iomanip>


//===================================================================================================================
//
//  Constructors
//
//===================================================================================================================


Array::Array( int xSize ) : _xSize(xSize), _ySize(1), _zSize(1)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");

   _array = new real[ xSize ];
}

Array::Array( int xSize, int ySize ) : _xSize(xSize), _ySize(ySize), _zSize(1)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");
  CHECK_MSG(ySize >= 0, "the y dimension of the array cannot be negative");

   _array = new real[ xSize*ySize ];
}

Array::Array( int xSize, int ySize, int zSize ) : _xSize(xSize), _ySize(ySize), _zSize(zSize)
{

  CHECK_MSG(xSize >= 0, "the x dimension of the array cannot be negative");
  CHECK_MSG(ySize >= 0, "the y dimension of the array cannot be negative");
  CHECK_MSG(zSize >= 0, "the z dimension of the array cannot be negative");

   _array = new real[ xSize*ySize*zSize ];
}

Array::Array(const Array& s) : _xSize(s._xSize), _ySize(s._ySize), _zSize(s._zSize)
{
  _array = new real[ s._xSize*s._ySize*s._zSize ];
  for( int i = 0; i < s._xSize*s._ySize*s._zSize; ++i )
  {
    _array[i] = s._array[i];
  }
}

Array& Array::operator= (const Array& s)
{
  Array tmp( s );
  
  std::swap( _xSize, tmp._xSize );
  std::swap( _ySize, tmp._ySize );
  std::swap( _zSize, tmp._zSize );
  std::swap( _array, tmp._array );
  
  return *this;
}



Array::~Array()
{
  delete [] _array;
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
  std::fill(_array, _array + this->getSize(), value);
}

void Array::incrementFill()
{
  for( int i = 0; i < this->getSize(); ++i )
  {
    this->_array[i] = i;
  }
}

// Print the whole array (for debugging purposes)
void Array::print()
{
   // For 2D Arrays the positive x-coordinate goes to the right
   //                   positive y-coordinate goes upwards
   //      -> the line with highest y-value should be printed first
  for( int z = 0; z < _zSize; ++z )
  {
    for( int y = _ySize - 1; y >= 0; --y )
    {
      for( int x = 0; x < _xSize; ++x ) 
      {
	std::cout << std::left << std::setw(13) << (*this)(x, y, z);
      }
      std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
  }
}

int Array::getSize( int dimension ) const
{
   if( dimension == 0 )
   {
     return _xSize;
   }
   else if( dimension == 1 )
   {
     return _ySize;
   }
   else if( dimension == 2 )
   {
     return _zSize;
   }
   else
   {
     return 0;
   }
}

//return total size of the array
int Array::getSize() const
{
   return _xSize*_ySize*_zSize;
}
