/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:16:22 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 17:39:03 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

float Fixed::toFloat() const {
	return (float)value / (float)(1 << fractionalBits);
}

int Fixed::toInt() const {
	return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return os << fixed.toFloat();
}

int Fixed::getRawBits(void)const{
    return (value);    
}

void Fixed::setRawBits(int const raw){
    this->value = raw;
}
