/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:28:50 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/11 12:39:36 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : _N(copy._N), _numbers(copy._numbers) {}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_N = copy._N;
		this->_numbers = copy._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() < _N) // if span is not full
		_numbers.push_back(number); // add number at the end
	else
		throw std::out_of_range("Span is full"); 
}

void	Span::addIntoRange(int start, int end)
{
	if (end - start + _numbers.size() > _N) // if the range is too big
		throw std::out_of_range("Span is full");
	// add the range of numbers
	for (int i = start; i <= end; ++i)
		_numbers.push_back(i);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find span");
	// copy the numbers in a new vector 
	std::vector<int> tmp = _numbers;
	// sort the vector in ascending order
	std::sort(tmp.begin(), tmp.end());
	// initialize the shortest span with the difference between the first two numbers
	int min = tmp[1] - tmp[0];
	// this loop finds the shortest span by comparing the difference between the next number and the previous one
	for (size_t i = 1; i < tmp.size() - 1; ++i)
		min = std::min(min, tmp[i + 1] - tmp[i]); // updated shortest span comparing with the next number
	return (min);
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find span");
	// return the difference between the largest and the smallest number
	// we use * to dereference the iterator and obtain the value
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}