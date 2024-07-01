/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:11 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:43:36 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int		N = 3;
	int		i = 0;
	
	std::string	name = "Zombie";
	
	Zombie*	horde = zombieHorde(N, name);
	if (horde != NULL)
	{
		while (i < N)
		{
			horde[i].announce();
			i++;
		}
	}
	delete[] horde;
	return (0);
}