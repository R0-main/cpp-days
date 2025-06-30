/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/27 09:28:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <strings.h>

template <typename T> class Array
{
  private:
	typedef unsigned int uint;

	T *_data;
	uint _size;

  public:
	Array() : _data(0), _size(0) {};

	Array(uint n) : _size(n) {
		this->_data = new(std::nothrow) T[n]();
		if (this->_data == 0)
		{
			this->_size = 0;
			return;
		}
	};

	Array(Array &array) : _data(0), _size(0)
	{
		*this = array;
	}

	Array &operator=(Array &other)
	{
		if (this->_data != 0)
			delete[] this->_data;
		this->_data = new(std::nothrow) T[other._size]();
		if (this->_data == 0)
		{
			this->_size = 0;
			return *this;
		}
		for (size_t i = 0; i < other._size; i++)
			this->_data[i] = other._data[i];
		this->_size = other._size;
		return *this;
	}

	T &operator[](uint index) const
	{
		if (index >= this->_size || index < 0)
			throw std::exception();
		return this->_data[index];
	}

	~Array() throw()
	{
		if (this->_data)
			delete[] this->_data;
	}

	uint size() const throw()
	{
		return (this->_size);
	}
};
