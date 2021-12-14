#include "Karen.hpp"

int main(int argc, char **argv)
{
    std::string input;
    int index;
    Karen example;

    if (argc != 2)
    {
        std::cout << "wrong number of arguments!" << std::endl;
        return 0;
    }
    index = example.get_int(argv[1]);
    switch(index)
    {
        case 0:
            example.complain("DEBUG");
            std::cout << std::endl;
        case 1:
            example.complain("INFO");
            std::cout << std::endl;
        case 2:
            example.complain("WARNING");
            std::cout << std::endl;
        case 3:
            example.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            example.complain("random");
            std::cout << std::endl;
            break;
    }
    return 0;
}