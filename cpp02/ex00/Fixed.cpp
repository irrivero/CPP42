/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/10 16:06:11 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto: Inicializa el valor a 0.
Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia: Crea una copia de un objeto Fixed.
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/**
 * Destructor for the Fixed class.
 *
 * This destructor is called when an instance of the Fixed class is destroyed.
 * It prints a message to the console indicating that the destructor has been called.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operador de asignación: Asigna el valor de un objeto Fixed a otro.
Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

/**
 * Get the raw bits of the Fixed object.
 *
 * @return the raw bits value
 */
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/**
 * Sets the raw bits of the Fixed object.
 *
 * @param raw the new raw bits value
 */
void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}