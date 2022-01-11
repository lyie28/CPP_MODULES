#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"


class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
        
    public:
    /*canonical functions + <<*/
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(void);
    virtual ~PresidentialPardonForm(void);
    PresidentialPardonForm( PresidentialPardonForm const & copy);
    PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs);

    /*exra functions*/
    void execute(Bureaucrat const & executor) const;
};

#endif
