#include <iostream>
#include <string>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "AREA OF MEMORY:" << std::endl;
	std::cout << "pointer: " << stringPTR << std::endl;
	std::cout << "reference: " << &stringREF << std::endl;

	std::cout << "content:" << std::endl;
	std::cout << "pointer: " << *stringPTR << std::endl;
	std::cout << "reference: " << stringREF << std::endl;

	return 0;
}
