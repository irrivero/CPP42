/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:40:20 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:09:52 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Function to create a Zombie with the given name and make it announce itself.
 * Uses stack memory.
 * @param name the name of the Zombie to be created
 */
void	randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}