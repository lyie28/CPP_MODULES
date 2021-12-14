#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>
#include <iomanip>

HumanB::HumanB( std::string name ) : _name(name)
{
    return ;
}

HumanB::~HumanB( void )
{
    return ;
}

void    HumanB::attack(void) const
{
    std::cout << _name << " attacks with her " << _weapon->getType() << std::endl;
    return ;
}

void        HumanB::setWeapon(Weapon  &weapon_type)
{
    _weapon = &weapon_type;
}