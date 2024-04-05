/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:13:57 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/04 02:56:10 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm () : AForm("PresidentialPardonForm", 25, 5, "MARS") {}

PresidentialPardonForm::PresidentialPardonForm (const std::string &target) : AForm("PresidentialPardonForm", 145, 137, target) {}

PresidentialPardonForm::~PresidentialPardonForm (){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkFormAction(executor);
	std::cout << get_Target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

