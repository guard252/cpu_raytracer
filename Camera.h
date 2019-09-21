#pragma once

class Vector2;
class Ray;
class Camera
{

public:
	Camera();
	virtual ~Camera();
	virtual Ray CastRay(const Vector2& point) const = 0;
};

