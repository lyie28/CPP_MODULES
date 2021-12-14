#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc <= 1)
	{
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			return (0);
	}
	else
	{
		while (i < argc - 1)
		{
			j = 0;
			while (j < (int)((std::string)argv[i + 1]).length())
			{
				std::cout << (char)toupper(argv[i + 1][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
