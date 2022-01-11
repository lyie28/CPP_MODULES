#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : virtual public AMateria
{
    public:
    /*canonical functions*/
        Cure(void);
        ~Cure(void);
        Cure &operator=(Cure const& rhs);
        Cure(Cure const& rhs);

    /*other functions*/
        void use(ICharacter& target);
        Cure* clone(void) const;
};

#endif
