/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:09:07 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 20:09:25 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* learnedMaterias[4];
		int numLearned;
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};

#endif
