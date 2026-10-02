#pragma once

#include <string>
#include <iostream>
#include "color.hpp"

enum e_type
{
	TYPE_INVALID,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter();
			
	public:
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static void convert(const std::string &literal);

};
