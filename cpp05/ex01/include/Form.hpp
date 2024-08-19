/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:01:07 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:42 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class 	Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute); // constructor
		Form(const Form& copy); // copy constructor
		Form& operator=(const Form& copy);	// copy assignment operator
		~Form(); // destructor

		// Getters
		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		// Member functions
		void				beSigned(const Bureaucrat& b);
		
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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif