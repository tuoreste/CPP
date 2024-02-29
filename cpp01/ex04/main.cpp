/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:58:12 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/21 18:36:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Unable to open input file: " << filename << std::endl;
		return;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Unable to create output file: " << filename << ".replace" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: Plz use as follows" << " <./ex04> <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replaceInFile(filename, s1, s2);
	std::cout << "Task completed. Check " << filename << ".replace" << std::endl;
	return 0;
}

