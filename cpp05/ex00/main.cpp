/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 14:47:09 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try 
	{
		Bureaucrat	bureaucrat("Irene", 1); // grade 1 to 150 is ok
		std::cout << bureaucrat << std::endl;
		std::cout << YELLOW << "Incrementing grade to 0 (invalid)" << RESET << std::endl;
		bureaucrat.incrementGrade();		// incrementing grade (too high)
		std::cout << bureaucrat << std::endl; // should not be displayed
	}
	catch (std::exception &e) 				// catching exceptions
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat	bureaucrat("Irene", 150); // grade 1 to 150 is ok
		std::cout << bureaucrat << std::endl;
		std::cout << YELLOW << "Decrementing grade to 151 (invalid)" << RESET << std::endl;
		bureaucrat.decrementGrade();		// decrementing grade (too low)
		std::cout << bureaucrat << std::endl; // should not be displayed
	}
	catch(const std::exception& e)			// catching exceptions
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	bureaucrat("Irene", 75); // grade 1 to 150 is ok
		std::cout << bureaucrat << std::endl;
		std::cout << YELLOW << "Incrementing and decrementing grade" << RESET << std::endl;
		bureaucrat.decrementGrade();		// decrementing grade
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();		// incrementing grade
		std::cout << bureaucrat << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << YELLOW << "This throws an exception directly: " << RESET << std::endl;
		Bureaucrat	invalid("Invalid", 0); // grade 1 to 150 is ok so 0 is invalid
		std::cout << invalid << std::endl; // should not be displayed
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}
