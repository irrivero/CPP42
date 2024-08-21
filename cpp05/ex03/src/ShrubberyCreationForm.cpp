/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:18:34 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/21 12:56:23 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{
    std::cout << CYAN << "Creating ShrubberyCreationForm with target <" << target << ">" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	ofs((this->target + "_shrubbery").c_str());

    if (!ofs)
    {
        std::cerr << "Error: could not open file " << this->target << "_shrubbery" << std::endl;
        return ;
    }

	ofs << "       ccee88oo\n"
        << "  C8O8O8Q8PoOb o8oo\n"
        << " dOB69QO8PdUOpugoO9bD\n"
        << "CgggbU8OU qOp qOdoUOdcb\n"
        << "    6OuU  /p u gcoUodpP\n"
        << "      \\\\//  /douUP\n"
        << "        \\\\////\n"
        << "         |||/\\\n"
        << "         |||\\/\\\n"
        << "         |||||\\/\n"
        << "   .....//||||\\....\n";
    ofs.close();
}