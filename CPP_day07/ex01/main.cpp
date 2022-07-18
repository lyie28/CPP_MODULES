#include "iter.hpp"
#include <iostream>

int main(void)
{
	char char_table[5] = {'1', '2', '3', '4', '5'};
	int int_table[4] = {-3, -2, -1, 0};
	std::string str_table[3] = {"Hello", "Laura", "Yie"};

	iter(char_table, 5, &my_print);
	iter(int_table, 4, &my_print);
	iter(str_table, 3, &my_print);
	return 0;
}
