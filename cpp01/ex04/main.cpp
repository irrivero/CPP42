/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:00:35 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/17 12:54:37 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/**
 * Replaces all occurrences of a specified string within another string.
 *
 * @param filename The string in which replacements are to be made.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace s1 with.
 *
 */
void	replace(std::string &filename, const std::string &s1, const std::string &s2)
{
	size_t	pos = 0;
	
	//loop checks if s1 is in filename
	while ((pos = filename.find(s1, pos)) != std::string::npos)
	{
		filename.erase(pos, s1.length()); //deletes s1 from filename
		filename.insert(pos, s2); //inserts s2 in place of s1
		pos += s2.length(); //moves the cursor to the end of s2
	}
}

int	main(int ac, char **av)
{
	// Check if the number of arguments is correct
	if (ac != 4)
	{
		std::cerr << "Usage " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream iFile(filename.c_str()); // open the file
	if (!iFile) // check if the file was opened successfully
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (1);
	}
	// read the content of the file and store it in the content strings
	std::string content((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
	iFile.close(); // close the input file

	if (content.empty()) // check if the file is empty or if s1 is not in the file
	{
		std::cerr << "Error: file is empty" << std::endl;
		return (1);
	}

	if (content.find(s1) == std::string::npos) // check if s1 is not in the file
	{
		std::cerr << "Error: '" << s1 << "' is not in the file" << std::endl;
		return (1);
	}

	std::ofstream oFile((filename + ".replace").c_str()); // open the output file
	if (!oFile) // check if the file was opened successfully
	{
		std::cerr << "Error: could not open file " << filename + ".replace" << std::endl;
		return (1);
	}

	replace(content, s1, s2); // replace all occurrences of s1 with s2
	oFile << content; // write the modified content to the output file
	oFile.close(); // close the output file
	return (0);
}