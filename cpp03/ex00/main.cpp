/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:10 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 13:11:36 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Police Officer");

	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);

	return 0;
}
