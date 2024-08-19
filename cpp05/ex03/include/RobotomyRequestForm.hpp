/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:24:17 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:27:48 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target); // constructor
		RobotomyRequestForm(const RobotomyRequestForm& copy); // copy constructor
		~RobotomyRequestForm(); // destructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy); // copy assignment operator
		
		void	action() const;
		
	private:
		const std::string	target;
};

#endif