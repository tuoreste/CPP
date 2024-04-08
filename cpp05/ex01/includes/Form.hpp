/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:33:27 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/07 20:46:44 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <exception>
#include	"../includes/Bureaucrat.hpp"

class	Form {
	public:
		Form();
		Form(const std::string &name, const int Sign_grade, const int Exec_grade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		std::string	get_Name(void) const;
		bool		get_Signature(void) const;
		int			get_Sign_grade(void) const;
		int			get_Exec_grade(void) const;
		void		beSigned(const Bureaucrat& bureaucrat);
		struct High: public std::runtime_error {
			High(const std::string str_sms);
		};
		struct Low: public std::runtime_error {
			Low(const std::string str_sms);
		};

	private:
		const std::string	_Name;
		bool				_Signature;
		const int			_Sign_grade;
		const int			_Exec_grade;
};

std::ostream&	operator<<(std::ostream& output, const Form Form);

#endif
