/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:42:41 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 11:55:38 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;

	data.number = 42;
	data.text = "Hello World!";

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		deserialized = Serializer::deserialize(raw);

	if (deserialized == &data)
	{
		std::cout << "Success! \033[36mdeserialized\033[0m is \033[32mequal\033[0m to the original \033[36mraw\033[0m pointer" << std::endl;
		std::cout << "Original number: " << deserialized->number << std::endl;
		std::cout << "Original text: " << deserialized->text << std::endl;
	}
	else
		std::cout << "Failure! \033[36mdeserialized\033[0m is \033[31mnot equal\033[0m to the original \033[36mraw\033[0m pointer" << std::endl;
	
	return (0);
}