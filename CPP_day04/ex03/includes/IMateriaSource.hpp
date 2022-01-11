#ifndef IMATERIASOURCE_CLASS_HPP
# define IMATERIASOURCE_CLASS_HPP

#include <iostream>
#include "AMateria.hpp"
/*copy from subject: no changed required*/
/*not canonical because cannot be initialised itself*/

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif