/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 11:28:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
  private:
	std::vector<int> _array;
	size_t _size;

  public:
	typedef std::vector<int>::iterator iterator;
	typedef std::vector<int>::const_iterator const_iterator;

	Span();
	Span(const Span &span);
	Span(size_t size);
	Span &operator=(Span span);
	~Span();

	const_iterator begin() const throw();
	const_iterator end() const throw();
	iterator begin() throw();
	iterator end() throw();

	size_t shortestSpan() const;
	size_t longestSpan() const;

	void addNumber(int n);
	void addRange(iterator begin, iterator end);
};
