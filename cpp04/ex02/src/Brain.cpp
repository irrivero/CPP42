/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:02:50 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:47:57 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\e[31mBrain constructor called\e[0m" << std::endl;
}
Brain::~Brain()
{
    std::cout << "\e[31mBrain destructor called\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "\e[31mBrain copy constructor called\e[0m" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = copy.getIdea(i);
    return (*this);
}

std::string Brain::getIdea(int i) const
{
    if (i < 0 || i >= 100)
        return "Invalid index";
    return this->_ideas[i];
}

void    Brain::setIdea(std::string const &idea, int i)
{
    if (i < 0 || i >= 100)
        return ;
    this->_ideas[i] = idea;
}