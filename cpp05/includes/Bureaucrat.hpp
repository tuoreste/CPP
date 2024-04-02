/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:19:45 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/03 00:23:45 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	public:
		Bureaucrat(const std::string &name, int grade);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increments(int gradeUp);
		void		decrements(int gradeDown);

	private:
		const std::string	_Name;
		int					_Grade;
};

std::ostream& operator<<(std::ostream& input, Bureaucrat const& Bureaucrat);

#endif
