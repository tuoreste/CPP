/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:06:49 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/26 16:34:43 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanB.hpp
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(std::string name) : name(name), weapon(NULL) {}
		HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {}
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& newWeapon);
};

#endif
