/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/24 18:29:29 by otuyishi         ###   ########.fr       */
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
		PmergeMe();
		~PmergeMe();
		
		class PmergeMe_Exception : public std::runtime_error {
			public:
				PmergeMe_Exception(const std::string &msg): std::runtime_error(msg) {}
		};
		//vector container
		std::vector<int> vector_c;
		std::vector< std::vector<int> > vector_pairs;

		//list container
		std::list<int> list_c;
		std::list< std::vector<int> > list_pairs;

		void	duoMaker(const std::vector<int> vect);
		static 	bool	compar(const std::vector<int> &f, const std::vector<int> &s);
		void	sorter(std::vector< std::vector<int> > vector_double);
};

// # include "PmergeMe.tpp"

#endif
