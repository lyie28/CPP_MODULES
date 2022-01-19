#include "data_struct.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
    if (ptr == NULL)
        return 0;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

/*reinterpret cast is a pretty crazy cast type that let's you convert between almost anything,
except for classes that inherit from each other or constants- you need const cast for that.
If you convert it to new data type and then back again it should always still equal original value because bits don't change*/
int main(void)
{
    std::cout << "creating Data struct with name = Laura and x = 7 inside" << std::endl << std::endl;
    Data *my_struct = new Data;
    my_struct->x = 7;
    my_struct->name = "Laura";
    uintptr_t ptr;
    std::cout << "using reinterpret_cast to turn Data struct into a uintptr_t!" << std::endl << std::endl;
    ptr = serialize(my_struct);
    std::cout << "Data * as crazy uintptr_t value: " << ptr << std::endl << std::endl;
    std::cout << "Making new empty Data struct" << std::endl << std::endl;
    Data *new_struct;
    std::cout << "using reinrepret_cast to convert uintptr_t back to Data and assing it to our new struct" << std::endl << std::endl;
    new_struct = deserialize(ptr);
    if (new_struct == my_struct)
        std::cout << "Struct 1 and 2 are same" << std::endl;
    else
        std::cout << "Struct 1 and 2 are not same" << std::endl;
    std::cout << "It worked. New_struct has become old structure" << std::endl << std::endl;
    std::cout << "old_struct x is " << my_struct->x << " old_struct name is " << new_struct->name << std::endl;
    std::cout << "New_struct x is " << new_struct->x << " new_struct name is " << new_struct->name << std::endl;
    std::cout << std::endl << "checking can still use new_struct. setting x to 8" << std::endl;
    new_struct->x = 8;
    std::cout << "It worked! x is now " << new_struct-> x << std::endl << std::endl;
    delete my_struct;
    /*null pointers*/
    std::cout << "testing program doesn't crash with null pointers" << std::endl;
    Data *empty = NULL;
    uintptr_t ptr2 = serialize(empty);
    empty = deserialize(ptr2);
    if (empty == NULL)
        std::cout << "still null" << std::endl;
    return 0;
}



