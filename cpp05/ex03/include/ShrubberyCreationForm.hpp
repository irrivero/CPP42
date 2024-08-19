/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:09:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:22:23 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target); // constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& copy); // copy constructor
		~ShrubberyCreationForm();	// destructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy); // copy assignment operator

		void	action() const;

	private:
		const std::string	target;
};

#endif