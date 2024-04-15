/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:23:02 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/15 16:02:38 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyFind(T& param1, int param2)
{
	typename T::iterator i = std::find(param1.begin(), param1.end(), param2);
	if (i != param1.end())
	{
		std::cout << "Param2 Found Successfully" << std::endl;
		return (i);
	}
	else
		throw std::string("Unfortunately Param2 not Found");
}
