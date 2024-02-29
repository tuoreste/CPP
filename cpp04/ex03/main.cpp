/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:30:47 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/25 08:56:59 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	// Tst Char & MateriaSource
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// Tst deep cpy of Char
	Character original("original");
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	original.equip(src2->createMateria("ice"));
	Character copy = original;
	copy.use(0, original);

	// Tst unequip
	copy.unequip(0);
	copy.use(0, original);

	delete src2;

	return 0;
}
