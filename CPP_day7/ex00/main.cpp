#include "whatever.hpp"
#include <iostream>

int main(void)
{
	std::cout << "testing functions with char" << std::endl;
	char a = 'a';
	char b = 'z';
	std::cout << "Testing min('a', 'z') = " << ::min(a, b) << std::endl;
	std::cout << "max('a', 'z') = " << ::max(a, b) << std::endl;
	std::cout << "Testing swap('a', 'z') = " << std::endl;
	::swap(a , b);
	std::cout << "a is now: " << a << " b is now: " << b << std::endl << std::endl;
	std::cout << "testing functions with int" << std::endl;
	int x = -12;
	int y = 8;
	std::cout << "Testing min(-12, 8) = " << ::min(x, y) << std::endl;
	std::cout << "Testing max(-12, 8) = " << ::max(x, y) << std::endl;
	std::cout << "Testing swap(-12, 8)" << std::endl;
	::swap(x , y);
	std::cout << "x is now: " << x << " y is now: " << y << std::endl << std::endl;
	std::cout << "testing functions with floats" << std::endl;
	float f1 = 12.4;
	float f2 = 12.2;
	std::cout << "Testing min(12.4, 12.2) = " << ::min(f1, f2) << std::endl;
	std::cout << "Testing max(12.4, 12.2) = " << ::max(f1, f2) << std::endl;
	std::cout << "Testing swap(12.4, 12.2)" << std::endl;
	::swap(f1 , f2);
	std::cout << "f1 is now: " << f1 << " f2 is now: " << f2 << std::endl << std::endl;
	std::cout << "testing functions with strings" << std::endl;
	std::string c = "Hello";
	std::string d = "Laura";
	std::cout << "min(Hello, Laura) = " << ::min( c, d ) << std::endl;
	std::cout << "max(Hello, Laura) = " << ::max( c, d ) << std::endl;
	std::cout << "Testing swap(Hello, Laura)" << std::endl;
	::swap(c , d);
	std::cout << "str1 is now: " << c << " str2 is now: " << d << std::endl;
	return 0;
}
