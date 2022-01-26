#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span
{
    public:

    Span(unsigned int i);
    Span(void);
    ~Span(void);
    Span(Span const & copy);
    Span & operator=(Span const & rhs);
    void addNumber(int nbr);
    std::vector<int> getArray(void) const
    {
        return _array;
    }
    template <typename T>
    void range(T start, T end)
    {
    	if (_array.size() + distance(start, end) <= _size)
        	_array.insert(_array.begin() + _array.size(), start, end);
	else
		throw Span::full_array();
	return;
    }
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    void print_table(unsigned int x);

    class full_array : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return("ERROR: Span's table is already full!");
            }
    };

    class table_too_small : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("ERROR: table not big enough to perform this operation");
            }
    };

    private:
        std::vector<int> _array;
        const unsigned int _size;
};

#endif
