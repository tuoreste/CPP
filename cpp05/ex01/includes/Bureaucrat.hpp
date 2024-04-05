/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:19:45 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 19:50:24 by otuyishi         ###   ########.fr       */
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

	private:
		const std::string	_Name;
		int					_Grade;
};

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat);

#endif
