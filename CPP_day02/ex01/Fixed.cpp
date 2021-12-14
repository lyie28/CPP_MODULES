#include "Fixed.hpp"
#include <cmath>

/*formula to move binary point 8 step to right is number * (2 ^ 8)*/

Fixed::Fixed(void) : fp_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int ivalue)
{
    int power;
    std::cout << "Int constructor called" << std::endl;
    power = my_powers(2, fract_bits);
    fp_value = (ivalue * power);
    return ;
}

Fixed::Fixed(const float fvalue)
{
    float power;
    power = my_powers(2, fract_bits);
    std::cout << "Float constructor called" << std::endl;
    fp_value = (roundf(fvalue * power));
    return ;
}

Fixed::Fixed( Fixed const & copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;

    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=( Fixed const & right_hand_value)
{
    std::cout << "Assignation operator called" << std::endl;
    fp_value = (right_hand_value.getRawBits());
    return *this;
}

int     my_powers(int no, int powers)
{
    int i;
    i = 0;
    while (i < (powers - 1))
    {
        no = no * 2;
        i++;
    }
    return no;
}

float   Fixed::toFloat( void ) const
{
    float converted;
    float power;
    power = my_powers(2, fract_bits);
    converted = (fp_value / power);
    return converted ;
}

int     Fixed::toInt( void ) const
{
    int converted;
    int power;
    power = my_powers(2, fract_bits);
    converted = (fp_value / power);
    return converted ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fp_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fp_value = raw;
    return;
}

std::ostream & operator<<( std::ostream & output, Fixed const & hello)
{
    float rep;

    rep = hello.toFloat();
    /*put float representation into specified output stream*/
    output << rep;
    return output;
}