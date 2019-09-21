#pragma once
#include "Vector3.h"
#include "Ray.h"
#include "Bitmap.h"

class SceneObject
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


	virtual bool Intersects(Ray ray, Vector3& p) = 0;
};

