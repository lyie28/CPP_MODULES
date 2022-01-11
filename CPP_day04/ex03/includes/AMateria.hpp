#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        //Canonical: constructor, destructor, copy, equals
        AMateria(std::string const & type);
        AMateria(void);
        virtual ~AMateria(); /*virtual destructor to avoid memory issues*/
        AMateria( AMateria const & copy);
        AMateria & operator=( AMateria const & rhv);

        /*extra fuctions*/
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
