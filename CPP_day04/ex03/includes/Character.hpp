#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    protected:
        std::string _name;
        AMateria* _inventory[4];

    public:
        /*canonical functions*/
        Character(std::string name);
        Character(void);
        Character( Character const & copy);
        ~Character(void);
        Character & operator=(Character const & rhv);


        /*extra functions*/
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        /*function for tests*/
        void print_address_info(int idx);
};

#endif
