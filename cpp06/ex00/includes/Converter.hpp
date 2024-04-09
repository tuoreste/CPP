/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:35:41 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 18:10:59 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream> 
# include <iomanip>
# include <string>
# include <exception>
# include <sstream>
# include <limits>

struct data
{
	char			chr;
	long			num;
	double			flot;
	long double		dble;
};

class ScalarConverter {
	private:
		static void			convert(const std::string &str);

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		void	cast_chr(char c);
		void	cast_int(long data_type);
		void	cast_float(double data_type);
		void	cast_double(long double data_type);
};

#endif
