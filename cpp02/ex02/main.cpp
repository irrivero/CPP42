/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:19:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/08 12:53:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void ) 
{ 
	Fixed a; // since a is const, it cannot be modified after its init
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //temporary Fixed obj 5.05f and
	//another temp FIxed obj int 2
	// multiplication of those 2
	
std::cout << a << std::endl; // line prints 0 since a was init with 0 by default constructor
std::cout << ++a << std::endl; // 0.00390625 is the result of incrementing 0 by a fixed-point, 
// corresponding to 1/(2 to the 4th) or 1/256, given that _fractionalBits is 8 in Fixed class.
std::cout << a << std::endl; // the value of the after the pre increment operation. Remains the same
std::cout << a++ << std::endl; // This is the result of the post-increment operation a++. 
// The a++ prints the value of a before it is incremented, so it prints 0.00390625 and then increments a after printing.
std::cout << a << std::endl; // This is the value of a after the post-increment operation. 
//Since a was 0.00390625 before increment, and each increment step is 0.00390625, adding one more step results in 0.0078125.
std::cout << b << std::endl; // This is the value of b, which was initialized with Fixed(5.05f) * Fixed(2).
// The multiplication of these fixed-point values results in 10.1016 in floating-point representation.
std::cout << Fixed::max( a, b ) << std::endl; // This is the result of Fixed::max(a, b), which should return 
//the maximum of a and b. Since a is 0.0078125 and b is 10.1016, the maximum is 10.1016
return 0; 
}
