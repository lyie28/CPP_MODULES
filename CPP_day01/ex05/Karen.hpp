#ifndef KAREN_CLASS_HPP
# define KAREN_CLASS_HPP

#include <iostream>
#include <string>

class Karen
{
    public:
        /*need to defind a pointer to function here */
        typedef void (Karen::*my_pointer_to_function)();
        Karen(void);
        ~Karen(void);
        void complain( std::string level );

    private:
        int get_int(std::string level);
        my_pointer_to_function  _my_function[4];
        void debug( void ) ;
        void info( void ) ;
        void warning( void ) ;
        void error( void ) ;
};

#endif
