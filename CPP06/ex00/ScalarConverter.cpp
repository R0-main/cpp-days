/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:51:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/19 12:19:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

size_t count_letter(std::string str, char c)
{
	size_t count = 0;
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

bool is_numeric(const std::string& str) {
   for (size_t i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

template <typename T>
void print_converted(std::string input, T value)
{
	char c;
	float f;
	double d;
	c = static_cast<char>(value);
	f = static_cast<float>(value);
	d = static_cast<double>(value);

	std::cout << "char: '" << ((c >= 32 && c <= 127) ? c : 'i') << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(input.length()) << f  << "f" << std::endl;
	std::cout << "double: " << std::fixed <<  std::setprecision(input.length()) << d << std::endl;
}

void ScalarConverter::convert(const char *i)
{
	std::string input(i);
	if (input.length() == 1 && input[0] >= 32 && input[0] <= 127)
		print_converted(input, input[0]);
	else if ((input.find('f') != std::string::npos
			&& input.find('.') != std::string::npos)
		|| (input.find("ff") != std::string::npos && count_letter(input, 'f') <= 2))
		print_converted(input, atof(input.c_str()));
	else if (input.find('.') != std::string::npos
		|| input.find("inf") != std::string::npos)
		print_converted(input, atof(input.c_str()));
	else if (is_numeric(input))
		print_converted(input, atoi(input.c_str()));
	else
		std::cerr << "Invalid Input" << "\n";
}
