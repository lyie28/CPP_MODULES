#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Weapon::Weapon( std::string weapon_type )
{
    setType(weapon_type);
    return ;
}

Weapon::~Weapon( void )
{
    return ;
}

void        Weapon::setType( std::string weapon_type )
{
    _type = weapon_type;
    return ;
}

std::string const   &Weapon::getType(void) const
{
        return (_type);
}