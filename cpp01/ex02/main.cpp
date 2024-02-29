/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:14:49 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/21 14:33:15 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string &stringREF = brain;
	std::string *stringPTR = &brain;

	std::cout << brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
