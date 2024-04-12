/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:01:37 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/12 09:26:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Array.hpp"
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char **) {
Array<int> numbers(MAX_VAL);
int *mirror = new int[MAX_VAL];
srand(time(NULL));
for (int i = 0; i < MAX_VAL; i++) {
	const int value = rand();
	numbers[i] = value;
	mirror[i] = value;
}
// SCOPE
{
	Array<int> tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++) {
	if (tmp[i] != numbers[i]) {
		std::cerr << "didn't save the same value!!" << std::endl;
		return 1;
	}
	}

	for (int i = 0; i < MAX_VAL; i++) {
	if (test[i] != tmp[i]) {
		std::cerr << "didn't save the same value!!" << std::endl;
		return 1;
	}
	}
}

for (int i = 0; i < MAX_VAL; i++) {
	if (mirror[i] != numbers[i]) {
	std::cerr << "didn't save the same value!!" << std::endl;
	return 1;
	}
}
try {
	std::cout << "mirror[42]: " << mirror[42] << std::endl;
	mirror[42] = 42;
	std::cout << "mirror[42]: " << mirror[42] << std::endl;
	std::cout << "numbers[42]: " << numbers[42] << std::endl;

	numbers[-2] = 0;
} catch (const std::exception &e) {
	std::cerr << e.what() << '\n';
}
try {
	numbers[MAX_VAL] = 0;
} catch (const std::exception &e) {
	std::cerr << e.what() << '\n';
}

for (int i = 0; i < MAX_VAL; i++) {
	numbers[i] = rand();
}
delete[] mirror; //
return 0;
}
