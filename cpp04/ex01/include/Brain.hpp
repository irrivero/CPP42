/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:01:12 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/18 15:13:18 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class   Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &copy); // copy constructor
        Brain &operator=(const Brain &copy); // assignment operator

        // Member functions
        void    setIdea(std::string const &idea, int index);
        std::string getIdea(int index) const;
};

#endif