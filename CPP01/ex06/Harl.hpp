/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:33:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 11:00:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl
{
  public:
	enum	E_Types
	{
		NONE = -1,
		ALL,
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	Harl(void);
	~Harl();
	void complain(std::string level);
	void setFilterType(Harl::E_Types type);

  private:
	E_Types	_filter;
	std::string _level;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};
