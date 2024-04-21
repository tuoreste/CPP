/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/21 13:37:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &cpyRhs) {
	(void)cpyRhs;
}

RPN& RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

bool	RPN::inspectInput(const std::string &inputString)
{
	int num;
	int operands = 0;
	int operators = 0;
	std::string token;
	std::istringstream ss(inputString);
	while (ss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
			std::istringstream iss(token);
			if (!(iss >> num))
				;
			operands++;
		}
		else
			operators++;
	}
	if (operators == (operands -1 ))
		return (true);
	return (false);
}

int RPN::parse(const std::string &inputString) {
	if (inputString.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw RPN_Exception("Invalid Input, byeee!");
	if (isdigit(inputString[inputString.size() -1]))
		throw RPN_Exception("Should end with an operand at least!");
	if (inspectInput(inputString) == false)
		throw RPN_Exception("Oparators should be one less from operands!");
	int num;
	int res;
	std::string token;
	std::istringstream ss(inputString);
	while (ss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
			std::istringstream iss(token);
			if (!(iss >> num))
				throw RPN_Exception("Invalid Input, byeee!");
			figures.push(num);
		} else {
			int first = figures.top();
			figures.pop();
			int second = figures.top();
			figures.pop();
			if (token == "*")
				res = second * first;
			if (token == "/")
				res = second / first;
			if (token == "+")
				res = second + first;
			if (token == "-")
				res = second - first;
			figures.push(res);
		}
	}
	res = figures.top();
	std::cout << res << std::endl;
	return (res);
}
