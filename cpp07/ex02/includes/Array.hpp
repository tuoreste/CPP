/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:04:39 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 21:39:51 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template <class T>
class Array {
	public:
		Array();
		Array (unsigned int n) {
			
		}
		~Array(){}
		Array(const string& other) {}
	private:
	size_t _n;
	T *array;
};

template <typename T>
Array<T>::Array() : _n(0), array(NULL) {}

#endif
