/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:26:10 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/09 16:28:34 by irivero-         ###   ########.fr       */
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
		
		// Find shortest and longest span
		int		shortestSpan();
		int		longestSpan();
};

#endif