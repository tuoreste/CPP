/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:13:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 15:19:14 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;

	public:
		Point();
		Point(Fixed const &x, Fixed const &y);
		Point(Point const &src);
		~Point();

		Point &operator=(Point const &rhs);

		Fixed getX() const;
		Fixed getY() const;

		Point operator-(Point const &rhs) const;
		Point operator*(Point const &rhs) const;
		Point operator/(Fixed const& scalar) const;
};

#endif
