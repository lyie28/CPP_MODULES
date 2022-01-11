#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    public:
    /*canonical functions*/
        Dog(void);
        virtual ~Dog(void);
        Dog( Dog const & copy);
        Dog & operator=( Dog const & rhv);

    /*functions*/
        void makeSound(void) const;
        void print_brain_addr();
        void set_value(int i, std::string str);
        void print_value(int i);



    private:
        Brain *_brain;

};

#endif
