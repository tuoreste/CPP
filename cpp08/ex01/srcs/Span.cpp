/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:10:52 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/16 12:07:15 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(): _N(0), _Cont(0){}

Span::Span(const unsigned int &n): _N(n), _Cont(0){}

Span::Span(const Span &other): _N(other._N), _Cont(other._Cont) {
	_Cont.reserve(_N);
}

Span::~Span(){}

Span& Span::operator<<(const Span &other){
	_Cont.insert(_Cont.end(), other._Cont.begin(), other._Cont.end());
	return (*this);
}

Span::excepioN::excepioN(const std::string& str_sms) : std::runtime_error(str_sms){}

//addNumber() to add a single number to the Span
//It will be used in order to fill it.
//Any attempt to add a new element if there are already N elements stored should throw an exception.
void Span::addNumber(unsigned int addMe)
{
	if (_N > _Cont.size())
		_Cont.push_back(addMe);
	else
		throw Span::excepioN("The container is full");
}

//If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.
// the shortest span(distance) btn all the numbers stored
unsigned int	Span::shortestSpan(void)
{
	if (_Cont.size() <= 1)
		throw Span::excepioN("no span can be found!");
	unsigned int	distance = 0;
	unsigned int _short = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < _Cont.size(); i++)
	{
		for (unsigned int j = i + 1; j < _Cont.size(); j++)
		{
			distance = std::abs(_Cont[i] - _Cont[j]);
			_short = std::min(distance, _short);
		}
	}
	return _short;
}

//the longest span(distance) btn all the numbers stored
unsigned int	Span::longestSpan(void) const
{
	if (_Cont.size() <= 1)
		throw Span::excepioN("no span can be found!");
	std::vector<int>::const_iterator maxA = std::max_element(_Cont.begin(), _Cont.end());
	std::vector<int>::const_iterator maxB = std::min_element(_Cont.begin(), _Cont.end());
	unsigned int x = *maxA;
	unsigned int y = *maxB;
	return (x - y);
}

void	Span::print() const {
	std::cout << "{ ";
	for (std::vector<int>::const_iterator it = _Cont.begin(); it != _Cont.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << "}\n";
}