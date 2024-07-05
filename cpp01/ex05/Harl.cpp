/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:53:50 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 14:36:50 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void	Harl::complain(std::string level)
{
	void (Harl::*complaintF)() = nullptr;

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			switch (i)
			{
			case 0:
				complaintF = &Harl::debug;
				break;
			case 1:
				complaintF = &Harl::info;
				break;
			case 2:
				complaintF = &Harl::warning;
				break;
			case 3:
				complaintF = &Harl::error;
				break;
			default:
				break;
			}
			break;
		}
	}
	if (complaintF != nullptr)
		(this->*complaintF)();
	else
	    std::cout << "Oh dear, I haven't heard of the complaint level '" << level << "'. Could you enlighten me?" << std::endl;
}