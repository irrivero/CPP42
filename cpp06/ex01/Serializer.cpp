/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:41:47 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 12:01:08 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &copy){ *this = copy; }

Serializer &Serializer::operator=(const Serializer &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}