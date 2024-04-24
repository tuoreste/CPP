/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/24 20:58:24 by otuyishi         ###   ########.fr       */
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
