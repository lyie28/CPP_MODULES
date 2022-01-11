#include "includes/Bureaucrat.hpp"

int main(void)
{
    std::cout << "Let's create a Bureaucrat and a form correctly" << std::endl;
    try
    {
        Bureaucrat Bob("Bob", 100);
        Form P5("P5", 123, 121);
        std::cout << "Let's check form is initally set to unsigned using << operator" << std::endl << P5 << std::endl;
        std::cout << "Let's get Bob to sign P5 and then print out its stats" << std::endl;
        Bob.signForm(P5);
        std::cout << P5 << std::endl;
        std::cout << "Let's now try to get Dave to sign a P5 where the grade is lower than than the required sign grade" << std::endl;
        Bureaucrat Dave("Dave", 140);
        Dave.signForm(P5);
        std::cout << "Finally lets try to create a form whose signing grade is outside of limits (1-150)" << std::endl;
        Form P6("P6", 160, 140);
        std::cout << "This line will never print out" << std::endl;

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    return (0);
}
