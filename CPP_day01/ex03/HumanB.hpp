#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include <string>

class HumanB
{
    public:
        HumanB( std::string name );
	    ~HumanB( void );
        void    attack(void) const;
        /*need to pass string as REF so if weapon is then changed, it will be updated here*/
        void    setWeapon(Weapon    &weapon_type);

    private:
        std::string _name;
        /*need to use pointer as could be NULL*/
        Weapon    * _weapon;
};

#endif