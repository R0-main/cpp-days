/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:56:53 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/16 09:43:24 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define STR(str) #str
#define STRING(str) STR(str)
#define HIGHEST_GRADE 150
#define LOWEST_GRADE 1

class Bureaucrat
{
  private:
	const std::string name;
	unsigned char grade;

  public:
	Bureaucrat(const Bureaucrat &b);
	Bureaucrat(std::string name, unsigned char grade);
	const Bureaucrat &operator=(const Bureaucrat &b);
	~Bureaucrat() throw();

	std::string getName(void) const throw();
	unsigned int getGrade(void) const throw();

	void	incrementGrade(void);
	void	decrementGrade(void);



	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void) throw();
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void) throw();
		const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
