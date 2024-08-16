/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:01:25 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/16 16:49:20 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}