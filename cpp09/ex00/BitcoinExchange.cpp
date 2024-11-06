/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:01:43 by irivero-          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:15 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

// Constructor that initializes the database by loading data from a file.
BitcoinExchange::BitcoinExchange(const std::string &db_file)
{
	loadDatabase(db_file);
}

BitcoinExchange::~BitcoinExchange() {}

// Copy constructor: creates a new instance by copying data from another.
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

// Assignment operator overload for copying data from one instance to another.
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_priceData = other._priceData;
	}
	return (*this);
}

// Loads the price database from a CSV file.
void BitcoinExchange::loadDatabase(const std::string &db_file)
{
	std::ifstream file(db_file.c_str());  // Convert std::string to C-string for C++98 compatibility
	if (!file)  // Check if the file opened successfully
	{
		std::cerr << "Error: could not open file " << db_file << std::endl;
		return;
	}
	std::string line, date;
	float price;
	while (getline(file, line))  // Read each line from the file
	{
		std::stringstream ss(line);
		getline(ss, date, ',');  // Extract date (first part of the line)
		ss >> price;  // Extract price (second part of the line)
		_priceData[date] = price;  // Store the date-price pair in the map
	}
}

// Utility function to trim whitespace from both ends of a string.
std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";  // Return an empty string if no non-space character is found
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);  // Return trimmed substring
}

// Processes each line of the input file and calculates the equivalent bitcoin value.
void BitcoinExchange::processInputFile(const std::string &input_file)
{
	std::ifstream file(input_file.c_str());
	if (!file)  // Check if the file opened successfully
	{
		std::cerr << "Error: could not open file " << input_file << std::endl;
		return;
	}
	    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: file " << input_file << " is empty" << std::endl;
        return;
    }
	std::string line;
	bool firstLine = true;  // Used to skip header line, if any
	while (getline(file, line))
	{
		if (firstLine || line.empty())  // Skip first line or any empty line
		{
			firstLine = false;
			continue;
		}
		std::stringstream ss(line);
		std::string date;
		float value;
		if (!getline(ss, date, '|'))  // Read date up to delimiter '|'
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = trim(date);  // Remove any surrounding whitespace from the date
		if (!(ss >> value))  // Try to read the float value after '|'
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (isDateValid(date))  // Validate date format
		{
			if (isValueValid(value))  // Check if value is within allowed range
				calculateValue(date, value);  // Calculate and display the bitcoin value
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

// Calculates and outputs the equivalent bitcoin value based on the closest historical price.
void BitcoinExchange::calculateValue(const std::string &date, float value)
{
    std::map<std::string, float>::iterator it = _priceData.lower_bound(date);
    if (it == _priceData.end() || it->first != date)  // If exact date is not found
    {
        if (it == _priceData.begin())  // No earlier date available
        {
            std::cout << "Error: no data available for this date or earlier." << std::endl;
            return;
        }
        --it;  // Use the closest earlier date
    }
    float result = value * it->second;  // Calculate equivalent bitcoin value
    std::cout << date << " => " << value << " = " << result << std::endl;  // Output result
}

// Validates if the date is in YYYY-MM-DD format and if the month/day values are plausible.
bool BitcoinExchange::isDateValid(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
        return false;
	}
	int month, day;
	std::istringstream(date.substr(5, 2)) >> month;
	std::istringstream(date.substr(8, 2)) >> day;

    if (month < 1 || month > 12 || day < 1 || day > 31)  // Basic range check
        return false;
    return true;
}

// Checks if the bitcoin value is within a reasonable range (0-1000).
bool BitcoinExchange::isValueValid(float value)
{
    if (value < 0)  // Check for non-negative value
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)  // Check upper limit
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
