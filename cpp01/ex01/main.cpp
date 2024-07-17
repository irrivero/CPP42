/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:11 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 14:58:06 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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