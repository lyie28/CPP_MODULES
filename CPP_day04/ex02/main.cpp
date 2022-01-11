#include "includes/AAnimal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main()
{
    /*We cannot instanciate an animal because it is abstract*/
    //AAnimal hello;

    std::cout << "Let's create a dog:" << std::endl;
    const Dog* puppy = new Dog();
    std::cout << "Let's create a cat:" << std::endl;
    Cat* kitty = new Cat();

    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's check sounds: (woof then meow expected):" << std::endl;
    puppy->makeSound();
    kitty->makeSound();

    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's check destructors:" << std::endl;
    std::cout << "Dog:" << std::endl;
    delete puppy;
    std::cout << "Cat:" << std::endl;
    delete kitty;

     std::cout << "---------------------------------" << std::endl << std::endl;
    /*Deep copies test: should have diff addresses*/
    std::cout << "Creating dog 1 and dog 2 for deep copy tests" << std::endl;
    Dog real;
    Dog temp;
    int i = 0;
    while (i < 10)
    {
        real.set_value(i, "David Beckham");
        temp.set_value(i, "Eric Cantona");
        i++;
    }
    std::cout << std::endl << "Narrator: Checking values in Dog 1 and Dog 2's brains pre assignation" << std::endl;
    std::cout << "dog 1: ";
	real.print_value(0);
    std::cout << "dog 2: ";
	temp.print_value(0);
    std::cout << std::endl << "Narrator: Dog 2 = Dog 1" << std::endl;
    temp = real;
    std::cout << "Narrator: Checking values are now the same..." << std::endl;
    std::cout << "Dog 1 is: ";
	real.print_value(0);
    std::cout << "Dog 2 is: ";
	temp.print_value(0);
    std::cout << "Narrator: Checking address of brains is still different!" << std::endl;
    real.print_brain_addr();
    temp.print_brain_addr();
    std::cout << "---------------------------------" << std::endl << std::endl;
    std::cout << "Narrator: Checking copy also has separate brains with same content:" << std::endl;
    Dog copy(temp);
    copy.print_brain_addr();
    temp.print_brain_addr();
    std::cout << "dog 1: ";
	real.print_value(3);
    std::cout << "dog 2: ";
	temp.print_value(3);
    std::cout << "---------------------------------" << std::endl << std::endl;
    return 0;

    return 0;
}
