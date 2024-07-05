/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:30:37 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 11:54:22 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string _type; // type of weapon
	
	public:
		Weapon (const std::string type); // constructor that initializes _type of Weapon
		
		const std::string	getType(void) const; // returns _type of Weapon
		void	setType(std::string type); // sets a new _type of Weapon
};

#endif