/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:18:34 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 14:54:30 by irivero-         ###   ########.fr       */
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

	ofs << "    ###\n"
        << "   #o###\n"
        << " #####o###\n"
        << "#o#\\#|#/###\n"
        << " ###\\|/#o#\n"
        << "  # }|{  #\n"
        << "    }|{\n";
    ofs.close();
}