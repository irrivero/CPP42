/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:41:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 15:56:21 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(int &n) 
{
    std::cout << n << " ";
}

void incrementInt(int &n) 
{
    ++n;
}

void printDouble(double &n) 
{
    std::cout << n << " ";
}

void incrementDouble(double &n) 
{
    ++n;
}

void printChar(char &c)
{
	std::cout << c << " ";
}

void	incrementChar(char &c)
{
	c--;
}

int main() 
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "INT\nOriginal int array: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    std::cout << "Incremented int array: ";
    iter(intArray, intArraySize, incrementInt);
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << std::endl;
    std::cout << "DOUBLE\nOriginal double array: ";
    iter(doubleArray, doubleArraySize, printDouble);
    std::cout << std::endl;

    std::cout << "Incremented double array: ";
    iter(doubleArray, doubleArraySize, incrementDouble);
    iter(doubleArray, doubleArraySize, printDouble);
    std::cout << std::endl;

	char charArray[] = {'b', 'c', 'd', 'e', 'f'};
	size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << std::endl;
	std::cout << "CHAR\nOriginal char array: ";
	iter(charArray, charArraySize, printChar);
	std::cout << std::endl;
	
	std::cout << "Decremented char array: ";
	iter(charArray, charArraySize, incrementChar);
	iter(charArray, charArraySize, printChar);
	std::cout << std::endl;

    return 0;
}
