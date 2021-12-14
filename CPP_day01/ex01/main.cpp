#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
    std::string input;
    std::string input2;
    int i;
    long int magic_number;

    /*section 1: get integer value for no of zombies*/
    i = 0;
    long int max = 2147483647;
    magic_number = 0;
    while (magic_number < 1)
    {
        std::cout << "How many Zombies would you like to create? [must be greater than 0 and less than INT_MAX]" << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof() == 1)
	    {
		    std::cout << "exiting" << std::endl;
		    return 0;
	    }
        if (input.find_first_not_of("0123456789\n") != 0)
        {
            while (i < (int)input.length())
            {
                if ((magic_number * 10) + (input[i] - 48) > max)
                {
                    std::cout << "Error: number is too big" << std::endl;
                    return 0;
                }
                magic_number = (magic_number * 10) + (input[i] - 48) ;
                i++;
            }
        }
        else
        {
            std::cout << "Error: not all numeric" <<std::endl;
            return 0;
        }
        std::cin.clear();
    }
    /*section two: get names for zombies*/
    std::cout << "OK. What shall we name our zombies?" << std::endl;
    std::getline(std::cin, input2);
    if (std::cin.eof() == 1)
	{
		std::cout << "exiting" << std::endl;
		return 0;
	}
    /*create zombie horde with function zombieHorde*/
    Zombie  *my_horde = zombieHorde(magic_number, input2);

    /*check they all exist using announce*/
    std::cout << "Let's check my horde exists. Calling announce..." << std::endl;
    i = 0;
    while (i < magic_number)
    {
        my_horde[i].announce();
        i++;
    }

    /*delete my_horde and exit*/
    delete [] my_horde;
    return 0 ;
}
