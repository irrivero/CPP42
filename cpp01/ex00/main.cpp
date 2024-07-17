/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:43:37 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 14:56:29 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*nZombie;

	nZombie = newZombie("heapZombie:");
	nZombie->announce();
	delete nZombie;
	randomChump("stackZombie: ");
	return (0);
}