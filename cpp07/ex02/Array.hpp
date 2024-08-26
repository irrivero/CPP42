/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:01:27 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 16:28:50 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#define CYAN "\e[36m"
#define RESET "\e[0m"
#define RED "\e[91m"

template <typename T>
class Array
{
	public:
		Array();							// Default constructor
		Array(unsigned int n);				// Constructor with size
		Array(const Array &src);			// Copy constructor
		Array &operator=(const Array &src);	// Assignment operator
		~Array(); 							// Destructor

		// Access operator
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		// Member function
		unsigned int size() const;
		
	private:
		T				*_array;
		unsigned int	_size;	
};

#include "Array.tpp" // include implementation of template methods

#endif