/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:35:26 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/13 09:40:24 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"

class Point {
	private:
		int x;
		int y;
	public:
		Point(int x, int y) : x(x), y(y) {}
		void print() const {
			std::cout << "(" << x << ", " << y << ")" << std::endl;
		}
};

// Method to double integers
void doubleInt(int x) {
	x *= 2;
	std::cout << "Doubled int: " << x << std::endl;
}

// Method to print strings in reverse
void reverseString(const std::string& str) {
	std::string reversed(str.rbegin(), str.rend());
	std::cout << "Reversed string: " << reversed << std::endl;
}

// Method to print Point objects
void printPoint(const Point& p) {
	std::cout << "Point: ";
	p.print();
}

//print empty
void printInt(int x) {
    std::cout << x << " ";
}

void tester() {
	// Testing with integers
	int arrInt[] = {1, 2, 3, 4, 5};
	std::cout << "Testing with (integers):" << std::endl;
	iter(arrInt, 5, doubleInt);

	// Testing with strings
	std::string arrStr[] = {"hello", "world", "open", "ai"};
	std::cout << "\nTesting with (strings):" << std::endl;
	iter(arrStr, 4, reverseString);

	// Testing with const type (const int)
	const int arrConst[] = {1, 2, 3, 4, 5};
	std::cout << "\nTesting with const type (const int):" << std::endl;
	try {
		iter(arrConst, 5, doubleInt);
	} catch (const std::exception& e) {
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// Testing with complex type (Point)
	std::vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(3, 4));
    points.push_back(Point(5, 6));
	std::cout << "\nTesting with complex type (Point):" << std::endl;
	iter(&points[0], points.size(), printPoint);
    std::cout << std::endl;

	// Test with an empty array
    int emptyArray[0];
    std::cout << "Testing with (empty) array:" << std::endl;
    iter(emptyArray, 0, printInt);
    std::cout << std::endl;

    // Test with an empty container (e.g., vector)
    std::vector<int> emptyVector;
    std::cout << "Testing with (empty) vector:" << std::endl;
    iter(emptyVector.data(), emptyVector.size(), printInt);
    std::cout << std::endl;

}
