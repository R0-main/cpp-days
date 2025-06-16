/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:33:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/16 11:47:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define STR(str) #str
#define STRING(str) STR(str)
#define HIGHEST_GRADE 150
#define LOWEST_GRADE 1

class Form
{
  private:
	const std::string name;
	bool is_signed;
	const unsigned int min_grade_sign;
	const unsigned int min_grade_execute;

  public:
	Form(const Form &b);
	Form(std::string name, unsigned char min_grade_sign, unsigned char min_grade_execute);
	const Form &operator=(const Form &b);
	~Form() throw();

	void beSigned(Bureaucrat &b);

	const std::string getFormData(void) const throw();

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

std::ostream &operator<<(std::ostream &out, const Form &b);
