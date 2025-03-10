/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/10 12:19:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap robot("Wall-e");
	ClapTrap clap("Dark Vador");

	clap.attack("Temu");
	robot.attack("Shreck");
	robot.takeDamage(5);
	robot.beRepaired(10);
	// robot.takeDamage(1005);
	robot.beRepaired(10);
	// robot.takeDamage(1005);

	for (size_t i = 0; i < 9; i++)
	{
		robot.attack("Shreck");
	}
	robot.attack("Shreck");
	robot.beRepaired(10);
	robot.takeDamage(1005);
	return 0;
}

