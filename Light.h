#pragma once
#include "Vector3.h"
class Light
{
protected:
	Vector3 position;
public:
	Light() {}
	Light(Vector3 pos) : position{ pos } {}
	~Light() {}

	Vector3 Position() { return position; }
	Light& SetPosition(Vector3 pos) { position = pos; return *this; }

};

