/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/24 10:37:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap robot("Wall-e");
	// ScavTrap robot2("TEST");
	ClapTrap clap("Dark Vador");
	FragTrap frag("GTA 6");


	// robot = robot2;

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
	frag.highFivesGuys();
	return 0;
}

