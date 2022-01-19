#include "Lit.hpp"
#include <iostream>
#include <string>
#include <limits.h>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iomanip>


Lit::Lit(std::string value) : _value(value)
{
    _type = whatType(value);
    if (get_int(_type) == -1)
        _validInput = false;
    else
        _validInput = true;
    _my_function[0] = &Lit::char_printer;
    _my_function[1] = &Lit::double_printer;
    _my_function[2] = &Lit::float_printer;
    _my_function[3] = &Lit::int_printer;
}

Lit::~Lit(void) {}

Lit::Lit( Lit const & copy)
{
    *this = copy;
}

Lit & Lit::operator=( Lit const & rhs)
{
    this->_validInput = rhs._validInput;
    this->_input = rhs._input;
    this->_value = rhs._value;
    this->_type = rhs._type;
    int i = -1;
    while (++i < 4)
    {
        _my_function[i] = rhs._my_function[i];
    }
    return *this;
}

bool Lit::getBool(void)
{
    return (this->_validInput);
}

Lit::Lit(void) : _validInput(false), _type("invalid") {}

int Lit::get_int(std::string type)
{
    int i;
    i = 0;
    std::string modes[4] = {"char", "double", "float", "int"};

    while (i < 4)
    {
        if (type == modes[i])
            return i;
        i++;
    }
    return (-1);
}

void Lit::float_printer(void)
{
    float f = strtof(_value.c_str(), NULL);
    if (errno == ERANGE)
    {
        std::cout << "float value out of range" << std::endl;
        return;
    }
    if (f < -2147483648.f || f > 2147483520.f || _value == "nanf")
    {
        std::cout << "char: conversion impossible" << std::endl;
        std::cout << "int: conversion impossible" << std::endl;
    }
    else
    {

        if (f > static_cast<float>(CHAR_MAX) || f < static_cast<float>(CHAR_MIN))
            std::cout << "char: conversion impossible" << std::endl;
        else
        {
            char c = static_cast<char>(f);
            if (std::isprint(c))
                std::cout << "char: " << static_cast<char>(f) << std::endl;
            else
                std::cout << "char: non-displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    int set = 0;
    int i = -1;
    while (_value[++i])
    {
        if (_value[i] == '.')
        {
            set--;
            while (_value[++i])
                set++;
            break ;
        }
    }
    if (set < 1)
        set = 1;
    std::cout << std::fixed << std::setprecision(set);
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void Lit::int_printer(void)
{
    if (_value.length() > 11)
    {
        std::cout << "Out of range int value" << std::endl;
        return;
    }
    long x = atol(_value.c_str());
    if (x > 2147483647 || x < -2147483648 || errno == ERANGE)
    {
        std::cout << "Out of range int value" << std::endl;
        return;
    }
    if (x < CHAR_MIN || x > CHAR_MAX)
        std::cout << "char: conversion impossible" << std::endl;
    else
    {
        char c = static_cast<char>(x);
        if (std::isprint(c))
            std::cout << "char: " << static_cast<char>(x) << std::endl;
        else
            std::cout << "char: non-displayable" << std::endl;
    }
    std::cout << "int: " << x << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(x) << std::endl;
}

void Lit::double_printer(void)
{
    double f = strtod(_value.c_str(), NULL);
    if (errno == ERANGE)
    {
        std::cerr << "double out of range" << std::endl;
        return;
    }
    if (f > static_cast<double>(std::numeric_limits<char>::max()) || f < static_cast<int>(std::numeric_limits<char>::min()) || _value == "nan")
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(f);
        if (std::isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: non-displayable" << std::endl;
    }
    if (f > static_cast<double>(std::numeric_limits<int>::max()) || f < static_cast<int>(std::numeric_limits<float>::min()) || _value == "nan")
            std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    int set = 0;
    int i = -1;
    while (_value[++i])
    {
        if (_value[i] == '.')
        {
            while (_value[++i])
                set++;
            break ;
        }
    }
    if (set < 1)
        set = 1;
    std::cout << std::fixed << std::setprecision(set);
    if (f > static_cast<double>(std::numeric_limits<float>::max()) || f < static_cast<float>(std::numeric_limits<float>::min()))
        std::cout << "float: impossible" << std::endl;
    else
            std::cout << "float: " << static_cast<float>(f) << 'f' << std::endl;
    std::cout << "double: " << f << std::endl;
}
void Lit::char_printer(void)
{
    char c = _value[0];
    if (c < CHAR_MIN)
    {
        std::cout << "char out of range" << std::endl;
        return;
    }
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non-printable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

int Lit::char_count(std::string str, char c)
{
    int count = 0;
    int i = -1;
    while (str[++i])
    {
     if (str[i] == c)
            count++;
    }
    return count;
}

bool Lit::typeInt(std::string value)
{
    if (value.find_first_not_of("0123456789") == value.npos)
        return true;
    return false;
}

bool Lit::typeFloat(std::string value)
{

    if (value == "inff" || value == "nanf")
        return true;
    if (char_count(value, 'f') == 1)
    {
        int pos = value.find('f');
        if (pos != -1)
        {
            int where = value.length() -1;
            if (pos != where || char_count(value, '.' > 1))
                return false;
            value.erase(pos, 1);
            pos = value.find('.');
            if (pos != -1)
                value.erase(pos, 1);
        }
        if (value.find_first_not_of("0123456789") == value.npos)
            return true;
    }
    return false;
}

bool Lit::typeDouble(std::string value)
{
    if (value == "inf" || value == "nan")
            return true;
    if (char_count(value, '.') == 1)
    {
        int pos = value.find('.');
        value.erase(pos, 1);
        if (value.find_first_not_of("0123456789") == value.npos)
            return true;
    }
    return false;
}

std::string Lit::whatType(std::string value)
{
    if(value.empty())
        return "unknown";
    if (value.length() == 1)
    {
        if (std::isdigit(value[0]))
            return "int";
        if (std::isprint(value[0]))
            return "char";
    }
    if (value[0] == '+' || value[0] == '-')
        value.erase(0, 1);
    if (typeInt(value))
        return "int";
    if (typeFloat(value))
        return "float";
    if (typeDouble(value))
        return "double";
    return "invalid";
}

void Lit::printer(void)
{
    int i = get_int(this->_type);
    (this->*(_my_function[i]))();
}
