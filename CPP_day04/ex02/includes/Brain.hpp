#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

#include <iostream>

class Brain
{
    public:
    /*canonical functions*/
        Brain(void);
        ~Brain(void);
        Brain( Brain const & copy);
        Brain & operator=( Brain const & rhv);
        void set_value(int i, std::string str);
        std::string get_value(int i);
        std::string get_values( Brain const & rhv, int i);
        std::string *get_addr(int i);

    protected:
        std::string _ideas[100];   
};

#endif