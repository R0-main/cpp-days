/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/04 09:37:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac <= 3 || ac > 4)
	{
		std::cerr << "Usage : " << av[0] << " <filepath> <target> <replacment>" << std::endl;
		return (1);
	}
	Sed sed(av[1], av[2], av[3]);
	return (sed.fail());
}
