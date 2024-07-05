/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:33:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 11:59:07 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (const std::string type) : _type(type) {}

/**
 * @return the type ofthe Weapon
 */
const std::string	Weapon::getType(void) const
{
	return (this->_type);
}

/**
 * @param newType The new type of the weapon.
 * 
 * Sets the type of the weapon
 */
void	Weapon::setType(std::string type)
{
	this->_type = type;
}

