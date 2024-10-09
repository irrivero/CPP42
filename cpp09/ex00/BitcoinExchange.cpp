/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:29:36 by irivero-          #+#    #+#             */
/*   Updated: 2024/10/09 18:12:12 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &db_file)
{
	loadDatabase(db_file);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_priceData = other._priceData;
	}
	return (*this);
}

void	BitcoinExchange::loadDatabase(const std::string &db_file)
{
	std::ifstream	file(db_file);
	if (!file)
	{
		std::cerr << "Error: could not open file " << db_file << std::endl;
		return ;
	}
	std::string	line, date;
	float		price;
	while (getline(file, line))
	{
		std::stringstream	ss(line);
		getline(ss, date, ',');
		ss >> price;
		_priceData[date] = price;	
	}
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

void	BitcoinExchange::processInputFile(const std::string &input_file)
{
	std::ifstream	file(input_file);
	if (!file)
	{
		std::cerr << "Error: could not open file " << input_file << std::endl;
		return ;
	}
	std::string	line;
	bool		firstLine = true;
	while (getline(file, line))
	{
		if (firstLine || line.empty())
		{
			firstLine = false;
			continue ;
		}
		std::stringstream	ss(line);
		std::string		date;
		float			value;
		if (!getline(ss, date, '|'))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = trim(date);
		if (!(ss >> value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (isDateValid(date))
		{
			if (isValueValid(value))
				calculateValue(date, value);
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}


void BitcoinExchange::calculateValue(const std::string &date, float value)
{
    std::map<std::string, float>::iterator it = _priceData.lower_bound(date);
    if (it == _priceData.end() || it->first != date)
    {
        if (it == _priceData.begin())
        {
            std::cout << "Error: no data available for this date or earlier." << std::endl;
            return;
        }
        --it;
    }
    float result = value * it->second;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

bool BitcoinExchange::isDateValid(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    //int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12 || day < 1 || day > 31 ) // Basic check; can refine further
        return false;
    return true;
}

bool BitcoinExchange::isValueValid(float value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
