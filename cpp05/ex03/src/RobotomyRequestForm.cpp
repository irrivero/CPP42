/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:27:06 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:37:24 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << CYAN << "Creating RobotomyRequestForm with target <" << target << ">" << RESET << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this == &copy)
		AForm::operator=(copy);
	return *this;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "* drilling noises * " << std::endl;
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}