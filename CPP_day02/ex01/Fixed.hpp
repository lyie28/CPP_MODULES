#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void); //canonical 1: default constructor
        Fixed(const int ivalue);
        Fixed(const float fvalue);
        Fixed( Fixed const & copy); //canonical 2: copy constructor
        ~Fixed(void); //canonical 3: destructor
        Fixed & operator=( Fixed const & right_hand_value); //canonical 4: assignation operator overload
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
    
    private:
        int                 fp_value;
        static const int    fract_bits = 8;
};

int my_powers(int no, int powers);
std::ostream & operator<<( std::ostream & output, Fixed const & hello);
#endif