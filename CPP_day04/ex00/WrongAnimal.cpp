#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "An WrongAnimal is born" << std::endl;
    return ;
}
    
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal is dead. RIP WrongAnimal" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & copy)
{
    *this = copy;
    return ;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void WrongAnimal::makeSound(void) const
{
    std::cout << "*makes generic WrongAnimal noise*" << std::endl;
    return ;
}

 std::string WrongAnimal::getType(void) const
 {
     return _type;
 }
 
 void WrongAnimal::setType(std::string type)
 {
    _type = type;
    return ;
 }