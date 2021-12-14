#include "Karen.hpp"

int main(void)
{
    Karen example;
    example.complain("DEBUG");
    std::cout << std::endl;
    example.complain("INFO");
    std::cout << std::endl;
    example.complain("WARNING");
    std::cout << std::endl;
    example.complain("ERROR");
    std::cout << std::endl;
    example.complain("not a function");
    return 0;
}