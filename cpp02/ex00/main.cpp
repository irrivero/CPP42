/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:41:49 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/10 16:13:40 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/** 
 * Se crean tres objetos Fixed (a, b y c).
 * b se inicializa como una copia de a.
 * c se inicializa por defecto y luego se le asigna el valor de b.
 * 
 * Los valores de _value de los tres objetos (a, b y c) se imprimen, todos mostrando 0,
 *  ya que no se han modificado desde la inicialización.
 */
int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;
c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
return 0; }