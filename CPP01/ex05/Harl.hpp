/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:33:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 10:27:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl
{
  private:

	typedef struct {
		const char *str;
		void (Harl::*func)(void);
	}	t_str_to_function;

	static t_str_to_function _mapping[];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl(void);
	~Harl();
	void complain( std::string level );
};
