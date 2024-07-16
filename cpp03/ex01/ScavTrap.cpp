/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:14:16 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/11 15:28:47 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " can't attack because it's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <=0)
	{
		std::cout << "ScavTrap " << this->getName() << " can't attack because it's out of energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}