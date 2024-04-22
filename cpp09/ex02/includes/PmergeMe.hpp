/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/22 16:54:39 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <exception>
# include <list>
# include <string>
# include <cstring>
# include <sys/stat.h>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <algorithm>

class PmergeMe {
	public:
		typedef std::vector<int>::iterator it;
		PmergeMe();
		~PmergeMe();
		void	duoMaker(std::vector<int> vector);

		class PmergeMe_Exception : public std::runtime_error {
			public:
				PmergeMe_Exception(const std::string &msg): std::runtime_error(msg) {}
		};
		std::vector<int> vector_c;
		std::list<int> list_c;
};

// template <typename T>
// typename T::iterator duoMaker(T& param1) {
// 	typedef typename T::value_type ValueType;
// 	typedef std::pair<ValueType, ValueType> PairType;

// 	T result;

// 	typename T::iterator it = param1.begin();
// 	while (it != param1.end()) {
// 		typename T::iterator next = it;
// 		++next;

// 		if (next == param1.end()) {
// 			result.push_back(*it);
// 			break;
// 		}

// 		PairType pair = std::make_pair(*it, *next);
// 		result.push_back(pair);

// 		it = next;
// 		++next;
// 	}

// 	param1 = result;

// 	return param1.end();
// }

#endif
