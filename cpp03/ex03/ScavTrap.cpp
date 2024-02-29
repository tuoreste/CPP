/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:10:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 19:49:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (getEnergyPoints() > 0) {
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    } else {
        std::cout << "ScavTrap " << getName() << " is out of energy and cannot attack!" << std::endl;
    }
}

unsigned int ScavTrap::getHitPoints() const {
    return hitPoints;
}

void ScavTrap::setHitPoints(unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}

unsigned int ScavTrap::getEnergyPoints() const {
    return energyPoints;
}

void ScavTrap::setEnergyPoints(unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}

unsigned int ScavTrap::getAttackDamage() const {
    return attackDamage;
}

void ScavTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}

std::string ScavTrap::getName() const {
    return name;
}

void ScavTrap::setName(const std::string& name) {
    this->name = name;
}
