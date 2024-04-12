/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:04:39 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/11 19:12:07 by otuyishi         ###   ########.fr       */
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

// #include "../includes/Array.tpp"

template <typename T>
Array<T>::Array() : _n(0), array(NULL) {}

template <typename T>
Array<T>::Array(size_t size) : 
	_n(size),
	array(new T[size])	{
    for (size_t i = 0; i < _n; i++)
        array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &other) : 
	_n(other._n), 
	array(new T[_n]) {
    for (size_t i = 0; i < _n; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] array;
		array = NULL;
        _n = other._n;
		if (_n > 0)
        	array = new T[_n];
        for (size_t i = 0; i < _n; i++) {
            this->array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _n)
        throw std::out_of_range("Out of range");
    return array[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _n;
}

#endif
