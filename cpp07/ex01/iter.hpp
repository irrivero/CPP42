/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:40:01 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 15:51:07 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

// T *array means that T is a pointer to an array of any type
// length means the length of the array
// f means the function to be applied to each element of the array (takes a reference of an T object and returns nothing)
template <typename T>
void	iter(T *array, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; ++i)	// loop that goes through all the elements of the array
		f(array[i]);					// calls the f function to each elemente og the array
}

#endif
