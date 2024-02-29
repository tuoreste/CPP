/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:13:59 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 14:38:43 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(Fixed const &x, Fixed const &y) : x(x), y(y) {}

Point::Point(Point const &src) : x(src.getX()), y(src.getY()) {}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
    if (this != &rhs) {
        // Copy the values from rhs to this object
        this->x = rhs.getX();
        this->y = rhs.getY();
    }
    return *this;
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

Point Point::operator-(Point const &rhs) const {
    return Point(this->getX() - rhs.getX(), this->getY() - rhs.getY());
}

Point Point::operator*(Point const &rhs) const {
    return Point(this->getX() * rhs.getX(), this->getY() * rhs.getY());
}

Point Point::operator/(Fixed const& scalar) const {
    if (scalar == Fixed(0)) { // Check if scalar is zero
        std::cerr << "Error: division by zero" << std::endl;
        return Point();
    }

    // Cast non-const member variables to temporary values for division
    return Point((Fixed)(x) / scalar, static_cast<Fixed>(y) / scalar);
}
