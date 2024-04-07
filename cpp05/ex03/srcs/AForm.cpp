/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:16:56 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 15:50:52 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _Name("unknown"), _Signature(false), _Sign_grade(0), _Exec_grade(0), _Target("default") {}

AForm::~AForm(){}

AForm::AForm(const std::string &name, const int sign_grade, const int exec_grade, const std::string &target) :
	_Name(name), _Signature(false), _Sign_grade(sign_grade), _Exec_grade(exec_grade), _Target(target)
{
	if (sign_grade < 1)
		throw std::string("AForm::GradeTooHighException");
	if (exec_grade < 1)
		throw std::string("AForm::GradeTooHighException");
	if (sign_grade > 150)
		throw std::string("AForm::GradeTooLowException");
	if (exec_grade > 150)
		throw std::string("AForm::GradeTooLowException");
}

AForm::AForm(const AForm& other) : _Name(other._Name), _Signature(other._Signature), 
      _Sign_grade(other._Sign_grade), _Exec_grade(other._Exec_grade), _Target(other._Target) {}

AForm&	AForm::operator=(const AForm& other){
	if (this != &other)
	{
		_Signature = other._Signature;
		_Target = other._Target;
	}
	return (*this);
}

const std::string	AForm::get_Name(void) const
{
	return (this->_Name);
}

const std::string	AForm::get_Target(void) const
{
	return (this->_Target);
}

bool		AForm::get_Signature(void) const
{
	return (this->_Signature);
}

int			AForm::get_Sign_grade(void) const
{
	return (this->_Sign_grade);
}

int			AForm::get_Exec_grade(void) const
{
	return (this->_Exec_grade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= get_Sign_grade())
		this->_Signature = true;
	else
		throw std::string("AForm::GradeTooLowException");
}

void	AForm::checkFormAction(Bureaucrat const & executor) const {
	if (!get_Signature()){
		throw std::string("Form is not signed");
	}
	if (executor.getGrade() > get_Sign_grade()){
        throw std::string("Bureaucrat's grade is too low to execute the form");
	}
}