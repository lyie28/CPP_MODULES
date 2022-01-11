#include "includes/Intern.hpp"
#include "includes/Form.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"



Intern::Intern(void)
{
    _my_function[0] = &Intern::makePresident;
    _my_function[1] = &Intern::makeShrubbery;
    _my_function[2] = &Intern::makeRobotomy;
}

Intern::~Intern(void) {}

Intern::Intern( Intern const & copy)
{
    *this = copy;
}

Intern & Intern::operator=( Intern const & rhs)
{
    this->_my_function[0] = rhs._my_function[0];
    this->_my_function[1] = rhs._my_function[1];
    this->_my_function[2] = rhs._my_function[2];
    return (*this);
}

int Intern::get_int( std::string mode)
{
    int i;
    i = 0;
    std::string modes[4] = {"presidential pardon", "shrubbery creation", "robotomy request"};

    while (i < 3)
    {
        if (mode == modes[i])
            return i;
        i++;
    }
    return (-1);
}

Form* Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form* Intern::makePresident(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form* Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string form_name, std::string target)
{
    Form *form;
    int i = get_int(form_name);
    if (i != -1)
    {
        form = (this->*(_my_function[i]))(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
    }
    else
        throw formException();
    return form;
}
