/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:02:52 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/23 13:52:16 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstring>

class Zombie {
	private:
		std::string name;

	public:
		Zombie(std::string name) : name(name) {}
		~Zombie();
		void announce() const;
};

int		main();
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
