#include "includes/MateriaSource.hpp"
#include "includes/AMateria.hpp"

MateriaSource::MateriaSource(void) : inventory()
{
    return ;
}

MateriaSource::~MateriaSource(void)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (inventory[i])
            delete inventory[i];
        i++;
    }
    return ;
}

MateriaSource::MateriaSource(MateriaSource const &copy): inventory()
{
	if (this != &copy)
    {
        int i = 0;
        while (i < 4)
        {
            if (inventory[i])
                delete inventory[i];
            if (copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
            i++;
        }
    }
    return;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhv)
{
    if (this != &rhv)
    {
        int i = 0;
        while (i < 4)
        {
            if (inventory[i] && rhv.inventory[i])
                 delete inventory[i];
            if (rhv.inventory[i])
                inventory[i] = rhv.inventory[i]->clone();
            i++;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* to_copy)
{
    int i = 0;
    while (i < 4)
    {
        if (! inventory[i])
        {
            inventory[i] = to_copy;
            return ;
        }
        i++;
    }
    if (i == 4)
    {
        delete to_copy;
        std::cout << "!Materia inventory is full. Materia wasn't added to inventory!" << std::endl;
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i;

    i = 3;
    while (i >= 0)
    {
        if (inventory[i] && inventory[i]->getType() == type)
            return inventory[i]->clone();
        i--;
    }
    if (i == -1)
        std::cout << "!This type is not in the inventory. Could not create Materia" << std::endl;
    return 0;
}
