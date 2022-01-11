#include "includes/Animal.hpp"
#include "includes/Dog.hpp"

Dog::Dog(void)
{
    this->setType("dog");
    std::cout << "A Dog is born" << std::endl;
    return ;
}
    
Dog::~Dog(void)
{
    std::cout << "Dog is dead. RIP Dog" << std::endl;
    return ;
}

Dog::Dog( Dog const & copy) : Animal()
{
    *this = copy;
    return ;
}

Dog & Dog::operator=( Dog const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void Dog::makeSound(void) const
{
    std::cout << "*WOOOOOOF WOOOOF*" << std::endl;
    return ;
}
