/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:15:14 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/11 15:26:42 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " copied" << std::endl;
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

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int			ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int			ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int			ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

//public member functions

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " can't attack because it's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " can't attack because it's out of energy points" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " <<this->getName() << " takes " << amount << " points of damage! Hit points left: " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " can't be repaired because it's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " can't be repaired because it's out of energy points" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->getName() << " is repaired by " << amount << "! Hit points left: " << this->_hitPoints << std::endl;
	this->_energyPoints -= 1;
}