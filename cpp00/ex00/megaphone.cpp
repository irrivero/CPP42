#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
				std::cout << (char)std::toupper(av[i][j++]);
			++i;
		}
		if (ac < i)
			return(0);
		std::cout << std::endl;
	}
	return(0);
}

