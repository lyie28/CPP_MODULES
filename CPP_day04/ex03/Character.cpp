#include "includes/Character.hpp"

Character::Character(std::string name) : _name(name), _inventory()
{
    return ;
}

Character::Character(void) : _name("unkown"), _inventory()
{
    return;
}

Character::Character( Character const & copy) : _inventory()
{
    if (this != &copy)
    {
        this->_name = copy.getName();
        int i = 0;
        while (i < 4)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            i++;
        }
    }
    return;
}

Character::~Character(void)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (_inventory[i])
            delete _inventory[i];
        i++;
    }
    return ;
}

/*extra functions*/
std::string const & Character::getName() const
{
    return this->_name;
}

Character &Character::operator=(Character const & rhv)
{
    if (this != &rhv)
    {
        this->_name = rhv.getName();
        int i = 0;
        while (i < 4)
        {
            if (_inventory[i] && rhv._inventory[i])
               delete _inventory[i];
            if (rhv._inventory[i])
                _inventory[i] = rhv._inventory[i]->clone();
            i++;
        }
    }
    return (*this);
}

void Character::equip(AMateria* m)
{
    int i;
    i = 0;
    while (i < 4)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
        i++;
    }
    if (i == 4)
        std::cout << "! Inventory if full. You must unequip to add this spell to inventory" << std::endl;
    return ;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        _inventory[idx] = 0;
    else
        std::cout << "! There is no spell in this inventry slot. Please try again!" << std::endl;
    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (_inventory[idx])
            _inventory[idx]->use(target);
        else
            std::cout << "! There is no spell in this inventory slot!" << std::endl;
    }
    else
        std::cout << "! This is not a valid slot in your inventory. Please select a slot between 0 and 4!" << std::endl;
    return ;
}

void Character::print_address_info(int idx)
{
    if (idx >= 0 && idx <= 3 && _inventory[idx])
        std::cout << "address is " << &(_inventory[idx]) << " value is: " << _inventory[idx]->getType() << std::endl;
    return;
}

