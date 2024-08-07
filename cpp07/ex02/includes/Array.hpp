/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:04:39 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/13 09:56:55 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template <class T>
class Array {
	public:
		Array();
		Array (size_t n);
		~Array();
		Array(const Array &other);
		Array<T>& operator=(const Array &other);

		T& operator[](unsigned int index);
		size_t size() const;
	private:
		size_t _n;
		T *array;
};

#include "../includes/Array.tpp"

#endif
