/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:18:01 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 14:50:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << CYAN << "A new intern is here" << RESET << std::endl;
}

Intern::Intern(const Intern& copy) { *this = copy; }

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern() {}

AForm*  Intern::createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createPresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* (Intern::*formCreators[])(const std::string&) = 
    {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << YELLOW << "Intern creates " << formName << RESET << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}