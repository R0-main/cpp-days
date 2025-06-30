/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 09:15:22 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{

	std::vector<int> t;

	t.push_back(2);
	t.push_back(3);
	t.push_back(4);
	t.push_back(5);
	t.push_back(100);

	try
	{
		int n = easyfind(t, 5);

		std::cout << n << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		int n = easyfind(t, 145);

		std::cout << n << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}
