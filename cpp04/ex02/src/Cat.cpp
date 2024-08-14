/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:01:25 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:48:10 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "\e[32mCat constructor called\e[0m" << std::endl;
    _brain = new Brain();
}
Cat::~Cat()
{
    std::cout << "\e[32mCat destructor called\e[0m" << std::endl;
    delete _brain;
}
Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "\e[32mCat assignation operator called\e[0m" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(copy._brain));
    }
    return (*this);
}

Cat::Cat(const Cat &copy)
{
    std::cout << "\e[32mCat copy constructor called\e[0m" << std::endl;
    this->_brain = new Brain(*(copy._brain));
}

void    Cat::makeSound() const
{
    std::cout << "\e[32mMeow Meow\e[0m" << std::endl;
}

Brain *Cat::getBrain() const
{
    return _brain;
}