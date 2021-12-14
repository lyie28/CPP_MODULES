#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>

class Weapon
{
    public:
        Weapon( std::string weapon_type );
	    ~Weapon( void );
        void setType(std::string    weapon_type);
        std::string const &getType(void) const;
    
   private:
        std::string _type;
};

#endif