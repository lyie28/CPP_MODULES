#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        std::string const   _name;
		const unsigned int  _signGrade;
        const unsigned int  _executeGrade;
		bool				_signed;

    public:
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return ("Form: This grade is too high");
            }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                return ("Form: This grade is too low");
                }
        };

        class NotSignedException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return ("Form: This form has not been signed");
            }
        };
        /*canonical functions + <<*/
        Form(std::string name, unsigned int g1, unsigned int g2);
        Form(void);
        virtual ~Form(void);
        Form( Form const & copy);
        Form & operator=( Form const & rhs);

	    /*getters + setters*/
        std::string const   getName(void) const;
	    unsigned int        getsignGrade(void) const;
        unsigned int        getexecuteGrade(void) const;
        bool        		getBool(void) const;

        void		        setSigned(bool x);
        void		        setName(std::string str);
        void		        setsignGrade(const unsigned int x);
        void		        setexecuteGrade(const unsigned int x);

        /*exra functions*/
	    void beSigned(Bureaucrat dude);
        virtual void execute(Bureaucrat const & executor) const = 0;

};
std::ostream & operator<<( std::ostream & output, Form const & Paperwork);

#endif
