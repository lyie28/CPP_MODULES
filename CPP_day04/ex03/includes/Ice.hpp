#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria
{
    public:
    /*canonical functions*/
        Ice(void);
        ~Ice(void);
        Ice &operator=(Ice const& rhs);
        Ice(Ice const& rhs);

    /*functions from abstract AMateria class*/
        void use(ICharacter& target);
        Ice* clone(void) const;
};

#endif
