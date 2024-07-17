/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:12:06 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 16:08:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;	
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " is dead!" << std::endl;
}


void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}