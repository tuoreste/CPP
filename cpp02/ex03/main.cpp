/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:16:35 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 18:25:42 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main() {
	Point a(0, 0);
	Point b(0, 4);
	Point c(4, 0);
	Point p1(20, 1);
	Point p2(1, 0);
	Point p3(15, 5);
	Point p4(0, 4);

	std::cout << "Is point p1 inside the triangle? " <<  bsp(a, b, c, p1) << std::endl;
	std::cout << "Is point p2 inside the triangle? " <<  bsp(a, b, c, p2) << std::endl;
	std::cout << "Is point p3 inside the triangle? " <<  bsp(a, b, c, p3) << std::endl;
	std::cout << "Is point p4 inside the triangle? " <<  bsp(a, b, c, p4) << std::endl;

	return 0;
}

