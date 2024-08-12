/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/12 12:25:22 by irivero-         ###   ########.fr       */
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
	//std::cout << "getRawBits member function called" << std::endl;
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

//ex01

/**
 * Integer constructor: Converts an integer to the fixed-point format by shifting left
 * by the number of fractional bits and initializes the Fixed object with this value.
 *
 * @param value The integer value to convert and store.
 */
Fixed::Fixed(const int value) : _value(value << Fixed::_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}


/**
 * Float constructor: Converts a floating-point value to the fixed-point format by multiplying
 * by 2^fractionalBits and rounding to the nearest integer. Initializes the Fixed object with this value.
 *
 * @param value The floating-point value to convert and store.
 */
Fixed::Fixed(const float value) : _value(roundf(value * (1 << Fixed::_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

/**
 * Converts the internal fixed-point value to a floating-point number.
 *
 * @return The floating-point representation of the fixed-point value.
 */
float	Fixed::toFloat( void ) const
{
	return (float)this->getRawBits() / (1 << Fixed::_fractionalBits);
}

/**
 * Converts the internal fixed-point value to an integer by shifting
 * right by the number of fractional bits.
 *
 * @return The integer representation of the fixed-point value.
 */
int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_fractionalBits);
}

/**
 * Overloaded stream insertion operator: Allows a Fixed object to be output to a stream.
 * The fixed-point value is first converted to a floating-point number.
 *
 * @param o The output stream.
 * @param i The Fixed object to be inserted into the stream.
 * @return The output stream after insertion.
 */
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

