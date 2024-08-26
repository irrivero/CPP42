/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 14:18:44 by irivero-         ###   ########.fr       */
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
    std::cout << "int:  Impossible" << std::endl;
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "float:  " << str << std::endl;
        std::cout << "double: " << (str == "nanf" ? "nan" : str.substr(0, str.length() - 1)) << std::endl;
    }
    else
    {
        std::cout << "float:  " << (str == "nan" ? "nanf" : str + "f") << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

void    ScalarConverter::printChar(char value)
{
    int    c = static_cast<char>(value);
    std::cout << "char:   " << (c > 127 || c < 0 ? "Impossible" 
        : (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable")) << std::endl;
    std::cout << "int:    " << c << std::endl;
    std::cout << "float:  " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void    ScalarConverter::printInt(int value)
{
    //printChar(value);
    std::cout << "char:   " << (value > 127 || value < 0 ? "Impossible"
        : (std::isprint(value) ? "'" + std::string(1, value) + "'" : "Non displayable")) << std::endl;
    std::cout << "int:    " << value << std::endl;
    std::cout << "float:  " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}
void ScalarConverter::printFloat(float value)
{
    std::cout << "char:   ";
    if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int:    ";
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float:  ";
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(5) << value << "f" << std::endl;

    std::cout << "double: ";
    if (static_cast<double>(value) == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    else
        std::cout << std::fixed << std::setprecision(5) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "char:   ";
    if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int:    ";
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float:  ";
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(5) << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: ";
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << std::fixed << std::setprecision(5) << value << std::endl;
}

void    ScalarConverter::convert(const std::string& literal)
{
    if (literal.size() == 1 && !std::isdigit(literal[0]))
            printChar(literal[0]);
    else if (isPseudo(literal))
        printPseudo(literal);
    else if (isInt(literal))
    {
        long    l = std::strtol(literal.c_str(), nullptr, 10);
        if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
            std::cout << RED << "Impossible: Overflow in the literal value" << RESET <<std::endl;
        else
            printInt(static_cast<int>(l));
    }
    else if (isFloat(literal))
    {
        float    f = std::strtof(literal.c_str(), nullptr);
        if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
            std::cout << RED << "Impossible: Overflow in the literal value" << RESET <<std::endl;
        else
            printFloat(f);
    }
    else if (isDouble(literal))
    {
        double    f = std::strtod(literal.c_str(), nullptr);
        if (f > std::numeric_limits<double>::max() || f < std::numeric_limits<double>::min())
            std::cout << RED << "Impossible: Overflow in the literal value" << RESET <<std::endl;
        else
            printDouble(f);
    }
    else
        std::cout << RED <<"Invalid input\n" << RESET << "Enter char, int, float or double" << std::endl;
}