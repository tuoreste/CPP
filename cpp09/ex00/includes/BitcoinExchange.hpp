/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:08:55 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/28 15:41:10 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <list>
# include <string>
# include <cstring>
# include <sys/stat.h>
# include <iomanip>
# include <ctime>
# include <cstdlib>

// Create a Program which outputs value certain amount of BITCOIN on a certain DATE.
// Program must use a database in csv format, represents bitcoin price over time.(given)
// Program takes input a second database, storing different prices/dates to evaluate.
// Program respects these rules:
// • The program name is btc.
// • Your program must take a file as argument.
// • Each line in this file must use the following format: "date | value".
// • A valid date will always be in the following format: Year-Month-Day.
// • A valid value must be either a float or a positive integer, between 0 and 1000.

typedef struct yearMonthDay {
	int	year;
	int	month;
	int	day;
}		y_m_d;

class BitcoinExchange {
	public:
		//canonics
		BitcoinExchange();
		BitcoinExchange(const int &btc_a, const std::string path, std::map<std::string, double> _dataBase);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpyRhs);
		BitcoinExchange& operator=(const BitcoinExchange &other);

		// my funcs
		bool				leapYear(int year);
		void 				parseDataBase();
		int					file_reader(int argc, const std::string argv);
		bool				inspect_date(const std::string &date);

		struct BtcException: std::runtime_error {
			BtcException(const std::string &sms): std::runtime_error(sms) {
				std::cout << "BtcException terminates with error: " << sms << std::endl;
			}
		};
		std::map<std::string, double>	_DataBase;

	private:
		int 							_Btc_amount;
		std::string						_Path;
};

#endif
