/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:35:40 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 00:28:00 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("John Doe", 151);
		std::cout << b1 << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
}
