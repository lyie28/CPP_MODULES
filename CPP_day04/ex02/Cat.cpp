#include "includes/AAnimal.hpp"
#include "includes/Cat.hpp"

Cat::Cat(void)
{
    std::cout << "A Cat is born" << std::endl;
    _brain = new Brain();
    this->setType("cat");
    return ;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat is dead. RIP Cat" << std::endl;
    return ;
}

Cat::Cat( Cat const & copy) : AAnimal()
{
    _brain = new Brain;
    std::cout << "A Cat is born" << std::endl;
    *this = copy;
    return ;
}

Cat & Cat::operator=( Cat const & rhv)
{
    _type = rhv._type;
    *(this->_brain) = *(rhv._brain);
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "*MEEOOOOWWWW*" << std::endl;
    return ;
}

void Cat::set_value(int i, std::string str)
{
   _brain->set_value(i, str);
    return ;
}

void Cat::print_value(int i)
{
	std::cout << "Value at brain[" << i << "] is " << _brain->get_value(i) << std::endl;
	return ;
}

void Cat::print_addr(int i)
{
	std::cout << "Address is " <<  _brain->get_addr(i) << std::endl;
}

void Cat::print_brain_addr()
{
	std::cout << "Brain address is " <<  &_brain << std::endl;
}

