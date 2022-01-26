#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(T container, int x)
{
	typename T::const_iterator ptr = find(container.begin(), container.end(), x);
	if (ptr == container.end())
	{
		throw (std::out_of_range("ERROR: element not found"));
	}
	else
		return (ptr);
}

#endif
