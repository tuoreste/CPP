/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/26 18:54:24 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

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
		Container duos;
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
void	 PmergeMe::ford_Johnson_vector(std::vector<int> &container) {
	std::vector<int> indexes;
	duoMaker<std::vector<int> >(container);
	sorter<std::vector<std::vector<int> > >(vector_pairs);
	separator<std::vector<std::vector<int> > >(vector_pairs);
	if (container.size() % 2 != 0)
		vector_smaller.push_back(container[container.size() - 1]);
	indexes = jacobsthal(vector_smaller.size());
	binaryInsertSortSmallBig(vector_bigger, vector_smaller, indexes);

	std::cout << "Before: ";
	for (std::vector<int> ::iterator it = vector_c.begin(); it != vector_c.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int> ::iterator it = vector_bigger.begin(); it != vector_bigger.end(); it++)
		std::cout << *it << " ";
}

void	 PmergeMe::ford_Johnson_deque(std::vector<int> &container) {
	//calls with deque container
	std::deque<int> indexes;
	duoMaker<std::deque<int> >(container);
	sorter<std::deque<std::deque<int> > >(deque_pairs);
	separator<std::deque<std::deque<int> > >(deque_pairs);
	if (container.size() % 2 != 0)
		deque_smaller.push_back(container[container.size() - 1]);
	indexes = jacobsthal(deque_smaller.size());
	binaryInsertSortSmallBig(deque_bigger, deque_smaller, indexes);

	std::cout << "Before: ";
	for (std::vector<int> ::iterator it = vector_c.begin(); it != vector_c.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int> ::iterator it = vector_bigger.begin(); it != vector_bigger.end(); it++)
		std::cout << *it << " ";
}
