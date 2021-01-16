#pragma once
#include <string>
class Object
{
public:
	Object() {}
	~Object() {}

	virtual std::string GetType() = 0;
};

