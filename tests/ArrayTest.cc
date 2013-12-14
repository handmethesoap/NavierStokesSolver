
#include "Array.hh"
#include "Debug.hh"

#include <iostream>

void copyTest()
{
   const int size = 10;

   // Fill single array...
   Array<real> arr (size);
   for ( int i = 0; i<size; ++i )
      arr(i) = i;

   // check if values where set correctly
   for ( int i = 0; i<size; ++i )
      CHECK( arr(i) == i );


   // create a copy of the array, and check if values are the same
   Array<real> arrCopy (arr);
   for ( int i = 0; i<size; ++i )
      CHECK( arrCopy(i) == i );


   // write new values to copy
   for ( int i = 0; i<size; ++i )
      arrCopy(i) = 2*i;

   // and check both arrays again
   for ( int i = 0; i<size; ++i )
      CHECK( arr(i) == i );
   for ( int i = 0; i<size; ++i )
      CHECK( arrCopy(i) == 2*i );

}

void  contiguousMemoryTest()
{
   Array<real> arr ( 10, 5 );

   size_t memDifference =  & ( arr (9,4 ) ) - & ( arr(0,0) );
   CHECK( memDifference == 10*5 - 1 );
}


int main( )
{
  
   std::cout << "########## ARRAY TEST #########" << std::endl << std::endl;
   
   std::cout << "+ Testing copy" << std::endl;
   copyTest();
   std::cout << "     PASSED" << std::endl;

   std::cout << "+ Testing contiguous memory" << std::endl;
   contiguousMemoryTest();
   std::cout << "     PASSED" << std::endl;

   std::cout << std::endl << "########## ARRAY TEST PASSED #########" << std::endl << std::endl;
   return 0;
}
