/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:36 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/14 15:55:11 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::vector<int> sequence;
	try
	{	
		sequence = PmergeMe::validateInput(ac, av);
	}
	catch(...)
	{
		return (1);
	}
	PmergeMe pmerge(sequence);
	pmerge.displayBefore();
	long vectorTime = pmerge.timeVectorSort();
	long dequeTime = pmerge.timeDequeSort();
	pmerge.displayAfter();
	pmerge.displaySortingTimes(vectorTime, dequeTime);
	return (0);
}