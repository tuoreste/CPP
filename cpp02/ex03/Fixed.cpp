/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:16:22 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 14:43:54 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) : value(value << fractionalBits) {}

Fixed::Fixed(const float value) : value(roundf(value * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		value = other.value;
	}
	return *this;
}

float Fixed::toFloat() const {
	return (float)(value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return value >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
	return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	++value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--() {
	--value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return os << fixed.toFloat();
}
