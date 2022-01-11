#include "includes/Cure.hpp"
#include "includes/AMateria.hpp"
#include "includes/ICharacter.hpp"

/*canonical functions*/
Cure::Cure(void) : AMateria("cure")
{
    return ;
}

Cure::~Cure(void)
{
    return ;
}

Cure &Cure::operator=(Cure const& rhs)
{
    /*subject says not to copy type and there is no other data to copy!*/
    (void)rhs;
    return *this;
}

Cure::Cure(Cure const& rhs) : AMateria()
{
    *this = rhs;
    return ;
}

/*functions*/
void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}

Cure*    Cure::clone(void) const
{
    return new Cure();
}
