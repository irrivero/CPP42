/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:23:44 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/04 11:43:17 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#define RED "\e[91m"
#define RESET "\e[0m"

#include <cstdlib>
#include <limits>
#include <iostream>
#include <cstring>
#include <cstddef>
#include <string>
#include <cerrno>
#include <cmath>
#include <iomanip> 

class   ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);

        static bool    isPseudo(const std::string& literal);
        static bool    isDigit(char c);
        static bool    isInt(const std::string& literal);
        static bool    isDouble(const std::string& literal);
        static bool    isFloat(const std::string& literal);
        static bool    isChar(const std::string& literal);

        static void    printPseudo(const std::string &str);
        static void    printChar(char value);
        static void    printInt(int value);
        static void    printFloat(float value);
        static void    printDouble(double value);

    public:
        static void     convert(const std::string& literal);
};

// static_cast: a type cast expression that performs conversions between compatible types
// int a = 10;
// double b = static_cast<double>(a); converts int to a double


#endif
