/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:59:40 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/07 16:25:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <\"expression\">" << std::endl;
		return (-1);
	}

	RPN	rpn;
	std::string expression = av[1];
	int result = rpn.calculate(expression);
	if (result != -42)
		std::cout << result << std::endl;
	return (0);
}