#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <iostream>
#include "Animal.hpp"

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
};

#endif
