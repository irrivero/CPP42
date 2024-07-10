/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/10 17:04:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto: Inicializa el valor a 0.
Fixed::Fixed() : _value(0) {}

// Constructor de copia: Crea una copia de un objeto Fixed.
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

/**
 * Destructor for the Fixed class.
 *
 * This destructor is called when an instance of the Fixed class is destroyed.
 */
Fixed::~Fixed() {}

// Operador de asignación: Asigna el valor de un objeto Fixed a otro.
Fixed	&Fixed::operator=(const Fixed &copy)
{
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
	//std::cout << "getRawBits member function called" << std::endl;
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

Fixed::Fixed(const int value) : _value(value << Fixed::_fractionalBits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << Fixed::_fractionalBits))) {}

float	Fixed::toFloat( void ) const
{
	return (float)this->getRawBits() / (1 << Fixed::_fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

// ex02

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++() // prefix
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int) // postfix
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--() // prefix
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int) // postfix
{
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}