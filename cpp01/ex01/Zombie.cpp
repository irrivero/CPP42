/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:13 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:46:14 by irivero-         ###   ########.fr       */
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

/**
 * @brief Constructs a new Zombie object using stack memory.
 * @details The name of the Zombie is "namez"
*/
Zombie::Zombie(void) : _name("namez"){}

/**
 * @brief Sets the name of the Zombie
 * @param name The name of the Zombie
*/
void	Zombie::putName(std::string name)
{
	this->_name = name;
}