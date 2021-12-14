#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>

class HumanA
{
    public:
        HumanA( std::string name, Weapon &weapon_type);
	    ~HumanA( void );
        void    attack(void) const;

    private:
        std::string _name;
        /*can use REF directly as can't be NULL*/
        Weapon&      _weapon;
};

#endif