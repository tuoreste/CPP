/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:43:11 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/24 10:50:45 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.cpp
#include "Harl.hpp"

void Harl::debug() {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {
	logLevelMap[DEBUG] = &Harl::debug;
	logLevelMap[INFO] = &Harl::info;
	logLevelMap[WARNING] = &Harl::warning;
	logLevelMap[ERROR] = &Harl::error;
}

void Harl::complain(LogLevel level) {
	std::map<LogLevel, LogLevelFunction>::iterator it = logLevelMap.find(level);
	if (it != logLevelMap.end()) {
		(this->*(it->second))();
	} else {
		std::cout << "Unknown log level!" << std::endl;
	}
}
