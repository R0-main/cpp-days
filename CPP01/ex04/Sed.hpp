/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:33:30 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/04 10:42:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <string>
#include <memory>

#define ERROR_FILE_NOT_VALID "Error, please provide a valid file !"

class Sed
{
  private:
	std::string _file_path;
	std::string _target;
	std::string _replacment;

	std::string _output_path;
	bool _failed;

	void _process(void);
	std::string _replace_word(std::string str) const;

  public:
	Sed(std::string file_path, std::string target, std::string replacment);
	~Sed();

	bool fail(void) const;
};
