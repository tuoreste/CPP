/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:44:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/23 10:26:26 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(){}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
<<<<<<< HEAD
typename T::iterator	PmergeMe<T>::duoMaker(T &container) {
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
=======
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
>>>>>>> e15499d664138598d28bee02cf3949420f3fd059
}
