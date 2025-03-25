/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 10:15:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("Diamond");
	FragTrap frag("Frag");
	ScavTrap scav("Scav");

	diamond.whoAmI();
	scav.display();
	frag.display();
	diamond.display();
	diamond.attack("Frag");
	return 0;
}

