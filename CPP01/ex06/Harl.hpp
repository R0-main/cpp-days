/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:33:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 12:27:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl
{
  public:
	enum	E_Types
	{
		UNDIFINED = -2,
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
	void setFilterType(char *str);
	Harl::E_Types getFilterType(void) const;

  private:

  typedef struct {
	const char *str;
	Harl::E_Types type;
	}	t_str_to_function;

	static t_str_to_function _mapping[];

	E_Types	_filter;
	std::string _level;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

};
