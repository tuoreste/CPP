/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:35:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 16:14:13 by otuyishi         ###   ########.fr       */
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
	int asInt;
	float asFloat;
	double asDouble;

	std::cout << "char: ";
	if (isprint(chr))
		std::cout << "'" << chr << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	asInt = static_cast<int>(chr);
	asFloat = static_cast<float>(chr);
	asDouble = static_cast<double>(chr);
	std::cout << "int: " << asInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void ScalarConverter::cast_int(long num)
{
	char asChar;
	int asInt;
	float asFloat;
	double asDouble;

	asChar = static_cast<char>(num);
	asInt = static_cast<int>(num);
	asFloat = static_cast<float>(num);
	asDouble = static_cast<double>(num);
	if (isprint(num))
		std::cout << "char: " << "'" << asChar << "'" << std::endl;
	else if (num >= std::numeric_limits<char>::max() || num <= std::numeric_limits<char>::min())
		std::cout << "char: char overflow" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: ";
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		std::cout << "overflow" << std::endl;
	else
		std::cout << asInt << std::endl;
	std::cout << "float: " << std::fixed << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void ScalarConverter::cast_float(double num)
{
	int asInt;
	float asFloat;

	if (isprint(num))
		std::cout << static_cast<char>(num) << std::endl;
	else if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		std::cout << "char: char overflow" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	asInt = static_cast<int>(num);
	std::cout << "int: ";
	if (asInt > std::numeric_limits<int>::max() || asInt < std::numeric_limits<int>::min())
		std::cout << "overflow" << std::endl;
	else
		std::cout << asInt << std::endl;
	asFloat = static_cast<float>(num);
	std::cout << "float: ";
	std::cout << std::fixed << asFloat << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << num << std::endl;
}

void ScalarConverter::cast_double(long double num)
{
	int asInt;
	float asFloat;
	double asDouble;

    if (isprint(num))
        std::cout << static_cast<char>(num) << std::endl;
    else if (num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
        std::cout << "char: char overflow" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    asInt = static_cast<int>(num);
    std::cout << "int: ";
    if (asInt > std::numeric_limits<int>::max() || asInt < std::numeric_limits<int>::min())
        std::cout << "overflow" << std::endl;
    else
        std::cout << asInt << std::endl;
    asFloat = static_cast<float>(num);
    std::cout << "float: "
     			<< std::fixed << asFloat << "f" << std::endl;
    asDouble = static_cast<double>(num);
    std::cout << "double: ";
    if (asDouble > std::numeric_limits<double>::max() || asDouble < std::numeric_limits<double>::min())
        std::cout << "overflow" << std::endl;
    else
        std::cout << std::fixed << asDouble << std::endl;
}

std::string filtered(std::string str, data &conv)
{
	std::istringstream filter(str);
	size_t len;

	if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return "char";
	filter >> conv.num;
	if (!filter.fail() && filter.eof())
		return "int";
	len = str.length();
	if (len > 1 && (str[len - 1] == 'f' || str[len - 1] == 'F')) {
		filter.clear();
		filter.str(str.substr(0, len - 1));
		filter >> conv.flot;
		if (!filter.fail() && filter.eof())
			return "float";
	}
	filter.clear();
	filter.str(str);
	filter >> conv.dble;
	if (!filter.fail() && filter.eof())
		return "double";
	return "Input Error";
}

void	ScalarConverter::convert(const std::string &str)
{
	ScalarConverter	convert;
	data	data;
	std::string result = filtered(str, data);
	result == "char" ? convert.cast_chr(str[0]) :
	result == "int" ? convert.cast_int(data.num) :
	result == "float" ? convert.cast_float(data.flot) :
	result == "double" ? convert.cast_double(data.dble) :
	(void)(std::cout << "Input ain't valid" << std::endl);
}
