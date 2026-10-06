#include "../include/Base.hpp"
#include "../include/color.hpp"
#include <exception>

Base::~Base() 
{
	std::cout << BOLD_ON RED << "Base destructor called !" << BOLD_OFF << std::endl;
}

Base *generate(void)
{
	static bool started = false;
	if (!started) {
		std::srand(std::time(NULL));
		started = true;
	}
	switch (std::rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BOLD_ON GREEN << "A" << BOLD_OFF << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BOLD_ON GREEN << "B" << BOLD_OFF << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BOLD_ON GREEN << "C" << BOLD_OFF << std::endl;
	else
		std::cout << BOLD_ON YELLOW << "Unknow" << BOLD_OFF << std::endl;
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BOLD_ON GREEN << "A" << BOLD_OFF << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BOLD_ON GREEN << "B" << BOLD_OFF << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BOLD_ON GREEN << "C" << BOLD_OFF << std::endl;
		return ;
	} catch (...) {}
	std::cout << BOLD_ON YELLOW << "Unknow" << BOLD_OFF << std::endl;
}
