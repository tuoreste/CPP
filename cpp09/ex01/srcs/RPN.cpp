/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:03:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 15:44:23 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() : figures() {}

RPN::~RPN() {}

RPN::RPN(const RPN &cpyRhs) : figures(cpyRhs.figures) {}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other)
		figures.operator=(other.figures);
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
				throw RPN_Exception("Invalid arguments / input!");
			operands++;
		}
		else
			operators++;
	}
	if (operators == (operands - 1 ))
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
	float res;
	std::string token;
	std::istringstream ss(inputString);
	while (ss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
			std::istringstream iss(token);
			if (!(iss >> num))
				throw RPN_Exception("Invalid Input, byeee!");
			figures.push(num);
		} else {
			float first = static_cast<float>(figures.top());
			figures.pop();
			float second = static_cast<float>(figures.top());
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
