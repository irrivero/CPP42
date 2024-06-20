/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:00:35 by irivero-          #+#    #+#             */
/*   Updated: 2024/06/20 15:11:51 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// initialize the contactcount and the oldestindex to 0
// when the class is created
PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0){}

//add a new contact to the phonebook
void	PhoneBook::addContact(Contact contact)
{
	if (this->_contactCount < 8) // if the contact count is less than 8
		this->_contacts[this->_contactCount++] = contact; // add the contact to the next possible position
	else // if there are already 8 contacts
		{
			this->_contacts[this->_oldestIndex] = contact; // subscribe the oldest contact
			this->_oldestIndex = (this->_oldestIndex + 1) % 8; // update the oldest index to the next position
		}
}

// search and show the contacts in a table
void	PhoneBook::searchContacts()
{
	int		i;
	
	// if there are no contacts
	if (this->_contactCount == 0)
	{
		// show a message and return
		std::cout << "No contacts found!" << std::endl;
		return ;
	}
	// show the table header, uses setw to set the width of the columns
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	i = 0;
	while (i < this->_contactCount) // goes through the contacts
	{
		std::cout << std::setw(10) << i << "|"; // prints the index i with a column width of 10
		
		//first name
		std::string first_name = this->_contacts[i].getFirstName(); // get the first name
		if (first_name.length() > 10) // if the length of the first name is greater than 10
			first_name = first_name.substr(0, 9) + "."; // cut the first name to 9 characters and add a dot
		std::cout << std::setw(10) << first_name << "|"; // shows the name with a column width of 10 and a |
		//last name
		std::string last_name = this->_contacts[i].getLastName();
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";
		//nickname
		std::string nickname = this->_contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "|" << std::endl; // after the last column newline
		++i; // increment the index to go to the next contact
	}
}
// show the details of a specific contact by index
void	PhoneBook::displayContact(int index)
{
	// if the index is invalid show a message
	if (index < 0 || index >= this->_contactCount)
		std::cout << "Invalid index!" << std::endl;
	else // if the index is valid show the contact details
	{
		std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	}
}

bool	PhoneBook::isEmpty()
{
	return (_contactCount <= 0);
}