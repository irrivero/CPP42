/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:11:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 11:28:27 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * Main function that demonstrates memory addresses and values of a string variable.
 *
 * ### Memory Explanation
 * - `stringVAR`: It is a variable of type std::string that is stored on the stack. 
 * 		It has a unique memory address and contains the value "HI THIS IS BRAIN".
 * - `stringPTR`: It is a pointer that stores the memory address of `stringVAR`. 
 * 		When accessing *stringPTR, you get the value of `stringVAR`.
 * - `stringREF`: It is a reference that acts as an alias for `stringVAR`. Both `stringREF`
 * 		and `stringVAR` refer to the same memory block, so any change through `stringREF`
 * 		will directly affect `stringVAR`.
 */
int main()
{
	std::string	stringVAR("HI THIS IS BRAIN");
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	std::cout << "Memory address of the string variable: " << &stringVAR << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the string variable: " << stringVAR << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}