/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:00:35 by irivero-          #+#    #+#             */
/*   Updated: 2024/05/28 16:32:15 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0){}

void	PhoneBook::addContact(Contact contact)
{
	// if (this->_contactCount == 0)
	// 	return ;
	 if (this->_contactCount < 8)
		this->_contacts[this->_contactCount++] = contact;
	else
		{
			this->_contacts[this->_oldestIndex] = contact;
			this->_oldestIndex = (this->_oldestIndex + 1) % 8;
		}
}

void	PhoneBook::searchContacts()
{
	int		i;
	
	if (this->_contactCount == 0)
	{
		std::cout << "No contacts found!" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	i = 0;
	while (i < this->_contactCount)
	{
		std::cout << std::setw(10) << i << "|";
		
		std::string first_name = this->_contacts[i].getFirstName();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";

		std::string last_name = this->_contacts[i].getLastName();
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";

		std::string nickname = this->_contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "|" << std::endl;
		++i;
	}
}
void	PhoneBook::displayContact(int index)
{
	if (index < 0 || index >= this->_contactCount)
		std::cout << "Invalid index!" << std::endl;
	else
	{
		std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	}
}