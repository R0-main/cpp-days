/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:01:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 10:07:16 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	RobotomyRequestForm::AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	RobotomyRequestForm::AForm::execute(executor);
    int i;

    std::srand((unsigned)std::time(0));
    i = (std::rand()%2);
	system("ffplay -loglevel -8 -nodisp -autoexit drill.mp3 2> /dev/null > /dev/null &");
	std::cout << "** Drilling Noise **" << std::endl;
	if (i == 0)
		std::cout << this->target << " has been robotomized!" << std::endl;
	else
		std::cout << this->target << " robotomy failed!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{
}
