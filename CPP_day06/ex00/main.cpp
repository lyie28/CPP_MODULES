#include <iostream>
#include "Lit.hpp"

/*static cast can be used for any conversions that would be allowed implicitly*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "USAGE: ./convert [value]" << std::endl;
        return 0;
    }
    Lit myConvert(argv[1]);
    if (myConvert.getBool())
    {
        myConvert.printer();
        return 0;
    }    
    else
    {
        std::cerr << "Invalid input" << std::endl;
        return 0;
    }
}