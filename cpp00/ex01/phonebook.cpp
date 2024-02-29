/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:42:48 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/25 11:55:03 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void PhoneBook::addContact() {
	if (_numContacts < MAX_CONTACTS) {
		Contact contact;
		std::string first, last, nick, secret, phone;

		std::cout << "Enter first name: ";
		std::cin >> first;
		contact.setFirstname(first);

		std::cout << "Enter last name: ";
		std::cin >> last;
		contact.setLastname(last);

		std::cout << "Enter nickname: ";
		std::cin >> nick;
		contact.setNickname(nick);

		std::cout << "Enter phone number: ";
		std::cin >> phone;
		contact.setPhonenumber(phone);

		std::cout << "Enter darkest secret: ";
		std::cin >> secret;
		contact.setDarksecret(secret);

		_contacts[_numContacts++] = contact;
	} else {
		std::cout << "Phonebook is full. Replacing the oldest contact." << std::endl;
		for (int i = 0; i < MAX_CONTACTS - 1; ++i) {
			_contacts[i] = _contacts[i + 1];
		}

		Contact contact;
		std::string first, last, nick, secret, phone;

		std::cout << "Enter first name: ";
		std::cin >> first;
		contact.setFirstname(first);

		std::cout << "Enter last name: ";
		std::cin >> last;
		contact.setLastname(last);

		std::cout << "Enter nickname: ";
		std::cin >> nick;
		contact.setNickname(nick);

		std::cout << "Enter phone number: ";
		std::cin >> phone;
		contact.setPhonenumber(phone);

		std::cout << "Enter darkest secret: ";
		std::cin >> secret;
		contact.setDarksecret(secret);

		_contacts[MAX_CONTACTS - 1] = contact;
	}
}

void PhoneBook::searchContact() const {
    if (_numContacts == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(9) << std::right << "Index" << " | ";
    std::cout << std::setw(10) << std::right << "First name" << " | ";
    std::cout << std::setw(10) << std::right << "Last name" << " | ";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < _numContacts; ++i) {
        std::cout << std::setw(9) << std::right << i + 1 << " | ";
        std::string firstName = _contacts[i].getFirstname();
        std::string lastName = _contacts[i].getLastname();
        std::string nickname = _contacts[i].getNickname();
        if (firstName.length() > 10) {
            firstName = firstName.substr(0, 9) + ".";
        }
        if (lastName.length() > 10) {
            lastName = lastName.substr(0, 9) + ".";
        }
        if (nickname.length() > 10) {
            nickname = nickname.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << firstName << " | ";
        std::cout << std::setw(10) << std::right << lastName << " | ";
        std::cout << std::setw(10) << std::right << nickname << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    int index;
    std::cout << "Enter index of contact to display: ";
    std::cin >> index;
    index--;
    if (index >= 0 && index < _numContacts) {
        const Contact& contact = _contacts[index];
        std::cout << "First name: " << contact.getFirstname() << std::endl;
        std::cout << "Last name: " << contact.getLastname() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Darksecret: " << contact.getDarksecret() << std::endl;
        std::cout << "Phone Number: " << contact.getPhonenumber() << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void PhoneBook::displayContacts() const {
    if (_numContacts == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << "Contacts in phonebook:" << std::endl;
    for (int i = 0; i < _numContacts; ++i) {
        std::cout << "Contact " << i + 1 << ":" << std::endl;
        std::cout << "First name: " << _contacts[i].getFirstname() << std::endl;
        std::cout << "Last name: " << _contacts[i].getLastname() << std::endl;
        std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
        std::cout << "Darksecret: " << _contacts[i].getDarksecret() << std::endl;
        std::cout << "Phone Number: " << _contacts[i].getPhonenumber() << std::endl;
    }
}
