/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:01:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/13 12:09:34 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Array.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    // Test creating an empty array
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    // Test creating an array of size 5
    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;

    // Test accessing elements of intArray
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i + 1;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // Test copying intArray to another array
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;

    return 0;
}
