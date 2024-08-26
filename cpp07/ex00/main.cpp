/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:39:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 15:05:46 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int	x = 42;
	int y = 24;

	std::cout << YELLOW << "initial int values:" << RESET << std::endl;
	std::cout << "x = " << x << ", y = " << y << RESET << std::endl;

	std::cout << std::endl;
	//test swap function
	std::cout << YELLOW << "swapping x and y.." << RESET << std::endl;
	swap(x, y);
	std::cout << std::endl;
	std::cout << YELLOW <<"After swap:\n" << RESET << "x = " << x << ", y = " << y << RESET << std::endl;
	std::cout << std::endl;
	//test max function
	std::cout << CYAN << "max(x, y)" << RESET << " = " << max(x, y) << std::endl;
	std::cout << std::endl;
	//test min function
	std::cout << CYAN << "min(x, y)" << RESET << " = " << min(x, y) << std::endl;

	double a = 42.42;
	double b = 24.24;
	
	std::cout << std::endl;
	std::cout << YELLOW << "initial double values:" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW <<"swapping a and b..." << RESET <<std::endl;
	swap(a, b);
	std::cout << std::endl;
	std::cout << YELLOW << "After swap:\n" << RESET << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "max(a, b)" << RESET << " = " << max(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "min(a, b)" << RESET << " = " << min(a, b) << std::endl;

	return (0);
}