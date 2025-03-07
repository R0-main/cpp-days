/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/07 10:33:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	Point	b;

	Point a(1, 2);
	b = a;
	a = b;
	b.print();
	a.print();
	if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 15)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 150)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	if (bsp(Point(0, 0), Point(10.54, 0), Point(10.54, 35.74), Point(10.54, 0)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	if (bsp(Point(0, 0), Point(10.54, 0), Point(10.54, 35.74), Point(10.53, 1)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	if (bsp(Point(0, 0), Point(10.54, 0), Point(10.54, 35.74), Point(10.54, 1)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	if (bsp(Point(0, 0), Point(10.54, 0), Point(10.54, 35.74), Point(70.55,
				5.9)))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	return (0);
}
