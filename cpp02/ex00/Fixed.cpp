/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/12 12:23:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor: Initializes the Fixed object with a value of 0.
Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor: Creates a new Fixed object by copying the value from another Fixed object.
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor: Cleans up resources when a Fixed object is destroyed.

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator: Assigns the value from one Fixed object to another.
Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

/**
 * Gets the raw integer value stored in the Fixed object.
 *
 * @return The raw bits value representing the fixed-point number.
 */
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/**
 * Sets the raw integer value in the Fixed object.
 *
 * @param raw The new raw bits value to be stored.
 */
void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
