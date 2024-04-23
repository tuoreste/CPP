/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/23 10:34:48 by otuyishi         ###   ########.fr       */
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

template <typename T>
class PmergeMe {
	public:
		typedef typename T::iterator iterator;
		typedef typename T::value_type value_type;
	
		PmergeMe();
		~PmergeMe();
		typename T::iterator	duoMaker(T &container);

		class PmergeMe_Exception : public std::runtime_error {
			public:
				PmergeMe_Exception(const std::string &msg): std::runtime_error(msg) {}
		};
<<<<<<< HEAD
		typedef std::vector<int>::iterator it;
=======

		template <typename T>
		typename T::iterator	duoMaker(T &container);

>>>>>>> e15499d664138598d28bee02cf3949420f3fd059
		std::vector<int> vector_c;
		std::list<int> list_c;
};

#endif
