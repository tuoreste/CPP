/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:19:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 13:30:46 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat				X("Jado", 100);
	Bureaucrat				Y("Kumbani", 145);

	ShrubberyCreationForm	shrubbery_form("garden_Y");
	PresidentialPardonForm	presidents_form("Mr.Y");
	RobotomyRequestForm		robot_form("robot_Y");

	std::cout << std::endl;
	Y.executeForm(shrubbery_form);
	std::cout << std::endl;

	std::cout << "=======ShrubberyCreationForm=======" << std::endl;
	shrubbery_form.beSigned(Y);
	Y.executeForm(shrubbery_form);
	std::cout << std::endl;

	std::cout << "=======PresidentialPardonForm=======" << std::endl;
	presidents_form.beSigned(Y);
	Y.executeForm(presidents_form);
	std::cout << std::endl;

	std::cout << "=======RobotomyRequestForm=======" << std::endl;
	robot_form.beSigned(Y);
	Y.executeForm(robot_form);
	std::cout << std::endl;

	std::cout << "=======Forms below would throw error=======" << std::endl;
	try {
		X.executeForm(shrubbery_form);
	} catch (const std::string & e) {
		std::cout << e << std::endl;
	}
}
