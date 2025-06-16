/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:41:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 11:26:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	// const AAnimal	*meta = new AAnimal();
	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();
	AAnimal	*i2 = new Cat();
	*i2 = i;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();

	// delete meta;
	delete j;
	delete i;
	delete i2;
	return (0);
}
