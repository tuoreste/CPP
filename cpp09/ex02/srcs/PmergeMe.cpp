/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/22 16:19:06 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

template <typename T>
typename T::iterator	PmergeMe::duoMaker(T &container) {
	typedef typename T::value_type  ContentType;
    typedef std::pair<ContentType, ContentType> DuoType;
    T   res;
    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        typename T::iterator next = it;
        ++next;
        if (next == container.end()) {
            res.push_back(*it);
            break ;
        }
        DuoType duo = std::make_pair(*it, *next);
        res.push_back(duo);
        it = next;
        ++next;
    }
    container = res;
    return (container.end());
}
