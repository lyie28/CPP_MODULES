#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

/*canonical functions*/
DiamondTrap::DiamondTrap(std::string name)
{
    _name = name;
    this->_attack_damage = get_ad();
    this->_energy = this->ScavTrap::_energy;
    this->_hitpoints = this->FragTrap::_hitpoints;
    ClapTrap::_name = _name + "_clap_name";
    std::cout << "DIAMONDTRAP: " << _name << " is born" << std::endl;
    return ;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhv)
{
    std::cout << "DIAMONDTRAP: Assignation operator called: " << _name << " is now " << rhv._name << std::endl;
    _name = rhv._name;
    set_name(rhv.get_name());
    set_hp(rhv._hitpoints);
    set_ep(rhv._energy);
    set_ad(rhv._attack_damage);
    return *this;
}

DiamondTrap::DiamondTrap( DiamondTrap const & copy) : ClapTrap(), FragTrap(), ScavTrap()
{
    *this = copy;
    std::cout << "DIAMONDTRAP: " << _name << " has been copied" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(void)
{
    this->_attack_damage = this->FragTrap::_attack_damage;
    this->_energy = this->ScavTrap::_energy;
    this->_hitpoints = this->FragTrap::_hitpoints;
    ClapTrap::_name = "_clap_name";
    std::cout << "DIAMONDTRAP: unnamed is born" << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DIAMONDTRAP: " << _name << " is dead" << std::endl;
    return ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
