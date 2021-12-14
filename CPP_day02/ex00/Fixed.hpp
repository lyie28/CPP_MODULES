#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
    public:
    Fixed(void); //Canonical format 1: Constructor
    Fixed( Fixed const & copy); //Canonical format 2: copy
    ~Fixed(void); //Canonical format 3: destructor
    Fixed & operator=( Fixed const & right_hand_value); //Canonical format 4: assingation operator
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    private:
        int fp_value;
        static const int fract_bits = 8;
};

#endif