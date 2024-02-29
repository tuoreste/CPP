/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:56:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:19:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {}

Cat::Cat(const Cat& other) : brain(new Brain(*(other.brain))) {}

Cat::~Cat() {
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}

AAnimal* Cat::clone() const {
    return new Cat(*this);
}
