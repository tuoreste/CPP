/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:21:22 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/26 18:06:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void filterMessages(LogLevel minLevel) {
    const char* messages[] = {
        "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!",
        "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!",
        "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.",
        "This is unacceptable! I want to speak to the manager now."
    };
    const char* levelStrings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = minLevel; i <= ERROR; ++i) {
        std::cout << "[ " << levelStrings[i] << " ]" << std::endl;
        std::cout << messages[i] << std::endl;
    }
}

const char* to_string(LogLevel level) {
	switch (level) {
		case DEBUG: return "DEBUG";
		case INFO: return "INFO";
		case WARNING: return "WARNING";
		case ERROR: return "ERROR";
	}
	return "";
}
