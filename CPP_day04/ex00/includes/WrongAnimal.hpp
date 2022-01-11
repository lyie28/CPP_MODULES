#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <iostream>

class WrongAnimal
{
    public:
    /*canonical functions*/
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal( WrongAnimal const & copy);
        WrongAnimal & operator=( WrongAnimal const & rhv);
    
    /*functions*/
        void makeSound(void) const;
    
    /*accessors*/
        std::string getType(void) const;
        void setType(std::string);

    protected:
        std::string _type;   
};

#endif