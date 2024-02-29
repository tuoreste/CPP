/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:16:35 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 10:40:59 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	Fixed x;
	Fixed y(x);
	Fixed z;
	z = y;

	std::cout << x.getRawBits() << std::endl;
	std::cout << y.getRawBits() << std::endl;
	std::cout << z.getRawBits() << std::endl;

	return 0;
}
