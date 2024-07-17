/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:17 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 16:05:44 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &copy);
		
		void	whoAmI();
		void	attack(const std::string &target);
};

#endif