#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Intern
{
    public:
    /*canonical functions + <<*/
    Intern(void);
    ~Intern(void);
    Intern( Intern const & copy);
    Intern & operator=( Intern const & rhs);
    typedef Form* (Intern::*my_pointer_to_function)(std::string target);

    Form*   makeForm(std::string name, std::string target);
    int     get_int(std::string name);
    Form* makeRobotomy(std::string target);
    Form* makePresident(std::string target);
    Form* makeShrubbery(std::string target);

    class formException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Excuse me, this is not a real form");
        }
    };

    private:
        my_pointer_to_function  _my_function[3];
};
#endif
