/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/27 18:21:39 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int size){
	vector_c.reserve(size);
}

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

bool PmergeMe::is_sorted(std::vector<int> data) {
	for (unsigned int i = 1; i < data.size(); ++i) {
		if (data[i] < data[i - 1]) {
			return false;
		}
	}
	return true;
}

void	PmergeMe::parse(std::string argv) {
	std::istringstream ss(argv);
	std::string token;
	int num;
	ss >> num;
	if (ss.eof() != true || num < 0)
		throw PmergeMe::PmergeMe_Exception("Error");
	setVector_c(num);
	setDeque_c(num);
}

//========================================================================//
//							VECTOR CONTAINER							  //
//========================================================================//

bool	PmergeMe::compar(const std::vector<int> &f, const std::vector<int> &s) {
	return (f[0] < s[0]);
}

template	<typename Container>
void	PmergeMe::sorter(Container &container_double) {
	std::sort(container_double.begin(), container_double.end(), compar);
}

template	<typename Container>
void	PmergeMe::separator(Container &sorted_duos) {
	for (typename Container::iterator iter = sorted_duos.begin(); iter != sorted_duos.end(); iter++)
	{
		vector_bigger.push_back((*iter)[0]);
		vector_smaller.push_back((*iter)[1]);
	}
}

template	<typename Container>
void		PmergeMe::duoMaker(const Container &vect) {
	for (typename Container::const_iterator iter = vect.begin(); iter != vect.end(); iter += 2) {
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

template	<typename Container>
void	PmergeMe::binaryInsertSortSmallBig(Container &container_b, Container &container_s, std::vector<int> &indexes) {
	container_b.insert(container_b.begin(), container_s[0]);
	if (container_s.size() > 1 && indexes.size() > 1)
	{
		typename Container::iterator i = std::lower_bound(container_b.begin(), container_b.end(), container_s[1]);
		container_b.insert(i, container_s[1]);
	}
	for (size_t j = 2; j < indexes.size(); j++) {
		size_t	k = indexes[j - 1];
		size_t	z = indexes[j];
		if (z > container_s.size() - 1)
			z = container_s.size() - 1;
		while (z > k)
		{
			typename Container::iterator it = std::lower_bound(container_b.begin(), container_b.end(), container_s[z]);
			container_b.insert(it, container_s[z]);
			z--;
		}
	}
}

//calls with vector container
void	 PmergeMe::ford_Johnson_vector(std::vector<int> vec) {
	std::vector<int> indexes;

	clock_t	start = clock();
	duoMaker<std::vector<int> >(vec);
	sorter<std::vector<std::vector<int> > >(vector_pairs);
	separator<std::vector<std::vector<int> > >(vector_pairs);
	if (vec.size() % 2 != 0)
		vector_smaller.push_back(vec[vec.size() - 1]);
	indexes = jacobsthal(vector_smaller.size());
	binaryInsertSortSmallBig(vector_bigger, vector_smaller, indexes);
	clock_t	finish = clock();
	double duration = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

	std::cout << "=======================using vectors==========================" << std::endl;
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

//========================================================================//
//							DEQUE CONTAINER								  //
//========================================================================//

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

// //sort duos
void		PmergeMe::sortDeque(std::deque<std::pair<int, int> > &deques_double) {
	std::sort(deques_double.begin(), deques_double.end());
}

// //duos separating
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
void	 PmergeMe::ford_Johnson_deque(std::deque<int> deq) {
	std::deque<int> indexes;

	clock_t	start = clock();
	duoMakerDeque(deq);
	sortDeque(deque_pairs);
	separatorDeque(deque_pairs);
	if (deq.size() % 2 != 0)
		deque_smaller.push_back(deq[deq.size() - 1]);
	indexes = jacobsthalDeque(deque_smaller.size());
	binaryInsertSortSmallBigDeque(deque_bigger, deque_smaller, indexes);
	clock_t	finish = clock();
	double duration = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

	std::cout << "=======================using deque============================" << std::endl;
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
