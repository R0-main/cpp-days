/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:51:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/04 10:32:12 by rguigneb         ###   ########.fr       */
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
#include <cfloat>
#include <cerrno>
#include <limits.h>
#include <string>

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

template< typename T >
T convert_from_string(const std::string& str)
{
  std::istringstream iss(str);
  T result;
  try
  {
	bool success = iss >> result;
	if(!success || !iss.good()) throw std::exception();
  }
  catch(const std::exception& e)
  {
	// std::cerr << e.what() << '\n';
  }

  return result;
}

template <typename T>
void print_converted(std::string input, T value, long l)
{
	char c;
	float f;
	double d;
	(void)l;

	f = static_cast<float>(value);
	c = static_cast<char>(value);
	d = static_cast<double>(value);

	size_t max_fp = input.find('.');
	if (max_fp != std::string::npos)
		max_fp = input.substr(max_fp + 1, input.length() ).length();
	else
		max_fp = 1;
	if (input.find('f') != std::string::npos)
		max_fp -= 1;

	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nan" << "f" << std::endl;
		std::cout << "double: " << "nan" << std::endl;\
	}
	else if (input == "inf" ||  input == "-inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
	else if (input == "inff" ||  input == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;\
	}
	else
	{
		std::string str = "\'";
		str += c;
		str += "\'";
		if (l < CHAR_MAX && l > CHAR_MIN)
			std::cout << "char: " << ((c >= 32 && c <= 127) ? str : "Non displayable") << "" << std::endl;
		else
			std::cout << "char: " << "impossible" << std::endl;
		if (static_cast<long>(value) <= INT_MAX && static_cast<long>(value) >= INT_MIN)
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		else
			std::cout << "int: " << "impossible" << std::endl;
		if (!std::isinf(f) && !std::isnan(f))
			std::cout << "float: " << std::fixed << std::setprecision(max_fp) << f << "f" << std::endl;
		else if (std::isinf(f))
			std::cout << "float: " << "inff" << std::endl;
		else if (std::isnan(f))
			std::cout << "float: " << "nan" << std::endl;
		else
			std::cout << "float: " << "impossible" << std::endl;
		if (!std::isinf(d) && !std::isnan(d))
			std::cout << "double: " << std::fixed << std::setprecision(max_fp) << d << std::endl;
		else if (std::isinf(f))
			std::cout << "double: " << "inff" << std::endl;
		else if (std::isnan(f))
			std::cout << "double: " << "nan" << std::endl;
		else
			std::cout << "double: " << "impossible" << std::endl;

	}
}

void ScalarConverter::convert(const char *i)
{
	std::string input(i);
	if (input.length() == 1 && input[0] >= 32 && input[0] <= 127 && (input[0] > '9' || input[0] < '0'))
		print_converted(input, input[0], convert_from_string<long>(input));
	else if ((input.find('f') != std::string::npos
			&& input.find('.') != std::string::npos && is_numeric(input, true) && count_letter(input, 'f') == 1 && count_letter(input, '.') == 1)
		|| input == "-inff" || input == "inff" || input == "+inff")
		print_converted(input, atof(input.c_str()), convert_from_string<long>(input));
	else if ((input.find('.') != std::string::npos && is_numeric(input, true) && count_letter(input, 'f') == 0 && count_letter(input, '.') == 1)
		|| input == "-inf" || input == "inf" || input == "+inf")
		print_converted(input, atof(input.c_str()), convert_from_string<long>(input));
	else if (is_numeric(input, false) && count_letter(input, 'f') == 0 && count_letter(input, '.') == 0)
		print_converted(input, atol(input.c_str()), convert_from_string<long>(input));
	else if (input == "nan" || input == "nanf")
		print_converted(input, atol(input.c_str()), convert_from_string<long>(input));
	else
		std::cerr << UMAG BHRED "Error" RESET BLK " > " RESET << "invalid input" << std::endl;
}
