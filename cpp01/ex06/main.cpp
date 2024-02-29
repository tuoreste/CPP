/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:21:30 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/26 18:16:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "How to use: " << "./harlFilter" << " <LOG_LEVEL>" << std::endl;
		return 1;
	}

	LogLevel minLevel;
	const char* levelStr = argv[1];

	if (std::strcmp(levelStr, "I am not sure how tired I am today...") == 0) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	else if (std::strcmp(levelStr, "DEBUG") == 0) {
		minLevel = DEBUG;
	} else if (std::strcmp(levelStr, "INFO") == 0) {
		minLevel = INFO;
	} else if (std::strcmp(levelStr, "WARNING") == 0) {
		minLevel = WARNING;
	} else if (std::strcmp(levelStr, "ERROR") == 0) {
		minLevel = ERROR;
	} else {
		std::cerr << "Plz pass a valid level: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	filterMessages(minLevel);
	return 0;
}
