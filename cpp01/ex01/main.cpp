/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:47:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/23 16:04:31 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int numZombies = 10;
	std::string zombieName = "Mr. Zombie";

	Zombie* horde = zombieHorde(numZombies, zombieName);
	for (int i = 0; i < numZombies; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
