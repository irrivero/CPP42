/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:37:03 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 14:20:33 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        std::cout << "  Literals: char, int, float, double" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}