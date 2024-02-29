/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:35:34 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/23 13:44:17 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	PhoneBook phonebook;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::string command;
		std::cin >> command;

		if (std::cin.eof())
			break ;
		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchContact();
		} else if (command == "EXIT") {
			std::cout << "Exiting...Bye..." << std::endl;
			break;
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	return 0;
}
