/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:41:52 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/28 15:36:17 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << name << ", and my ClapTrap name is " << this->getName() << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name + "_frag_name"), name(name) {
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergyPoints(50);
	this->FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

