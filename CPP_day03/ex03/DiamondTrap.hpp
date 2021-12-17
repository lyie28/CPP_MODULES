#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class DiamondTrap : public virtual FragTrap, virtual public ScavTrap
{
    public:
    /*canonical functions*/
        DiamondTrap(std::string name);
        ~DiamondTrap(void);
        DiamondTrap & operator=( DiamondTrap const & rhv);
        DiamondTrap( DiamondTrap const & copy);

    /*Diamond functions*/
        void    whoAmI();
    
    private:
        std::string _name;
        DiamondTrap(void);

};

#endif