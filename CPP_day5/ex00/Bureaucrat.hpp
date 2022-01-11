#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade is too high");
            }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                return ("Grade is too low");
                }
        };

    private:
        std::string const   _name;
        unsigned int        _grade;

    public:
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

};
std::ostream & operator<<( std::ostream & output, Bureaucrat const & Bob);

#endif
