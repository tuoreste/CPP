/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:35:47 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 15:50:03 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm () : AForm("RobotomyRequestForm", 72, 45, "RobotGUY") {}

RobotomyRequestForm::RobotomyRequestForm (const std::string &target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm (){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkFormAction(executor);
	std::cout << "vvvvvvvvuvuvuvuuuvuvuu " << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << get_Target() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
