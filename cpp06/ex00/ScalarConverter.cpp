/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/21 16:30:32 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return (*this);
}

void    ScalarConverter::convert(const std::string& literal)
{
    // try pseudo-literals to float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        float   floatValue = std::strtof(literal.c_str(), NULL);
        double  doubleValue = static_cast<double>(floatValue);
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << floatValue << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return ;
    }
    // try pseudo-literals to double
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        double  doubleValue = std::strtod(literal.c_str(), NULL);
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(doubleValue) << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return ;
    }
    
    try 
    {   // try to convert to char
        if (literal.length() == 1 && !isdigit(literal[0]))
        {
            char    charValue = literal[0];
            std::cout << "char: '" << charValue << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(charValue) << std::endl;
            std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
            return ;
        }
        // try to convert to int
        char *end;
        errno = 0;
        long inVal = std::strtol(literal.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE || inVal > INT_MAX || inVal < INT_MIN)
            throw std::invalid_argument("Invalid int");
        int intValue = static_cast<int>(inVal);
        std::cout << "char: ";
        if (intValue >= 0 && intValue <= 127 && isprint(intValue))
            std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
        return ;
    }
    catch (std::invalid_argument &e)
    {
        
    }
    catch (std::out_of_range &e)
    {
        
    }

    try
    {   // try to convert to float
        char *end;
        errno = 0;
        float floatValue = std::strtof(literal.c_str(), &end);
        if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE)
            throw std::invalid_argument("Invalid float");
        std::cout << "char: ";
        if (floatValue >= 0 && floatValue <= 127 && isprint(static_cast<int>(floatValue)))
            std::cout << "'" << static_cast<char>(floatValue) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
        std::cout << std::fixed << std::setprecision(1); // set precision to 1 decimal
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
        return ;
    }
    catch (std::invalid_argument &e)
    {
        
    }
    catch (std::out_of_range &e)
    {
        
    }
    
    try
    {
        // try to convert to double
        char *end;
        errno = 0;
        double doubleValue = std::strtod(literal.c_str(), &end);
        if (*end != '\0' || errno == ERANGE)
            throw std::invalid_argument("Invalid double");
        std::cout << "char: ";
        if (doubleValue >= 0 && doubleValue <= 127 && isprint(static_cast<int>(doubleValue)))
            std::cout << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
        std::cout << std::fixed << std::setprecision(1); // set precision to 1 decimal
        std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return ;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid literal" << std::endl;   
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Out of range literal" << std::endl;   
    }
}