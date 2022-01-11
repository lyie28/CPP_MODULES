#include <iostream>
#include <stdexcept>
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"
#include <sstream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shruberry_form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shruberry_form", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & copy) : Form("Shrubbery_copy", 145, 137), _target(copy._target)
{
	*this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs)
{
	Form::setName(rhs.getName());
	Form::setSigned(rhs.getBool());
	Form::setsignGrade(rhs.getsignGrade());
	Form::setexecuteGrade(rhs.getexecuteGrade());
	return (*this);
}

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	std::ofstream ofs;
	std::string name = _target + "_shrubbery";
	ofs.open(name.c_str(), std::ofstream::trunc);
    if (!ofs.good())
    {
        std::cout << "ERROR: cannot create output file" << std::endl;
        return ;
    }
	else
	{
		ofs << "      /\\       " << std::endl;
		ofs << "     /\\*\\      " << std::endl;
		ofs << "    /\\O\\*\\     " << std::endl;
		ofs << "   /*/\\/\\/\\    " << std::endl;
		ofs << "  /\\O\\/\\*\\/\\   " << std::endl;
		ofs <<" /\\*\\/\\*\\/\\/\\  " << std::endl;
		ofs <<"/\\O\\/\\/*/\\/O/\\ " << std::endl;
		ofs << "      || " << std::endl;
		ofs << "      || " << std::endl;
		ofs << "      || " << std::endl;
		return;
	}
}
