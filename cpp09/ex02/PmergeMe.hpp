/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:24 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/14 15:55:24 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stdexcept>

class PmergeMe
{
	private:
		std::deque<int> dequeSequence;
		std::vector<int> vectorSequence;

	public:
		PmergeMe(const std::vector<int> &sequence);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);

		static std::vector<int> validateInput(int argc, char **argv);
		void displayBefore() const;
		void displayAfter() const;
		void mergeInsertSortVector();
		void mergeInsertSortDeque();
		long timeVectorSort();
		long timeDequeSort();
		void	displaySortingTimes(long vectorTime, long dequeTime) const;
};

/*
 * This program implements the merge-insertion sort algorithm, inspired by the Ford-Johnson algorithm,
 * to sort a sequence of positive integers using both a vector and a deque as containers. The sequence
 * is sorted by inserting each element in the correct position within an already sorted sequence. The
 * program also measures and compares the time taken to sort the sequence with each container.
 */

#endif