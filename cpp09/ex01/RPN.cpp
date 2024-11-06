/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:02:02 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/06 15:10:50 by irivero-         ###   ########.fr       */
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
		// If token is a number, push it onto the stack
		if (isdigit(token[0]))
		{
			//int num = std::stoi(token);
			std::stringstream ss(token);
			int num;
			ss >> num;
			if (num >= 10)
			{
				std::cerr << "Error: numbers used must be less than 10" << std::endl;
				return (1);
			}
			stack.push(num);
		}
		// If token is an operator, pop two elements and perform the operation
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// Check for at least two operands in the stack
			if (stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return (1);
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
				result = num1 / num2;

			// Push the result back onto the stack
			stack.push(result);
		}
		// Handle invalid tokens
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return (1);
		}
	}

	// The result should be the only value remaining in the stack
	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (1);
	}
	return (stack.top()); // Return the final result
}
