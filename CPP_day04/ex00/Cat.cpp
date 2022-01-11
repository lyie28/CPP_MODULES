#include "includes/Animal.hpp"
#include "includes/Cat.hpp"

Cat::Cat(void)
{
    this->setType("cat");
    std::cout << "A Cat is born" << std::endl;
    return ;
}
    
Cat::~Cat(void)
{
    std::cout << "Cat is dead. RIP Cat" << std::endl;
    return ;
}

Cat::Cat( Cat const & copy) : Animal()
{
    *this = copy;
    return ;
}

Cat & Cat::operator=( Cat const & rhv)
{
    _type = rhv._type;
    return (*this);
}
    
void Cat::makeSound(void) const
{
    std::cout << "*MEEOOOOWWWW*" << std::endl;
    return ;
}