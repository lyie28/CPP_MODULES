#include "includes/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
    std::cout << "An AAnimal is born" << std::endl;
    return ;
}
    
AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal is dead. RIP AAnimal" << std::endl;
    return ;
}

AAnimal::AAnimal( AAnimal const & copy)
{
    *this = copy;
    return ;
}

AAnimal & AAnimal::operator=( AAnimal const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void AAnimal::makeSound(void) const
{
    std::cout << "*makes generic AAnimal noise*" << std::endl;
    return ;
}

 std::string AAnimal::getType(void) const
 {
     return _type;
 }
 
 void AAnimal::setType(std::string type)
 {
    _type = type;
    return ;
 }