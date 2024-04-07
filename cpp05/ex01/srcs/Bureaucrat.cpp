/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:59:50 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/05 16:49:48 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::High::High(const std::string str_sms) : runtime_error(str_sms) {}

Bureaucrat::Low::Low(const std::string str_sms) : runtime_error(str_sms) {}

Bureaucrat::Bureaucrat() : _Name("default"), _Grade(0) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_Name(name), _Grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::High("Exception: " + name + " 's grade is Too High");
	if (grade > 150)
		throw Bureaucrat::Low("Exception: " + name + " 's grade is Too Low");
}

Bureaucrat::~Bureaucrat(){};
 
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _Name(other._Name), _Grade(other._Grade){}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
		_Grade = other._Grade;
	return (*this);
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
		throw Bureaucrat::High("Exception: " + getName() + " 's grade is Too High");
	this->_Grade -= gradeUp;
}

void		Bureaucrat::decrements(int gradeDown)
{
	if (_Grade + gradeDown > 150)
		throw Bureaucrat::Low("Exception: " + getName() + " 's grade is Too Low");
	this->_Grade += gradeDown;
}

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat)
{
	input << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (input);
}

void		Bureaucrat::signForm(Form& form) {
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.get_Name() << std::endl;
	}
	catch(const std::runtime_error &e)
	{
		std::cout << getName() << " couldn't sign " << form.get_Name() << " because of " << e.what() << std::endl;
	}
}
