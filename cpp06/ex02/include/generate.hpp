/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:34:45 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/04 11:45:34 by irivero-         ###   ########.fr       */
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

// dynamic_cast: a type cast expression that u use in polymorphic classes that has at least
// one virtual function.
// it's safer but more expensive because it checks if the cast is valid at runtime

#endif