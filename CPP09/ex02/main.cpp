/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/03 13:49:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include "stdlib.h"
#include <deque>
#include <sstream>
#include <vector>
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

template <typename D>
void print_data(D container, const char *name)
{
	std::cout << name << ":	";
	for (std::vector<long>::iterator i = container.begin(); i != container.end(); i++)
		std::cout << *i << " ";
	std::cout << "\n";
}

int	main(int ac, const char **av)
{
	std::vector<long> vec;
	std::deque<long> deq;

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
		vec.push_back(n);
		deq.push_back(n);
	}

	print_data(vec, "Begin");
	{
		PmergeMe<std::vector>::Timer timer("std::vector");
		PmergeMe<std::vector> pmerge(vec);
		print_data(vec, "After");
	}
	{
		PmergeMe<std::deque>::Timer timer("std::deque");
		PmergeMe<std::deque> pmerge(deq);
	}
	return (0);
}
