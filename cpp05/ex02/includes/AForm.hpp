/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:16:27 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 12:55:39 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <string>
#include <exception>
#include	"../includes/Bureaucrat.hpp"

class	AForm {
	public:
		// Canonical Form
		AForm();
		AForm(const std::string &name, const int Sign_grade, const int Exec_grade, const std::string &target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Getters
		const std::string		get_Name(void) const;
		const std::string		get_Target(void) const;
		bool					get_Signature(void) const;
		int						get_Sign_grade(void) const;
		int						get_Exec_grade(void) const;

		// Public methods
		void			beSigned(const Bureaucrat& bureaucrat);
		void			checkFormAction(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_Name;
		bool				_Signature;
		const int			_Sign_grade;
		const int			_Exec_grade;
		std::string			_Target;
};

// std::ostream&	operator<<(std::ostream& output, const AForm AForm);
   
#endif
