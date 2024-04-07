/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:19:45 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/05 16:42:45 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
    	Bureaucrat& operator=(const Bureaucrat& other);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increments(int gradeUp);
		void		decrements(int gradeDown);
		void		signForm(Form& form);
		struct High: public std::runtime_error {
			High(const std::string str_sms);
		};
		struct Low: public std::runtime_error {
			Low(const std::string str_sms);
		};

	private:
		const std::string	_Name;
		int					_Grade;
};

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat);

#endif
