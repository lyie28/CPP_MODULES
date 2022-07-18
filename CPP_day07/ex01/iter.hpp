#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void my_print(T const & t1)
{
	std::cout << t1 << std::endl;
	return ;
}

/*const or references for array/function or not?*/
template<typename T>
void iter(T my_array[], int size, void(*my_function)(T const & p1))
{
	if (!my_function || !my_array)
		return;
	int i = -1;
	while (++i < size)
		(*my_function)(my_array[i]);
	return;
}

#endif
