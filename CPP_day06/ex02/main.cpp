/*cannot do horizontal casts so will know which is correct*/
#include <stdexcept>
#include "Base.hpp"
#include <iostream>
#include <cstdlib>

/*Can convert from child to parent and from A TO A, B to B etc...
But A->B etc... not possible. And parent to child also not possible*/
void identify(Base* p)
{
    A *test1 = dynamic_cast<A*>(p);
    if (test1 != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
    B *test2 = dynamic_cast<B*>(p);
    if (test2 != NULL)
    {
        std::cout << "B" << std::endl;
        return;
    }
    C *test3 = dynamic_cast<C*>(p);
    if (test3 != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Not a valid type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        Base &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {} /* catches any exception*/
    try
    {
        Base &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    try
    {
        Base &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
    std::cout << "Not a valid type" << std::endl;
}

Base * generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            std::cout << "returning type A" << std::endl;
            return new A;
        case 1:
            std::cout << "returning type B" << std::endl;
            return new B;
        case 2:
            std::cout << "returning type C" << std::endl;
            return new C;
        break;
    }
    return NULL;
}


int main(void)
{
    std::cout << "generating random number" << std::endl;
    Base *random = generate();
    std::cout << "identifying with pointer function" << std::endl;
    identify(random);
    std::cout << "identifying with & function" << std::endl;
    identify (*random);
    delete random;
    /*Progam doesn't crash even with null pointers*/
    std::cout << std::endl << "testing with null pointers" << std::endl;
    Base *empty = NULL;
    identify(empty);
    identify(NULL);

    return (0);
}
