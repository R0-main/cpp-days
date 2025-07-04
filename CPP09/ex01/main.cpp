/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/02 14:27:22 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int	main(int ac, const char **av)
{
	if (ac <= 1 || ac > 2)
	{
		std::cerr << "ERROR : Invalid Input\n";
		return (1);
	}
	RPN btc(av[1]);
	return (0);
}
