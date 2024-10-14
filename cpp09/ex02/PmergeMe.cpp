/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:33 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/14 15:55:02 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &sequence)
{
	this->vectorSequence = sequence;
	this->dequeSequence.insert(dequeSequence.begin(), sequence.begin(), sequence.end());
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->vectorSequence = copy.vectorSequence;
		this->dequeSequence = copy.dequeSequence;
	}
	return (*this);
}

std::vector<int> PmergeMe::validateInput(int argc, char **argv)
{
	std::vector<int> sequence;
	
	try
	{
		for (int i = 1; i < argc; i++)
		{
			int num = std::atoi(argv[i]);
			if (num <= 0)
				throw std::invalid_argument("Only positive numbers are allowed");
			sequence.push_back(num);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		throw;
	}
	return (sequence);
}

void	PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = this->vectorSequence.begin(); it != this->vectorSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::displayAfter() const
{
	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = this->dequeSequence.begin(); it != this->dequeSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Algorithm from Ford-Johnson using merge sort
void	PmergeMe::mergeInsertSortVector()
{
	std::vector<int> sorted;
	
	for (std::vector<int>::iterator it = this->vectorSequence.begin(); it != this->vectorSequence.end(); it++)
	{
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);
	}
	this->vectorSequence = sorted;
}

void	PmergeMe::mergeInsertSortDeque()
{
	std::deque<int> sorted;
	for (std::deque<int>::iterator it = this->dequeSequence.begin(); it != this->dequeSequence.end(); it++)
	{
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);
	}
	this->dequeSequence = sorted;
}

long	PmergeMe::timeVectorSort()
{
	clock_t start = clock();
	mergeInsertSortVector();
	clock_t end = clock();
	return ((end - start) * 1000000 / CLOCKS_PER_SEC);
}

long	PmergeMe::timeDequeSort()
{
	clock_t start = clock();
	mergeInsertSortDeque();
	clock_t end = clock();
	return ((end - start) * 1000000 / CLOCKS_PER_SEC);
}

void	PmergeMe::displaySortingTimes(long vectorTime, long dequeTime) const
{
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::vector : "
			<< vectorTime << " us." << std::endl;
	std::cout << "Time to process a range of " << dequeSequence.size() << " elements with std::deque : "
			<< dequeTime << " us." << std::endl;
}