#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "Let's check values of three new forms match with subject" << std::endl;
    std::cout << "Shrubbery form: sign 145, exec 137" << std::endl;
    ShrubberyCreationForm test1;
    std::cout << test1;
    std::cout << "Robotomy form: sign 72, exec 45" << std::endl;
    RobotomyRequestForm test2;
    std::cout << test2;
    std::cout << "Pardon form: sign 25, exec 5" << std::endl;
    PresidentialPardonForm test3;
    std::cout << test3;
    std::cout << "----------------------------------" << std::endl << std::endl;

    {
    std::cout << "Let's create a Shrubbery Form and ask Bureacrat Bob to execute it" <<std::endl;
    Bureaucrat Bob("Bob", 100);
    ShrubberyCreationForm P5("P5");
    Bob.signForm(P5);
    Bob.executeForm(P5);
    std::cout << "You now have a shrubbery file in your directory!" <<std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a Shrubbery Form and ask Bureacrat Brenda with a too low grade to sign it" <<std::endl;
    Bureaucrat Brenda("Brenda", 146);
    Brenda.signForm(P5);
    Brenda.executeForm(P5);
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a RobotomyRequest Form and ask Bureacrat Bob to execute it 4 times (will work 50% of time)" << std::endl;
    {
    Bureaucrat Bob("Bob", 2);
    RobotomyRequestForm P6("P5");
    Bob.signForm(P6);
    Bob.executeForm(P6);
    Bob.executeForm(P6);
    Bob.executeForm(P6);
    Bob.executeForm(P6);
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a Robotomy Form and try to execute it without signing it" <<std::endl;
    Bureaucrat Brenda("Brenda", 4);
    RobotomyRequestForm P5("P5");
    Brenda.executeForm(P5);
    }
    std::cout << "----------------------------------" << std::endl << std::endl;
    {
    std::cout << "Let's create a Presidential Pardon Form and ask Bureacrat Bob to execute it" <<std::endl;
    Bureaucrat Bob("Bob", 2);
    PresidentialPardonForm P5("P5");
    Bob.signForm(P5);
    Bob.executeForm(P5);
    std::cout << "----------------------------------" << std::endl << std::endl;
    std::cout << "Let's create a Presidential Pardon Form and ask Bureacrat Brenda with a too low grade to execute it but OK to sign" <<std::endl;
    Bureaucrat Brenda("Brenda", 10);
    Brenda.signForm(P5);
    Brenda.executeForm(P5);
    }
    return (0);
}
