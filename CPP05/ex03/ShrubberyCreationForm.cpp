/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:01:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 11:19:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	ShrubberyCreationForm::AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	ShrubberyCreationForm::AForm::execute(executor);
    int i;

	std::string str(this->target);
	str += "_shrubbery";

	std::ofstream outfile;
	outfile.open(str.c_str());
    std::srand((unsigned)std::time(0));
    i = (std::rand()%3);
	if (i == 0)
		outfile << TREE_1 << std::endl;
	if (i == 1)
		outfile << TREE_2 << std::endl;
	if (i == 2)
		outfile << TREE_3 << std::endl;
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
}
