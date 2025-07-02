/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:46:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/02 11:12:36 by rguigneb         ###   ########.fr       */
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
	std::stack<long, std::vector<long> > _numbers;
	std::string _input;

	bool _is_valid_input() const throw();

	template <typename T>
	T _get_and_pop(std::stack<T, std::vector<long> > &queue)
	{
		T tmp = queue.top();
		queue.pop();
		return (tmp);
	}

	void _execute(char operation) throw();

  public:
	RPN();
	RPN(const RPN &ref);
	RPN(const char *input);
	const RPN &operator=(const RPN &other);
	~RPN();
};
