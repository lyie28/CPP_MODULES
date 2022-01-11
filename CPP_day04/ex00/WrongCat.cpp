#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->setType("WrongCat");
    std::cout << "A WrongCat is born" << std::endl;
    return ;
}
    
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat is dead. RIP WrongCat" << std::endl;
    return ;
}

WrongCat::WrongCat( WrongCat const & copy) : WrongAnimal()
{
    *this = copy;
    return ;
}

WrongCat & WrongCat::operator=( WrongCat const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void WrongCat::makeSound(void) const
{
    std::cout << "*MEEOOOOWWWW*" << std::endl;
    return ;
}