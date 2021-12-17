#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>

class ClapTrap
{
    public:
    /*canonical functions*/
        ClapTrap(std::string name);
        ClapTrap( ClapTrap const & copy);
        virtual ~ClapTrap(void); /*need virtual because deleting a pointer of base class type that has a non-virtual destructor results in undefined behaviour*/
        ClapTrap & operator=( ClapTrap const & rhv);
        
    /*functions from subject*/
        virtual void attack(std::string const & target); /*need virtual for case of ClapTrap * = ScavTrap*/
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    /*getters and setters*/
        void set_name( std::string name);
        void set_ep( unsigned int ep );
        void set_hp( unsigned int hp );
        void set_ad( unsigned int ad );
        std::string get_name(void) const;
        unsigned int get_ad(void) const;
        unsigned int get_hp(void) const;
        unsigned int get_ep(void) const;
    
    protected:
        ClapTrap(void); //incase deemed necessary for canonical form but actual not meant to be used here so put in private
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _attack_damage;
        unsigned int _energy;
};

#endif