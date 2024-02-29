/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:10 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 19:21:23 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	// Test ClapTrap
	ClapTrap claptrap("Clap");
	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	// Test ScavTrap
	ScavTrap scavtrap("Scav");
	scavtrap.attack("Bandit");
	scavtrap.guardGate(); // Test special capacity
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);

	return 0;
}
