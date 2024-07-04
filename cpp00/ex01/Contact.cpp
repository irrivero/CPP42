/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:53:15 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/04 16:08:48 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void    Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}

void    Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void    Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}
void    Contact::setDarkestSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return (this->_firstName);
}

std::string Contact::getLastName()
{
    return (this->_lastName);
}

std::string Contact::getNickname()
{
    return (this->_nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->_darkestSecret);
}

bool    Contact::isEmptyInfo() 
{
	return (_firstName.empty() || _lastName.empty() || _nickname.empty() || _phoneNumber.empty() || _darkestSecret.empty());
}	