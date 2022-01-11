#include "includes/Animal.hpp"

Animal::Animal(void) : _type("animal")
{
    std::cout << "An animal is born" << std::endl;
    return ;
}
    
Animal::~Animal(void)
{
    std::cout << "Animal is dead. RIP animal" << std::endl;
    return ;
}

Animal::Animal( Animal const & copy)
{
    *this = copy;
    return ;
}

Animal & Animal::operator=( Animal const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void Animal::makeSound(void) const
{
    std::cout << "*makes generic animal noise*" << std::endl;
    return ;
}

 std::string Animal::getType(void) const
 {
     return _type;
 }
 
 void Animal::setType(std::string type)
 {
    _type = type;
    return ;
 }