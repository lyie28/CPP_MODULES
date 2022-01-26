#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <list>
#include <stdexcept>

int main()
{
    srand(time(NULL));
    MutantStack<int> Jack;
    std::list<int> test;
    std::cout << "Testing creating MutantStack with 10 random elements and a list with same elements" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        int j = rand() % 100;
        Jack.push(j);
        test.push_back(j);
    }
    std::cout << "Size of MutantStack is " << Jack.size() << std::endl;
    std::cout << "Size of list is " << test.size() << std::endl;
    std::cout << "Element at top of MutantStack is " << Jack.top() << std::endl;
    std::cout << "Element at top of list is " << test.back() << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;;
    std::cout << "Checking some different iterator algos" << std::endl;
    MutantStack<int>::iterator min_val = std::min_element(Jack.begin(), Jack.end());
    MutantStack<int>::iterator max_val = std::max_element(Jack.begin(), Jack.end());
    std::list<int>::iterator min_val2 = std::min_element(test.begin(), test.end());
    std::list<int>::iterator max_val2 = std::max_element(test.begin(), test.end());
    std::cout << "Mutant min val " << *min_val << std::endl;
    std::cout << "List min val " << *min_val2 << std::endl;
    std::cout << "Mutant max val " << *max_val << std::endl;
    std::cout << "List max val " << *max_val2 << std::endl;
    std::cout << "distance between Mutant min and max val is " << std::distance(min_val, max_val) << std::endl;
    std::cout << "distance between List min and max val is " << std::distance(min_val2, max_val2) << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;;
    std::cout << "Removing last three elements" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        Jack.pop();
        test.pop_back();
    }
    std::cout << "Size of MutantStack is " << Jack.size() << std::endl;
    std::cout << "Size of list is " << test.size() << std::endl;
    std::cout << "Element at top of MutantStack is " << Jack.top() << std::endl;
    std::cout << "Element at top of list is " << test.back() << std::endl;
    std::cout << "Creating and using iterator to print out MutantStack" << std::endl;
    MutantStack<int>::iterator ptr;
    for (ptr = Jack.begin(); ptr != Jack.end(); ptr++)
        std::cout << *(ptr) << std::endl;
    std::cout << "And list..." << std::endl;
    std::list<int>::iterator ptr2;
    for (ptr2 = test.begin(); ptr2 != test.end(); ptr2++)
        std::cout << *(ptr2) << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;
    std::cout << "emptying stack and list" << std::endl;
    while (Jack.begin() != Jack.end())
    {
        Jack.pop();
        test.pop_back();
    }
    std::cout << "Mutant size is now " << Jack.size() << std::endl;
    std::cout << "List size is now " << test.size() << std::endl;
    std::cout << "Try to iterate over empty stack" << std::endl;
    for (ptr = Jack.begin(); ptr != Jack.end(); ptr++)
        std::cout << *(ptr) << std::endl;
    std::cout << "And empty list..." << std::endl;
    for (ptr2 = test.begin(); ptr2 != test.end(); ptr2++)
        std::cout << *(ptr2) << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;;
    std::cout << "Checking copies are deep: Copying Jack (empty)" << std::endl;
    MutantStack<int> copy(Jack);
    std::cout << "Mutant copy size is now " << copy.size() << std::endl;
    std::cout << "Adding '99'' to mutant copy" << std::endl;
    copy.push(99);
    std::cout << "Mutant copy size is now " << copy.size() << std::endl;
    std::cout << "Mutant orig size is now " << Jack.size() << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;;
    std::cout << "Testing const reverse iterator with strings!" << std::endl;
    MutantStack<std::string> Shakespeare;
    std::list<std::string> tmp;
    Shakespeare.push("I");
    Shakespeare.push("am");
    Shakespeare.push("Lord");
    Shakespeare.push("Voldemort");
    tmp.push_back("I");
    tmp.push_back("am");
    tmp.push_back("Lord");
    tmp.push_back("Voldemort");
    MutantStack<std::string>::const_reverse_iterator rev;
    for (rev = Shakespeare.rbegin(); rev != Shakespeare.rend(); rev++)
        std::cout << *(rev) << std::endl;
    std::cout << "And list..." << std::endl;
    std::list<std::string>::const_reverse_iterator rev2;
    for (rev2 = tmp.rbegin(); rev2 != tmp.rend(); rev2++)
        std::cout << *(rev2) << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;;



}
