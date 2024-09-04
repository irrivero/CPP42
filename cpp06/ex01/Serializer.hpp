/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:37:02 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/04 11:41:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
};

#endif

// serializer/deserializer: to convert pointers to data and back
// uintptr_t: an unsigned integer type that is capable of storing a data pointer
// reinterpret_cast: a type cast expression that changes the type of a pointer