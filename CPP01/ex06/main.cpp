/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 12:29:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl harl;

	if (ac <= 1 || ac > 2)
	{
		std::cout << "Usage : " << av[0] << " <filter : NONE;ALL;DEBUG;INFO;WARNING;ERROR>" << std::endl;
		return (1);
	}
	harl.setFilterType(av[1]);
	if (harl.getFilterType() == Harl::UNDIFINED)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	harl.complain("fwqfqqf");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return (0);
}
