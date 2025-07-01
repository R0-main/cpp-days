/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/01 11:21:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <numbers>
#include <sstream>
#include <string>

class BitcoinExchange
{
  private:
	class CSVParser
	{
		public:
		typedef enum
		{
			INT,
			FLOAT
		} e_type;

		typedef struct
		{
			e_type			type;
			union
			{
				long double	f;
				int			i;
			};
		} t_data;

		typedef std::map<std::string, t_data> t_map;

		CSVParser();
		CSVParser(const CSVParser &other);
		CSVParser &operator=(const CSVParser &other);
		~CSVParser();

		t_map parse(const char *filename, const char *limiter);
		void parse(const char *filename, const char *limiter,
			BitcoinExchange::CSVParser::t_map map, BitcoinExchange &btc);
	};

  public:
	typedef struct
	{
		int					year;
		int					month;
		int					day;
	} t_time;
	CSVParser				parser;
	BitcoinExchange();
	BitcoinExchange(const char *input);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	std::string find_the_cloest_down_in_map(BitcoinExchange::CSVParser::t_map &map,
		BitcoinExchange::t_time time);
	void exec_input(BitcoinExchange::CSVParser::t_map &map, std::string value,
		std::string data);
	~BitcoinExchange();
};
