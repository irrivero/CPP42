/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:53 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 17:08:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Constructs a new Zombie object using heap memory.
 * @param name The name of the Zombie.
 * @return A pointer to the newly created Zombie object.
 */
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}