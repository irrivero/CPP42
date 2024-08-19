/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:06:15 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 15:31:19 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << CYAN << "Creating Form with name <" << name << "> and grade to sign <" 
	<< gradeToSign << "> and grade to execute <"
	<< gradeToExecute << ">" << RESET << std::endl;
	
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : name(copy.name), signedStatus(copy.signedStatus), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		this->signedStatus = copy.signedStatus;
	return (*this);
}

Form::~Form() {}

const	std::string&	Form::getName() const { return (this->name); }

bool	Form::getSignedStatus() const { return (this->signedStatus); }

int		Form::getGradeToSign() const { return (this->gradeToSign); }

int		Form::getGradeToExecute() const { return (this->gradeToExecute); }

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeToSign)
		this->signedStatus = true;
	else
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw() { return ("\033[31mGrade is too high\033[0m"); }

const char	*Form::GradeTooLowException::what() const throw() { return ("\033[31mGrade is too low\033[0m"); }

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << GREEN <<"Form: " << f.getName() << ", signed: " << (f.getSignedStatus() ? "yes" : "no")
	<< ", grade to sign: " << f.getGradeToSign() 
	<< ", grade to execute: " << f.getGradeToExecute() << RESET;
	return (os);
}