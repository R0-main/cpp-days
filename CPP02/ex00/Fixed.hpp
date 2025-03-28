/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:36:02 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/24 09:21:36 by rguigneb         ###   ########.fr       */
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
	~Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
