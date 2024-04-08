/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:35:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/08 10:46:49 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

void ScalarConverter::cast_chr(char chr)
{
	if (isprint(chr))
		std::cout << "char: " << chr << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(chr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(chr) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(chr) << std::endl;
}

void	ScalarConverter::cast_int(long num)
{
	if (isprint(num))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char: Non displaybale" << std::endl;
	if (static_cast<char>(num) > std::numeric_limits<char>::max() ||
		static_cast<char>(num) < std::numeric_limits<char>::min())
		std::cout << "char: char overflow" << std::endl;
	if (static_cast<int>(num) > std::numeric_limits<int>::max() ||
		static_cast<int>(num) < std::numeric_limits<int>::min())
		std::cout << "int: overflow" << std::endl;
	else 
		std::cout << "int: " << num << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::cast_float(double num)
{
	if (isprint(num))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char: Non displaybale" << std::endl;
	if (static_cast<char>(num) > std::numeric_limits<char>::max() ||
		static_cast<char>(num) < std::numeric_limits<char>::min())
		std::cout << "char: char overflow" << std::endl;
	if (static_cast<int>(num) > std::numeric_limits<int>::max() ||
		static_cast<int>(num) < std::numeric_limits<int>::min())
		std::cout << "int: overflow" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (static_cast<float>(num) > std::numeric_limits<float>::max() ||
		static_cast<float>(num) < std::numeric_limits<float>::min())
		std::cout << "float: overflow" << std::endl;
	else 
		std::cout << "float: " << std::fixed << num << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::cast_double(long double num)
{
	if (isprint(num))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char: Non displaybale" << std::endl;
	if(static_cast<char>(num) > std::numeric_limits<char>::max() ||
		static_cast<char>(num) < std::numeric_limits<char>::min())
		std::cout << "char: char overflow" << std::endl;
	if(static_cast<int>(num) > std::numeric_limits<int>::max() ||
		static_cast<int>(num) < std::numeric_limits<int>::min())
		std::cout << "int: overflow" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if(static_cast<float>(num) > std::numeric_limits<float>::max() ||
		static_cast<float>(num) < std::numeric_limits<float>::min())
		std::cout << "float: overflow" << std::endl;
	else 
		std::cout << "float: " << std::fixed << num << "f" << std::endl;
	if(static_cast<double>(num) > std::numeric_limits<double>::max() ||
		static_cast<double>(num) < std::numeric_limits<double>::min())
		std::cout << "double: overflow" << std::endl;
	else 
		std::cout << "double: " << std::fixed << num << std::endl;
}

std::string	filtered(std::string str, data &conv)
{
	std::istringstream	filter(str);

	if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return ("char");
	filter >> conv.num;
	if (!filter.fail() && filter.eof())
		return ("int");
	filter.clear();
	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
		str = str.substr(0, str.length() - 1);
	filter.str(str);
	filter >> conv.flot;
	if (!filter.fail() && filter.eof())
		return ("float");
	filter.clear();
	filter.str(str);
	filter >> conv.dble;
	if (!filter.fail() && filter.eof())
		return ("double");
	return ("Input Error");
}

void	ScalarConverter::convert(const std::string &str)
{
	ScalarConverter	convert;
	data	data;
	if (filtered(str, data) == "char")
		convert.cast_chr(str[0]);
	else if (filtered(str, data) == "int")
		convert.cast_int(data.num);
	else if (filtered(str, data) == "float")
		convert.cast_float(data.flot);
	else if (filtered(str, data) == "double")
		convert.cast_double(data.dble);
	else
		std::cout << "Input ain't valid" << std::endl;
}

