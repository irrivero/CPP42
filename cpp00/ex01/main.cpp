/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:10:30 by irivero-          #+#    #+#             */
/*   Updated: 2024/05/28 16:42:09 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	stringToInt(std::string str)
{
	std::stringstream	ss(str);
	int					result;
	
	ss >> result;
	return (result);
}

void	addContact(PhoneBook &phoneBook)
{
	Contact	contact;
	std::string	input;

	std::cout << "Enter the first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
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
	if (contact.isEmptyInfo())
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
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			addContact(phoneBook);
		else if (command == "SEARCH")
		{
			if (phoneBook.isEmpty())
			{
				std::cout << "No contacts found!" << std::endl;
				continue ;
			}
			phoneBook.searchContacts();
			std::cout << "Enter an index of the contact to display: ";
			std::getline(std::cin, command);
			if (isalpha(command[0]))
				std::cout << "Invalid index!" << std::endl;
			else
				phoneBook.displayContact(stringToInt(command));
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}