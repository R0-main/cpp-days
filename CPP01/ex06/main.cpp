/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 11:13:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl harl;
	std::string str;

	if (ac <= 1 || ac > 2)
	{
		std::cout << "Usage : " << av[0] << " <filter : NONE;ALL;DEBUG;INFO;WARNING;ERROR>" << std::endl;
		return (1);
	}
	// switch ()
	// {
	// 	case str(av[2]):
	// 	/* code */
	// 	break;

	// default:
	// 	break;
	// }
	// harl.setFilterType(HA)
	harl.complain("fwqfqqf");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.setFilterType(Harl::ERROR);
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("INFO");

	return (0);
}
