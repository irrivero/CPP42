/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:15:14 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/13 14:40:41 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << this->_name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " is destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << this->_name << " copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << this->_name << " assigned" << std::endl;
	return (*this);
}

// Returns the name of the ClapTrap
std::string	ClapTrap::getName() const
{
	return (this->_name);
}

//public member functions

// Attack function: Reduces energy points and outputs an attack message.
// If the ClapTrap is dead (hit points <= 0) or out of energy, it cannot attack.
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->getName() << " can't attack because it's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->getName() << " can't attack because it's out of energy points" << std::endl;
		return ;
	}

	std::cout << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

// TakeDamage function: Reduces the ClapTrap's hit points by the specified amount. 
// If hit points drop below zero, they are set to zero.
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << this->getName() << " takes " << amount << " points of damage! Hit points left: " << this->_hitPoints << std::endl;
}

// BeRepaired function: Increases the ClapTrap's hit points by the specified amount.
// If the ClapTrap is dead or out of energy, it cannot be repaired.
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->getName() << " can't be repaired because it's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout  << this->getName() << " can't be repaired because it's out of energy points" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	std::cout << this->getName() << " is repaired by " << amount << "! Hit points left: " << this->_hitPoints << std::endl;
	this->_energyPoints -= 1;
}