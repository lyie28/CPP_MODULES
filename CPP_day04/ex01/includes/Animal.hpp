#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>

class Animal
{
    public:
    /*canonical functions*/
        Animal(void);
        virtual ~Animal(void);
        Animal( Animal const & copy);
        Animal & operator=( Animal const & rhv);
    
    /*functions*/
    virtual void makeSound(void) const;
    
    /*accessors*/
    std::string getType(void) const;
    void setType(std::string);

    protected:
        std::string _type;   
};

#endif