#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

void    find_and_replace(std::string file, std::string name, std::string find, std::string replace)
{
    std::ifstream ifs;
    std::ofstream ofs;
    std::size_t pos;
    std::string line;
    std::string substring;

    ifs.open(file, std::ifstream::in);
    if (!ifs.good())
    {
        std::cout << "ERROR: cannot open this file" << std::endl;
        return ;
    }
    ofs.open(name, std::ofstream::trunc);
    if (!ofs.good())
    {
        std::cout << "ERROR: cannot create output file" << std::endl;
        return ;
    }
    while (ifs.peek() != EOF)
    {
        std::getline(ifs, line);
        if (find != replace)
        {
            pos = line.find(find);
            while (pos != std::string::npos)
            {
                line.erase(pos, find.length());
                line.insert(pos, replace);
                pos = line.find(find);
            }
        }
        if (ifs.peek() == EOF)
            ofs << line;
        else
            ofs << line << std::endl;
    }
    ifs.close();
    ofs.close();
}

std::string get_filename(std::string temp)
{
    std::size_t pos;
    int i = 0;
    while (temp[i])
    {
        temp[i] = (char)toupper(temp[i]);
        i++;
    }
    pos = temp.rfind('.');
    if (pos == std::string::npos)
        temp = temp += ".replace";
    else
    {
        temp.erase(pos, temp.length() - pos);
        temp.insert(pos, ".replace");
    }
    return (temp);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "ERROR: required format./program_name [FILENAME] [STR_TOREPLACE] [REPLACE_WITH]" << std::endl;
        return (0);
    }
    std::string to_find = argv[2];
    std::string temp = argv[1];
    std::string replace_with = argv[3];
    if (to_find.length() == 0 || replace_with.length() == 0)
    {
        std::cout << "ERROR: cannot except null strings" << std::endl;
        return (0);
    }
    std::string filename = get_filename(temp);
    find_and_replace(argv[1], filename, argv[2], argv[3]);
    return (0);
}
