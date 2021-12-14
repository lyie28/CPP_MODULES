#ifndef YELLOW_PAGES_CLASS_H
# define YELLOW_PAGES_CLASS_H

#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	add(int i);
		void	search() const;
		void	bar_width_print(std::string) const;

	private:
		Contact	_buddies[8];
};

#endif
