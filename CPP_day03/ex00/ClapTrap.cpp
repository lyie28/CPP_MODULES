#include "ClapTrap.hpp"

/*canonical functions*/
ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _attack_damage(0), _energy(10)
{
    std::cout << "CLAPTRAP: " << get_name() << " is born" << std::endl;
    return ;
}

ClapTrap::ClapTrap(void) : _hitpoints(10), _attack_damage(0), _energy(10)
{
    std::cout << "CLAPTRAP: unnamed is born" << std::endl;
    return ;
}

ClapTrap::ClapTrap( ClapTrap const & copy)
{
    *this = copy;
    std::cout << "CLAPTRAP: " << get_name() << " has been copied" << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "CLAPTRAP: " << get_name() << " is dead" << std::endl;
    return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhv)
{
    std::cout << "CLAPTRAP: Assignation operator called: " << get_name() << " is now " << rhv.get_name() << std::endl;
    set_name(rhv._name);
    set_hp(rhv._hitpoints);
    set_ep(rhv._energy);
    set_ad(rhv._attack_damage);
    return *this;
}
        
/*functions from subject*/
void ClapTrap::attack(std::string const & target)
{
    if (get_hp() == 0)
        std::cout << "ClapTrap " << get_name() << " cannot attack " << target << ". Please heal " << get_name() << std::endl;
    else
        std::cout << "ClapTrap " << get_name() << " attacks " << target <<", causing " << get_ad() << " points of damage!" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << get_name() << " has been ambushed. " << amount <<" damage sustained!" << std::endl;
    if ((int)get_hp() - (int)amount < 0)
        set_hp(0);
    else
        set_hp(get_hp() - amount);
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << get_name() << " has been healed. " << amount <<" health added!" << std::endl;
    set_hp(get_hp() + amount);
    return ;
}

/*getters and setters*/
void ClapTrap::set_name( std::string name)
{
    _name = name;
    return ;
}

std::string ClapTrap::get_name(void) const
{
    return (_name);
}

unsigned int ClapTrap::get_ad(void) const
{
    return (_attack_damage);
}

unsigned int ClapTrap::get_hp(void) const
{
    return (_hitpoints);
}

unsigned int ClapTrap::get_ep(void) const
{
    return (_energy);
}

void ClapTrap::set_ep( unsigned int ep )
{
    _energy = ep;
    return ;
}

void ClapTrap::set_hp( unsigned int hp )
{
    _hitpoints = hp;
    return ;
}

void ClapTrap::set_ad( unsigned int ad )
{
    _attack_damage = ad;
    return ;
}