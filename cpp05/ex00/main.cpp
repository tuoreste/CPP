/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:35:40 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/05 16:35:54 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main()
{
	try {
		// Setting up default grade
		Bureaucrat bureaucrat1;
		std::cout << "Default bureaucrat: " << bureaucrat1 << std::endl;

		// Create a bureaucrat with custom name and grade
		Bureaucrat bureaucrat2("Alice", 50);
		std::cout << "Custom bureaucrat: " << bureaucrat2 << std::endl;

		// Test increments and decrements
		bureaucrat2.increments(5);
		std::cout << "After incrementing 5 grades: " << bureaucrat2 << std::endl;

		bureaucrat2.decrements(10);
		std::cout << "After decrementing 10 grades: " << bureaucrat2 << std::endl;

		// Try invalid grade which Should throw an exception
		Bureaucrat bureaucrat3("Bob", 0);
		std::cout << "Here will not be reached" << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
    return 0;
}
