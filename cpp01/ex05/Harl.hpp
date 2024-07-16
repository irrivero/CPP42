/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:51:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/05 14:02:08 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	
	public:
		void	complain( std::string level );
};

#endif