/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:41:05 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/11 12:08:06 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void increment(T &n) 
{
    ++n;
}

template <typename T>
void printall(T &n) 
{
    std::cout << n << " ";
}

template <typename T>
void	decrement(T &c)
{
	c--;
}

int main() 
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "INT\nOriginal int array: ";
    iter(intArray, intArraySize, printall<int>);
    std::cout << std::endl;

    std::cout << "Incremented int array: ";
    iter(intArray, intArraySize, increment<int>);
    iter(intArray, intArraySize, printall<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	  std::cout << std::endl;
    std::cout << "DOUBLE\nOriginal double array: ";
    iter(doubleArray, doubleArraySize, printall<double>);
    std::cout << std::endl;

    std::cout << "Incremented double array: ";
    iter(doubleArray, doubleArraySize, increment<double>);
    iter(doubleArray, doubleArraySize, printall<double>);
    std::cout << std::endl;

	  char charArray[] = {'b', 'c', 'd', 'e', 'f'};
	  size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

	  std::cout << std::endl;
	  std::cout << "CHAR\nOriginal char array: ";
	  iter(charArray, charArraySize, printall<char>);
	  std::cout << std::endl;
	
	  std::cout << "Decremented char array: ";
	  iter(charArray, charArraySize, decrement<char>);
	  iter(charArray, charArraySize, printall<char>);
	  std::cout << std::endl;

    return 0;
}

// eval test
// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
