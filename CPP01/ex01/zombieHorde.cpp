/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:37 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 13:53:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie [N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
