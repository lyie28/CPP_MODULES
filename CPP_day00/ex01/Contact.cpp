#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>
#include <iomanip>

Contact::~Contact( void )
{
	return;
}

Contact::Contact( void )
{
	_initialised = 0;
	return;
}

void	Contact::add(int i)
{
	std::cout << "First name:" << std::endl;
	std::getline (std::cin, _first_name);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Last name:" << std::endl;
	std::getline (std::cin, _last_name);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Nickname:" << std::endl;
	std::getline (std::cin, _nickname);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Phone number:" << std::endl;
	std::getline (std::cin, _phone_number);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Darkest Secret:" << std::endl;
	std::getline (std::cin, _darkest_secret);
	if (std::cin.eof() == 1)
		return ;
	_initialised = 1;
	_index = i;
}

void	Contact::print_full() const
{
	std::cout << _first_name << std::endl;
	std::cout << _last_name << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _phone_number << std::endl;
	std::cout << _darkest_secret << std::endl;
}

void	Contact::print_formatted() const
{
	if (_initialised == 1)
	{
		std::cout << '|';
		std::cout << std::setw(10);
		std::cout << _index;
		std::cout << '|';
		std::cout << std::setw(10);
		if (_first_name.length() >= 10)
		{
			std::cout << std::setw(9);
			std::cout << _first_name.substr(0, 9) << '.';
		}
		else
			std::cout << _first_name;
		std::cout << '|';
		std::cout << std::setw(10);
		if (_last_name.length() >= 10)
		{
			std::cout << std::setw(9);
			std::cout << _last_name.substr(0, 9) << '.';
		}
		else
			std::cout << _last_name;
		std::cout << '|';
		std::cout << std::setw(10);
		if (_nickname.length() >= 10)
		{
			std::cout << std::setw(9);
			std::cout << _nickname.substr(0, 9) << '.';
		}
		else
		{
			std::cout << std::setw(10);
			std::cout << _nickname;
		}
		std::cout << '|';
		std::cout << std::endl;
	}

}

int	Contact::isinit() const
{
	if (_initialised == 1)
		return (1);
	return (0);
}

void	Contact::bar_width_print(std::string str) const
{
	std::cout << '|';
	std::cout << std::setw(10);
	std::cout << str;
}

void	Contact::search() const
{
	print_formatted();
}
