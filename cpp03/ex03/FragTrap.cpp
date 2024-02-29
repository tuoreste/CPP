/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:46:43 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/28 15:36:06 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name), ScavTrap(name) {
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(100);
	FragTrap::setAttackDamage(30);
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << ScavTrap::getName() << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "Positive high fives request!" << std::endl;
}
