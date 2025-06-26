/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 12:18:16 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <strings.h>

template <typename T> class Array
{
  private:
	T *data;
	unsigned int size;

  public:
	Array(){
		this->data = 0;
		this->size = 0;
	};

	Array(unsigned int n){
		this->size = n;
		this->data = new T[n];
		bzero(this->data, sizeof(T) * n);
	};

	Array(Array &array)
	{
		*this = array;
	}

	Array &operator=(Array &other)
	{
		delete[] this->data;
		this->data = new T[other.size];
		bzero(this->data, sizeof(T) * other.size);
		for (size_t i = 0; i < other.size; i++)
			this[i] = other[i];
		this->size = other.size;
	}

	T &operator[](unsigned int index)
	{
		if (index >= this->size)
			throw std::exception();
		return this->data[index];
	}

	~Array()
	{
		delete[] this->data;
	}
};
