/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 19:00:27 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {
	(void)cpy;
}
		
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return (*this);
}

std::vector<int>	PmergeMe::getVector_c(void) const {
	return (vector_c);
}

std::deque<int>		PmergeMe::getDeque_c(void) const {
	return (deque_c);
}

void				PmergeMe::setVector_c(int num) {
	this->vector_c.push_back(num);
}

void				PmergeMe::setDeque_c(int num) {
	this->deque_c.push_back(num);
}

//==============================vector container========================

// //vect sorting check point
// void	PmergeMe::sortCheckVec(const std::vector<int> &vec) {
// 	for (size_t i = 1; i < vec.size(); i++) {
// 		if (vec[i] < vec[i - 1])
// 			throw PmergeMe_Exception("Die Eingabe ist sortiert, Danke.");
// 	}
// 	return ;
// }

//parsing vect
void	PmergeMe::parseVector(int argc, char **argv) {
	if (argc < 2)
		throw PmergeMe_Exception("Usage: Exec <input1> <input2>");
	for (int i = 1; i < argc; ++i) {
		std::istringstream ss(argv[i]);
		std::string token;
		if (argv[i] == '\0')
			break ;
		int num;
		ss >> num;
		if (ss.eof() != true || num < 0)
			throw PmergeMe::PmergeMe_Exception("Error");
		vector_c.push_back(num);
		ss.clear();
	}
}

//sorting the duos on deq
void PmergeMe::mergeInsertSortVect(std::vector<std::vector<int> > &double_vec) {
	if (double_vec.size() <= 1)
		return;
	size_t mid = double_vec.size() / 2;
	std::vector<std::vector<int> > left(double_vec.begin(), double_vec.begin() + mid);
	std::vector<std::vector<int> > right(double_vec.begin() + mid, double_vec.end());
	mergeInsertSortVect(left);
	mergeInsertSortVect(right);
	std::merge(left.begin(), left.end(), right.begin(),
				right.end(), double_vec.begin());
}

void	PmergeMe::separatorVector(std::vector<std::vector<int> > &sorted_duos) {
	for (std::vector<std::vector<int> >::const_iterator iter = sorted_duos.begin(); iter != sorted_duos.end(); iter++)
	{
		vector_bigger.push_back((*iter)[0]);
		vector_smaller.push_back((*iter)[1]);
	}
}

void		PmergeMe::duoMakerVect(const std::vector<int> &vect) {
	for (std::vector<int>::const_iterator iter = vect.begin(); iter != vect.end(); iter += 2) {
		std::vector<int> duos;
		if ((iter + 1) == vect.end())
			break ;
		duos.push_back(std::max(*iter, *(iter + 1)));
		duos.push_back(std::min(*iter, *(iter + 1)));
		vector_pairs.push_back(duos);
	}
}

std::vector<int>	PmergeMe::jacobsthal(int n)
{
	std::vector<int>	indexes;
	if (n > 0)
		indexes.push_back(0);
	if (n > 1)
		indexes.push_back(1);
	int	i = 2;
	while (1)
	{
		int index = indexes[i - 1] + 2 * indexes[i - 2];
		indexes.push_back(index);
		if (n < indexes[i])
			break ;
		i++;
	}
	return (indexes);
}

void	PmergeMe::binaryInsertSortSmallBig(std::vector<int> &vect_b, std::vector<int> &vect_s, std::vector<int> &indexes) {
	vect_b.insert(vect_b.begin(), vect_s[0]);
	if (vect_s.size() > 1 && indexes.size() > 1)
	{
		std::vector<int>::iterator i = std::lower_bound(vect_b.begin(), vect_b.end(), vect_s[1]);
		vect_b.insert(i, vect_s[1]);
	}
	for (size_t j = 2; j < indexes.size(); j++) {
		size_t	k = indexes[j - 1];
		size_t	z = indexes[j];
		if (z > vect_s.size() - 1)
			z = vect_s.size() - 1;
		while (z > k)
		{
			std::vector<int>::iterator it = std::lower_bound(vect_b.begin(), vect_b.end(), vect_s[z]);
			vect_b.insert(it, vect_s[z]);
			z--;
		}
	}
}

