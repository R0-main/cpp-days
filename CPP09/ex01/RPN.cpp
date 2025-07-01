/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:45:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/01 15:59:47 by rguigneb         ###   ########.fr       */
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
	char operation;

	i = 0;
	if (this->_is_valid_input() == false)
	{
		std::cerr << "ERROR : Invalid Input\n";
		return ;
	}
	while (this->_input.empty() == false)
	{
		i = this->_input.find_first_of(NUMBERS OPERATIONS, 0);
		if (i == std::string::npos)
			break;
		if (std::isdigit(this->_input[i]))
			this->_numbers.push(this->_input[i] - '0');
		else
		{
			if (this->_numbers.size() >= 2 )
			{
				operation = this->_input[i];

				int second = this->_get_and_pop(this->_numbers);
				int first = this->_get_and_pop(this->_numbers);

				switch (operation)
				{
					case '+':
						this->_numbers.push(first + second);
						break;
					case '-':
						this->_numbers.push(first - second);
						break;
					case '*':
						this->_numbers.push(first * second);
						break;
					case '/':
						this->_numbers.push(first / second);
						break;
				}
			}
		}
		this->_input = this->_input.substr(i + 1, this->_input.length());
	}
	std::cout << this->_numbers.top() << "\n";
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

// long RPN::_execute() throw()
// {
// 	long result = 0;
// 	char operation;

// 	result += this->_get_and_pop(this->_numbers) - '0';

// 	while (this->_numbers.empty() == false)
// 	{
// 		operation = this->_get_and_pop(this->_symbols);
// 		switch (operation)
// 		{
// 			case '+':
// 				result += this->_get_and_pop(this->_numbers) - '0';
// 				break;
// 			case '-':
// 				result -= this->_get_and_pop(this->_numbers) - '0';
// 				break;
// 			case '*':
// 				result *= this->_get_and_pop(this->_numbers) - '0';
// 				break;
// 			case '/':
// 				result /= this->_get_and_pop(this->_numbers) - '0';
// 				break;
// 		}
// 	}
// 	std::cout << result << "\n";
// 	return (result);
// }
