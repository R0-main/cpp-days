/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 10:01:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void change(int &d)
{
	d = 10;
}

void function(const int &d)
{
	std::cout << d + 5 << "\n";
}

int	main(void)
{
	 int a[] = {0, 1, 5, 10};

	::iter(a, 4, function);
	::iter(a, 4, change);
	::iter(a, 4, function);
	return (0);
}
