/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 15:44:00 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
    Bureaucrat bob("Bob", 50);
    Form formA("FormA", 49, 10);
    Form formB("FormB", 60, 10);
	std::cout << std::endl;

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

	std::cout << std::endl;
    std::cout << YELLOW << "Bob tries to sign FormA." << RESET << std::endl;
    bob.signForm(formA); // Should fail because Bob's grade is too low

	std::cout << std::endl;
    std::cout << YELLOW << "Bob tries to sign FormB." << RESET << std::endl;
    bob.signForm(formB); // Should succeed

	std::cout << std::endl;
    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

	std::cout << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
	bob.signForm(formA);
	std::cout << formA << std::endl;
	
    return 0;
}
