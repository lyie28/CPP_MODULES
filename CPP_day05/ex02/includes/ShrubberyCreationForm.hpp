#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"


class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;

    public:
    /*canonical functions + <<*/
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(void);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm( ShrubberyCreationForm const & copy);
    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs);

    /*exra functions*/
    void execute(Bureaucrat const & executor) const;
};

#endif
