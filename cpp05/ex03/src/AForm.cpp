/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:06:15 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 16:06:47 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << CYAN << "Creating Form with name <" << name << "> and grade to sign <" 
	<< gradeToSign << "> and grade to execute <"
	<< gradeToExecute << ">" << RESET << std::endl;
	
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : name(copy.name), signedStatus(copy.signedStatus), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		this->signedStatus = copy.signedStatus;
	return (*this);
}

AForm::~AForm() {}

const	std::string&	AForm::getName() const { return (this->name); }

bool	AForm::getSignedStatus() const { return (this->signedStatus); }

int		AForm::getGradeToSign() const { return (this->gradeToSign); }

int		AForm::getGradeToExecute() const { return (this->gradeToExecute); }

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeToSign)
		this->signedStatus = true;
	else
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw() { return ("\033[31mGrade is too high\033[0m"); }

const char	*AForm::GradeTooLowException::what() const throw() { return ("\033[31mGrade is too low\033[0m"); }

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << GREEN <<"Form: " << f.getName() << ", signed: " << (f.getSignedStatus() ? "yes" : "no")
	<< ", grade to sign: " << f.getGradeToSign() 
	<< ", grade to execute: " << f.getGradeToExecute() << RESET;
	return (os);
}

//ex02

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSignedStatus())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	this->action();
}

const char	*AForm::FormNotSignedException::what() const throw() { return ("\033[31mForm is not signed\033[0m"); }