/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:21:26 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/26 18:06:52 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstring>

enum LogLevel { DEBUG, INFO, WARNING, ERROR };

void		filterMessages(LogLevel minLevel);
const char*	to_string(LogLevel level);

#endif
