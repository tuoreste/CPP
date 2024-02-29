/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:56:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 17:01:44 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Animal* Cat::clone() const {
	return new Cat(*this);
}
