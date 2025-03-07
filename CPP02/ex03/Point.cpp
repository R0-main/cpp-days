/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:02:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/07 10:47:47 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <memory>

Point::Point(void)
{
}

Point::~Point()
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point::Point(Point const &other) : x(other.x), y(other.y)
{
}

Point Point::operator=(Point const &other)
{
	(void)other;
	std::cerr << "Cannot use Point = Point !" << std::endl;
	return (*this);
}

void Point::print(void)
{
	std::cout << "x : " << this->x << std::endl;
	std::cout << "y : " << this->y << std::endl;
}

Point Point::getVector(Point const p1, Point const p2)
{
	Point p(p2.x.toFloat() - p1.x.toFloat(), p2.y.toFloat() - p1.y.toFloat());
	return (p);
}

bool Point::touchVector(Point const p1, Point const p2, Point const p)
{
	Point pvector = Point::getVector(p, p1);
	Point vector = Point::getVector(p1, p2);

	return(Fixed(pvector.x) * vector.y - Fixed(pvector.y) * vector.x == 0);
}

Fixed Point::getArea(Point const p1, Point const p2, Point const p3)
{
	Fixed x1 = p1.x;
	Fixed x2 = p2.x;
	Fixed x3 = p3.x;
	Fixed y1 = p1.y;
	Fixed y2 = p2.y;
	Fixed y3 = p3.y;

	Fixed r = ( x1 * ( y2 -y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 ) ) / 2;
	if (r < 0)
		r.setRawBits(-r.getRawBits());
	return (r);
}
