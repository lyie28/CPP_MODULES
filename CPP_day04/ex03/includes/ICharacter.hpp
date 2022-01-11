#ifndef ICHARACTER_CLASS_HPP
# define ICHARACTER_CLASS_HPP
#include <iostream>
#include "AMateria.hpp"

/*interface, can't do anything itself, no attributes*/
/*copy from subject: no changed required*/
/*not canonical because cannot be initialised itself*/
class AMateria;

class ICharacter
{
    public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif
