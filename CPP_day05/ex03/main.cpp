#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"

int main(void)
{

    std::cout << "Let's create an intern and have him create the following forms:" <<std::endl;
    Intern Geoff;
    Form *the_form;
    Form *decree;
    Form *herby;
    Form *paperz;
    try
    {
        std::cout << "1) Robotomy request..." <<std::endl;
        the_form = Geoff.makeForm("robotomy request", "THE FORM");
        std::cout << *the_form << std::endl;
        std::cout << "2) Presidential pardon..." <<std::endl;
        decree = Geoff.makeForm("presidential pardon", "THE DECREE");
        std::cout << *decree << std::endl;
        std::cout << "3) Shrubbery creation..." <<std::endl;
        herby = Geoff.makeForm("shrubbery creation", "HERBS GALORE");
        std::cout << *herby << std::endl;
        std::cout << "4) blah blah blah..." <<std::endl;
        paperz = Geoff.makeForm("blah blah blah", "paperz");
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl << std::endl;
    std::cout << "Let's check these forms still work!" <<std::endl;
    Bureaucrat Bob("Bob", 2);
    Bob.signForm(*the_form);
    Bob.executeForm(*the_form);
    Bob.signForm(*decree);
    Bob.executeForm(*decree);
    Bob.signForm(*herby);
    Bob.executeForm(*herby);
    delete the_form;
    delete herby;
    delete decree;
}
