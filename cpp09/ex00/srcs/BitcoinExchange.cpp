/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:31:12 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/18 12:51:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():_Btc_amount(0), _Path("default") {}

BitcoinExchange::BitcoinExchange(const int &btc_a, const std::string path):_Btc_amount(btc_a), _Path(path) {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpyRhs): _Btc_amount(cpyRhs._Btc_amount){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		_Btc_amount = other._Btc_amount;
	return (*this);
}

void				BitcoinExchange::setPath(std::string path){
	_Path = path;
}

int					BitcoinExchange::getBtc_amount(void) const {
	return (this->_Btc_amount);
}

const std::string	BitcoinExchange::getPath(void) const {
	return (this->_Path);
}

bool BitcoinExchange::str_path_check(std::string path) {
	const std::string extension = ".csv";
	size_t dotPos = path.find_last_of('.');
	if (dotPos != std::string::npos) {
		std::string fileExtension = path.substr(dotPos);
		if (fileExtension == extension) {
			struct stat buffer;
			return (stat(path.c_str(), &buffer) == 0);
		}
	}
	return (false);
}

bool				BitcoinExchange::inspect_date(const std::string &date) {
	std::tm t = {};
	std::istringstream ss(date);
	ss >> std::get_time(&t, "%Y-%m-%d");
	if (ss.fail()) {
		throw BtcException("Date Format Unrecognized!");
	}
	std::cout << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << std::endl;
	return (true);
}


int	BitcoinExchange::file_reader(int argc, const std::string argv)
{
	if (str_path_check(argv) == false)
		throw BtcException("Path not found");
	setPath(argv);
	std::ifstream file(_Path);
	if (!file.is_open())
		throw BtcException("Opening File Error");
	std::string file_title;
	if (!std::getline(file, file_title))
		throw BtcException("Why is your title unreadable");
	std::map<std::string, double> dataMap;
	std::string	line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		double	value;
		if (std::getline(iss, date, ',') && iss >> value)
		{
			dataMap[date] = value;
			inspect_date(date);
		}
		else
		{
			std::cout << line << std::endl;
			throw BtcException("Error reading line!");
		}
	}
	file.close();
	// std::map<std::string, double>::iterator it;
	// std::cout << file_title << std::endl;
	// for (it = dataMap.begin(); it != dataMap.end(); it++){
	// 	std::cout << it->first << "," << std::fixed << std::setprecision(2) << it->second << std::endl;
	// }
	return (0);
}
