#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    fp_value = 0;
    return ;
}

Fixed::Fixed(const int ivalue)
{
    int power;
    power = my_powers(2, fract_bits);
    fp_value = ivalue * power;    
    return ;
}

Fixed::Fixed(const float fvalue)
{
    float power;
    power = my_powers(2, fract_bits);
    fp_value = roundf(fvalue * power);
    return ;
}

Fixed::Fixed( Fixed const & copy)
{
    *this = copy;
    return ;
}

Fixed::~Fixed(void)
{
    return ;
}

Fixed & Fixed::operator=( Fixed const & right_hand_value)
{
    this->fp_value = right_hand_value.getRawBits();
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
    return (fp_value);
}

void Fixed::setRawBits(int const raw)
{
    fp_value = raw;
    return;
}

std::ostream & operator<<( std::ostream & output, Fixed const & hello)
{
    float rep;

    rep = hello.toFloat();
    output << rep;
    return output;
}

/*six comparison functions*/
bool Fixed::operator>( Fixed const & rhs)
{
    if (fp_value > rhs.fp_value)
        return (true);
    return (false);
}

bool Fixed::operator<( Fixed const & rhs)
{
    if (fp_value < rhs.fp_value)
        return (true);
    return (false);
}

bool Fixed::operator<=( Fixed const & rhs)
{
    if (fp_value <= rhs.fp_value)
        return (true);
    return (false);
}
bool Fixed::operator>=( Fixed const & rhs)
{
     if (fp_value >= rhs.fp_value)
        return (true);
    return (false);
}

bool Fixed::operator!=( Fixed const & rhs)
{
    if (fp_value != rhs.fp_value)
        return (true);
    return (false);
}

bool Fixed::operator==( Fixed const & rhs)
{
    if (fp_value == rhs.fp_value)
        return (true);
    return (false);
}

/*arithmatic operators*/
Fixed Fixed::operator*( Fixed const &rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const &rhs)
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed  Fixed::operator-( Fixed const &rhs)
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed  Fixed::operator+( Fixed const &rhs)
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

/*pre and post plus/subtract*/
Fixed & Fixed::operator++( void )
{
    /*++i changes real value*/
    this->fp_value++;
    return *this;
}

Fixed  Fixed::operator++( int )
{
	/*we want to change orig value but not at first*/
	Fixed temp;
	
	temp = *this; //create temp copy of current state
	this->fp_value++; //change current copy 
	return (temp); //change of value occured in this but we don't see this in temp because not &
}

Fixed &  Fixed::operator-- ( void )
{
    /*--i changes orig value*/
    fp_value--;
    return (*this);
}

Fixed  Fixed::operator--( int )
{
	
    Fixed temp;

    temp = *this;
    this->fp_value--;
    return (temp); //return unchanged value but change real value
}

/*min max functions*/

Fixed & Fixed::min ( Fixed &fp1, Fixed &fp2)
{
    std::cout << "INFO: calling fixed max function" << std::endl;
    if (fp1 < fp2)
        return (fp1);
    else
        return (fp2);
}

Fixed & Fixed::max ( Fixed &fp1, Fixed &fp2)
{
    std::cout << "INFO: calling fixed max function" << std::endl;
     if (fp1 > fp2)
        return (fp1);
    else
        return (fp2);
}


Fixed const & Fixed::min( Fixed const & fp1, Fixed const & fp2)
{
    std::cout << "INFO: calling const fixed min function" << std::endl;
    //need to access values with get raw bits
    if (fp1.getRawBits() < fp2.getRawBits())
        return (fp1);
    else
        return (fp2);
}

Fixed const & Fixed::max( Fixed const & fp1, Fixed const & fp2)
{
    //need to access values iwth get raw bits
    std::cout << "INFO: calling const fixed max function" << std::endl;
    if (fp1.getRawBits() > fp2.getRawBits())
        return (fp1);
    else
        return (fp2);
}
