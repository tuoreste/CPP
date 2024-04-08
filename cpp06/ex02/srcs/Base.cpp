/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:50:07 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/08 21:48:51 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base	*generate(void) {
	int	random_num;

	random_num = rand() % 3;
	switch (random_num)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		break;
	}
	return NULL;
}

void identify(Base *p) {
		if (dynamic_cast<A*>(p))
			std::cout << "Type Class A casted successfully";
		else if (dynamic_cast<B*>(p))
			std::cout << "Type Class B casted successfully";
		else if (dynamic_cast<C*>(p))
			std::cout << "Type Class C casted successfully";
		else
			std::cout << "Type casting failure";
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type Class A casted successfully";
		return ;
	} catch (const std::bad_cast& e) {
	}
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Type Class B casted successfully";
			return ;
		} catch (const std::bad_cast& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type Class C casted successfully";
	} catch (const std::bad_cast& e) {
		std::cout << "Type casting failure";
	}
}
