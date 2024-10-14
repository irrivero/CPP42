/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:11:44 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/14 13:56:37 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		int calculate(const std::string &expression);
};


// - Stack: We use a std::stack<int> to store the numbers as we parse the expression.
// - Token Parsing: The std::istringstream is used to split the input string into tokens.
// - Operator Handling: When encountering an operator, two operands are popped from the stack, 
//		the operation is performed, and the result is pushed back onto the stack.
// - Error Handling: The program checks for invalid inputs, such as an operator without 
//		enough operands or an invalid token.

#endif