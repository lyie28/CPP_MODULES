#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    std::cout << "Let's create an animal:" << std::endl;
    const Animal* general = new Animal();
    std::cout << "Let's create a dog:" << std::endl;
    const Animal* puppy = new Dog();
    std::cout << "Let's create a cat:" << std::endl;
    const Animal* kitty = new Cat();
    
    
    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's check typing: (animal, dog, cat expected):" << std::endl;
    std::cout << general->getType() << " " << std::endl;
    std::cout << puppy->getType() << " " << std::endl;
    std::cout << kitty->getType() << " " << std::endl;
    std::cout << "Let's check sounds: (general, woof, meow expected):" << std::endl;
    general->makeSound();
    puppy->makeSound();
    kitty->makeSound();
    
    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's check destructors:" << std::endl;
    std::cout << "Animal:" << std::endl;
    delete general;
    std::cout << "Dog:" << std::endl;
    delete puppy;
    std::cout << "Cat:" << std::endl;
    delete kitty;

    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's create a WrongAnimal of type WrongCat" << std::endl;
    WrongAnimal *fail = new WrongCat();
    std::cout << "Without virtual keyword before function, compiler understands cat to be animal" << std::endl;
    fail->makeSound();
    std::cout << "Let's check destructors:" << std::endl;
    delete fail;
    
    return 0;
}