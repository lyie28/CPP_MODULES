#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
    public:
    /*canonical functions*/
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap & operator=( FragTrap const & rhv);
        FragTrap( FragTrap const & copy);
        
    /*functions from subject*/
        void highFivesGuys(void);

    protected:
        FragTrap(void);
};

#endif