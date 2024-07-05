/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:38:33 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 12:17:53 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string _name;
		Weapon*		_weapon; // weapon pointer because it can change depending on the weapon
	 
	public:
		HumanB(const std::string name); // constructor that initializes _name
		void	attack(void) const; // attack function
		void	setWeapon(Weapon& weapon); // set a new _weapon
};

#endif