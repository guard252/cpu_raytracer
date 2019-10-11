#pragma once
#include "Vector3.h"
#include "Ray.h"
#include "Bitmap.h"
#include "Object.h"

class SceneObject : public Object
{
protected:
	RGBColor* color{ nullptr };
public:
	SceneObject() {}
	SceneObject(RGBColor* c) : color{ c } {}
	virtual ~SceneObject() {}

	RGBColor* GetColor() { return color; }
	SceneObject& SetColor(RGBColor* c)
	{
		color = c;
	}

	virtual Vector3 GetNormal(Vector3 point) = 0;
	virtual bool Intersects(Ray ray, Vector3& p) = 0;

	virtual std::string GetType() = 0;
	// ADD GetType!!!!
};

