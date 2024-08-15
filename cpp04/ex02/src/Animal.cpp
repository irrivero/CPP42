/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:38:01 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:47:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
    std::cout << "\e[33mAnimal constructor called\e[0m" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type)
{
    std::cout << "\e[33mAnimal type constructor called\e[0m" << std::endl;
}

Animal::~Animal()
{
    std::cout << "\e[33mAnimal destructor called\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "\e[33mAnimal copy constructor called\e[0m" << std::endl;
    *this = copy;
}
Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "\e[33mAnimal assignation operator called\e[0m" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "\e[33mAnimal sound\e[0m" << std::endl;
}
 
std::string Animal::getType() const
{
    return this->_type;
}