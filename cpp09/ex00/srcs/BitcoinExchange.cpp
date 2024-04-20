/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:31:12 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/20 16:15:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():_Btc_amount(0), _Path("default") {}

BitcoinExchange::BitcoinExchange(const int &btc_a, const std::string path, std::map<std::string, double> _dataBase):
	_Btc_amount(btc_a), _Path(path), _DataBase(_dataBase) {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpyRhs): _Btc_amount(cpyRhs._Btc_amount){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		_Btc_amount = other._Btc_amount;
	return (*this);
}

bool	BitcoinExchange::leapYear(int year) {
	return (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)));
}

bool	BitcoinExchange::inspect_date(const std::string &string) {
	std::istringstream ss(string);
	int year;
	int month;
	int date;
	char c;
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	ss >> year >> c;
	if (year < 1 || c != '-')
		return false;
	ss >> month >> c;
	if ((month < 1 || month > 12) || c != '-')
		return false;
	ss >> date;
	if (ss.eof() == false)
		return false;
	if (leapYear(year) == true && month == 2)
		return (date > 0 && date < 30);
	if (date < 1 || date > days[month - 1])
		return false;
	return true;
}

void BitcoinExchange::parseDataBase() {
	std::ifstream data_b("database/data.csv");
	if (!data_b.is_open())
		throw BtcException("Opening database Error");
	std::string file_title;
	if (!std::getline(data_b, file_title))
		throw BtcException("Why is your title unreadable");
	std::string row;
	while (std::getline(data_b, row)) {
		std::istringstream iss(row);
		std::string which_date;
		double rate;
		if (std::getline(iss, which_date, ',') && iss >> rate)
			_DataBase[which_date] = rate;
		else
			throw BtcException("Error reading line!");
	}
	data_b.close();
}

int BitcoinExchange::file_reader(int argc, const std::string argv) {
	
	parseDataBase();
	std::ifstream file(argv.c_str());
	if (!file.is_open())
		throw BtcException("Opening File Error");
	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() == true)
			continue;
		std::istringstream ss(line);
		std::string date;
		char	c;
		double value;
		ss >> date >> c >> value;
		if (inspect_date(date) == false) {
			std::cout << "Error: Bad date => " << date <<  std::endl;
			continue;
		}
		if (value < 0) {
			std::cout << "Error: Negative Value" << std::endl;
			continue;			
		}
		if (value > 1000) {
			std::cout << "Error: Too big a value" << std::endl;
			continue;			
		}
		std::map<std::string, double>::iterator it = _DataBase.lower_bound(date);
		if (date < it->first)
			--it;
		if (it == _DataBase.end())
			--it;
		_Btc_amount = value * it->second;
		std::cout << date << " => " << value << " = "
					<< _Btc_amount << std::endl; 
	}
	file.close();
	return 0;
}
