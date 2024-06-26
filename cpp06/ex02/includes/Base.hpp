/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:48:48 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 17:59:58 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <string>
# include <cstdlib>

class Base {
	public:
		virtual	~Base(){}
};

// class D : public Base {}; //example meant to FAIL on purpose

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);

#endif
