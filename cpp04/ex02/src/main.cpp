/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:03:57 by irivero-          #+#    #+#             */
/*   Updated: 2024/08/19 13:22:52 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    // You can't instantiate an abstract class Animal
    // const Animal* meta = new Animal(); // This line will cause an error

    // We instantiate an object of the class Dog through a pointer to the base class Animal
    const Animal* j = new Dog();
    // We instantiate an object of the class Cat the same way
    const Animal* i = new Cat();

    std::cout << std::endl;

    // We show the type of each object
    std::cout << "Type of Dog: " << j->getType() << std::endl;
    std::cout << "Tye of Cat: " << i->getType() << std::endl;

    std::cout << std::endl;

    // We call the function makeSound that is polymorphic
    // Each derived class has its own implementation
    std::cout << "Sound of cat: ";
    i->makeSound(); // Should print the sound of the cat

    std::cout << "Sound of dog: ";
    j->makeSound(); // Should print the sound of the dog

    std::cout << std::endl;
    // We delete the objects
    delete j;
    delete i;

    return 0;
}
