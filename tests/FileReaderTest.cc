
#include "FileReader.hh"
#include "Debug.hh"

#include <cmath>
#include <iostream>


int main( )
{
   std::cout << "########## FILE READER TEST #########" << std::endl << std::endl;
   FileReader myReader;

   myReader.registerIntParameter   ("exampleInt" );
   myReader.registerRealParameter  ("exampleReal");
   myReader.registerStringParameter("exampleString" );

   bool res = myReader.readFile ( "parameterfiles/FileReaderTestInput.txt" );
   
   std::cout << "+ Testing file opens" << std::endl;
   CHECK_MSG(res, "   FAILED: Could not open file 'FileReaderTestInput.txt' which has to be in the current directory.");
   std::cout << "     PASSED" << std::endl;

   std::cout << "+ Testing reading of ints" << std::endl;
   CHECK( myReader.getIntParameter   ("exampleInt")    == 42 );
   std::cout << "     PASSED" << std::endl;
   
   std::cout << "+ Testing reading of strings" << std::endl;
   CHECK( myReader.getStringParameter("exampleString") == "someStringValue" );
   std::cout << "     PASSED" << std::endl;
   
   std::cout << "+ Testing reading of reals" << std::endl;
   CHECK( std::abs( myReader.getRealParameter("exampleReal") - 42.4242 ) < 1e-5 );
   std::cout << "     PASSED" << std::endl;

   myReader.registerIntParameter("aNewInt");
   myReader.setParameter( "aNewInt",    43 ); // add new value ( no registration required )
   myReader.setParameter( "exampleInt", 44 ); // overwrite existing value

   std::cout << "+ Testing adding new value to file reader" << std::endl;
   CHECK( myReader.getIntParameter("aNewInt")     == 43 );
   std::cout << "     PASSED" << std::endl;
   
   std::cout << "+ Testing resetting integer value" << std::endl;
   CHECK( myReader.getIntParameter("exampleInt")  == 44 );
   std::cout << "     PASSED" << std::endl;


   std::cout << std::endl << "########## FILE READER TEST PASSED ##########" << std::endl << std::endl;

   return 0;
}
