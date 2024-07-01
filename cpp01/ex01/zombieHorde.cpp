/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:20 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:46:03 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Creates a horde of Zombies based on the given number and name.
 * @param N the number of Zombies to create
 * @param name the name to assign to each Zombie
 *
 * @return a pointer to the array of Zombie objects created
 */
Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];
	int		i = 0;
	
	if (N < 0)
		return (NULL);
	while (i < N)
	{
		horde[i].putName(name);
		i++;
	}
	return (horde);
}