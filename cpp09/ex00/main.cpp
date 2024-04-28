/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:01:04 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 20:24:36 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <file path>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	obj;
		obj.file_reader(argv[1]);
	}
	catch(const BitcoinExchange::BtcException& e)
	{
		// std::cout << e << '\n';
	}
	return (0);
}
