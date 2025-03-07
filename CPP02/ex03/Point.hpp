/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 08:56:11 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
  private:
	Fixed const x;
	Fixed const y;

  public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &other);
	Point operator=(Point const &other);

	void print(void);

	~Point();

	static Fixed getArea(Point const p1, Point const p2, Point const p3);
	static Point getVector(Point const p1, Point const p2);
	static bool touchVector(Point const p1, Point const p2, Point const p);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
