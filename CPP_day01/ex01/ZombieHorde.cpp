#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    int i;
    std::string input1;
    std::string input;
    Zombie  *zombies = new Zombie[N];

    std::cout << "Do you want to give Zombies unique names? (y/n)" << std::endl;
    while (input != "y" && input != "n")
    {
        std::getline(std::cin, input);
        if (std::cin.eof() == 1)
	    {
		    std::cout << "exiting" << std::endl;
		    return zombies;
	    }
    }
    i = 0;
    while (i < N)
    {
        if (input == "y")
        {
            std::cout << "Please enter unique name for zombie number " << i << ":" << std::endl;
            std::getline(std::cin, input1);
            if (std::cin.eof() == 1)
	        {
		        std::cout << "exiting" << std::endl;
		        return zombies;
	        }
            zombies[i].set_name(input1);
        }
        else
            zombies[i].set_name(name);
        i++;
    }
    return (zombies);
}
