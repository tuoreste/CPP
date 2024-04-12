/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:24:43 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/12 14:27:52 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(const T& param1, int param2);

#include "easyfind.tpp"

#endif
