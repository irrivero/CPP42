/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:18:03 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/20 14:42:57 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
    private:
        AForm* createShrubberyForm(const std::string& target);
        AForm* createRobotomyForm(const std::string& target);
        AForm* createPresidentialForm(const std::string& target);

    public:
        Intern(); // Default constructor
        Intern(const Intern& copy); // Copy constructor
        Intern& operator=(const Intern& copy);  // Copy assignment operator
        ~Intern();  // Destructor
        
        // Form creation
        AForm* makeForm(const std::string& formName, const std::string& target);
        class FormNotFoundException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
};

#endif
