/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:24:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/11 16:24:15 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
int	main()
{
	// ClapTrap	Potato("Potato");
	// ClapTrap	Tomato("Tomato");

	// Potato.attack(Tomato.getName());
	// Tomato.takeDamage(3);
	// Tomato.beRepaired(4);
	// Tomato.attack(Potato.getName());
	// Potato.takeDamage(9);
	// Potato.beRepaired(2);

	// ScavTrap	Scav("Carrot");
	// Scav.attack(Potato.getName());
	// Scav.guardGate();

	// FragTrap	Frag("Lettuce");
	// Frag.highFivesGuys();
	// Frag.attack(Scav.getName());

	DiamondTrap	Diamond("Cucumber");
	Diamond.whoAmI();
	Diamond.attack("Lettuce");
	std::cout << "Cucumber's energy points: " << Diamond.getEnergyPoints() << std::endl;
	std::cout << "Cucumber's hit points: " << Diamond.getHitPoints() << std::endl;
	
	return (0);
}