/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:24:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/11 14:54:02 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Potato("Potato");
	ClapTrap	Tomato("Tomato");

	Potato.attack("Tomato");
	Tomato.takeDamage(3);
	Tomato.beRepaired(4);
	Tomato.attack("Potato");
	Potato.takeDamage(9);
	Potato.beRepaired(2);
	
	return (0);
}