/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:27:06 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 16:15:23 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::srand(std::time(0));
	std::cout << CYAN << "Creating RobotomyRequestForm with target <" << target << ">" << RESET << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), target(copy.target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	std::srand(std::time(0));
	if (this == &copy)
		AForm::operator=(copy);
	return *this;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "* drilling noises * " << std::endl;
	if ((rand() % 100) > 50)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}