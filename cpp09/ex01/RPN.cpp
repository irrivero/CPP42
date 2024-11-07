/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:02:02 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/07 16:27:18 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Copy constructor
RPN::RPN(const RPN &other) 
{
	(void)other; // Since there's no dynamic data, no need to copy anything
}

// Copy assignment operator
RPN &RPN::operator=(const RPN &other) 
{
	(void)other; // Same here; no data to copy
	return (*this);
}

// Main calculation function for Reverse Polish Notation expressions
int RPN::calculate(const std::string &expression) 
{
	// Use a stack to manage operands and intermediate results
	std::stack<int> stack;
	std::istringstream iss(expression); // Stream to tokenize the input expression
	std::string token;

	// Loop through each token in the expression
	while (iss >> token)
	{
		// If token is a single-digit number, push it onto the stack
		if (token.size() == 1 && isdigit(token[0])) 
		{
			int num = token[0] - '0'; // Convert character to integer
			stack.push(num);
		}
		// If token is an operator, pop two elements and perform the operation
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// Check for at least two operands in the stack
			if (stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return (-42);
			}
			int num2 = stack.top(); stack.pop(); // Pop the top element (second operand)
			int num1 = stack.top(); stack.pop(); // Pop the next element (first operand)
			int result;

			// Perform the operation based on the operator
			if (token == "+")
				result = num1 + num2;
			else if (token == "-")
				result = num1 - num2;
			else if (token == "*")
				result = num1 * num2;
			else if (token == "/")
			{
				// Check for division by zero
				if (num2 == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return (-42); // Exit with an error
				}
				result = num1 / num2;
			}

			// Push the result back onto the stack
			stack.push(result);
		}
		// Handle invalid tokens
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return (-42);
		}
	}

	// The result should be the only value remaining in the stack
	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (-42);
	}

	//std::cout << "Result: " << stack.top() << std::endl; // Output the final result
	return (stack.top());
}
