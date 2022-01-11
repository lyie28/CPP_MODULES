#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include <iostream>
#include "Animal.hpp"

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

    protected:
        std::string _type;
};

#endif
