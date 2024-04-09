/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:39:36 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 18:18:11 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

// 12 213 231 34 62 456 13 131 351 3
// a  cfads  adsf  asdfasdf  afasdfasd 

int main() {
	srand(time(NULL));
	// Generate a random object
	Base* obj = generate();
	// D*	d = new D; // example fail

	// Identify the type of the object using pointer
	std::cout << "Using pointer: ";
	identify(obj);
	std::cout << std::endl;

	// Identify the type of the object using reference
	Base *b = generate();
	std::cout << "Using reference: ";
	identify(*b);
	std::cout << std::endl;

	// //meant to fail
	// std::cout << "Using reference: ";
	// identify(*d);
	// std::cout << std::endl;
	// delete d;

	delete obj;

	return 0;
}