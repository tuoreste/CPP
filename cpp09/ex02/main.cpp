/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/27 14:42:27 by otuyishi         ###   ########.fr       */
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
		PmergeMe obj;
		for (int i = 1; i < argc; ++i) {
			std::istringstream ss(argv[i]);
			std::string token;
			int num;
			ss >> num;
			if (ss.eof() != true || num < 0)
				throw PmergeMe::PmergeMe_Exception("Error");
			obj.vector_c.push_back(num);
			obj.deque_c.push_back(num);
		}
		if (std::is_sorted(obj.vector_c.begin(), obj.vector_c.end()))
		{
			std::cout << "Die Eingabe ist sortiert, Danke." << std::endl;
			return (0);
		}
		obj.ford_Johnson_vector(obj.vector_c);
		obj.ford_Johnson_deque(obj.deque_c);
		// for (std::deque<int>::iterator it = obj.deque_smaller.begin(); it != obj.deque_smaller.end(); it++) {
			// if (it->size() == 1) {
			// 		std::cout << (*it)[0] << std::endl;
			// 		break ;
			// }
			
			// std::cout << *it << " ";
			// for (size_t i = 0; i < it->size(); i++)
			// 	std::cout << (*it)[i] << " ";
		// }
		// std::cout << std::endl;

		// std::cout << "Resulting vector: ";
		// for (std::deque<int>::iterator it = obj.deque_c.begin(); it != obj.deque_c.end(); ++it) {
		// 	if (it != obj.deque_c.begin())
		// 		std::cout << ", ";
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// for(std::vector<int>::iterator it = obj.vector_c.begin(); it != obj.vector_c.end(); it++)
// 	std::cout << *it << std::endl;
