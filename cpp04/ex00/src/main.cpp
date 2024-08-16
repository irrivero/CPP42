/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:03:57 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/16 15:22:54 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* w = new WrongAnimal();
const WrongAnimal* x = new WrongCat();

std::cout << std::endl;
std::cout << j->getType() << " " << std::endl; // will output the dog type
std::cout << i->getType() << " " << std::endl; // will output the cat type
std::cout << meta->getType() << " " << std::endl; // will output the animal type
std::cout << std::endl; 

delete meta; // destroy the animal
meta = new Cat(); // meta is now a cat
std::cout << meta->getType() << " " << std::endl; // will output the cat type
meta->makeSound(); // will output the cat sound

std::cout << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); //will output the dog sound!
w->makeSound(); //will output the wrong animal sound!
x->makeSound();	//will output the wrong cat sound! (tweet tweet)

std::cout << std::endl;

delete j; // destroy the dog + animal
delete i; // destroy the cat + animal
delete meta; // destroy the animal
delete w;	// destroy the wrong animal
delete x;	// destroy the wrong cat + wrong animal

return 0;
}