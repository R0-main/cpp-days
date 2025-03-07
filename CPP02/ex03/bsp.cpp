/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:09:52 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_area = Point::getArea(a, b, c);
	Fixed area1 = Point::getArea(point, b, c);
	Fixed area2 = Point::getArea(a, point, c);
	Fixed area3 = Point::getArea(a, b, point);
	Point l1 = Point::getVector(a, b);
	Point l2 = Point::getVector(a, c);
	Point l3 = Point::getVector(b, c);

	return (
		(triangle_area == area1 + area2 + area3)
		&& !Point::touchVector(a, b, point)
		&& !Point::touchVector(a, c, point)
		&& !Point::touchVector(b, c, point)
	);
}
