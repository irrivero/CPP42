/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:40:24 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/13 14:47:32 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap // FragTrap is derived from ClapTrap
{
	public:
		FragTrap(std::string name);			// default constructor
		~FragTrap();						// destructor
		FragTrap(const FragTrap &copy);		// copy constructor
		FragTrap &operator=(const FragTrap &copy); // copy assignment operator
		
		void	highFivesGuys(void);
		void	attack(const std::string &target);
};

#endif