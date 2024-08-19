/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:31:06 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:32:39 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string& target); // constructor
		PresidentialPardonForm(const PresidentialPardonForm& copy); // copy constructor
		~PresidentialPardonForm(); // destructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy); // copy assignment operator
		
		void	action() const;

	private:
		const std::string	target;
};

#endif