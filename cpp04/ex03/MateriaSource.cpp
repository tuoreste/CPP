/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:09:32 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 20:10:00 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : numLearned(0) {
	for (int i = 0; i < 4; ++i) {
		learnedMaterias[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < numLearned; ++i) {
		delete learnedMaterias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (numLearned >= 4 || !m) return;
	learnedMaterias[numLearned++] = m->clone();
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < numLearned; ++i) {
		if (learnedMaterias[i]->getType() == type) {
			return learnedMaterias[i]->clone();
		}
	}
	return nullptr;
}
