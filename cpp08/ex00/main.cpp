/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:18:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/15 12:38:35 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/easyfind.hpp"
#include <list>
#include <vector>

// void print_test_name(const std::string &test_name) {
//   std::cout << "[TEST] " << test_name << "\n";
// }

// template <typename Container>
// void test_find_in_container(const std::string &description, int numToSearch,
//                             Container &container) {
//   print_test_name(description);
//   try {
//     typename Container::iterator it = easyFind(container, numToSearch);
//     int position = std::distance(container.begin(), it);
//     std::cout << "Number " << numToSearch << " found at position "
//               << position + 1 << " in the container: { ";
//     for (typename Container::iterator iter = container.begin();
//          iter != container.end(); ++iter) {
//       std::cout << *iter << " ";
//     }
//     std::cout << "}\n\n";
//   } catch (const std::string &e) {
//     std::cerr << "Error: " << e << "\n\n";
//   }
// }

// int main() {
//   int numsVector[] = {5, 3, 17, -2, 9, 11};
//   std::vector<int> vector1(numsVector, numsVector + sizeof(numsVector) /
//                                                         sizeof(numsVector[0]));
//   std::vector<int> vector2(numsVector, numsVector + sizeof(numsVector) /
//                                                         sizeof(numsVector[0]));
//   vector2.push_back(42);

//   int numsList[] = {5 ,3, 17, -2, 9, 11};
//   std::list<int> list1(numsList,
//                        numsList + sizeof(numsList) / sizeof(numsList[0]));
//   std::list<int> list2(numsList,
//                        numsList + sizeof(numsList) / sizeof(numsList[0]));
//   list2.push_back(42);

//   test_find_in_container("Find number in vector.", -2, vector1);
//   test_find_in_container("Number not found in vector.", 42, vector1);
//   test_find_in_container("Find number in vector.", 42, vector2);
//   test_find_in_container("Number not found in vector.", 100, vector2);

//   test_find_in_container("Find number in list.", -2, list1);
//   test_find_in_container("Number not found in list.", 42, list1);
//   test_find_in_container("Find number in list.", 42, list2);
//   test_find_in_container("Number not found in list.", 100, list2);

//   return 0;
// }

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
		std::vector<int>::iterator it_vec = easyFind(vec, param2_vec);
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
		std::list<int>::iterator it_lst = easyFind(lst, param2_lst);
		std::cout << "Element found at position: " << std::distance(lst.begin(), it_lst) << std::endl;
	} catch (const std::string &error) {
		std::cout << "[TEST]catch: " << error << std::endl;
	}
	std::cout << "==================================================";

	return 0;
}
