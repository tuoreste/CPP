/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:48:48 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 11:24:31 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

#include <iostream>
#include <string>

class Base {
	public:
		virtual	~Base(){}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

// class D : public Base {}; //example to fail

Base	*generate(void);
void identify(Base *p);
void identify(Base& p);

#endif
