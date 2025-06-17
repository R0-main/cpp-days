/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 12:02:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
  public:
	Intern(Intern &other);
	Intern(void);
	Intern &operator=(Intern &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target) const;

	class UnknownName : public std::exception
	{
		public:
		UnknownName(void) throw();
		const char *what(void) const throw();
	};
};
