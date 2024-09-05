/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:13 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/05 17:33:36 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

// define any exception 
class NotFoundException : public std::exception
{
	public:
		const char	*what() const throw()
		{
			return ("Element not found");
		}
};

// function template that searches for the first element in a container
template <typename T>
typename T::iterator	easyfind(T &container, int element)
{
	// we use the std::find function to search for the value in the container
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	// if the value is not found, we throw an exception
	if (it == container.end())
		throw NotFoundException();
	return (it); // return the iterator to the element
}

#endif