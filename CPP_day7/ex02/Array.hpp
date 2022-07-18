#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template<typename T>

class Array
{
    public:
    Array(void) : my_array(NULL), _size(0) {}
    Array(unsigned int n) : my_array( new T [n]), _size(n) {}
    ~Array(void)
    {
         if (my_array)
            delete [] my_array;
    }

    Array( Array const & copy)
    {
        _size = copy._size;
        my_array = new T[_size];
        *this = copy;
    }

    Array & operator=( Array const & rhs)
    {
        this->_size = rhs._size;
        unsigned int i = 0;
        while (i < _size)
        {
            my_array[i] = rhs.my_array[i];
            i++;
        }
        return (*this);
    }

    T & operator[]( unsigned int i )
    {
        if (i >= _size)
        {
            throw Array::oor();
        }
        return
            my_array[i];
    }
    unsigned int size(void) const { return this->_size; }


    class oor : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("ERROR: out of range");
            }
    };

    private:
        T *my_array;
        unsigned int _size;
};
#endif
