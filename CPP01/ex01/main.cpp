/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:40:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 13:57:52 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZOMBIE_HORDE_COUNT 10

int main(void)
{
	Zombie *heap_zombies;

	heap_zombies = zombieHorde(ZOMBIE_HORDE_COUNT, "Emerik");
	for (size_t i = 0; i < ZOMBIE_HORDE_COUNT; i++)
	{
		heap_zombies[i].announce();
	}
	delete[] heap_zombies;
	return (0);
}


