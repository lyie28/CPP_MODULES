#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <string>

int main(void)
{
    int i = -1;
    try
	{
		std::vector<int> my_array;
    	std::cout << "Creating vector: 0, 1, 2, 3, 4" << std::endl;
    	while (++i < 5)
        	my_array.push_back(i);
    	std::cout << "where is the int 2 ?" << std::endl;
    	std::cout << *easyfind(my_array, 2) << std::endl;
    	std::cout << "where is the int 10 ?" << std::endl;
    	std::cout << *easyfind(my_array, 10) << std::endl;
	}
	catch (std::out_of_range& oor)
	{
		std::cout << oor.what() << std::endl;
	}
    std::cout << "--------------------------------------" << std::endl << std::endl;
    try
    {
        std::deque<int> my_deque;
        std::cout << "Creating a deque: -3, -2, -1" << std::endl;
        i = -1;
        int add = -1;
        while (++i < 3)
        {
            my_deque.push_front(add);
            add--;
        }
        std::cout << "where is the int -1 ?" << std::endl;
        std::cout << *easyfind(my_deque, -1) << std::endl;
        std::cout << "where is the int 10 ?" << std::endl;
        std::cout << *easyfind(my_deque, 10) << std::endl;
    }
    catch (std::out_of_range& oor)
	{
		std::cout << oor.what() << std::endl;
	}
    std::cout << "--------------------------------------" << std::endl << std::endl;
    try
    {
        std::list<int> my_list;
        std::cout << "Creating a list: 10, 20, 30, 40" << std::endl;
        my_list.push_back(10);
        my_list.push_back(20);
        my_list.push_back(30);
        my_list.push_back(40);
        std::cout << "where is the int 30 ?" << std::endl;
        std::cout << *easyfind(my_list, 30) << std::endl;
        std::cout << "where is the int 100?" << std::endl;
        std::cout << *easyfind(my_list, 100) << std::endl;
    }
    catch (std::out_of_range& oor)
	{
		std::cout << oor.what() << std::endl;
	}
    return 0;
}
