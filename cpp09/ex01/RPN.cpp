/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:55:50 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/14 14:02:55 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) 
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other) 
{
	(void)other;
	return (*this);
}

int	RPN::calculate(const std::string &expression) 
{
	std::stack<int>	stack;
	std::istringstream iss(expression);
	std::string		token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
			stack.push(std::stoi(token));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return (1);
			}
			int	num2 = stack.top(); stack.pop();
			int	num1 = stack.top(); stack.pop();
			int	result;

			if (token == "+")
				result = num1 + num2;
			else if (token == "-")
				result = num1 - num2;
			else if (token == "*")
				result = num1 * num2;
			else if (token == "/")
				result = num1 / num2;
			stack.push(result);
		}
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return (1);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (1);
	}
	return (stack.top());
}