/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:10:30 by irivero-          #+#    #+#             */
/*   Updated: 2024/06/20 15:22:31 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// basically atoi
int	stringToInt(std::string str)
{
	std::stringstream	ss(str);
	int					result;
	
	ss >> result;
	return (result);
}

// creates a new contact and asks for the information
void	addContact(PhoneBook &phoneBook)
{
	Contact	contact;
	std::string	input;

	std::cout << "Enter the first name: "; // ask for the first name in stdout
	std::getline(std::cin, input); // read the input
	contact.setFirstName(input); // set the first name
	std::cout << "Enter the last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	if (contact.isEmptyInfo()) // if any of the fields is empty show an error message
	{
		std::cout << "Error: All fields must be filled!" << std::endl;
		return ;
	}
	else
	{
		phoneBook.addContact(contact);
		std::cout << "Contact added!" << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phoneBook; // create a new phonebook
	std::string	command; // get the command from the user

	while (1)
	{
		// ask for a command to the user
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		// read the command
		std::getline(std::cin, command);
		if (command == "ADD") // if the command is ADD
			addContact(phoneBook); // call the addContact function
		else if (command == "SEARCH") // if the command is SEARCH
		{
			// if the phonebook is empty show a message and continue
			if (phoneBook.isEmpty())
			{
				std::cout << "No contacts found!" << std::endl;
				continue ;
			}
			// search and show the contacts
			phoneBook.searchContacts();
			std::cout << "Enter an index of the contact to display: ";
			std::getline(std::cin, command);
			// if the index is not a number, show an error message
			if (isalpha(command[0]))
				std::cout << "Invalid index!" << std::endl;
			else
				phoneBook.displayContact(stringToInt(command)); // convert the index to int and calls the displayContact function
		}
		else if (command == "EXIT") // if the command is EXIT
			break ; // exit the loop
		else // if the command is invalid
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}