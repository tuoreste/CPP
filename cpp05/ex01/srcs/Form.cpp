/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:30:00 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 20:10:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _Name("Default"), _Signature("Default"), _Sign_grade(0), _Exec_grade(0) {}

Form::~Form(){}

Form::Form(const std::string &name, const int sign_grade, const int exec_grade) :
	_Name(name), _Signature(false), _Sign_grade(sign_grade), _Exec_grade(exec_grade)
{
	if (sign_grade < 1)
		throw std::string("Form::GradeTooHighException");
	if (exec_grade < 1)
		throw std::string("Form::GradeTooHighException");
	if (sign_grade > 150)
		throw std::string("Form::GradeTooLowException");
	if (exec_grade > 150)
		throw std::string("Form::GradeTooLowException");
}

Form::Form(const Form& other) : _Name(other._Name), _Signature(other._Signature), 
      _Sign_grade(other._Sign_grade), _Exec_grade(other._Exec_grade){}

Form&	Form::operator=(const Form& other){
	if (this != &other)
		_Signature = other._Signature;
	return (*this);
}

std::string	Form::get_Name(void) const
{
	return (this->_Name);
}

bool		Form::get_Signature(void) const
{
	return (this->_Signature);
}

int			Form::get_Sign_grade(void) const
{
	return (this->_Sign_grade);
}

int			Form::get_Exec_grade(void) const
{
	return (this->_Exec_grade);
}

std::ostream&	operator<<(std::ostream& output, Form const Form)
{
	output << "Form name: " << Form.get_Name() << "\nForm sign grade: "<< Form.get_Sign_grade() << "\nForm Execution Grade: " <<  Form.get_Exec_grade() << "\nSIGNED AND EXECUTED SUCCESSFULLY";
	return (output);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= get_Sign_grade())
		this->_Signature = true;
	else
		throw std::string("Form::GradeTooLowException");
}
