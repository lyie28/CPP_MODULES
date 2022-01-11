#ifndef WrongCat_CLASS_HPP
# define WrongCat_CLASS_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    /*canonical functions*/
        WrongCat(void);
        virtual ~WrongCat(void);
        WrongCat( WrongCat const & copy);
        WrongCat & operator=( WrongCat const & rhv);

    /*function*/
    void makeSound(void) const;
};

#endif
