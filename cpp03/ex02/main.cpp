/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:10 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 20:31:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	// Test ClapTrap
	ClapTrap claptrap("Clap");
	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	// Test ScavTrap
	ScavTrap scavtrap("Scav");
	scavtrap.attack("Bandit");
	scavtrap.guardGate();
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);

	// Testing FragTrap functionality
	FragTrap fragTrap("Fraggy");
	fragTrap.attack("Bandit");
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	return 0;
}