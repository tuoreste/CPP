/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:10 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/28 15:37:38 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	// Tst ClapTrap
	ClapTrap claptrap("Clap");
	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	// Tst ScavTrap
	ScavTrap scavtrap("Scav");
	scavtrap.attack("Bandit");
	scavtrap.guardGate();
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);

	// Tst FragTrap
	FragTrap fragTrap("Frag");
	fragTrap.attack("Bandit");
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();

	// Tst DiamondTrap
	DiamondTrap diamondTrap("Diamond");
	diamondTrap.attack("Enemy");
	diamondTrap.takeDamage(15);
	diamondTrap.beRepaired(7);
	diamondTrap.whoAmI();

	return 0;
}