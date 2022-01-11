#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
     private:
        std::string const   _name;
        unsigned int        _grade;

    public:
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return ("This is grade is too high, man");
            }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                return ("This grade is too low for me to sign");
                }
        };

        /*canonical functions + <<*/
        Bureaucrat(std::string name, unsigned int note);
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat( Bureaucrat const & copy);
        Bureaucrat & operator=( Bureaucrat const & rhs);

        /*getters*/
        std::string const   getName(void) const;
        unsigned int        getGrade(void) const;

        /*augment + decrease*/
        Bureaucrat & increase(void);
        Bureaucrat & decrease(void);
        void signForm(Form &paperwork);
};
std::ostream & operator<<( std::ostream & output, Bureaucrat const & Bob);

#endif
