/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:31:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:25:39 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int animalCount = 6;
	AAnimal* animals[animalCount];

	for (int i = 0; i < animalCount / 2; ++i) {
		animals[i] = new Dog();
	}

	for (int i = animalCount / 2; i < animalCount; ++i) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < animalCount; ++i) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < animalCount; ++i) {
		delete animals[i];
	}

	return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;
// 	delete i;
// 	return 0;
// }
