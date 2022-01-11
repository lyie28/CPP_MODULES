#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Brain.hpp"

Dog::Dog(void)
{
    std::cout << "A Dog is born" << std::endl;
    _brain = new Brain();
    this->setType("dog");
    return ;
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog is dead. RIP Dog" << std::endl;
    return ;
}

Dog::Dog( Dog const & copy) : Animal()
{
    std::cout << "A Dog is born" << std::endl;
    _brain = new Brain;
    *this = copy;
    return ;
}

Dog & Dog::operator=( Dog const & rhv)
{
   this->_type = rhv._type;
   *(this->_brain) = *(rhv._brain);
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "*WOOOOOOF WOOOOF*" << std::endl;
    return ;
}

void Dog::print_brain_addr()
{
    std::cout << "brain is at... " << _brain << std::endl;
}

void Dog::set_value(int i, std::string str)
{
   _brain->set_value(i, str);
    return ;
}

void Dog::print_value(int i)
{
	std::cout << "Value at brain[" << i << "] is " << _brain->get_value(i) << std::endl;
	return ;
}
