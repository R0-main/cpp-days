/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:36:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/07 08:53:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
  private:
	int _base;
	static const int _fractional_bits;

  public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	Fixed &operator++();   // prefix
	Fixed operator++(int); // postfix

	Fixed &operator--();   // prefix
	Fixed operator--(int); // postfix

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);
