/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:42:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:59:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 14:24:44 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
    Bureaucrat ire("Irene", 50);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("robot");
    PresidentialPardonForm pardon("Alice");

    ire.signForm(shrubbery);
    ire.executeForm(shrubbery); // Ire should be able to execute ShrubberyCreationForm

    ire.signForm(robotomy);
    ire.executeForm(robotomy); // Ire might execute form with 50% success rate

    ire.signForm(pardon); // Ire's grade is too low to sign form
    ire.executeForm(pardon); // Ire can't execute form cause it's not signed

    return 0;
}
