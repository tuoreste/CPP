/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:57 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/29 20:32:28 by otuyishi         ###   ########.fr       */
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

//test examples
// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error
// $> ./RPN 12 - 45 +
// Error
// $> ./RPN 12 - 45 + -
// Error
// $> ./RPN "12 - 45 + -"
// Error
// $> ./RPN 12 45 /
// 0.266667
