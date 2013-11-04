#include "Array.hh"
#include "FileReader.hh"

#include <iostream>


int main( int argc, char** argv )
{

    Array test(7, 6, 5);
    test.incrementFill();
    Array test2(1,2,3);
    test2.fill(2.0);
    std::cout << test2(0,1,1) << std::endl;
    test2.print();
    test2 = test;
    std::cout << test2(3,3,3) << std::endl;
    test2.print();
    
    FileReader testread;
    testread.registerStringParameter("name");
    testread.registerIntParameter("bcN");
    testread.registerIntParameter("bcE");
    testread.registerIntParameter("bcS");
    testread.registerIntParameter("bcW");
    testread.registerRealParameter("GX");
    testread.registerRealParameter("GY");
    
    testread.readFile("parameters.txt");
    testread.printParameters();
   return 0;
}
