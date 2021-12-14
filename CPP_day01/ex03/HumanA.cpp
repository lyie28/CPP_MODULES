#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>
#include <string>
#include <iomanip>

HumanA::HumanA( std::string name, Weapon &my_weapon ) : _name(name), _weapon(my_weapon)
{
    return ;
}

HumanA::~HumanA( void )
{
    return ;
}

void    HumanA::attack(void) const
{
    std::cout << _name << " attacks with her " << _weapon.getType() << std::endl;
    return ;
}