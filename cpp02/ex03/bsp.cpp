/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:14:06 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/27 18:34:57 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"
# include "Fixed.hpp"
# include "Point.hpp"

Fixed       s_area(Point const a, Point const b, Point const c)
{
    Fixed det_area = ((a.getX() * (b.getY() - c.getY()) +
                     b.getX() * (c.getY() - a.getY()) + 
                     c.getX() * (a.getY() - b.getY())) / 2);

	if (det_area < 0)
		det_area = det_area * -1;
    return (det_area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed w = s_area(a, b, c);
    Fixed w1 = s_area(point, b, c);
    Fixed w2 = s_area(a, point, c);
    Fixed w3 = s_area(a, b, point);
    return (w == w1 + w2 + w3);
}


