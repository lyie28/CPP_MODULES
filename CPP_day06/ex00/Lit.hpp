#ifndef LIT_HPP
# define LIT_HPP

#include <iostream>

class Lit
{
    public:
    /*canonical funcitons*/
        Lit(std::string value);
        virtual ~Lit(void);
        Lit( Lit const & copy);
        Lit & operator=( Lit const & rhs);

    /*others*/
        typedef void (Lit::*my_pointer_to_function)(void);
        bool getBool(void);
        void printer(void);

    private:
        my_pointer_to_function  _my_function[4];
        bool _validInput;
        std::string _input;
        std::string _type;
        std::string _value;

        Lit(void);
        int  get_int(std::string name);
        bool typeInt(std::string value);
        bool typeFloat(std::string value);
        bool typeDouble(std::string value);
        void float_printer(void);
        void int_printer(void);
        void double_printer(void);
        void char_printer(void);
        int char_count(std::string str, char c);
        std::string whatType(std::string value);
};
#endif
