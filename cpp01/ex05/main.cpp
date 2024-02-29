/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:43:04 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 10:33:44 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain(DEBUG);
    harl.complain(INFO);
    harl.complain(WARNING);
    harl.complain(ERROR);
    return 0;
}
