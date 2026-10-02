#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/* ---------- Parsing / detection ---------- */

static bool	checkChar(const std::string &s)
{
	return (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])));
}

static bool parseNumber(const std::string &literal, double *value)
{
	char *endptr;

	*value = std::strtod(literal.c_str(), &endptr);
	if (endptr == literal.c_str())
		return false;
	if (*endptr == '\0')
		return true;
	return (*endptr == 'f' && *(endptr + 1) == '\0');
}

static e_type	detectType(const std::string &literal, double value)
{
	size_t	i;

	if (std::isnan(value))
	{
		if (literal == "nan")
			return TYPE_DOUBLE;
		if (literal == "nanf")
			return TYPE_FLOAT;
		return TYPE_INVALID;
	}
	if (std::isinf(value))
	{
		if (literal == "-inf" || literal == "+inf")
			return TYPE_DOUBLE;
		if (literal == "-inff" || literal == "+inff")
			return TYPE_FLOAT;
		return TYPE_INVALID;
	}
	i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	while (i < literal.size() && std::isdigit(static_cast<unsigned char>(literal[i])))
		i++;
	if (i == literal.size())
		return TYPE_INT;
	if (literal[i] != '.')
		return TYPE_INVALID;
	i++;
	while(i < literal.size() && std::isdigit(static_cast<unsigned char>(literal[i])))
		i++;
	if (i == literal.size())
		return TYPE_DOUBLE;
	if ((literal[i] == 'f' && i + 1 == literal.size()))
		return TYPE_FLOAT;
	return TYPE_INVALID;
}

/* ---------- Range checks ---------- */

static bool canConvertToChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
		return false;
	if (std::fmod(value, 1.0) != 0.0)
		return false;
	return (value >= std::numeric_limits<char>::min()
			&& value <= std::numeric_limits<char>::max());
}

static bool canConvertToInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
			return false;
	return (value >= std::numeric_limits<int>::min()
			 && value <= std::numeric_limits<int>::max());
}

static bool canConvertToFloat(double value)
{
	if (std::isnan(value) || std::isinf(value))
			return true;
	return (value >= -std::numeric_limits<float>::max()
			 && value <= std::numeric_limits<float>::max());
}

/* ---------- Display ---------- */

static void printInvalid()
{
	std::cout << RED << "Error: invalid input!" << RESET << std::endl;
}

static void	printNotPossible(const std::string &type)
{
	std::cout << BOLD_ON << "[" << type << "]: " << BOLD_OFF
			  << BLUE << "Conversion to " << type
			  << " impossible!" << RESET << std::endl;
}

static void	toChar(char value)
{
	std::cout << BOLD_ON << "[char]: " << BOLD_OFF;
	if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << YELLOW << "Non displayable!" << RESET;
	else
		std::cout << GREEN << "'" << value << "'" << RESET; 
	std::cout << std::endl;
}

static void	toInt(int value)
{
	std::cout << BOLD_ON << "[int]: " << BOLD_OFF
			<< GREEN << value << RESET << std::endl;
}

static void toFloat(float value)
{
	std::cout << BOLD_ON << "[float]: " << BOLD_OFF
			  << std::fixed << std::setprecision(1) << GREEN;
	if (std::isnan(value))
		std::cout << "nanf";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff");
	else
		std::cout << value << "f";
	std::cout << RESET << std::endl;
}

static void	toDouble(double value)
{
	std::cout << BOLD_ON << "[double]: " << BOLD_OFF
			  << std::fixed << std::setprecision(1) << GREEN;
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << value;
	std::cout << RESET << std::endl;
}

/* ---------- Conversions ---------- */

static void formChar(char value)
{
	toChar(value);
	toInt(static_cast<int>(value));
	toFloat(static_cast<float>(value));
	toDouble(static_cast<double>(value));
}

static void	formNumber(double value)
{
	if (canConvertToChar(value))
		toChar(static_cast<char>(value));
	else
		printNotPossible("char");
	if (canConvertToInt(value))
		toInt(static_cast<int>(value));
	else
		printNotPossible("int");
	if (canConvertToFloat(value))
		toFloat(value);
	else
		printNotPossible("float");
	toDouble(value);
}

void	ScalarConverter::convert(const std::string &literal)
{
	double value;
	e_type type;

	if (literal.empty())
		return (printInvalid());
	if (checkChar(literal))
		return (formChar(literal[0]));
	if (!parseNumber(literal, &value))
		return (printInvalid());
	type = detectType(literal, value);
	if (type == TYPE_INVALID)
		return (printInvalid());
	formNumber(value);
}
