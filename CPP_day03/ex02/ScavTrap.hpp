#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
    public:
    /*canonical functions*/
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap( ScavTrap const & copy);
        ScavTrap & operator=( ScavTrap const & rhv);
        
    /*functions from subject*/
        void attack(std::string const & target);
        void guardGate();
    
    private:
        ScavTrap(void); /*canonical void constructor but not needed for this exo*/

};

#endif