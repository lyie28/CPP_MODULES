#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <time.h>

int main(void)
{
    try
    {
        srand(time(NULL));
        std::cout << "TEST 1: Creating table with max size 1000" << std::endl;
        Span sp(1000);
        int i = -1;
        while (++i < 10)
            sp.addNumber(rand() % 100);
        std::cout << "10 random numbers added: " << std::endl;
        sp.print_table(10);
        std::cout << "Longest span is " << sp.longestSpan() << std::endl;
        std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
	    std::cout << "Now let's try add the first 5 Span value to a new Span using range function" << std::endl;
	    Span new_span(10);
        std::vector<int> testing = sp.getArray();
        std::vector<int>::iterator ptr = testing.begin();
        std::vector<int>::iterator ptr2 = testing.begin() + 5;
        std::vector<int>::iterator ptr3 = testing.end();
	    new_span.range(ptr, ptr2);
	    std::cout << "contents of new span are now..." << std::endl;
	    new_span.print_table(10);
	    std::cout << "Now let's try to exceed the new span capacity by adding 10 elements..." << std::endl;
	    new_span.range(ptr, ptr3);
    	new_span.print_table(10);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
	std::cout << std::endl << "TEST 3: Create table of size 1 and try to call shortestspan (error expected)" << std::endl;
        Span error(1);
        error.addNumber(712);
        std::cout << error.shortestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Span sp(1000);
        Span new_span(100000);
        int i = -1;
        while (++i < 1000)
            sp.addNumber(rand() % 100);
        std::vector<int> testing = sp.getArray();
        std::vector<int>::iterator ptr = testing.begin();
        std::vector<int>::iterator ptr2 = testing.end();
       	std::cout << std::endl << "TEST 4: Let's use range function to create giant Span" << std::endl;
        i = -1;
        while (++i < 100)
            new_span.range(ptr, ptr2);
        std::vector<int> gspan = new_span.getArray();
        std::cout << "Created Span of size " << gspan.size() << " Printing first 50 elements of giant span" << std::endl;
        new_span.print_table(50);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << std::endl << "TEST 5: creating array of max size 0" << std::endl;
        Span empty(0);
        std::cout << "Try to add number to an array of size 0" << std::endl;
        empty.addNumber(1);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Span empty(100);
        std::cout << std::endl << "TEST 6: Try to call longestspan with empty table" << std::endl;
        std::cout << empty.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "TEST 7: testing copies and = are deep copies" << std::endl;
    {
        std::cout << "Creating a table 9-9-9 and creating copy of it" << std::endl;
        Span tab(5);
        tab.addNumber(9);
        tab.addNumber(9);
        tab.addNumber(9);
        Span copy(tab);
        std::cout << "Checking both tables have same elements:" << std::endl;
        copy.print_table(3);
        tab.print_table(3);
        std::cout << "Adding two elements to copy" << std::endl;
        copy.addNumber(1);
        copy.addNumber(1);
        std::cout << "Checking only copy has been modified" << std::endl << "Copy:" << std::endl;
        copy.print_table(5);
        std::cout << "orig" << std::endl;
        tab.print_table(5);
    }
    return 0;
}
