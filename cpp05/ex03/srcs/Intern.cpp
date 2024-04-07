/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:22:27 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 15:48:18 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &equal)
{
	(void)equal;
	return (*this);
}

AForm*	newShrubbery(const std::string target){
	return new ShrubberyCreationForm(target);
}

AForm*	newRobot(const std::string target){
	return new RobotomyRequestForm(target);
}

AForm*	newPresident(const std::string target){
	return new PresidentialPardonForm(target);
}

typedef	AForm* (*FormBuilderPtr)(std::string);

AForm*	Intern::makeForm(std::string name, std::string target)
{
	FormBuilderPtr	builtForm[3] = { 
		&newShrubbery, &newRobot, &newPresident
	};

	const std::string	forms_names[] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon",
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms_names[i])
		{
			std::cout << "Intern creates " << forms_names[i] << std::endl;
			return builtForm[i](target);
		}
	}
	throw std::string("Oops! Enschuldigung ungültig bilden, Dankeschöne!");
	return (NULL);
}
