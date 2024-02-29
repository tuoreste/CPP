/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:30:40 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:35:56 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
