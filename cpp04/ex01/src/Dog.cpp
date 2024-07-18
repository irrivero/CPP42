/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:59:13 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:48:21 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "\e[0mDog constructor called\e[0m" << std::endl;
    _brain = new Brain();
}
Dog::~Dog()
{
    std::cout << "\e[0mDog destructor called\e[0m" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "\e[0mDog copy constructor called\e[0m" << std::endl;
    this->_brain = new Brain(*(copy._brain));
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "\e[0mDog assignation operator called\e[0m" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*copy.getBrain());
    }
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "\e[0mGuau guau\e[0m" << std::endl;
}

Brain  *Dog::getBrain() const
{
    return _brain;
}