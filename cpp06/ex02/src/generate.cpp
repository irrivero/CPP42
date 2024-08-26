/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:15:44 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 12:38:23 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"

Base	*generate(void)
{
	srand(static_cast<unsigned int>(time(NULL))); // set seed for random
	int	random = rand() % 3;	// get random number between 0, 1 or 2

	switch (random)
	{
		case 0:
			std::cout << "Generating A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generating B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generating C" << std::endl;
			return (new C());
		default:
			return (NULL); // should never happen
	}
}