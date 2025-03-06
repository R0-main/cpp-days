/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:35:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/06 15:47:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

int const Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	this->_base = 0;
}

Fixed::Fixed(const int num)
{
	this->_base = (num << Fixed::_fractional_bits);
	// this->_base = (num * pow(2, Fixed::_fractional_bits)); // remove pow
}

Fixed::Fixed(const float num)
{
	this->_base = num * (1 << Fixed::_fractional_bits) + (num >= 0 ? 0.5 :
			-0.5);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
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

Fixed &Fixed::operator++()
{
	this->_base += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++(*this);
	return (old);
}

Fixed &Fixed::operator--()
{
	this->_base -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--(*this);
	return (old);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed added;
	int n = this->_base + other.getRawBits();
	added.setRawBits(n);
	return (added);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed subst;
	int n = this->_base - other.getRawBits();
	subst.setRawBits(n);
	return (subst);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed multi;
	int n = ((int64_t)this->_base * (int64_t)other.getRawBits()) >> Fixed::_fractional_bits;
	multi.setRawBits(n);
	return (multi);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed divid;
	int n = ((int64_t)this->_base << Fixed::_fractional_bits) / (int64_t)other.getRawBits();
	divid.setRawBits(n);
	return (divid);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1.getRawBits() < f2.getRawBits() ? f1 : f2);
}

Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (Fixed &)(f1.getRawBits() < f2.getRawBits() ? f1 : f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return (Fixed &)(f1.getRawBits() < f2.getRawBits() ? f2 : f1);
}

Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (Fixed &)(f1.getRawBits() < f2.getRawBits() ? f2 : f1);
}
