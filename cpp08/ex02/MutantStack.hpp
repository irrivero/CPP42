/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:34:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/10 14:46:01 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>


// MutantStack class that inherits from std::stack
// Also provides iterators to access the stack
// this->c is the container of std::stack

template <typename T> 
class MutantStack : public std::stack<T>
{
    public:
        // Constructor, Destructor, Copy Constructor, Assignment Operator
        MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack& operator=(const MutantStack& src);
        ~MutantStack();

        // Typedefs to make it easier to use
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Methods to access the iterators
        // This methods allows to access the stack with iterators
        // This is as if it was any other container from STL
        iterator begin() { return std::stack<T>::c.begin(); };
        iterator end() { return std::stack<T>::c.end(); };
        const_iterator begin() const { return std::stack<T>::c.begin(); };
        const_iterator end() const { return std::stack<T>::c.end(); };
        reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
        reverse_iterator rend() { return std::stack<T>::c.rend(); };
        const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); };
        const_reverse_iterator rend() const { return std::stack<T>::c.rend(); };
};

#include "MutantStack.tpp"

#endif