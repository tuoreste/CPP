/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:31:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 16:41:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog() {
			type = "Dog";
			std::cout << "Dog constructor called" << std::endl;
		}
		~Dog() {
			std::cout << "Dog destructor called" << std::endl;
		}
		void makeSound() const {
			std::cout << "Woof!" << std::endl;
		}
};

class Cat : public Animal {
	public:
		Cat() {
			type = "Cat";
			std::cout << "Cat constructor called" << std::endl;
		}
		~Cat() {
			std::cout << "Cat destructor called" << std::endl;
		}
		void makeSound() const {
			std::cout << "Meow!" << std::endl;
		}
};

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}
