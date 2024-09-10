/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:19:38 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/10 12:41:57 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdexcept>

    struct Person{
        std::string name;
        int age;
    };

void testArray() 
{
    try {
        Array<int> arr1(7);  // Create an array of 7 integers
        for (unsigned int i = 0; i < arr1.size(); ++i)
            arr1[i] = i * 2;

        std::cout << CYAN << "Array " << RESET << std::endl;
        std::cout << std::endl;
        // Print elements
		std::cout << CYAN << "PRINT	ELEMENTS " << RESET << std::endl;
        for (unsigned int i = 0; i < arr1.size(); ++i)
            std::cout << arr1[i] << " ";
        std::cout << std::endl;
		std::cout << std::endl;

        // Copy constructor
        Array<int> arr2(arr1);
		std::cout << CYAN << "COPY CONSTRUCTOR " <<	RESET << std::endl;
        std::cout << "Copy array elements: ";
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
		std::cout << std::endl;

        // Assignment operator
        Array<int> arr3;
        arr3 = arr1;
		std::cout << CYAN << "ASSIGNMENT OPERATOR " << RESET << std::endl;
        std::cout << "Assigned array elements: ";
        for (unsigned int i = 0; i < arr3.size(); ++i)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;
		std::cout << std::endl;

        // Test out of range access
        std::cout << "Trying to access out of range index: " << std::endl;
        std::cout << arr1[10] << std::endl;  // Should throw exception
    } 
	catch (const std::out_of_range& e)
	{
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
    std::cout << std::endl;
}

void    testStruct()
{
    try {
    std::cout << std::endl;
    std::cout << CYAN << "Struct " << RESET << std::endl;
    std::cout << std::endl;
    Array<Person> arr(3);
    arr[0].name = "Alice";
    arr[0].age = 25;
    arr[1].name = "Bob";
    arr[1].age = 30;
    arr[2].name = "Charlie";
    arr[2].age = 35;

    std::cout << CYAN << "Array of persons: " << RESET << std::endl;
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << "Name: " << arr[i].name << ", Age: " << arr[i].age << std::endl;
    std::cout << std::endl;
    
    std::cout << "Trying to access out of range index: " << std::endl;
    std::cout << arr[5].name << std::endl;  // Should throw exception
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

void emptyArray()
{
    Array<int> arr;
    std::cout << std::endl;
    std::cout << CYAN << "Empty array " << RESET << std::endl;
    std::cout << std::endl;
    std::cout << "Size: " << arr.size() << std::endl;
}

int main() 
{
    testArray();
    std::cout << "------------------------------------------" << std::endl;
    testStruct();
    std::cout << "------------------------------------------" << std::endl;
    emptyArray();
    return 0;
}
