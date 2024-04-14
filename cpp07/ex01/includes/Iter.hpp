/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:23:24 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/13 09:22:40 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>
#include <vector>
#include <string>

//first parameter is address of an array.
//second one is length of an array.
//third one is a function that will be called on every element of the array.
template <typename T, typename Func>
void	iter(T *addres, size_t len, Func metho)
{
	for(size_t i = 0; i < len; ++i)
		metho(addres[i]);
}

void	tester(void);

#endif
