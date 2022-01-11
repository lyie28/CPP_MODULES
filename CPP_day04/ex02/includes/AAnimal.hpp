#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

#include <iostream>

class AAnimal
{
    public:
    /*canonical functions*/
        AAnimal(void);
        virtual ~AAnimal(void);
        AAnimal( AAnimal const & copy);
        AAnimal & operator=( AAnimal const & rhv);
    
    /*functions*/
    virtual void makeSound(void) const = 0;
    
    /*accessors*/
    std::string getType(void) const;
    void setType(std::string);

    protected:
        std::string _type;   
};

#endif