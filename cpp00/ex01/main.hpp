/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:19 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/23 13:39:56 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <cstring>
# include <iomanip>
# include <iostream>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _darksecret;
		std::string _phonenumber;

	public:
		// construct
		Contact() {}
		// destruct
		~Contact() {}
		// get the privates
		std::string getFirstname() const { return _firstname; }
		std::string getLastname() const { return _lastname; }
		std::string getNickname() const { return _nickname; }
		std::string getDarksecret() const { return _darksecret; }
		std::string getPhonenumber() const { return _phonenumber; }
		// set the privates
		void setFirstname(const std::string& first) { _firstname = first; }
		void setLastname(const std::string& last) { _lastname = last; }
		void setNickname(const std::string& nick) { _nickname = nick; }
		void setDarksecret(const std::string& secret) { _darksecret = secret; }
		void setPhonenumber(const std::string& number) { _phonenumber = number; }
};

class PhoneBook {
	private:
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];
		int _numContacts;

	public:
		// construct
		PhoneBook() : _numContacts(0) {}
		// destruct
		~PhoneBook() {}
		// declare funcs
		void addContact();
		void searchContact() const;
		void displayContacts() const;
};

#endif
