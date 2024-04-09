/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:39:36 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/08 15:14:55 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"

int main()
{
	// Create a Data object
	Data data;
	data.ptr = "Hello, World!";
	data.serialized = 12345;

	// Serialize the Data object
	uintptr_t serializedData = Serializer::serialize(&data);

	// Deserialize the serialized data
	Data* deserializedData = Serializer::deserialize(serializedData);

	// Verify that deserializedData is the same as the original data
	if (deserializedData->ptr == data.ptr && deserializedData->serialized == data.serialized) {
		std::cout << "Serialization and deserialization succeeded." << std::endl;
	} else {
		std::cerr << "Serialization and deserialization failed." << std::endl;
	}
	return 0;
}
