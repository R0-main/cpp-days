/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/24 10:06:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Wall-e");
	ClapTrap clap("Dark Vador");

	clap.attack("Temu");
	scav.attack("Shreck");
	scav.takeDamage(5);
	scav.beRepaired(10);
	// scav.takeDamage(1005);
	scav.beRepaired(10);
	// scav.takeDamage(1005);
	scav.guardGate();
	for (size_t i = 0; i < 9; i++)
	{
		scav.attack("Shreck");
	}
	scav.attack("Shreck");
	scav.beRepaired(10);
	scav.takeDamage(1005);
	return 0;
}

