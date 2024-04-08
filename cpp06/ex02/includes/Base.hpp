/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:48:48 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/08 21:42:53 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

#include <iostream>
#include <string>

// class myBadCast : public std::runtime_error {
// 	public:
// 		myBadCast(const std::string& error_sms) : std::runtime_error(error_sms) {
// 			std::cout << error_sms << std::endl;
// 		}
// };

class Base {
	public:
		virtual	~Base(){}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base	*generate(void);
void identify(Base *p);
void identify(Base& p);

#endif
