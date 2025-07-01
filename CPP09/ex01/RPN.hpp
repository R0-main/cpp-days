/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:46:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/01 14:42:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <queue>
#include <stack>

#define NUMBERS "0123456789"
#define SPACES " 	"
#define OPERATIONS "+-/*"
#define SUPPORTED_SYMBOLS NUMBERS OPERATIONS SPACES

class RPN
{
  private:
	std::queue<unsigned char> _numbers;
	std::queue<char> _symbols;
	std::string _input;

	bool _is_valid_input() const throw();

	template <typename T>
	T _get_and_pop(std::queue<T> &queue)
	{
		T tmp = queue.front();
		queue.pop();
		return (tmp);
	}


	long _execute() throw();

  public:
	RPN();
	RPN(const RPN &ref);
	RPN(const char *input);
	const RPN &operator=(const RPN &other);
	~RPN();
};
