/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:00:27 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:18:13 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &copy); // copy constructor
        Cat &operator=(const Cat &copy); // assignment operator

        // Member functions
        virtual void    makeSound() const;
        Brain   *getBrain() const;
    
};

#endif