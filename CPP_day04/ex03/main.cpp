#include "includes/AMateria.hpp"
#include "includes/Cure.hpp"
#include "includes/Ice.hpp"
#include "includes/MateriaSource.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/ICharacter.hpp"
#include "includes/Character.hpp"


int main()
{
    /*WE CANNOT CREATE AN IMateriaSource or an AMateria directly: uncomment to check out
    IMateriaSource * example = new IMateriaSource;
    AMateria * temp = new AMateria;
    */
    std::cout << "Narrator: Let's create a source material interface" << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << "Narrator: Let's create an Ice and stock it in our inventory" << std::endl;
    src->learnMateria(new Ice());
    std::cout << "Narrator: Let's repeat with a cure and stock it in our inventory" << std::endl;
    src->learnMateria(new Cure());

    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's check what happens if we try to add more than 4 materias into inventory " << std::endl;
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());


    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's create a new character and AMateria" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << "Narrator: Let's create a new materia of type ice and equip our character with it" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << "Narrator: Let's create a new materia of type cure and equip our character with it" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);


    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's try to create a new materia of incorrect type" << std::endl;
    tmp = src->createMateria("wrong");


    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's try to overflow our character's inventory of spells" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);


    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Hmm... Didn't work. Let's try unequipping and then try again" << std::endl;
    me->unequip(2);
    me->equip(tmp);
    std::cout << "Narrator: Great no errors this time!" << std::endl;

    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's check character uses deep copies" << std::endl;
    std::cout << "Narrator: Creating two characters" << std::endl;
    Character *assign = new Character("assign");
    Character *assign_test = new Character("Copy");
    std::cout << "Narrator: Equiping character 1 with ice and assigning char1 to char2" << std::endl;
    assign->equip(src->createMateria("ice"));
    assign->equip(src->createMateria("ice"));
    assign->equip(src->createMateria("ice"));
    assign->equip(src->createMateria("ice"));
    *assign_test = *assign;
    std::cout << "Narrator: Checking spells have a different address..." << std::endl;
    assign->print_address_info(3);
    assign_test->print_address_info(3);
    std::cout << "Narrator: Creating copy of char2" << std::endl;
    Character *copy2 = new Character(*assign_test);
    std::cout << "Narrator: Checking copy's spell has a different address..." << std::endl;
    copy2->print_address_info(3);
    delete assign_test;
    delete assign;
    delete copy2;

    std::cout << "-----------------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Let's create a new character and use our spells against him" << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "Narrator: Let's try to access an inventory slot which is empty" << std::endl;
    me->unequip(3);
    me->use(3, *bob);
    std::cout << "Narrator: ...or one out of range..." << std::endl;
    me->use(4, *bob);

    std::cout << "-----------------------------------------" << std::endl << std::endl;
    delete bob;
    delete me;
    delete src;
    return 0;
}
