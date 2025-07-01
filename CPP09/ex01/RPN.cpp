/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:45:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/01 14:43:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN::RPN(const char *input) : _input(input)
{
	size_t	i;

	i = 0;
	if (this->_is_valid_input() == false)
	{
		std::cerr << "ERROR : Invalid Input\n";
		return ;
	}
	while (this->_input.empty() == false)
	{
		i = this->_input.find_first_of(NUMBERS OPERATIONS, i);
		if (i == std::string::npos)
			break;
		if (std::isdigit(this->_input[i]))
			this->_numbers.push(this->_input[i]);
		else
			this->_symbols.push(this->_input[i]);
		this->_input = this->_input.substr(i + 1, this->_input.length());
	}
	if (this->_symbols.size() + 1 != this->_numbers.size())
	{
		std::cerr << "ERROR : Invalid Expression\n";
		return ;
	}
	this->_execute();
}

const RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::_is_valid_input() const throw()
{
	return (this->_input.find_first_not_of(SUPPORTED_SYMBOLS) == std::string::npos);
}

long RPN::_execute() throw()
{
	long result = 0;
	char operation;

	result += this->_get_and_pop(this->_numbers) - '0';

	while (this->_numbers.empty() == false)
	{
		operation = this->_get_and_pop(this->_symbols);
		switch (operation)
		{
			case '+':
				result += this->_get_and_pop(this->_numbers) - '0';
				break;
			case '-':
				result -= this->_get_and_pop(this->_numbers) - '0';
				break;
			case '*':
				result *= this->_get_and_pop(this->_numbers) - '0';
				break;
			case '/':
				result /= this->_get_and_pop(this->_numbers) - '0';
				break;
		}
	}
	std::cout << result << "\n";
	return (result);
}
