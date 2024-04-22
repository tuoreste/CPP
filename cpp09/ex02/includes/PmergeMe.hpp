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

		template <typename T>
		typename T::iterator	duoMaker(T &container);

		std::vector<int> vector_c;
		std::list<int> list_c;
};

#endif
