#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"


class RobotomyRequestForm : public Form
{
    private:
        std::string _target;

    public:
    /*canonical functions + <<*/
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(void);
    virtual ~RobotomyRequestForm(void);
    RobotomyRequestForm( RobotomyRequestForm const & copy);
    RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs);

    /*exra functions*/
    void execute(Bureaucrat const & executor) const;
};

#endif
