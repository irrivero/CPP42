/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:20:29 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/06 12:50:27 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructor: Initializes the vector and deque sequences with the provided input sequence
PmergeMe::PmergeMe(const std::vector<int> &sequence)
{
	// Initialize both vector and deque with the provided sequence
	this->vectorSequence = sequence;
	this->dequeSequence.insert(dequeSequence.begin(), sequence.begin(), sequence.end());
}

// Destructor
PmergeMe::~PmergeMe() {}

// Copy constructor: Performs a shallow copy of another PmergeMe object
PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy; // Calls the copy assignment operator
}

// Assignment operator: Copies the state of another PmergeMe object
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	// Prevent self-assignment
	if (this != &copy)
	{
		// Copy the vector and deque sequences
		this->vectorSequence = copy.vectorSequence;
		this->dequeSequence = copy.dequeSequence;
	}
	return (*this);
}

// Validates input by converting arguments into a vector of positive integers
std::vector<int> PmergeMe::validateInput(int argc, char **argv)
{
	std::vector<int> sequence;
	
	try
	{
		// Iterate over the input arguments, starting from index 1
		for (int i = 1; i < argc; i++)
		{
			int num = std::atoi(argv[i]); // Convert argument to integer
			if (num <= 0)
				throw std::invalid_argument("Only positive numbers are allowed"); // Throw exception if non-positive number
			sequence.push_back(num); // Add valid number to the sequence
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl; // Catch and display any exception thrown
		throw; // Rethrow the exception
	}
	return (sequence);
}

// Display the vector before sorting
void	PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = this->vectorSequence.begin(); it != this->vectorSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Display the deque after sorting
void	PmergeMe::displayAfter() const
{
	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = this->dequeSequence.begin(); it != this->dequeSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Sorting algorithm using the Ford-Johnson merge-insert sort for vector
void PmergeMe::mergeInsertSortVector() 
{
    std::vector<std::pair<int, int> > pairs;
    
    // Step 1: Split into pairs and sort each pair
    for (size_t i = 0; i + 1 < vectorSequence.size(); i += 2) {
        if (vectorSequence[i] > vectorSequence[i + 1]) {
            pairs.push_back(std::pair<int, int>(vectorSequence[i + 1], vectorSequence[i]));
        } else {
            pairs.push_back(std::pair<int, int>(vectorSequence[i], vectorSequence[i + 1]));

        }
    }
    // Handle odd number of elements by adding a pair with max value
    if (vectorSequence.size() % 2 != 0) {
        pairs.push_back(std::make_pair(vectorSequence.back(), INT_MAX));
    }

    // Step 2: Create sorted min and max lists
    std::vector<int> minList, maxList;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::pair<int, int>& p = *it;  // Dereference iterator to access the pair
        minList.push_back(p.first);    // Access the first element of the pair
        maxList.push_back(p.second);   // Access the second element of the pair
    }


    // Step 3: Sort the minList
    std::sort(minList.begin(), minList.end());
    std::vector<int> sorted = minList;

    // Step 4: Insert maxList elements into the sorted list
    for (std::vector<int>::iterator it = maxList.begin(); it != maxList.end(); ++it) {
        int max = *it;
        if (max == INT_MAX) continue;
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), max);
        sorted.insert(pos, max);
    }

    // Step 5: Final sorted result
    vectorSequence = sorted;
}

// Sorting algorithm using the Ford-Johnson merge-insert sort for deque
void	PmergeMe::mergeInsertSortDeque()
{
    std::deque<std::pair<int, int> > pairs;
    
    // Step 1: Split into pairs and sort each pair
    for (size_t i = 0; i + 1 < dequeSequence.size(); i += 2) {
        if (dequeSequence[i] > dequeSequence[i + 1]) {
            pairs.push_back(std::pair<int, int>(dequeSequence[i + 1], dequeSequence[i]));
        } else {
            pairs.push_back(std::pair<int, int>(dequeSequence[i], dequeSequence[i + 1]));

        }
    }
    // Handle odd number of elements by adding a pair with max value
    if (dequeSequence.size() % 2 != 0) {
        pairs.push_back(std::make_pair(dequeSequence.back(), INT_MAX));
    }

    // Step 2: Create sorted min and max lists
    std::deque<int> minList, maxList;
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::pair<int, int>& p = *it;  // Dereference iterator to access the pair
        minList.push_back(p.first);    // Access the first element of the pair
        maxList.push_back(p.second);   // Access the second element of the pair
    }

    // Step 3: Sort the minList
    std::sort(minList.begin(), minList.end());
    std::deque<int> sorted = minList;

    // Step 4: Insert maxList elements into the sorted list
    for (std::deque<int>::iterator it = maxList.begin(); it != maxList.end(); ++it) {
        int max = *it;
        if (max == INT_MAX) continue;
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), max);
        sorted.insert(pos, max);
    }

    // Step 5: Final sorted result
    dequeSequence = sorted;
}

// Measure the time taken to sort using vector
long	PmergeMe::timeVectorSort()
{
	clock_t start = clock(); // Start timing
	mergeInsertSortVector(); // Sort using mergeInsertSortVector
	clock_t end = clock(); // End timing
	// Calculate the elapsed time in microseconds
	return ((end - start) * 1000000 / CLOCKS_PER_SEC);
}

// Measure the time taken to sort using deque
long	PmergeMe::timeDequeSort()
{
	clock_t start = clock(); // Start timing
	mergeInsertSortDeque(); // Sort using mergeInsertSortDeque
	clock_t end = clock(); // End timing
	// Calculate the elapsed time in microseconds
	return ((end - start) * 1000000 / CLOCKS_PER_SEC);
}

// Display the sorting times for both vector and deque
void	PmergeMe::displaySortingTimes(long vectorTime, long dequeTime) const
{
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::vector : "
			<< vectorTime << " us." << std::endl;
	std::cout << "Time to process a range of " << dequeSequence.size() << " elements with std::deque : "
			<< dequeTime << " us." << std::endl;
}
