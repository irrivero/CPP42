/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:07:01 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 14:43:21 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
		std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	return (0);
}