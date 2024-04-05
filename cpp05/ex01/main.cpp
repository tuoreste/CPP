/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:35:40 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 13:56:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("John Doe", 42);
		Form form("US Tax Form", 125, 2);
		b1.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
}
