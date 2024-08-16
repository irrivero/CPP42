/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:35:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/16 15:40:29 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string		_type;
	
	public:
		//constructor and destructor
		Animal();
		virtual ~Animal();
		Animal(std::string const &type);
		Animal(const Animal &copy); // copy constructor
		Animal &operator=(const Animal &copy); // assignment operator

		// Member functions
		virtual void	makeSound() const;
		//getter
		std::string getType() const;
		
};

#endif