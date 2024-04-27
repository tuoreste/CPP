/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/27 18:08:19 by otuyishi         ###   ########.fr       */
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
		PmergeMe obj1(3000);
		for (int i = 1; i < argc; ++i) {
			obj1.parse(argv[i]);
		}
		if (obj1.is_sorted(obj1.getVector_c()))
		{
			std::cout << "Die Eingabe ist sortiert, Danke." << std::endl;
			return (0);
		}
		obj1.ford_Johnson_vector(obj1.getVector_c());
		obj1.ford_Johnson_deque(obj1.getDeque_c());
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
