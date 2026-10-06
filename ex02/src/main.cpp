#include "../include/Base.hpp"
#include "../include/color.hpp"

int	main(void)
{
	Base *base1 = generate();
	Base *base2 = NULL;

	std::cout << BOLD_ON BLUE << "Identify by pointer: " << BOLD_OFF;
	identify(base1);

	std::cout << BOLD_ON BLUE << "Identify by reference: " << BOLD_OFF;
	identify(*base1);

	std::cout << BOLD_ON BLUE << "Identify by pointer: " << BOLD_OFF;
	identify(base2);

	std::cout << BOLD_ON BLUE << "Identify by reference: " << BOLD_OFF;
	identify(*base2);

	delete base1;
	return (0);
}
