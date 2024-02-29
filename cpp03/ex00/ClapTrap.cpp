/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:48 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 13:08:59 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Constructor called for ClapTrap " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for ClapTrap " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " is out of energy and cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has no hit points left and cannot take any more damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints > 0) {
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " is destroyed and cannot be repaired!" << std::endl;
	}
}
