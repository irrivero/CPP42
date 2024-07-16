/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:24:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/11 15:33:34 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int	main()
{
	// ClapTrap	Potato("Potato");
	// ClapTrap	Tomato("Tomato");

	// Potato.attack("Tomato");
	// Tomato.takeDamage(3);
	// Tomato.beRepaired(4);
	// Tomato.attack("Potato");
	// Potato.takeDamage(9);
	// Potato.beRepaired(2);

	ScavTrap	Scav("Carrot");
	Scav.attack("Potato");
	//Scav.takeDamage(30);
	//Scav.beRepaired(20);
	Scav.guardGate();
	
	
	return (0);
}