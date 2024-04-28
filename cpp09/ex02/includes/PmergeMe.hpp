/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 19:00:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <exception>
# include <ctime>
# include <algorithm>
# include <deque>


class PmergeMe {
	public:
		PmergeMe();

		~PmergeMe();

		PmergeMe(const PmergeMe& cpy);
		
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>	getVector_c(void) const;

		std::deque<int>		getDeque_c(void) const;

		void				setVector_c(int num);

		void				setDeque_c(int num);

		void				parseVector(int argc, char **argv);

		void				parseDeque(int argc, char **argv);
		
		class PmergeMe_Exception : public std::runtime_error {
			public:
				PmergeMe_Exception(const std::string &msg): std::runtime_error(msg) {}
		};

		//=================================Vectors================================//
		//vec sorting check point
		// void 		sortCheckVec(const std::vector<int> &vec);
		//Ford-Johnson algo for vector
		void		ford_Johnson_vector(int argc, char **argv);
		//make duos
		void		duoMakerVect(const std::vector<int> &vect);
		//sort duos
		void		mergeInsertSortVect(std::vector<std::vector<int> > &double_vec);
		//duos separating
		void		separatorVector(std::vector<std::vector<int> > &sorted_duos);
		//return me the indexes in accordance to the smaller container
		std::vector<int>	jacobsthal(int n);
		//binary sorting, final sort stagetemplate	<typename Container>
		void		binaryInsertSortSmallBig(std::vector<int> &vect_b, std::vector<int> &vect_s, std::vector<int> &indexes);

		//=================================DEQUE================================//
		//deque sorting check point
		// void		sortCheckDeq(const std::deque<int> &deq);
		//Ford-Johnson algo for deque
		void		ford_Johnson_deque(int argc, char **argv);
		//make duos
		void		duoMakerDeque(std::deque<int> &d);
		//sort duos
		void		mergeInsertSortDeque(std::deque<std::pair<int, int> > &double_deq);
		//duos separating
		void		separatorDeque(std::deque<std::pair<int, int> > &deques_double_sorted);
		//return me the indexes in accordance to the smaller container
		std::deque<int>	jacobsthalDeque(int n);
		//binary sorting, final sort stagetemplate	<typename Container>
		void		binaryInsertSortSmallBigDeque(std::deque<int> &deque_b, std::deque<int> &deque_s, std::deque<int> &indexes);

	private:
		
		//vector container
		std::vector<int> vector_c;
		std::vector< std::vector<int> > vector_pairs;
		std::vector<int> vector_bigger;
		std::vector<int> vector_smaller;

		//deque container
		std::deque<int> deque_c;
		std::deque< std::pair<int, int> > deque_pairs;
		std::deque<int> deque_bigger;
		std::deque<int> deque_smaller;
};

#endif
