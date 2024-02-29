/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:46:43 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/28 12:30:12 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ScavTrap(name) {
	ScavTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(100);
	ScavTrap::setAttackDamage(30);
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << ScavTrap::getName() << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "Positive high fives request!" << std::endl;
}
