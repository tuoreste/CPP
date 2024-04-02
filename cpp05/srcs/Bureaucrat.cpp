/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:19:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 00:24:12 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_Name(name) , _Grade(grade)
{
	if (grade < 1)
		throw std::string("Bureaucrat::GradeTooHighException");
	if (grade > 150)
		throw std::string("Bureaucrat::GradeTooLowException");
}

std::string	Bureaucrat::getName(void) const {
	return (this->_Name);
}

int			Bureaucrat::getGrade(void) const {
	return (this->_Grade);
}

void		Bureaucrat::increments(int gradeUp)
{
	if (_Grade - gradeUp < 1)
		throw std::string("Bureaucrat::GradeTooHighException");
	this->_Grade -= gradeUp;
}

void		Bureaucrat::decrements(int gradeDown)
{
	if (_Grade + gradeDown > 150)
		throw std::string("Bureaucrat::GradeTooLowException");
	this->_Grade += gradeDown;
}

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat)
{
	input << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (input);
}
