/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:46:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 10:50:06 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>
#include <string>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {
private:
	typedef void (Harl::*LogLevelFunction)();
	std::map<LogLevel, LogLevelFunction> logLevelMap;

	void debug();
	void info();
	void warning();
	void error();

public:
	Harl();
	void complain(LogLevel level);
};

#endif
