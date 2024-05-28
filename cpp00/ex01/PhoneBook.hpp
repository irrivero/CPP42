/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:57:51 by irivero-          #+#    #+#             */
/*   Updated: 2024/05/28 16:37:21 by irivero-         ###   ########.fr       */
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
		Contact		_contacts[8];
		int			_contactCount;
		int			_oldestIndex;

	public:
		PhoneBook();
		void	addContact(Contact contact);
		void	searchContacts();
		void	displayContact(int index);
		bool	isEmpty()
		{
			return (_contactCount <= 0);
		}
};

#endif