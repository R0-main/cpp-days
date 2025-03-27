/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:06:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[CONSTRUCTOR] 🧠" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "[COPY CONSTRUCTOR] 🧠" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "[DESTRUCTOR] 🧠" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "[COPY ASIGNEMENT] 🧠" << std::endl;
	for (size_t i = 0; i < Brain::_MAX_IDEAS; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
