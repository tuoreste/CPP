/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:54:22 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:19:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {}

Dog::Dog(const Dog& other) : brain(new Brain(*(other.brain))) {}

Dog::~Dog() {
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

AAnimal* Dog::clone() const {
    return new Dog(*this);
}
