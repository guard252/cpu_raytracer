#pragma once
#include "Vector3.h"
#include "Object.h"
class Light : public Object
{
protected:
	Vector3 position;
public:
	Light() {}
	Light(Vector3 pos) : position{ pos } {}
	~Light() {}

	Vector3 Position() { return position; }
	Light& SetPosition(Vector3 pos) { position = pos; return *this; }


	// Inherited via Object
	virtual std::string GetType() { return std::string("Light"); }

};

