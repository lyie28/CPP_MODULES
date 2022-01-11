#include <iostream>
#include <stdexcept>
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy_form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy_form", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & copy) : Form("Robotomy_copy", 72, 45), _target(copy._target)
{
	*this = copy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs)
{
	Form::setName(rhs.getName());
	Form::setSigned(rhs.getBool());
	Form::setsignGrade(rhs.getsignGrade());
	Form::setexecuteGrade(rhs.getexecuteGrade());
	return (*this);
}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
	static int get;
	std::cout << "**DRILLING SOUNDS**" << std::endl;
	if (get % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Target Robotomization failed" << std::endl;
	get++;
}
