/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:35:40 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 11:57:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int	main()
{
	try {
			Form form2("Bank_Form", 45, 56);
			Bureaucrat A("Harsh", 12);
			std::cout << form2 << std::endl;
			A.signForm(form2);
			std::cout << form2 << std::endl;
			std::cout << "==========================" << std::endl;
			A.decrements(100);
			A.signForm(form2);
			std::cout << A << std::endl;
			std::cout << "==========================" << std::endl;
			A.increments(100);
			A.signForm(form2);
			std::cout << A << std::endl;
			std::cout << "==========================" << std::endl;
		} catch (const std::runtime_error &e) {
			std::cerr << e.what() << std::endl;
	}
	return 0;
}
