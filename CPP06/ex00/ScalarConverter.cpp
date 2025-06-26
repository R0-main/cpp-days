/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:51:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 09:33:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <sstream>
#include <stdio.h>
#include <cmath>
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

bool is_numeric(const std::string& str, bool t)
{
   for (size_t i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-') {
			if (t && (str[i] == 'f' || str[i] == '.'))
				continue;
			else
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

	size_t max_fp = input.find('.');
	if (max_fp != std::string::npos)
		max_fp = input.substr(max_fp + 1, input.length() ).length();
	else
		max_fp = 1;
	if (input.find('f') != std::string::npos)
		max_fp -= 1;

	if (input == "nan")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nan" << "f" << std::endl;
		std::cout << "double: " << "nan" << std::endl;\
	}
	else
	{
		std::string str = "\'";
		str += c;
		str += "\'";
		std::cout << "char: " << ((c >= 32 && c <= 127) ? str : "Non displayable") << "" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(max_fp) << f  << "f" << std::endl;
		std::cout << "double: " << std::fixed  << std::setprecision(max_fp) << d << std::endl;
	}
}

void ScalarConverter::convert(const char *i)
{
	std::string input(i);
	if (input.length() == 1 && input[0] >= 32 && input[0] <= 127)
		print_converted(input, input[0]);
	else if ((input.find('f') != std::string::npos
			&& input.find('.') != std::string::npos && is_numeric(input, true) )
		|| input == "-inff" || input == "inff" || input == "+inff")
		print_converted(input, atof(input.c_str()));
	else if ((input.find('.') != std::string::npos && is_numeric(input, true))
		|| input == "-inf" || input == "inf" || input == "+inf")
		print_converted(input, atof(input.c_str()));
	else if (is_numeric(input, false))
		print_converted(input, atoi(input.c_str()));
	else if (input == "nan")
		print_converted(input, atoi(input.c_str()));
	else
		std::cerr << UMAG BHRED "Error" RESET BLK " > " RESET << "invalid input" << std::endl;
}
