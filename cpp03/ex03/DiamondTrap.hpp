/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:17 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/13 14:48:55 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap	// DiamondTrap is derived from ScavTrap and FragTrap
{
	private:
		std::string _name;
		
	public:
		DiamondTrap(std::string name);			// default constructor
		~DiamondTrap();							// destructor
		DiamondTrap(const DiamondTrap &copy);	// copy constructor
		DiamondTrap &operator=(const DiamondTrap &copy);	// copy assignment operator
		
		void	whoAmI();
		void	attack(const std::string &target);
};

#endif