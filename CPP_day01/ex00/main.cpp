#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
    std::string input;

    /*TESTS: stack zombie*/
    std::cout << "What name would you like to give your stack zombie?" << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof() == 1)
	{
		std::cout << "exiting" << std::endl;
		return 0;
	}
    randomChump(input);
    std::cout << "the destructor was called at end of randomChump function ^^" << std::endl;
    std::cout << "---------------------------------------------------------------\n" << std::endl;

    /*TESTS: heap zombie*/
    std::cout << "What name would you like to give your heap zombie?" << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof() == 1)
	{
		std::cout << "exiting" << std::endl;
		return 0;
	}
    Zombie  *heap_zombie = newZombie(input);
    heap_zombie->announce();
    delete heap_zombie;
    std::cout << "the destructor was called during delete ^^" << std::endl;
    return 0 ;
}