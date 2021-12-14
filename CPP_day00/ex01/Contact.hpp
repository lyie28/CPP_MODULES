#ifndef BFF_CLASS_H
# define BFF_CLASS_H

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>


class Contact
{
	public:
		Contact( void );
		~Contact( void );
		void	add(int index);
		void	display (void) const;
		void	search(void) const;
		void	bar_width_print(std::string) const;
		void	print_formatted(void) const;
		void	print_full(void) const;
		int	isinit(void) const;
	
	private:
		int		_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int	_initialised;

};

#endif
