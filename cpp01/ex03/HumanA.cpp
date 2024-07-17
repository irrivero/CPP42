/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:45:03 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 13:22:18 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * 
 * @param name The name of the Human
 * @param weapon The weapon of the Human
 * 
 * Constructor that initializes _name and _weapon
 * 
 */
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

/**
 * @brief attack function 
 */
void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}