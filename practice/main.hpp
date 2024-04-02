/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:45:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/05 12:56:34 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
using std::string;

class Employee
{
	//by default attributes are private until a specific access modifier is declared
	string	I_am_private;
	private:
		string Name;
		string Company;
		int Age;

	public:

		void	introduceYourself() {
			std::cout << "Name  " << Name << std::endl;
			std::cout << "Company  " << Company << std::endl;
			std::cout << "Age  " << Age << std::endl;
		}
		Employee(string name, string company, int age) {
			Name = name;
			Company = company;
			Age = age;
		}
};
#endif