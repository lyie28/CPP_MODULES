#include "includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
    return ;
}

AMateria::AMateria(void) : _type("unknown")
{
    return ;
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria( AMateria const & copy)
{
    *this = copy;
    return ;
}

AMateria & AMateria::operator=( AMateria const & rhv)
{
    /*subject says don't copy type... so there is nothing to copy?? But need this to be canonical... MAKES NO SENSE
    this->_type = rhv._type;*/
    (void)rhv;
    return (*this);
}

/*extra fuctions*/
std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter & target)
{
    std::cout << "Abstract Materia use called of type " << target.getName() << std::endl;
    return ;
}

