/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:35:34 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/28 17:11:57 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	convert(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			char c = std::toupper(str[i]);
			std::cout << c;
		}
		else
			std::cout << (str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		convert(argv[1]);
	else if (argc > 2)
	{
		int i = 1;
		while (argv[i] != '\0')
		{
			convert(argv[i++]);
			std::cout << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
