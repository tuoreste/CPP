/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:09:41 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/15 12:48:34 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <exception>
#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>
#include <cmath>

class Span {
	public:
		Span();
		Span(const unsigned int &n);
		Span(const Span &other);
		~Span();
		Span& operator<<(const Span &other);

		void			addNumber(unsigned int addMe);		
		unsigned int	shortestSpan();
		unsigned int	longestSpan() const;;
		void			print() const;

		template <typename Container>
		void	range_of_iterators(Container &container) {
			_Cont.insert(_Cont.end(), container.begin(), container.end());
		}

		class excepioN: public std::runtime_error {
			public:
				excepioN(const std::string& str_sms);
		};

	private:
		unsigned int		_N;
		std::vector<int>	_Cont;
};

#endif
