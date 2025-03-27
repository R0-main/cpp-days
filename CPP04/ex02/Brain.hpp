/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:13:12 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 11:07:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
  private:
	static const unsigned int _MAX_IDEAS = 100;

  public:
	Brain(void);
	Brain(const Brain &other);
	~Brain();
	Brain &operator=(const Brain &other);

	std::string ideas[Brain::_MAX_IDEAS];
};
