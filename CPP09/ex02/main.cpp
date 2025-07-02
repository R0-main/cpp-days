/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/02 15:09:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include "stdlib.h"
#include <deque>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits.h>

std::list<long> split(const std::string& input) {
    std::list<long> result;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        try {
            long value = atol(token.c_str());
            result.push_back(value);
        } catch (const std::invalid_argument& e) {
            continue;
        } catch (const std::out_of_range& e) {
            continue;
        }
    }

    return result;
}

int	main(int ac, const char **av)
{
	std::list<long> ints;
	if (ac <= 1)
	{
		std::cerr << "ERROR : Invalid Input\n";
		return (1);
	}

	for (int i = 1; i < ac; i++)
	{
		long n = atol(av[i]);
		if (n > INT_MAX || n < INT_MIN || av[i][0] == 0 || std::string(av[i]).find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error\n";
			return (1);
		}
		ints.push_front(n);
	}

	for (std::list<long>::iterator i = ints.begin(); i != ints.end(); i++)
	{
		std::cout << *i << "\n";
	}

	PmergeMe< std::deque<long> > pmerge(ints);

	return (0);
}
