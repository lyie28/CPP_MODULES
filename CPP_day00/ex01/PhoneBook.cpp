#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iomanip>

PhoneBook::PhoneBook( void )
{
	return;
}

PhoneBook::~PhoneBook( void )
{
	return;
}

void	PhoneBook::add(int i)
{
	_buddies[i].add(i);
	return ;
}

void	PhoneBook::bar_width_print(std::string str) const
{
	std::cout << '|';
	std::cout << std::setw(10);
	std::cout << str;
}

void	PhoneBook::search() const
{
	int	i;
	std::string input;

	i = 0;
	bar_width_print("Index");
	bar_width_print("First name");
	bar_width_print("Last name");
	bar_width_print("Nickname");
	std::cout << '|' << std::endl;
	while (i < 8)
	{
		this->_buddies[i].search();
		i++;
	}
	std::cout << "Input the index of contact you wish to see" << std::endl;
	std::getline(std::cin, input);
	if (input[0] < 48 || input[0] > 55 || input.length() != 1)
	{
		std::cout << "This is not a valid index value" << std::endl;
		return ;
	}
	if (this->_buddies[(input[0] - 48)].isinit() == 1)
	{
		this->_buddies[(input[0] - 48)].print_full();
		return ;
	}
	std::cout << "This is not a valid index value" << std::endl;
	return ;
}
