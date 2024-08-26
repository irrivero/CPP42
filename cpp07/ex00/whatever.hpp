/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:38:08 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 15:02:53 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#define RESET "\e[0m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"

// template function to swap to values
template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// template function to return the minimum value
template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

// template function to return the maximum value
template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif