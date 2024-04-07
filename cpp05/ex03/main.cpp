/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:19:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 15:46:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat				x("Jado", 100);

	Intern					student_intern;
	std::cout << std::endl;

	std::cout << "=======ShrubberyCreationForm=======" << std::endl;
	AForm *shrubbery = student_intern.makeForm("Shrubbery Creation", "42");
	x.signForm(*shrubbery);
	x.executeForm(*shrubbery);
	

	std::cout << "=======PresidentialPardonForm=======" << std::endl;
	x.increments(97);
	std::cout << x << std::endl;
	AForm *pardon = student_intern.makeForm("Presidential Pardon", "John Doe");
	x.signForm(*pardon);
	x.executeForm(*pardon);

	std::cout << "=======RobotomyRequestForm=======" << std::endl;
	x.decrements(50);
	std::cout << x << std::endl;
	AForm *robotomy = student_intern.makeForm("Robotomy Request", "Car");
	x.signForm(*robotomy);
	x.executeForm(*robotomy);
	
	std::cout << "=======Intern can't create illegal form=======" << std::endl;
	try {
		AForm *not_valid = student_intern.makeForm("Invalid", "42");
		std::cout << not_valid << std::endl;
	} catch (const std::string & e) {
		std::cout << e << std::endl;
	}
	delete shrubbery;
	delete pardon;
	delete robotomy;
}
