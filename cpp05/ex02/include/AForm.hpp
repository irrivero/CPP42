/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:01:07 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:09:05 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class 	Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm(const std::string& name, int gradeToSign, int gradeToExecute); // constructor
		AForm(const AForm& copy); // copy constructor
		AForm& operator=(const AForm& copy);	// copy assignment operator
		virtual ~AForm(); // destructor (virtual because we will inherit from it)

		// Getters
		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		// Member functions
		void				beSigned(const Bureaucrat& b);
		void				execute(const Bureaucrat& executor) const;
		virtual void		action() const = 0; // abstract function
		
		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif