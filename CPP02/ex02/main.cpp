/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/06 15:47:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	Fixed	a;

	// Fixed const b(Fixed(5.05f) + Fixed(2.0f));
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	a = a++;
	std::cout << ++a << std::endl ;
	std::cout << a++ << std::endl ;
	std::cout << a << std::endl ;
	std::cout << --a << std::endl ;
	std::cout << a-- << std::endl ;
	std::cout << a << std::endl ;

	std::cout << (Fixed(5.05f) + Fixed(2.0f)) << std::endl ;
	std::cout << (Fixed(5.05f) - Fixed(2.0f)) << std::endl ;
	std::cout << (Fixed(5.05f) * Fixed(2.0f)) << std::endl ;
	std::cout << (Fixed(5.05f) / Fixed(2.0f)) << std::endl ;
	// exit((a++).toInt());
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	// std::cout << Fixed::min(a, b) << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}
