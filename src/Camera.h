#pragma once
#include "Object.h"
class Vector2;
class Ray;
class Camera : public Object
{

public:
	Camera() {}
	virtual ~Camera() {}
	virtual Ray CastRay(const Vector2& point) const = 0;

	// Inherited via Object
	virtual std::string GetType() = 0;
};

