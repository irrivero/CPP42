/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:57:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/06/20 14:59:48 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class	PhoneBook
{
	private:
		Contact		_contacts[8]; //array of 8 contacts
		int			_contactCount; // count the number of contacts
		int			_oldestIndex; // index of the oldest contact

	public:
		PhoneBook(); // constructor if the class
		void	addContact(Contact contact); // add a new contact
		void	searchContacts(); // search and show the contacts in a table
		void	displayContact(int index); // show the details of a specific contact
		bool	isEmpty(); // check if the phonebook is empty
};

#endif