#include "includes/Brain.hpp"
#include <cstring>

Brain::Brain(void)
{
    std::cout << "A Brain is made" << std::endl;
    return ;
}

Brain::~Brain(void)
{
    std::cout << "Brain is dead. RIP Brain" << std::endl;
    return ;
}

Brain::Brain( Brain const & copy)
{
    *this = copy;
    return ;
}

Brain & Brain::operator=( Brain const & rhv)
{
   int i = 0;
   if (this != &rhv)
   {
        while (i < 100)
        {
            this->set_value(i, rhv._ideas[i]);
            i++;
        }
   }
   return *this;
}

void Brain::set_value(int i, std::string str)
{
    _ideas[i] = str;
    return ;
}

std::string Brain::get_value(int i)
{
    return _ideas[i];
}

std::string *Brain::get_addr(int i)
{
    return &(_ideas[i]);
}
