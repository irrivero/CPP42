/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:32 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/09 16:34:34 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {
    try {
        Span sp(5);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Testing with 10,000 numbers
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(i);
        }
        std::cout << "Shortest Span (10,000 numbers): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (10,000 numbers): " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
