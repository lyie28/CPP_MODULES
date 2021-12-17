#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*canonical functions*/
ScavTrap::ScavTrap(std::string name)
{
    _name = name;
    _hitpoints = 100;
    _attack_damage = 20;
    _energy = 50;
    std::cout << "SCAVTRAP: " << get_name() << " is born" << std::endl;
    return ;
}

ScavTrap::ScavTrap(void)
{
    _hitpoints = 100;
    _attack_damage = 20;
    _energy = 50;
    std::cout << "SCAVTRAP: " << get_name() << " is born" << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "SCAVTRAP: " << get_name() << " is dead" << std::endl;
    return ;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhv)
{
    std::cout << "SCAVTRAP: Assignation operator called: " << get_name() << " is now " << rhv.get_name() << std::endl;
    set_name(rhv._name);
    set_hp(rhv._hitpoints);
    set_ep(rhv._energy);
    set_ad(rhv._attack_damage);
    return *this;
}

ScavTrap::ScavTrap( ScavTrap const & copy ) : ClapTrap()
{
    *this = copy;
    std::cout << "SCAVTRAP: " << get_name() << " has been copied" << std::endl;
    return ;
}

/*SCAVTRAP FUNCTIONS*/
void ScavTrap::attack(std::string const & target)
{
    if (get_hp() == 0)
        std::cout << "SCAVTRAP " << get_name() << " cannot attack " << target << ". Please heal " << get_name() << std::endl;
    else
        std::cout << "SCAVTRAP " << get_name() << " attacks " << target <<", causing " << get_ad() << " points of damage!" << std::endl;
    return ;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode" << std::endl;
}