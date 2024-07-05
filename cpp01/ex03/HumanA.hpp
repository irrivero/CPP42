/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:35 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 12:17:24 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name; // name of human
		Weapon&		_weapon; // weapon of human reference because it will always be the same
	
	public:
		HumanA(std::string name, Weapon& weapon); // constructor that initializes _name and _weapon
		void	attack(void) const; // attack function it is const function because it does not change _weapon
};

#endif