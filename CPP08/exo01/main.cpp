/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 11:39:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

int	main(void)
{
	Span span(10);


	try
	{
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
		span.addNumber(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int> f(300, 3);
		span.addRange(f.begin(), f.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (Span::const_iterator i = span.begin(); i != span.end(); i++)
	{
		std::cout << *i << ", ";
	}

	std::cout << std::endl;

	return (0);
}

// int	main(void)
// {
// 	Span	sp;

// 	sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return (0);
// }
