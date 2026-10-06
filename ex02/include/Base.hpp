#pragma once

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
