/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:19:33 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/05 07:15:09 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main()
{
	// try {
	// 	//Bureaucrat A("a", 151);
	// 	Bureaucrat B("b", 1);
	// } catch (const std::string & e) {
	// 	std::cout << e << std::endl;
	// }

	Bureaucrat A("a", 42);
	Bureaucrat B("b", 1);

	// try {
		// RobotomyRequestForm Robotomy("Robot");
		// A.signForm(Robotomy);
		// B.executeForm(Robotomy);

	// 	ShrubberyCreationForm Shrubbery("House");
	// 	A.signForm(Shrubbery);
	// 	// B.executeForm(Shrubbery);
	// } catch (const std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	PresidentialPardonForm Pardon("personUknown");
	A.signForm(Pardon);
	B.executeForm(Pardon);
}
