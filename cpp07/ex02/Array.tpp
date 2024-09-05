/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:09:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/05 13:52:36 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>	// constructor with size n (creates an array of n elements)
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& src) : _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>&Array<T>::operator=(const Array& src)
{
	if (this != &src) 		// avoid self-assignment
	{
		delete[] _array;	// delete the old array
		_size = src._size;	// copy the size
		_array = new T[_size];	// create a new array of the same size
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];	// copy each element
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

// Access operator[]: allow access to the elements of the array with index
// Returns a reference to the element at the specified index
// This one allows modification of the elements
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_array[index]);
}

// Access operator[]: allow access to the elements of the array with index
// Returns a constant reference to the element at the specified index
// This one does not allow modification of the elements (const version)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
