/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:40:40 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/10 10:44:04 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	getBuffer(std::string file)
{
	std::string	line;
	std::string	buffer;

	std::ifstream fichier(file.c_str());
	if (!fichier.is_open())
	{
		std::cerr << "Error!" << std::endl;
		return "";
	}
	while (getline(fichier, line)){
		buffer += line + "\n";
	}
	fichier.close();
	return buffer;
}

std::string	replace(std::string buffer, std::string s1, std::string s2)
{
	size_t	pos = 0;
	size_t	start = 0;
	std::string	result;

	if (buffer.find(s1) == std::string::npos)
	{
		std::cerr<< "Error ! The pattern is not present in the string."<<std::endl;
		return "";
	}
	while ((pos = buffer.find(s1, start)) != std::string::npos)
	{
		result += buffer.substr(start, pos - start) + s2;
		start = pos + s1.length();
	}
	result+=buffer.substr(start);
	return result;
}

int	main(int ac, char **av)
{
	std::string	buffer;
	std::string	newBuffer;
	std::string	fileName;
	std::string	line;

	if (ac != 4)
		return (0);
	buffer = getBuffer(av[1]);
	if (buffer.length() == 0)
		return 0;
	newBuffer = replace(buffer, av[2], av[3]);
	if (newBuffer.length() == 0)
		return (0);
	fileName = std::string(av[1]) + ".replace";
	std::ofstream newFile(fileName.c_str());
	if (!newFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return (0);
	}
	newFile << newBuffer;
	newFile.close();
	return (1);
}