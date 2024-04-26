/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/26 12:37:56 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::compar(const std::vector<int> &f, const std::vector<int> &s) {
	return (f[0] < s[0]);
}

void	PmergeMe::sorter(std::vector< std::vector<int> > &vector_double) {
	std::sort(vector_double.begin(), vector_double.end(), compar);
}

void	PmergeMe::separator(std::vector< std::vector<int> > sorted_duos) {
	for (std::vector< std::vector<int> >::iterator it = sorted_duos.begin(); it != sorted_duos.end(); it++)
	{
		vector_bigger.push_back((*it)[0]);
		vector_smaller.push_back((*it)[1]);
	}
}

void	PmergeMe::duoMaker(std::vector<int> vect) {
	for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter += 2) {
		std::vector<int> duos;
		if ((iter + 1) == vect.end())
		{
			duos.push_back(*iter);
			vector_pairs.push_back(duos);
			break ;
		}
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

void	PmergeMe::binaryInsertSortSmallBig(std::vector<int> &vector_b, std::vector<int> &vector_s, std::vector<int> &indexes) {
	typedef std::vector<int>::iterator	binary;
	vector_b.insert(vector_b.begin(), vector_s[0]);
	if (vector_s.size() > 1 && indexes.size() > 1)
	{
		binary i = std::lower_bound(vector_b.begin(), vector_b.end(), vector_s[1]);
		vector_b.insert(i, vector_s[1]);
	}
	for (size_t j = 2; j < indexes.size(); j++) {
		size_t	k = indexes[j - 1];
		size_t	z = indexes[j];
		if (z > vector_s.size() - 1)
			z = vector_s.size() - 1;
		while (z > k)
		{
			binary it = std::lower_bound(vector_b.begin(), vector_b.end(), vector_s[z]);
			// std::cout << *it << std::endl;
			vector_b.insert(it, vector_s[z]);
			z--;
		}
	}
}
