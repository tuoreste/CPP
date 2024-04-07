/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:00:21 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/06 15:50:09 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("ShrubberyCreationForm", 145, 137, "42HN") {}

ShrubberyCreationForm::ShrubberyCreationForm (const std::string &target) : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm (){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

const std::string ShrubberyCreationForm::_tree = 
							"      ###\n"
							"     #o###\n"
							"   #####o###\n"
							"  #o#\\#|#/###\n"
							"   ###\\|/#o#\n"
							"    # }|{  #\n"
							"      }|{\n";

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkFormAction(executor);
	std::ofstream out_f((get_Target() + "_shrubbery").c_str());
	if (!out_f) {
		throw std::runtime_error("File creation error");
	}
	out_f << _tree;
	out_f.close();
}
