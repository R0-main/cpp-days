/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:46:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/03 11:46:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <list>

#define NUMBERS "0123456789"
#define SPACES " 	"
#define OPERATIONS "+-/*"
#define SUPPORTED_SYMBOLS NUMBERS OPERATIONS SPACES

class RPN
{
  private:
	std::stack<long, std::list<long> > _numbers;
	std::string _input;

	bool _is_valid_input() const throw();

	template <typename T>
	T _get_and_pop(std::stack<T, std::list<long> > &queue)
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
