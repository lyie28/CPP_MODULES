#include "includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int note) : _name(name)
{
    if (note < 1)
        throw Bureaucrat::GradeTooHighException();
    if (note > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = note;
}

Bureaucrat::Bureaucrat(void) {}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat( Bureaucrat const & copy) : _name(copy._name)
{
    *this = copy;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs)
{
    const_cast<std::string&> (_name)= rhs._name;
    this->_grade = rhs.getGrade();
    return (*this);
}

/*getters*/
std::string const   Bureaucrat::getName(void) const
{
    return (_name);
}
unsigned int        Bureaucrat::getGrade(void) const
{
    return (_grade);
}

std::ostream & operator<<( std::ostream & output, Bureaucrat const & Bob)
{
    output << Bob.getName() << ", bureaucreat grade " << Bob.getGrade() << std::endl;
    return output;
}

Bureaucrat & Bureaucrat::increase(void)
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
    return (*this);
}

Bureaucrat & Bureaucrat::decrease(void)
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
    return (*this);
}

void Bureaucrat::signForm(Form &paperwork)
{
    try
    {
        paperwork.beSigned(*this);
        std::cout << getName() << " signs form" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << getName() << " cannot sign because... TROLL IN THE DUNGEON!" << std::endl;
    }
}
