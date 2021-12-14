#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
    public:
    Fixed(void);
    Fixed(const int ivalue);
    Fixed(const float fvalue);
    Fixed( Fixed const & copy); //canonical 2
    ~Fixed(void); //canonical 3
    Fixed & operator=( Fixed const & right_hand_value); //canonical 4
    /*six comparative operators*/
    bool operator<( Fixed const &rhs);
    bool operator>( Fixed const & rhs);
    bool operator<=( Fixed const & rhs);
    bool operator>=( Fixed const & rhs);
    bool operator!=( Fixed const & rhs);
    bool operator==( Fixed const & rhs);

    /*four arithmatic operators*/
    Fixed operator*( Fixed const &rhs);
    Fixed operator/( Fixed const &rhs);
    Fixed operator-( Fixed const &rhs);
    Fixed operator+( Fixed const &rhs);

    /*pre and post plus/subtract*/
    Fixed & operator++( void ); /*++c, need & for if you do multiple ++ with equals*/
    Fixed operator++( int ); /*c++: int just to distinguish between pre and post*/
    Fixed & operator-- ( void ); /*--c */
    Fixed operator--( int ); /*c--*/

    /*min and max functions*/
    static Fixed & min ( Fixed &fp1, Fixed &fp2); 
    static Fixed & max ( Fixed &fp1, Fixed &fp2);
    static Fixed const & min( Fixed const & fp1, Fixed const & fp2);
    static Fixed const & max( Fixed const & fp1, Fixed const & fp2);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;
    
    private:
        int fp_value;
        static const int fract_bits = 8;
};

int my_powers(int no, int powers);
std::ostream & operator<<( std::ostream & output, Fixed const & hello);
#endif