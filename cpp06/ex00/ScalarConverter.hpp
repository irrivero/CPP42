/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:23:44 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/23 11:41:52 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstring>
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



#endif
