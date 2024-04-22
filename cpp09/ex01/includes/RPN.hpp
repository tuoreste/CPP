/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:02:28 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/21 15:08:04 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <sstream>
# include <fstream>
# include <exception>
# include <iostream>
# include <iomanip>
# include <stack>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN &cpyRhs);
		RPN& operator=(const RPN &other);
		int		parse(const std::string &inputString);
		bool	inspectInput(const std::string &inputString);
		struct RPN_Exception: std::runtime_error {
			RPN_Exception(const std::string &sms): std::runtime_error(sms) {
				std::cout << "RPN_Exception terminates with error: " << sms << std::endl;
			}
		};
		std::stack<int>	figures;
};

#endif
