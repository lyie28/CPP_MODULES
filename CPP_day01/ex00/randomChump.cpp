#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie Dave;
    
    Dave.set_name(name);
    Dave.announce();
    return ;
}