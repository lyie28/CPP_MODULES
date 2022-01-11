#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
    public:
    /*canonical functions*/
        Cat(void);
        virtual ~Cat(void);
        Cat( Cat const & copy);
        Cat & operator=( Cat const & rhv);

    /*function*/
    void makeSound(void) const;
    void set_value(int i, std::string str);
    void print_value(int i);
    void print_addr(int i);
    void print_brain_addr();

    private:
	Brain *_brain;
};

#endif
