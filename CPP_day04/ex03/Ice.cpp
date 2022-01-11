#include "includes/Ice.hpp"
#include "includes/AMateria.hpp"
#include "includes/ICharacter.hpp"

/*canonical functions*/
Ice::Ice(void) : AMateria("ice")
{
    return ;
}

Ice::~Ice(void)
{
    return ;
}

Ice &Ice::operator=(Ice const& rhs)
{
    /*asked not to copy materia types in subject*/
    (void)rhs;
    return *this;
}

Ice::Ice(Ice const& rhs) : AMateria()
{
    *this = rhs;
    return ;
}

/*functions*/
void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}

Ice*    Ice::clone(void) const
{
    return new Ice();
}
