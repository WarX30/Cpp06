#include "../include/Serializer.hpp"
#include "../include/color.hpp"
#include <iostream>

static void	printData(const std::string &title, Data *data)
{
	std::cout << BOLD_ON << title << RESET << std::endl;
	if (data == NULL)
	{
		std::cout << YELLOW << "NULL" << RESET << std::endl;
		return ;
	}
	std::cout << "id    = " << BLUE << data->id << RESET << std::endl;
	std::cout << "name  = " << BLUE << data->name << RESET << std::endl;
	std::cout << "value = " << BLUE << data->value << RESET << std::endl;
}

static void	testData(Data *data)
{
	uintptr_t	raw;
	Data		*result;

	raw = Serializer::serialize(data);
	result = Serializer::deserialize(raw);

	printData("Original Data:", data);
	printData("Deserialized Data:", result);

	std::cout << "Original pointer     = " << data << std::endl;
	std::cout << "Serialized value     = " << raw << std::endl;
	std::cout << "Deserialized pointer = " << result << std::endl;

	if (data == result)
		std::cout << GREEN << "PASS: pointers match!" << RESET << std::endl;
	else
		std::cout << RED << "FAIL: pointers do not match!" << RESET << std::endl;

	if (data != NULL && result != NULL
		&& data->id == result->id
		&& data->name == result->name
		&& data->value == result->value)
		std::cout << GREEN << "PASS: data match!" << RESET << std::endl;
	else if (data == NULL && result == NULL)
		std::cout << GREEN << "PASS: NULL preserved!" << RESET << std::endl;
	else
		std::cout << RED << "FAIL: data do not match!" << RESET << std::endl;
}

int	main()
{
	Data	data1 = {1, "Eric", 245.04f};
	Data	data2 = {42, "Wariss", 42.42f};
	Data	data3 = {-10, "Test", -123.45f};
	Data	*nullData = NULL;

	std::cout << BOLD_ON << "\n========== TEST 1 =========="
			  << RESET << std::endl;
	testData(&data1);

	std::cout << BOLD_ON << "\n========== TEST 2 =========="
			  << RESET << std::endl;
	testData(&data2);

	std::cout << BOLD_ON << "\n========== TEST 3 =========="
			  << RESET << std::endl;
	testData(&data3);

	std::cout << BOLD_ON << "\n========== TEST 4 : NULL =========="
			  << RESET << std::endl;
	testData(nullData);

	return (0);
}
