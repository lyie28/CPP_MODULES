#include <iostream>
#include <stdexcept>
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

Form::Form(std::string name, const unsigned int g1, const unsigned int g2) : _name(name), _signGrade(g1), _executeGrade(g2), _signed(0)
{
	 if (g1 < 1 || g2 < 1)
        throw Form::GradeTooHighException();
    if (g1 > 150 || g2 > 150)
        throw Form::GradeTooLowException();
}

Form::Form(void) : _name("no name"), _signGrade(0), _executeGrade(0), _signed(0)
{}

Form::~Form(void) {}

Form::Form( Form const & copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _signed()
{
	*this = copy;
}

Form & Form::operator=( Form const & rhs)
{
	const_cast<std::string&> (_name)= rhs._name;
	const_cast<unsigned int&> (_signGrade)= rhs._signGrade;
	const_cast<unsigned int&> (_executeGrade)= rhs._executeGrade;
	this->_signed = rhs._signed;
	return (*this);
}

/*exra functions*/
void Form::beSigned(Bureaucrat dude)
{
	if (dude.getGrade() > getsignGrade())
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}

std::ostream & operator<<( std::ostream & output, Form const & Paperwork)
{
	std::cout << "State of form:" << std::endl << "Form name: " << Paperwork.getName() << std::endl;
	std::cout << "Form's signing grade: " << Paperwork.getsignGrade() << std::endl;
	std::cout << "Form's execute grade: " << Paperwork.getexecuteGrade() << std::endl;
	std::cout << "Form's current signed status: ";
	if (Paperwork.getBool() == 1)
		output << "Form is signed" << std::endl;
	else
		output << "Form is not signed. Soz man." << std::endl;
	return (output);
}

/*getters*/
std::string const	Form::getName(void) const
{
    return (_name);
}

unsigned int	Form::getsignGrade(void) const
{
    return (_signGrade);
}

bool	Form::getBool(void) const
{
    return (_signed);
}

unsigned int	Form::getexecuteGrade(void) const
{
    return (_executeGrade);
}
