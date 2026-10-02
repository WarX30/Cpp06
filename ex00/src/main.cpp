#include "../include/ScalarConverter.hpp"
#include <iostream>

// static void	printSection(const std::string &title)
// {
// 	std::cout << "\n========================================\n";
// 	std::cout << "  " << title << "\n";
// 	std::cout << "========================================\n";
// }
//
// static void	test(const std::string &literal)
// {
// 	std::cout << "\nInput: \"" << literal << "\"" << std::endl;
// 	ScalarConverter::convert(literal);
// }
//
// int	main(void)
// {
// 	printSection("CHARACTERS");
// 	test("a");
// 	test("A");
// 	test("?");
// 	test("+");
// 	test("-");
//
// 	printSection("INTEGERS");
// 	test("0");
// 	test("7");
// 	test("42");
// 	test("-42");
// 	test("127");
// 	test("128");
//
// 	printSection("FLOATS");
// 	test("42.5f");
// 	test("-42.5f");
// 	test("0.0f");
// 	test("127.5f");
// 	test("42.0");
// 	test("42.0f");
//
// 	printSection("DOUBLES");
// 	test("42.5");
// 	test("-42.5");
// 	test("0.0");
// 	test("127.5");
//
// 	printSection("SPECIAL VALUES");
// 	test("nan");
// 	test("nanf");
// 	test("+inf");
// 	test("-inf");
// 	test("+inff");
// 	test("-inff");
//
// 	printSection("INTEGER LIMITS");
// 	test("2147483647");
// 	test("2147483648");
// 	test("-2147483648");
// 	test("-2147483649");
//
// 	printSection("INVALID INPUT");
// 	test("abc");
// 	test("42abc");
// 	test("42ff");
// 	test("42.5ff");
// 	test("");
// 	test(".");
// 	test(".5");
// 	test("5.");
//
// 	return (0);
// }

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return (0);
	}
	std::cout << BOLD_ON RED << "Error: " << BOLD_OFF
			  << GREEN << "do ./convert <char/number>" << RESET << std::endl;
	return (0);
}
