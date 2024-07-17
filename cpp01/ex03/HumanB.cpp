/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:47:06 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 13:22:01 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

/**
 * Sets the weapon for the HumanB object.
 *
 * @param weapon The weapon to be set.
 *
 */
void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

/**
 * Performs an attack action using the weapon if available, otherwise attacks with bare hands.
 */
void	HumanB::attack(void) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
}