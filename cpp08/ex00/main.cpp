/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:18:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/12 14:29:02 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	int param2_vec = 1;

	std::cout << "==================================================" << std::endl;
	std::cout << "Testing with vector:" << std::endl;
	try {
		std::vector<int>::iterator it_vec = easyfind(vec, param2_vec);
		std::cout << "Element found at position: " << std::distance(vec.begin(), it_vec) << std::endl;
	} catch (const std::string &error) {
		std::cout << "[TEST] " << error << std::endl;
	}

	std::list<int> lst;
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(10);
	int param2_lst = 12;

	std::cout << "==================================================";
	std::cout << "\nTesting with list:" << std::endl;
	try {
		std::list<int>::iterator it_lst = easyfind(lst, param2_lst);
		std::cout << "Element found at position: " << std::distance(lst.begin(), it_lst) << std::endl;
	} catch (const std::string &error) {
		std::cout << "[TEST]catch: " << error << std::endl;
	}
	std::cout << "==================================================";

	return 0;
}
