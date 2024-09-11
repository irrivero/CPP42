/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:26:10 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/11 12:39:28 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
		
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);

		// Add number to the Span
		void	addNumber(int number);
		// Add range of numbers to the Span
		void	addIntoRange(int start, int end);
		
		// Find shortest and longest span
		int		shortestSpan();
		int		longestSpan();
};

#endif