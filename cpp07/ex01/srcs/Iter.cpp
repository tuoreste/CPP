/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:35:26 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 20:58:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"

//TESTING SAMPLES HERE,
// just printing
template <typename T>
void printElement(T& element)
{
	std::cout << element << " ";
}

template <typename T>
void squareElement(T& element)
{
	element *= element;
}

void	tester(void)
{
	//an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(intArray) / sizeof(int);

	// Test A: Print elements of the array
	std::cout << "Printing elements of the array:" << std::endl;
	iter(intArray, length, printElement<int>);
	std::cout << std::endl;

	// Test B: Square elements of the array
	std::cout << "Squaring elements of the array:" << std::endl;
	iter(intArray, length, squareElement<int>);

	// Print the modified array
	std::cout << "Modified array:";
	iter(intArray, length, printElement<int>);
	std::cout << std::endl;
}
