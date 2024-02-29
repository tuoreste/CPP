/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:10:08 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 20:12:25 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
		unsigned int getHitPoints() const;
		void setHitPoints(unsigned int hitPoints);
		
		unsigned int getEnergyPoints() const;
		void setEnergyPoints(unsigned int energyPoints);
		
		unsigned int getAttackDamage() const;
		void setAttackDamage(unsigned int attackDamage);
		
		std::string getName() const;
		void setName(const std::string& name);
};

#endif
