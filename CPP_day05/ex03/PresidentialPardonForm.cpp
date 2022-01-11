#include <iostream>
#include <stdexcept>
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Pardon_form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Pardon_form", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & copy) : Form("Pardon_copy", 25, 5), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs)
{
	Form::setName(rhs.getName());
	Form::setSigned(rhs.getBool());
	Form::setsignGrade(rhs.getsignGrade());
	Form::setexecuteGrade(rhs.getexecuteGrade());
	return (*this);
}

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (Form::getBool() == 1)
	{
		throw Form::NotSignedException();
		return ;
	}
	if (executor.getGrade() > getexecuteGrade())
	{
		throw Form::GradeTooLowException();
		return ;
	}
	std::cout << _target << " has been pardonned by Zafod Beeblebrox." << std::endl;
}
