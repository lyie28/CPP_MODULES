#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <stdexcept>
template<typename T>
class MutantStack: public std::stack<T>
{
    public:

    MutantStack(void): std::stack<T>() {};
    ~MutantStack(void) {};
    MutantStack(MutantStack<T> const & copy) : std::stack<T>() { *this = copy; }

    //defining iterator as a std::stack<T>::container_type::iterator to be considered as a type, which takes iterator from the default type inside stack class
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack<T> & operator=(MutantStack<T> const & rhs)
    {
        if (this->size() == 0)
            this->c.clear();
        const_iterator ptr2;
        for (ptr2 = rhs.begin(); ptr2 != rhs.end(); ptr2++)
          this->push(*ptr2);
        return (*this);
    };
    /*define begin and end pointers*/
    iterator begin(void) { return this->c.begin(); }
    iterator end(void) { return this->c.end(); }
    const_iterator begin(void) const {return this->c.begin(); }
    const_iterator end(void) const {return this->c.end(); }
    reverse_iterator rbegin(void) { return this->c.rbegin(); }
    reverse_iterator rend(void) { return this->c.rend(); }
    const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
    const_reverse_iterator rend(void) const { return this->c.rend(); }
};

#endif