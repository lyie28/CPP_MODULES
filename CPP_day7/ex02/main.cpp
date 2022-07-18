#include "Array.hpp"
#include <iostream>

int main(void)
{
    try
    {
        std::cout << "Simple test with floats" << std::endl;
        float float_array[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        Array<float>f_array(5);
        int i = -1;
        while (++i < 5)
            f_array[i] = float_array[i];
        i = -1;
        while (f_array[++i])
            std::cout << f_array[i] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        float float_array[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        Array<float>f_array(5);
        int i = -1;
        while (++i < 5)
            f_array[i] = float_array[i];
        Array <float>copy(f_array);
        std::cout << std::endl;
        std::cout << "copy of f_array starting value:" << std::endl;
        i = -1;
        while (++i < 5)
            std::cout << copy[i] << std::endl;
        std::cout << "modifying values to 0:" << std::endl;
        i = -1;
        while (++i < 5)
            copy[i] = 0;
        std::cout << "checking copy's values have changed" << std::endl;
        i = -1;
        while (++i < 5)
            std::cout << copy[i] << std::endl;
        std::cout << "checking original's values stay the same" << std::endl;
        i = -1;
        while (++i < 5)
            std::cout << f_array[i] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Test with empty array" << std::endl;
        Array<float> empty_array;
        std::cout << "size of array is " << empty_array.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Simple test with strings" << std::endl;
        std::string string_array[5] = { "once", "upon", "a", "time", "..."};
        Array<std::string>s_array(5);
        int i = -1;
        while (++i < 5)
            s_array[i] = string_array[i];
        i = -1;
        while (++i < 5)
            std::cout << s_array[i] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Test with empty array" << std::endl;
        Array<std::string> empty_array;
        std::cout << "size of array is " << empty_array.size() << std::endl;
        std::cout << empty_array[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
