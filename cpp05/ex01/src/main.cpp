/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 16:07:54 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
try {
    Bureaucrat bob("Bob", 50);
    Form formA("FormA", 49, 10);
    Form formB("FormB", 60, 10);
	std::cout << std::endl;

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

	std::cout << std::endl;
    std::cout << YELLOW << "Bob tries to sign FormA." << RESET << std::endl;
    try {
    bob.signForm(formA); // Should fail because Bob's grade is too low
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
	std::cout << std::endl;
    std::cout << YELLOW << "Bob tries to sign FormB." << RESET << std::endl;
    try {
    bob.signForm(formB); // Should succeed
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
	std::cout << std::endl;
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    std::cout << std::endl;
	std::cout << YELLOW << "We increment Bob's grade to 49" << RESET << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
    try {
	bob.signForm(formA);
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << formA << std::endl;
}
catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
}
    return 0;
}