//calls with vector container
void	 PmergeMe::ford_Johnson_vector(int argc, char **argv) {
	std::vector<int> indexes;

	std::cout << "//===========================================//" << std::endl;
	std::cout << "//    	    VECTOR CONTAINER		     //" << std::endl;
	std::cout << "//===========================================//" << std::endl;
	clock_t	start = clock();
	parseVector(argc, argv);
	// sortCheckVec(vector_c);
	duoMakerVect(vector_c);
	mergeInsertSortVect(vector_pairs);
	separatorVector(vector_pairs);
	if (vector_c.size() % 2 != 0)
		vector_smaller.push_back(vector_c[vector_c.size() - 1]);
	indexes = jacobsthal(vector_smaller.size());
	binaryInsertSortSmallBig(vector_bigger, vector_smaller, indexes);
	clock_t	finish = clock();
	double duration = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

	std::cout << "Before: ";
	for (std::vector<int> ::iterator it = vector_c.begin(); it != vector_c.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int> ::iterator it = vector_bigger.begin(); it != vector_bigger.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vector_c.size() << " elements with std::vector<int> : " << duration << "ms" << std::endl;
	std::cout << std::endl;
}

//==============================deque container========================

//deque sorting check point
// void	PmergeMe::sortCheckDeq(const std::deque<int> &deq) {
// 	for (size_t i = 0; i < deq.size() - 1; i++) {
// 		if (deq[i] < deq[i + 1])
// 			throw PmergeMe_Exception("Die Eingabe ist sortiert, Danke.");
// 	}
// 	return ;
// }

//parsing deq
void	PmergeMe::parseDeque(int argc, char **argv) {
	if (argc < 2)
		throw PmergeMe_Exception("Usage: Exec <input1> <input2>");
	for (int i = 1; i < argc; ++i) {
		std::istringstream ss(argv[i]);
		std::string token;
		int num;
		ss >> num;
		if (ss.eof() != true || num < 0)
			throw PmergeMe::PmergeMe_Exception("Error");
		deque_c.push_back(num);
		ss.clear();
	}
}

//make duos
void		PmergeMe::duoMakerDeque(std::deque<int> &deque) {
	for (std::deque<int>::iterator iter = deque.begin(); iter != deque.end(); iter += 2) {
		std::pair<int, int> duos;
		if ((iter + 1) == deque.end())
			break ;
		int duo1 = std::max(*iter, *(iter + 1));
		int duo2 = std::min(*iter, *(iter + 1));
		duos = std::make_pair(duo1, duo2);
		deque_pairs.push_back(duos);
	}
}

//sorting the duos
void PmergeMe::mergeInsertSortDeque(std::deque<std::pair<int, int> > &double_deq) {
	if (double_deq.size() <= 1)
		return;
	size_t mid = double_deq.size() / 2;
	std::deque<std::pair<int, int> > left(double_deq.begin(), double_deq.begin() + mid);
	std::deque<std::pair<int, int> > right(double_deq.begin() + mid, double_deq.end());
	mergeInsertSortDeque(left);
	mergeInsertSortDeque(right);
	std::merge(left.begin(), left.end(), right.begin(),
				right.end(), double_deq.begin());
}

//duos separating
void		PmergeMe::separatorDeque(std::deque<std::pair<int, int> > &deques_double_sorted) {
	for (std::deque<std::pair<int, int> >::iterator iter = deques_double_sorted.begin(); iter != deques_double_sorted.end(); iter++)
	{
		deque_bigger.push_back(iter->first);
		deque_smaller.push_back(iter->second);
	}
}

//return me the indexes in accordance to the smaller container
std::deque<int>	PmergeMe::jacobsthalDeque(int n) {
	std::deque<int>	indexes;

	if (n > 0)
		indexes.push_back(0);
	if (n > 1)
		indexes.push_back(1);
	int	i = 2;
	while (1)
	{
		int index = indexes[i - 1] + 2 * indexes[i - 2];
		indexes.push_back(index);
		if (n < indexes[i])
			break ;
		i++;
	}
	return (indexes);
}

//binary sorting, final sort stagetemplate	<typename Container>
void		PmergeMe::binaryInsertSortSmallBigDeque(std::deque<int> &deque_b, std::deque<int> &deque_s, std::deque<int> &indexes) {
	deque_b.insert(deque_b.begin(), deque_s[0]);
	if (deque_s.size() > 1 && indexes.size() > 1)
	{
		std::deque<int>::iterator i = std::lower_bound(deque_b.begin(), deque_b.end(), deque_s[1]);
		deque_b.insert(i, deque_s[1]);
	}
	for (size_t j = 2; j < indexes.size(); j++) {
		size_t	k = indexes[j - 1];
		size_t	z = indexes[j];
		if (z > deque_s.size() - 1)
			z = deque_s.size() - 1;
		while (z > k)
		{
			std::deque<int>::iterator it = std::lower_bound(deque_b.begin(), deque_b.end(), deque_s[z]);
			deque_b.insert(it, deque_s[z]);
			z--;
		}
	}
}

//Ford-Johnson algo for deque
void	 PmergeMe::ford_Johnson_deque(int argc, char **argv) {
	std::deque<int> indexes;

	std::cout << "//===========================================//" << std::endl;
	std::cout << "//    	   DEQUE CONTAINER		     //" << std::endl;
	std::cout << "//===========================================//" << std::endl;
	clock_t	start = clock();
	parseDeque(argc, argv);
	// sortCheckDeq(deque_c);
	duoMakerDeque(deque_c);
	mergeInsertSortDeque(deque_pairs);
	separatorDeque(deque_pairs);
	if (deque_c.size() % 2 != 0)
		deque_smaller.push_back(deque_c[deque_c.size() - 1]);
	indexes = jacobsthalDeque(deque_smaller.size());
	binaryInsertSortSmallBigDeque(deque_bigger, deque_smaller, indexes);
	clock_t	finish = clock();
	double duration = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

	std::cout << "Before: ";
	for (std::deque<int> ::iterator it = deque_c.begin(); it != deque_c.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::deque<int> ::iterator it = deque_bigger.begin(); it != deque_bigger.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << deque_c.size() << " elements with std::deque<int> : " << duration << "ms" << std::endl;
}
