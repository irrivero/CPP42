/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:36:50 by irivero-          #+#    #+#             */
/*   Updated: 2024/09/11 12:13:56 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        // test with integer vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        // test with integer list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::list<int>::iterator it_lst = easyfind(lst, 30);
        std::cout << "Found: " << *it_lst << std::endl;

        // test with non-existing element
        it = easyfind(vec, 42);  // should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
