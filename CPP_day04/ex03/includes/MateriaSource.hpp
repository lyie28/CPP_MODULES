#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria *inventory[4];
    public:
        /*canonical functions*/
        MateriaSource(void);
        ~MateriaSource(void);
        MateriaSource &operator=(MateriaSource const& rhs);
        MateriaSource(MateriaSource const& rhs);        

        /*funtions from IMateria... Cannot compile without them*/
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};
#endif
