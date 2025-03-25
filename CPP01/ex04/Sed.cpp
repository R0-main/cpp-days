/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 14:37:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>

Sed::Sed(std::string file_path, std::string target,
	std::string replacment) : _file_path(file_path), _target(target),
	_replacment(replacment)
{
	try
	{
		if (this->_file_path.empty())
			throw std::invalid_argument("Input file not valid !");
		if (this->_target.empty())
			throw std::invalid_argument("Empty word not valid !");
		this->_failed = false;
		this->_output_path = this->_file_path + ".replace";
		this->_process();
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "[Invalid Arg] ";
		std::cerr << e.what() << std::endl;
		this->_failed = true;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "[Runtime Error] ";
		std::cerr << e.what() << std::endl;
		this->_failed = true;
	}
}

Sed::~Sed()
{
}

void Sed::_process(void)
{
	std::string line;
	std::ifstream in_file_stream(this->_file_path.c_str());
	if (!in_file_stream.good())
		throw std::invalid_argument("In file not valid!");
	std::ofstream out_file_stream(this->_output_path.c_str());
	if (!out_file_stream.good())
		throw std::invalid_argument("Out file not valid!");
	while (std::getline(in_file_stream, line))
	{
		if (in_file_stream.fail())
			throw std::runtime_error("In file failed during execution!");
		out_file_stream << this->_replace_word(line);
		if (out_file_stream.fail())
			throw(std::runtime_error("Out file failed during execution!"));
	}
	out_file_stream << std::endl;
}

bool Sed::fail(void) const
{
	return (this->_failed);
}

std::string Sed::_replace_word(std::string str) const
{
	std::string result;
	std::size_t i;

	if (str.find(this->_target, 0) != str.npos)
		while (str.find(this->_target, 0) != str.npos && !str.empty())
		{
			i = str.find(this->_target, 0);
			result += str.substr(0, i);
			result += this->_replacment;
			str = str.substr(i + this->_target.length(), str.length());
		}
	result += str;
	result += '\n';
	return (result);
}
