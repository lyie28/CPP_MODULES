#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main()
{
    Animal *pack[4];
    int i;

    i = 0;
    while ( i < 4)
    {
        if (i == 0)
            std::cout << "Narrator: Creating 2 cats" << std::endl;
        if (i == 2)
                std::cout << "Narrator: Creating 2 dogs" << std::endl;
        if (i < 2)
            pack[i] = new Cat;
        else
            pack[i] = new Dog;
        i++;
    }
    std::cout << "---------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Delete all animals" << std::endl;
    i = -1;
    while (++i < 4)
    {
        delete pack[i];
        std::cout << std::endl;
    }
    std::cout << "---------------------------------" << std::endl << std::endl;
    /*Deep copies test: should have diff addresses*/
    std::cout << "Creating cat 1 and cat 2 for deep copy tests" << std::endl;
    Cat real;
    Cat temp;
    i = 0;
    while (i < 10)
    {
        real.set_value(i, "David Beckham");
        temp.set_value(i, "Eric Cantona");
        i++;
    }
    std::cout << std::endl << "Narrator: Checking values in cat1 and cat2's brains pre assignation" << std::endl;
    std::cout << "Cat 1: ";
	real.print_value(0);
    std::cout << "Cat 2: ";
	temp.print_value(0);
    std::cout << std::endl << "Narrator: Cat2 = cat1" << std::endl;
    temp = real;
    std::cout << "Narrator: Checking values are now the same..." << std::endl;
    std::cout << "Cat 1 is: ";
	real.print_value(0);
    std::cout << "Cat 2 is: ";
	temp.print_value(0);
    std::cout << "Narrator: Checking address of brains is still different!" << std::endl;
    real.print_brain_addr();
    temp.print_brain_addr();
    std::cout << "---------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Checking copy also has separate brains with same content:" << std::endl;
    Cat copy(temp);
    copy.print_brain_addr();
    temp.print_brain_addr();
    std::cout << "Cat 1: ";
	real.print_value(3);
    std::cout << "Cat 2: ";
	temp.print_value(3);
    std::cout << "---------------------------------" << std::endl << std::endl;
    return 0;
}
