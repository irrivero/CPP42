/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:03:13 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/15 11:26:35 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap // ScavTrap is derived from ClapTrap
{
	private:
		
	public:
		ScavTrap(std::string name);		// default constructor
		~ScavTrap();					// destructor
		ScavTrap(const ScavTrap &copy); //copy constructor
		ScavTrap &operator=(const ScavTrap &copy); // copy assignment operator

		void	guardGate();
		void	attack(const std::string& target);
};

#endif