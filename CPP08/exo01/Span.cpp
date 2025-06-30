/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:26:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 11:38:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(const Span &span)
{
	*this = span;
}

Span::Span(size_t size) : _size(size)
{
	this->_array.reserve(size);
	std::cout << "Span of _size created!\n";
}

Span &Span::operator=(Span span)
{
	this->_array = span._array;
	this->_size = span._size;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_array.size() >= this->_size)
		throw std::exception();
	this->_array.push_back(n);
}

void Span::addRange(Span::iterator begin, Span::iterator end)
{
	size_t	dist = std::distance(begin, end);
	if (_array.size() + dist > _size)
		throw std::exception();
	this->_array.insert(_array.end(), begin, end);
}

Span::const_iterator Span::begin() const throw()
{
	return (this->_array.begin());
}

Span::iterator Span::begin() throw()
{
	return (this->_array.begin());
}

Span::iterator Span::end() throw()
{
	return (this->_array.end());
}

Span::const_iterator Span::end() const throw()
{
	return (this->_array.end());
}

size_t Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw std::exception();

	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());

	std::vector<size_t> diffs;
	for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i)
		diffs.push_back(static_cast<size_t>(tmp[i] - tmp[i - 1]));

	return (*std::min_element(diffs.begin(), diffs.end()));
}

size_t Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::exception();

	int minVal = *std::min_element(_array.begin(), _array.end());
	int maxVal = *std::max_element(_array.begin(), _array.end());

	return (static_cast<size_t>(maxVal - minVal));
}

Span::~Span()
{
	std::cout << "Span deleted !\n";
}
