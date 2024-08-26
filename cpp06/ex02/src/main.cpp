/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:25:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 12:38:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"

int	main(void)
{
	// Generate a random type of Base A B or C
	Base	*base = generate();

	// Identify the type of a Base pointer
	std::cout << "Identify the type of a Base pointer: ";
	identify(base);
	
	// Identify the type of a Base reference
	std::cout << "Identify the type of a Base reference: ";
	identify(*base);

	delete base;
	return (0);
}