/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:03:58 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/09 18:03:07 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <exception>
# include <cstdlib>
#include <stdint.h>

struct Data {
	const char		*ptr;
	uintptr_t	serialized;
};

class Serializer {
	private:
		Serializer(){};
		~Serializer();
		Serializer(const Serializer& other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
