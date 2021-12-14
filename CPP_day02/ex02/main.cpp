#include <iostream>
#include "Fixed.hpp"
#include <iomanip>

void    comparison_tests(void)
{
    Fixed a;
    Fixed b;

    a = Fixed(10);
    b = Fixed(-1);
    std::cout << "is 10 > -1?" << std::endl;
    if (a > b)
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    a = Fixed(1.38f);
    b = Fixed(1.18f);
    std::cout << "is 1.38 < 1.18?" << std::endl;
    if (a < b)
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
        a = Fixed(10);
        b = Fixed(10);
    std::cout << "is 10 == 10?" << std::endl;
    if (a == b)
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    std::cout << "is 10 <= 10?" << std::endl;
    if (a <= b)
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    a = Fixed(9.15f);
    b = Fixed(9.14f);
    std::cout << "is 9.15 == 9.14?" << std::endl;
    if (a == b )
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    std::cout << "is 9.15 >= 9.14?" << std::endl;
    if (a >= b )
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    std::cout << "is 9.15 != 9.14?" << std::endl;
    if (a != b )
        std:: cout << "Yes!" << std::endl;
    else
        std:: cout << "No!" << std::endl;
    return ;
}

void post_pre_increment_tests(void)
{
    Fixed a;

    std::cout << a << " <-starting value of a" << std::endl;
    std::cout << ++a << " ++a, immediate incrementation of a" << std::endl;
    std::cout << a << " a remains at increased value" << std::endl;
    std::cout << a++ << " a++ doesn't increase immediately" << std::endl;
    std::cout << a << " a now at higher value" << std::endl;
    std::cout << --a << " --a, immediate decrease of a" << std::endl;
    std::cout << a << " a remains at new lower value" << std::endl;
    std::cout << a-- << " a-- doesn't increase immediately" << std::endl;
    std::cout << a << " a at new lower value" << std::endl;
    return;
}

void arithmatics_tests(void)
{
    Fixed a(12.5f);
    Fixed b(7.5f);
    Fixed c(70);
    Fixed d(10);

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << c << " * " << d << " = " << (c * d) << std::endl;
    std::cout << c << " / " << d << " = " << (c / d) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    return; 
}

void min_max_tests(void)
{
    Fixed a(7.5f);
    Fixed b(2.5f);
    Fixed const c(12);
    Fixed const d(-2);
    std::cout << "What is smaller? " << a << " or " << b << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << "What is bigger? " << a << " or " << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << "What is smaller (const)? " << c << " or " << d << std::endl;
    std::cout << Fixed::min(c, d) << std::endl;
    std::cout << "What is bigger? " << c << " or " << d << std::endl;
    std::cout << Fixed::max(c, d) << std::endl;
}

int main(void) 
{
    std::cout << "**launching comparison tests**" << std::endl;
    comparison_tests();
    std::cout << std::endl << std::endl;
    std::cout << "**launching ++/-- tests**" << std::endl;
    post_pre_increment_tests();
    std::cout << std::endl << std::endl;
    std::cout << "**launching arithmatics tests**" << std::endl;
    arithmatics_tests();
    std::cout << std::endl << std::endl;
    std::cout << "**launching min/max tests**" << std::endl;
    min_max_tests();
    return 0;
}
