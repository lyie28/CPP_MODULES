#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "Let's create a Bureaucrat correctly" << std::endl;
    try
    {
        Bureaucrat Bob("Bob", 150);
        std::cout << "Let's test << overload operator" << std::endl;
        std::cout << Bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's test increase grade function (remember 150 is low, 1 is high)" << std::endl;
    try
    {
        Bureaucrat Bob("Bob", 150);
        Bob.increase();
        std::cout << Bob << std::endl;
        std::cout << "Let's test decrease function" << std::endl;
        Bob.decrease();
        std::cout << Bob << std::endl;
        std::cout << "Let's decrease too much" << std::endl;
        Bob.decrease();
        std::cout << "We will never see this message" << std::endl;
        std::cout << Bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a Bureaucrat with a grade below 1" << std::endl;
    try
    {
        Bureaucrat Fail("Fail", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a Bureaucrat with a grade above 150" << std::endl;
    try
    {
        Bureaucrat Loser("Loser", 151);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    return (0);
}
