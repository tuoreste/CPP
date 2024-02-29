/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:10:07 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/26 16:37:43 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB() {
}

void HumanB::attack() const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks unarmed" << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon) {
	if (weapon != NULL) {
		delete weapon;
	}
	weapon = &newWeapon;
}
