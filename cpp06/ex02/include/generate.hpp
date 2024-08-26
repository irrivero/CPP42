/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:34:45 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/26 12:38:04 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_HPP
# define GENERATE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif