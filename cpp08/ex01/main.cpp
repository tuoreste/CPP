/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:12:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/14 20:26:00 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const Span::excepioN& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const Span::excepioN& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
