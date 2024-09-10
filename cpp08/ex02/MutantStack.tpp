/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:42:35 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/10 14:45:38 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
    *this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& src)
{
    (void)src;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}
