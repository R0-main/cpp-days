/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:01:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 10:45:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{

  public:
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm(std::string &target);
	PresidentialPardonForm &operator=(PresidentialPardonForm &other);

	void execute(Bureaucrat const &executor) const;

	~PresidentialPardonForm() throw();
};
