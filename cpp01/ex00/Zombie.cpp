/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:33:03 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:05:14 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Constructs a new Zombie object.
 * @param name The name of the Zombie.
*/
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

/**
 * @brief Destroy the Zombie object
 * @details Prints the name of the Zombie that died
*/
Zombie::~Zombie(void)
{
	std::cout << this->_name << " died" << std::endl;
}

/**
 * @brief Prints the name of the Zombie followed by "BraiiiiiiinnnzzzZ..."
*/
void	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
