/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:35:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/14 14:44:22 by irivero-         ###   ########.fr       */
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
		// one function at least pure virtual and = 0, so it can be converted in an abstract class
		virtual void	makeSound() const = 0; //
		//getter
		std::string getType() const;
		
};

#endif