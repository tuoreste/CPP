/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:22:45 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/05 13:52:01 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
    	Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increments(int gradeUp);
		void		decrements(int gradeDown);

		void		signForm(AForm& form);
		void		executeForm(AForm const & form);

	private:
		const std::string	_Name;
		int					_Grade;
};

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat);

#endif
