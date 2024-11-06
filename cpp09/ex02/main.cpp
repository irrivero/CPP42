/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:36 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/06 15:33:33 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./pmergeMe [positive integers]" << std::endl;
		return (1);
	}

    std::string arg = av[1];
    bool isNumber = true;

    for (size_t i = 0; i < arg.length(); ++i)
    {
        if (!std::isdigit(arg[i]))
        {
            isNumber = false;
            break;
        }
    }

	if (!isNumber)
	{
        std::cerr << "Error: Invalid argument." << std::endl;
        return (1);
    }
	
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