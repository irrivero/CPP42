/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:44:07 by irivero-          #+#    #+#             */
/*   Updated: 2024/06/20 13:38:51 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	// start at 1 to skip the program name
	int	i = 1;
	// go through the characters of each arg
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac) // go through the arguments
		{
			j = 0; // start at the first character of the arg
			while (av[i][j]) // go through the characters of the arg
				std::cout << (char)std::toupper(av[i][j++]); // convert to uppercase the character and goes to the next one
			++i; // go to the next argument
		}
		if (ac < i) // not sure if this is necessary
			return(0);
		std::cout << std::endl; // print a new line
	}
	return(0);
}

