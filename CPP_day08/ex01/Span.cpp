#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Span::Span(unsigned int i) : _size(i)
{
    return ;
}

Span::Span(void) : _size(0)
{
    return ;
}

Span::~Span(void)
{
    return ;
}

Span::Span(Span const & copy) : _size(0)
{
    *this = copy;
    return ;
}

Span & Span::operator=(Span const & rhs)
{
    const_cast<unsigned int &>(_size) = rhs._size;
    this->_array.clear();
    if (rhs._array.size() == 0)
        return *this;
    _array = rhs._array;
    return *this;
}

void Span::addNumber(int nbr)
{
    if (_array.size() < _size)
        _array.push_back(nbr);
    else
        throw Span::full_array();
    return ;
}

void Span::print_table(unsigned int x)
{
    char c = '-';
    unsigned int i = 0;
    std::vector<int>::iterator ptr = _array.begin();
    for (i = 0; i < x; i++)
    {
        if (i == x - 1 || ptr + 1 == _array.end())
            c = '|';
        if (ptr == _array.end())
        {
            if (i != 0)
            std::cout << std::endl;
            return;
        }
        std::cout << *ptr << c ;
        ptr++;
    }
    if (i == x)
        std::cout << std::endl;
}

unsigned int Span::shortestSpan(void)
{
    if (_array.size() < 2)
        throw Span::table_too_small();
    int diff = 0;
    std::vector<int>::iterator ptr;
    std::vector<int>::iterator ptr2;
    for (ptr = _array.begin(); ptr != _array.end(); ptr++)
    {
        for (ptr2 = ptr + 1; ptr2 != _array.end(); ptr2++)
        {
            if (*ptr2 - *ptr > 0) //if p1 smaller than p2
            {
                if (ptr == _array.begin()) //if this is 1st element, we need to update diff
                    diff = *ptr2 - *ptr;
                else if (*ptr2 - *ptr < diff) //else only update if the diff is smaller than prev value
                    diff = *ptr2 - *ptr;
            }
            else
            {
                if (ptr == _array.begin()) // if first pair of value then set diff as difference between them
                    diff = *ptr - *ptr2;
                if (*ptr - *ptr2 < diff) // else only update if diff is smaller
                    diff = *ptr - *ptr2;
            }
        }
    }
    return diff;
}

unsigned int Span::longestSpan(void)
{
    if (_array.size() < 2)
        throw Span::table_too_small();
    int min_val = *(std::min_element(_array.begin(), _array.end()));
    int max_val = *(std::max_element( _array.begin(), _array.end()));
    return (max_val - min_val);
}
