#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen(void)
{
    _my_function[0] = &Karen::debug;
    _my_function[1] = &Karen::info;
    _my_function[2] = &Karen::warning;
    _my_function[3] = &Karen::error;
    return ;
}
    
Karen::~Karen(void)
{
    return ;
}

int Karen::get_int( std::string mode)
{
    int i;
    i = 0;
    std::string modes[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4)
    {
        if (mode == modes[i])
            return i;
        i++;
    }
    return (-1);
}

void Karen::complain( std::string level )
{
    int index;

    index = 0;
    index = get_int(level);
    if (index != -1)
        (this->*(_my_function[index]))();
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
}

void Karen::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I just love it!" << std::endl;
    return ;
}

void Karen::info( void )
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon cost more money." << std::endl << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    return ;
}

void Karen::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl;
    return ;
}

void Karen::error( void )
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl;
    return ;
}