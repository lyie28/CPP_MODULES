#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/*canonical functions*/
FragTrap::FragTrap(std::string name)
{
    _name = name;
    _attack_damage = 30;
    _hitpoints = 100;
    _energy = 100;
    std::cout << "FRAGTRAP: " << get_name() << " is born" << std::endl;
    return ;
}

FragTrap::FragTrap(void)
{
    _attack_damage = 30;
    _hitpoints = 100;
    _energy = 100;
    std::cout << "FRAGTRAP: unnamed is born" << std::endl;
    return ;
}

FragTrap & FragTrap::operator=( FragTrap const & rhv)
{
    std::cout << "FRAGTRAP: Assignation operator called: " << get_name() << " is now " << rhv.get_name() << std::endl;
    set_name(rhv._name);
    set_hp(rhv._hitpoints);
    set_ep(rhv._energy);
    set_ad(rhv._attack_damage);
    return *this;
}

FragTrap::FragTrap( FragTrap const & copy) : ClapTrap()
{
    *this = copy;
    std::cout << "FRAGTRAP: " << get_name() << " has been copied" << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FRAGTRAP: " << get_name() << " is dead" << std::endl;
    return ;
}

/*FragTrap functions*/
void FragTrap::highFivesGuys()
{
    std::cout << "Give me five guys!" << std::endl;
}