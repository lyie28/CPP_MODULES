#include "Zombie.hpp"


void    Zombie::set_name( std::string name)
{
    _name = name;
}

Zombie::Zombie( void )
{
    std::cout << "CONSTRUCTOR CALLED. New zombie has been born..." << std::endl;
    return ;
}

Zombie::~Zombie( void )
{
    std::cout << "DESTRUCTOR CALLED. Bye bye " << _name << std::endl;
    return ;
}

void    Zombie::announce(void) const
{
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
