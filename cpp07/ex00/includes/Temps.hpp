/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Temps.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:07:26 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/15 10:35:08 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPS
# define TEMPS

#include <iostream>

//swap: Swaps the values of two given arguments. Does not return anything.
template <typename T>
void swap(T &x, T &y)
{
	T s = x;
	x = y;
	y = s;
}

// min: Compares the two values passed in its arguments and returns the smallest
// one. If the two of them are equal, then it returns the second one.
template <typename T>
T min(const T &first, const T &second)
{
	return first < second ? first : second;
}

// max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
T max(const T &first, const T &second)
{
	return first > second ? first : second;
}

void	tester(void);

#endif
