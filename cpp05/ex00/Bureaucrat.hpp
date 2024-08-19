/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:40:46 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 14:32:24 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define RESET   "\033[0m"
#define RED     "\033[31m"          /* Red */
#define GREEN   "\033[32m"          /* Green */
#define YELLOW  "\033[33m"          /* Yellow */
#define BLUE    "\033[34m"          /* Blue */
#define MAGENTA "\033[35m"          /* Magenta */
#define CYAN    "\033[36m"          /* Cyan */
#define WHITE   "\033[37m"          /* White */

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat(std::string const &name, int grade); // constructor
		Bureaucrat(const Bureaucrat &copy); // copy constructor
		~Bureaucrat(); // destructor
		Bureaucrat &operator=(const Bureaucrat &copy); // copy assignment operator

		// Getters
		const std::string	&getName() const;
		int					getGrade() const;

		void		incrementGrade();
		void		decrementGrade();

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
