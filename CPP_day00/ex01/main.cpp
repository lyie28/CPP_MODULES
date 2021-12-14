#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iomanip>

int	main( void )
{
	PhoneBook book;
	std::string	input;
	int	count;

	count = 0;
	std::cout << "Input a command (EXIT/ADD/SEARCH:)" << std::endl;
	std::getline(std::cin, input);
	while (std::cin.eof() != 1)
	{
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		{
			if (count > 7)
			{
				std::cout << "PhoneBook is full. Replacing oldest contact..." << std::endl;
				book.add(count % 8);
			}
			else
				book.add(count);
			count++;
		}
		else if (input == "SEARCH")
			book.search();
		if (std::cin.eof() == 1)
		{
			std::cout << "exiting" << std::endl;
			return 0;
		}
		std::cout << "Input a command (EXIT/ADD/SEARCH:)" << std::endl;
		std::getline (std::cin, input);
	}
	std::cout << "exiting" << std::endl;
	return 0;
}
