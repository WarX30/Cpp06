#pragma once

#include <string>
#include <stdint.h>

struct	Data
{
	int			id;
	std::string name;
	float		value;
};

class Serializer
{
	private:
		Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);

};
