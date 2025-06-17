/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:01:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 11:13:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{

  public:
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm(std::string &target);
	RobotomyRequestForm &operator=(RobotomyRequestForm &other);

	void execute(Bureaucrat const & executor) const;

	~RobotomyRequestForm() throw();
};
