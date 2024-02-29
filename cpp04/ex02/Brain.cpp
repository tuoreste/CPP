/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:59 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 18:20:40 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Idea " + std::to_string(i + 1);
    }
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {}
