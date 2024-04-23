/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/23 10:31:22 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << "<input1> <input2>" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe<std::vector<int> > obj;
		for (int i = 1; i < argc; ++i) {
			std::istringstream ss(argv[i]);
			std::string token;
			int num;
			ss >> num;
			if (ss.eof() != true || num < 0)
				throw PmergeMe<std::string>::PmergeMe_Exception("Invalid Input, byeee!");
			obj.vector_c.push_back(num);
		}
		obj.duoMaker(obj.vector_c);
		std::cout << "Resulting vector: ";
		for (std::vector<int>::iterator it = obj.vector_c.begin(); it != obj.vector_c.end(); ++it) {
			if (it != obj.vector_c.begin()) std::cout << ", ";
			std::cout << *it;
		}
	std::cout << std::endl;
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// for(std::vector<int>::iterator it = obj.vector_c.begin(); it != obj.vector_c.end(); it++)
// 	std::cout << *it << std::endl;
