#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie
{
    public:
        Zombie( void );
	    ~Zombie( void );
        void    announce(void) const;
        void    set_name( std:: string name );
    
    private:
        std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif