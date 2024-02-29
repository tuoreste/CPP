/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:32:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:23:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}
