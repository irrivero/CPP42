/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:32 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/02 11:29:25 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

// int main() {
//     try {
//         Span sp(5);
        
//         std::cout << "Adding numbers 1 to 5" << std::endl;
//         sp.addIntoRange(1, 5);

//         std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

//         std::cout << std::endl;

//         // std::cout << "Adding number 10" << std::endl;
//         // sp.addNumber(10); // should throw an exception

//         // std::cout << std::endl;

//         std::cout << "Adding numbers 1 to 124" << std::endl;
//         Span sp2(124);
//         sp2.addIntoRange(1, 124);
//         std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
//         std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
        
//         std::cout << std::endl;
//         // Testing with 10,000 numbers
//         std::cout << "Adding numbers 0 to 9999" << std::endl;
//         Span bigSpan(10000);
//         for (int i = 0; i < 10000; ++i) {
//             bigSpan.addNumber(i);
//         }
//         std::cout << "Shortest Span (10,000 numbers): " << bigSpan.shortestSpan() << std::endl;
//         std::cout << "Longest Span (10,000 numbers): " << bigSpan.longestSpan() << std::endl;

//     } catch (std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}