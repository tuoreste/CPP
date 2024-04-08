/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:39:36 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/08 21:53:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"

int main() {
	srand(static_cast<unsigned>(time(NULL)));
	// Generate a random object
	Base* obj = generate();

	// Identify the type of the object using pointer
	std::cout << "Using pointer: ";
	identify(obj);
	std::cout << std::endl;

	// Identify the type of the object using reference
	std::cout << "Using reference: ";
	identify(*obj);
	std::cout << std::endl;

	delete obj;

	return 0;
}