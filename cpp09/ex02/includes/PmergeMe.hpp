/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/26 13:28:16 by otuyishi         ###   ########.fr       */
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
		std::vector<int> vector_bigger;
		std::vector<int> vector_smaller;
		std::vector<int> indexes;


		void				duoMaker(const std::vector<int> vect);
		static 	bool		compar(const std::vector<int> &f, const std::vector<int> &s);
		void				sorter(std::vector< std::vector<int> > &vector_double);
		void				separator(std::vector< std::vector<int> > sorted_duos);
		std::vector<int>	jacobsthal(int n);
		void				binaryInsertSortSmallBig(std::vector<int> &vector_b, std::vector<int> &vector_s, std::vector<int> &indexes);
};

#endif
