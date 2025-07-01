/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/01 11:21:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *input)
{
	BitcoinExchange::CSVParser::t_map map = this->parser.parse("data.csv", ",");
	if (map.empty())
		return ;
	this->parser.parse(input, "|", map, *this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::CSVParser::CSVParser()
{
}

BitcoinExchange::CSVParser::CSVParser(const CSVParser &other)
{
	*this = other;
}

BitcoinExchange::CSVParser &BitcoinExchange::CSVParser::operator=(const CSVParser &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

BitcoinExchange::CSVParser::~CSVParser()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////

struct	IsNotSpace
{
	bool operator()(unsigned char ch) const
	{
		return (!std::isspace(ch));
	}
};

std::string trim(std::string s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), IsNotSpace()));
	s.erase(std::find_if(s.rbegin(), s.rend(), IsNotSpace()).base(), s.end());
	return (s);
}

BitcoinExchange::t_time get_time_from(std::string &str)
{
	BitcoinExchange::t_time time;
	std::string copy(str);
	time.year = atoi(copy.substr(0, copy.find('-')).c_str());
	copy.erase(0, copy.find('-') + 1);
	time.month = atoi(copy.substr(0, copy.find('-')).c_str());
	copy.erase(0, copy.find('-') + 1);
	time.day = atoi(copy.substr(0, copy.find('-')).c_str());
	copy.erase(0, copy.find('-') + 1);
	return (time);
}

std::string BitcoinExchange::find_the_cloest_down_in_map(BitcoinExchange::CSVParser::t_map &map,
	BitcoinExchange::t_time time)
{
	long	target_date;
	long	closest_date;
	long	current_date;

	std::string closest_key = "";
	target_date = time.year * 10000 + time.month * 100 + time.day;
	closest_date = -1;
	for (BitcoinExchange::CSVParser::t_map::iterator it = map.begin(); it != map.end(); ++it)
	{
		std::string current_key = it->first;
		BitcoinExchange::t_time current_time = get_time_from(current_key);
		current_date = current_time.year * 10000 + current_time.month * 100
			+ current_time.day;
		if (current_date <= target_date)
		{
			if (current_date > closest_date)
			{
				closest_key = current_key;
				closest_date = current_date;
			}
		}
	}
	return (closest_key);
}

int	get_decimal_length(double number)
{
	if (std::isnan(number) || std::isinf(number))
	{
		return (0);
	}
	std::ostringstream oss;
	oss << std::fixed << number;
	std::string str = oss.str();
	std::string::size_type dot_pos = str.find('.');
	if (dot_pos == std::string::npos)
	{
		return (0);
	}
	std::string decimal_part = str.substr(dot_pos + 1);
	while (!decimal_part.empty() && decimal_part[decimal_part.length()
		- 1] == '0')
	{
		decimal_part.erase(decimal_part.length() - 1);
	}
	return (static_cast<int>(decimal_part.length()));
}

bool	contains_only(const std::string &str, const char *allowed)
{
	return (str.find_first_not_of(allowed) == std::string::npos);
}

void BitcoinExchange::exec_input(BitcoinExchange::CSVParser::t_map &map,
	std::string data, std::string value)
{
	BitcoinExchange::t_time time = get_time_from(data);
	long double v_doubl = atof(value.c_str());
	if (time.year < 0 || time.month <= 0 || time.month > 12 || time.day <= 0
		|| time.day >= 31)
	{
		std::cout << "Error: bad input => " << data << "\n";
		return ;
	}
	if (v_doubl < 0)
	{
		std::cout << "Error: not a positive number."
					<< "\n";
		return ;
	}
	if (v_doubl > INT_MAX)
	{
		std::cout << "Error: too large a number."
					<< "\n";
		return ;
	}
	if (!contains_only(data, "0123456789- 	") || !contains_only(value,
				"0123456789."))
	{
		std::cout << "Error: invalid line chars."
					<< "\n";
		return ;
	}
	std::string date = BitcoinExchange::find_the_cloest_down_in_map(map, time);
	BitcoinExchange::CSVParser::t_data target = (date.empty() ? map[data] : map[date]);
	long double n = (target.type == BitcoinExchange::CSVParser::FLOAT ? target.f : target.i);
	std::cout << data << " => " << std::fixed << std::setprecision(get_decimal_length(n
			* v_doubl)) << value << " = " << n * v_doubl << "\n";
}

BitcoinExchange::CSVParser::t_map BitcoinExchange::CSVParser::parse(const char *filename,
	const char *limiter)
{
	BitcoinExchange::CSVParser::t_map map;
	std::string str;
	std::string data;
	std::string value;
	try
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			std::cerr << "Error: could not open file" << std::endl;
			return (map);
		}
		std::getline(file, str);
		while (std::getline(file, str))
		{
			data = trim(str.substr(0, str.find(limiter)));
			value = trim(str.erase(0, str.find(limiter)
						+ std::string(limiter).length()));
			if (!contains_only(data, "0123456789- 	") || !contains_only(value,
						"0123456789."))
				continue ;
			if (value.find('.') != std::string::npos)
			{
				map[data] = (t_data){.type = FLOAT, .f = atof(value.c_str())};
			}
			else
			{
				map[data] = (t_data){.type = INT, .i = atoi(value.c_str())};
			}
		}
		file.close();
	}
	catch (const std::ifstream::failure &e)
	{
		std::cerr << "Exception opening/reading file" << '\n';
	}
	return (map);
}

void BitcoinExchange::CSVParser::parse(const char *filename,
	const char *limiter, BitcoinExchange::CSVParser::t_map map,
	BitcoinExchange &btc)
{
	std::string str;
	std::string data;
	std::string value;
	try
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			std::cerr << "Error: could not open file" << std::endl;
			return ;
		}
		std::getline(file, str);
		while (std::getline(file, str))
		{
			data = trim(str.substr(0, str.find(limiter)));
			value = trim(str.erase(0, str.find(limiter)
						+ std::string(limiter).length()));
			btc.exec_input(map, data, value);
		}
		file.close();
	}
	catch (const std::ifstream::failure &e)
	{
		std::cerr << "Exception opening/reading file" << '\n';
	}
}
