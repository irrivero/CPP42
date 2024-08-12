/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:41:49 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/08 12:41:14 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/** 
 * Creats 3 objects Fixed (a, b, c).
 * b initializes as a copy of a
 * c initializes in default and then asigns the value of b
 * 
 * the values of the 3 objects are 0 since they are not modified since the init
 */
int main( void ) {
  Fixed a; //default constructor called
  Fixed b( a ); //copy constructor called
  Fixed c; // default constructor && copy assignment operator called (using getrawbits)
  c = b; // c is assigned the value of b using the copy assigment operator, the value of b is copied to c
  std::cout << a.getRawBits() << std::endl; //0
  std::cout << b.getRawBits() << std::endl; //0
  std::cout << c.getRawBits() << std::endl; //0
  
  //destructor calls 3 times
return 0; }
