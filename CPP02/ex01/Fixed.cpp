/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:35:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/06 13:43:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

int const Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_base = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_base = (num << Fixed::_fractional_bits);
	// this->_base = (num * pow(2, Fixed::_fractional_bits)); // remove pow
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_base = num * (1 << Fixed::_fractional_bits) + (num >= 0 ? 0.5 : -0.5);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_base);
}

void Fixed::setRawBits(int const raw)
{
	this->_base = raw;
}

int Fixed::toInt(void) const
{
	return (this->_base >> Fixed::_fractional_bits);
	// return (this->_base / pow(2, Fixed::_fractional_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_base) / (1 << Fixed::_fractional_bits);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (stream);
}
