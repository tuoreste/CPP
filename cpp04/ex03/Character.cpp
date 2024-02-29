/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:06:13 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 20:06:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) : name(name) {
	for (int i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
}

Character::Character(const Character& other) : name(other.name) {
	for (int i = 0; i < 4; ++i) {
		if (other.inventory[i]) {
			inventory[i] = other.inventory[i]->clone();
		} else {
			inventory[i] = nullptr;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		delete inventory[i];
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; ++i) {
			delete inventory[i];
			if (other.inventory[i]) {
				inventory[i] = other.inventory[i]->clone();
			} else {
				inventory[i] = nullptr;
			}
		}
	}
	return *this;
}

const std::string& Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) return;
	inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !inventory[idx]) return;
	inventory[idx]->use(target);
}
