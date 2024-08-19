/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:42:49 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 17:08:02 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
    // Create some burocrats
	std::cout << CYAN << "Creating Bureaucrats..." << RESET << std::endl << std::endl;
    Bureaucrat ire("Irene", 44);
    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat junior("Junior", 140);
	std::cout << std::endl;

    // Create some forms
	std::cout << CYAN << "Creating Forms..." << RESET << std::endl << std::endl;
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("robot");
    PresidentialPardonForm pardon("Alice");
	std::cout << std::endl;
	
    // Show information about the forms
	std::cout << CYAN << "Information about buros and forms:" << RESET << std::endl;
    std::cout << ire << std::endl;
    std::cout << boss << std::endl;
    std::cout << intern << std::endl;
    std::cout << junior << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

	std::cout << std::endl;
	//trying to sign and execute the forms with junior
    std::cout << CYAN << "\nAttempting to sign and execute ShrubberyCreationForm with Junior:" << RESET << std::endl;
    junior.signForm(shrubbery); // Junior should be able to sign the form
    junior.executeForm(shrubbery); // Junior should not be able to execute the form 
	std::cout << std::endl;

    // trying to sign and execute the forms with irene
    std::cout << CYAN << "\nAttempting to sign and execute RobotomyRequestForm with Irene:" << RESET << std::endl;
    ire.signForm(robotomy); // Ire should be able to sign the form
    ire.executeForm(robotomy); // Ire have to execute the form but will be 50% chance to succeed
	std::cout << std::endl;

    // trying to sign and execute the forms with irene but with the wrong grade
    std::cout << CYAN << "\nAttempting to sign and execute PresidentialPardonForm with Irene:" << RESET << std::endl;
    ire.signForm(pardon); // Ire's grade is too low to sign the form
    ire.executeForm(pardon); // Ire can't execute the form because it's not signed
	std::cout << std::endl;

    // trying to sign and execute the forms with the boss
    std::cout << CYAN << "\nAttempting to sign and execute PresidentialPardonForm with The Boss:" << RESET << std::endl;
    boss.signForm(pardon); // Boss should be able to sign the form
    boss.executeForm(pardon); // Boss should be able to execute the form
	std::cout << std::endl;

    // tryng to sing forms with intern (should fail)
    std::cout << CYAN << "\nAttempting to sign ShrubberyCreationForm with Intern:" << RESET << std::endl;
    intern.signForm(shrubbery); // Intern's grade is too low to sign the form
	std::cout << std::endl;

	// tryng to execute forms with intern (should fail)
    std::cout << CYAN << "\nAttempting to execute an unsigned RobotomyRequestForm with Junior:" << RESET << std::endl;
    junior.executeForm(robotomy); // Form not signed, should throw an exception

	std::cout << std::endl;
	//info about the forms
	std::cout << CYAN << "Information about the forms:" << RESET << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
    return 0;
}
