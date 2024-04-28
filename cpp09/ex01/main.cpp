/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:57 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 12:30:26 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc < 2)
		{
			std::cout << "Error: Args numbers required" << std::endl;
			return (1);
		}
		RPN rpn;
		rpn.parse(argv[1]);
	}
	catch(const RPN::RPN_Exception& e)
	{
		// std::cout << e.what() << std::endl;
	}
	return (0);
}

