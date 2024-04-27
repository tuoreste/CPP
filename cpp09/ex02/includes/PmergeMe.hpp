/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:29 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/27 18:18:32 by otuyishi         ###   ########.fr       */
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

		PmergeMe(int size);

		PmergeMe(const PmergeMe& cpy);
		
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>	getVector_c(void) const;

		std::deque<int>		getDeque_c(void) const;

		void				setVector_c(int num);

		void				setDeque_c(int num);

		void	parse(std::string argv);

		bool 	is_sorted(std::vector<int> data);
		
		class PmergeMe_Exception : public std::runtime_error {
			public:
				PmergeMe_Exception(const std::string &msg): std::runtime_error(msg) {}
		};

		//=================================Vectors================================//
		//Ford-Johnson algo for vector
		void		ford_Johnson_vector(std::vector<int> vec);
		//make duos
		template	<typename Container>
		void		duoMaker(const Container &vect);
		//compare duos true or false
		static 	bool		compar(const std::vector<int> &f, const std::vector<int> &s);
		//sort duos
		template	<typename Container>
		void		sorter(Container &container_double);

		//duos separating
		template	<typename Container>
		void		separator(Container &sorted_duos);

		//return me the indexes in accordance to the smaller container
		std::vector<int>	jacobsthal(int n);

		//binary sorting, final sort stagetemplate	<typename Container>
		template	<typename Container>
		void		binaryInsertSortSmallBig(Container &container_b, Container &container_s, std::vector<int> &indexes);

		//=================================DEQUE================================//
		//Ford-Johnson algo for deque
		void		ford_Johnson_deque(std::deque<int> deq);
		//make duos
		void		duoMakerDeque(std::deque<int> &d);
		//sort duos
		void		sortDeque(std::deque<std::pair<int, int> > &deques_double);
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
