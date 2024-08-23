/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/23 10:09:56 by irivero-         ###   ########.fr       */
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

void   ScalarConverter::printPseudo(const std::string &str)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << (str == "nanf" ? "nan" : str.substr(0, str.length() - 1)) << std::endl;
    }
    else
    {
        std::cout << "float: " << (str == "nan" ? "nanf" : str + "f") << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

void    ScalarConverter::printChar(char value)
{
    // if (value < 0 || value > 255)
    // {
    //     std::cout << "char: Impossible" << std::endl;
    //     return ;
    // }
    int    c = static_cast<char>(value);
    std::cout << "char: " << (c > 127 || c < 0 ? "Impossible" 
        : (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable")) << std::endl;
    std::cout << "int: " << c << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void    ScalarConverter::printInt(int value)
{
    //printChar(value);
    std::cout << "char: " << (value > 127 || value < 0 ? "Impossible"
        : (std::isprint(value) ? "'" + std::string(1, value) + "'" : "Non displayable")) << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void    ScalarConverter::printFloat(float value)
{
    std::cout << "char: ";
    if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: ";
    // if (value > static_cast<float>(INT_MAX) || value < static_cast<float>(INT_MIN) || std::floor(value) != value)
    //     std::cout << "Impossible" << std::endl;
    // else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void    ScalarConverter::printDouble(double value)
{
    std::cout << "char: ";
    if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: ";
    // if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN) || std::floor(value) != value)
    //     std::cout << "Impossible" << std::endl;
    // else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;

}
void    ScalarConverter::printExceptionMax()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: " << "2147483647" << std::endl;
    std::cout << "float: " << "2147483647.0f" << std::endl;
    std::cout << "double: " << "2147483647.0" << std::endl;
    
}

void    ScalarConverter::printExceptionMin()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: " << "-2147483648" << std::endl;
    std::cout << "float: " << "-2147483648.0f" << std::endl;
    std::cout << "double: " << "-2147483648.0" << std::endl;
}

void    ScalarConverter::convert(const std::string& literal)
{
    if (std::atoi(literal.c_str()) >= INT_MAX)
        printExceptionMax();
    else if (std::atoi(literal.c_str()) <= INT_MIN)
        printExceptionMin();
    else if (literal.size() == 1)
    {
        if (std::isdigit(literal[0]))
            printInt(std::atoi(literal.c_str()));
        else
            printChar(literal[0]);
    }
    else if (isPseudo(literal))
        printPseudo(literal);
    else if (isInt(literal))
        printInt(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        printFloat(std::atof(literal.c_str()));
    else if (isDouble(literal))
    {
        char    *end;
        printDouble(std::strtod(literal.c_str(), &end));
        if (*end)
            std::cout << "Invalid input" << std::endl;
    }
    else
        std::cout << "Invalid input" << std::endl;
}