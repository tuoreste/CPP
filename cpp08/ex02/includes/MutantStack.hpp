/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:09:41 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/14 22:28:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <deque>
#include <stack>
#include <vector>

//Write a MutantStack class
// will be implemented in terms of a std::stack
// It will offer all its member functions, plus an additional feature: iterators.
template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>(){}
		~MutantStack() {}
		MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
		MutantStack& operator=(const MutantStack &rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
};

#endif
