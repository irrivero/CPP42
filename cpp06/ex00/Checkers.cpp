/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checkers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:31:20 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/23 10:02:03 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

bool    ScalarConverter::isPseudo(const std::string& literal)
{
    return (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
            literal == "nan" || literal == "+inf" || literal == "-inf");
}

bool    ScalarConverter::isDigit(char c)
{
    if (isdigit(c))
        return (true);
    if (c == '+' || c == 'F' || c == 'e') 
        return (true);
    return (false);
}
bool    ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return (false);
    size_t  i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            return (false);
    }
    return (i > 1 || (i == 1 && isdigit(literal[0])));
}

bool    ScalarConverter::isDouble(const std::string& literal)
{
   if (literal.empty())
        return (false);
    size_t  i = 0;
    bool    decimalPoint = false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (decimalPoint)
                return (false);
            decimalPoint = true;
        }
        else if (!isDigit(literal[i]))
            return (false);
    }
    return (decimalPoint && i > 1);
}

bool    ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty())
        return (false);
    size_t  i = 0;
    bool    decimalPoint = false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (decimalPoint)
                return (false);
            decimalPoint = true;
        }
        else if (literal[i] == 'f')
            return (i == literal.length() - 1);
        else if (!isDigit(literal[i]))
            return (false);
    }
    return (decimalPoint && i > 1);
}

bool    ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 1 && isprint(literal[0]));
}