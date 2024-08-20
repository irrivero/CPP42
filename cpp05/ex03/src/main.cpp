/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:42:49 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 14:59:36 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) 
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("The Boss", 1);
        
        std::cout << std::endl;
        // Creates a robotomy request form
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;

        std::cout << std::endl;
        // creates a shrubbery creation form
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;

        std::cout << std::endl;
        // try to create an unknown form (throws exception)
        AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Nowhere");
        if (unknownForm)
            delete unknownForm;
        std::cout << std::endl;
    }
    catch (const Intern::FormNotFoundException& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
