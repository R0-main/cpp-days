/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/10 11:31:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap robot("Wall-e");

	ClapTrap robot2 = robot;
	robot2.attack("Shreck");
	robot2.takeDamage(5);
	robot2.beRepaired(10);
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

