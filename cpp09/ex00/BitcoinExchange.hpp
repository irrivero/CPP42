/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:18 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/09 17:29:59 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &db_file);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		void	processInputFile(const std::string &input_file);
	
	private:
		std::map<std::string, float>	_priceData;
		void	loadDatabase(const std::string &db_file);
		void	calculateValue(const std::string &date, float value);	
		bool	isDateValid(const std::string &date);
		bool	isValueValid(float value);
};

#endif
