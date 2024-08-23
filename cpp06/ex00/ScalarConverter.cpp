/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/23 12:14:48 by irivero-         ###   ########.fr       */
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
    if (std::numeric_limits<int>::max() < value || std::numeric_limits<int>::min() > value)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: ";
    if (std::numeric_limits<float>::max() < static_cast<float>(value) || std::numeric_limits<float>::min() > static_cast<float>(value))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << value << (value == std::floor(value) ? ".0f" : "f") << std::endl;
    std::cout << "double: ";
    double    d = static_cast<double>(value);
    if (std::numeric_limits<double>::max() < d || std::numeric_limits<double>::min() > d)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void    ScalarConverter::printDouble(double value)
{
    std::cout << "char: ";
    if (value < 0 || value > 255 || !std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: ";
    if (std::numeric_limits<int>::max() < value || std::numeric_limits<int>::min() > value)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: ";
    float    f = static_cast<float>(value);
    if (std::numeric_limits<float>::max() < value|| std::numeric_limits<float>::min() > value)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: ";
    if (std::numeric_limits<double>::max() < value || std::numeric_limits<double>::min() > value)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << value << (value == std::floor(value) ? ".0" : "") << std::endl;
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
            std::cout << "Impossible" << std::endl;
        else
            printInt(static_cast<int>(l));
    }
    else if (isFloat(literal))
    {
        float    f = std::strtof(literal.c_str(), nullptr);
        if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
            std::cout << "Impossible" << std::endl;
        else
            printFloat(f);
    }
        //printFloat(std::atof(literal.c_str()));
    else if (isDouble(literal))
    {
        // char    *endPtr;
        // float    f = std::strtod(literal.c_str(), &endPtr);
        // if (*endPtr == '\0')
        //     std::cout << "Invalid input" << std::endl;
        double    f = std::strtod(literal.c_str(), nullptr);
        if (f > std::numeric_limits<double>::max() || f < std::numeric_limits<double>::min())
            std::cout << "Impossible" << std::endl;
        else
            printDouble(f);
    }
    else
        std::cout << "Invalid input" << std::endl;
}