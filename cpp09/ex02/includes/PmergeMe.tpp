/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:51:59 by otuyishi          #+#    #+#             */
/*   Updated: 2024/04/22 16:54:49 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	duoMaker(vec);

	std::cout << "Resulting vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		if (it != vec.begin()) std::cout << ", ";
		std::cout << *it;
	}
	std::cout << std::endl;

	return 0;
}
