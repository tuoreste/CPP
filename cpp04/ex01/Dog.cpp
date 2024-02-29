/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:54:22 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 17:00:49 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Animal* Dog::clone() const {
	return new Dog(*this);
}
