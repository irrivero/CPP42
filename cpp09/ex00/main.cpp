/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:37:20 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/06 15:47:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2)
	{
        std::cerr << "Error" << std::endl << "Usage: ./btc [input_file]" << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");
    btc.processInputFile(argv[1]);

    return 0;
}
