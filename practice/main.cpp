/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:46:51 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/05 11:16:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main ()
{
	Employee employee1 = Employee("Saldina", "YT-Codebeauty", 25);
	employee1.introduceYourself();
	std::cout << "--------------------------------------"<< std::endl;
	Employee employee2 = Employee("John", "Amazon", 35);
	employee2.introduceYourself();
}
