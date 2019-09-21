#pragma once
#include "Vector3.h"
#include "Bitmap.h"
#include "SceneObject.h"
class Plane : public SceneObject
{
	Vector3 point;
	Vector3 normal{ 1,0,0 };
	

public:
	Plane();
	Plane(Vector3 p, Vector3 n, RGBColor* c) :
		SceneObject{c}, point{ p }, normal{ n }{}

	virtual ~Plane();

	Vector3 Point()const { return point; }
	Vector3 Normal()const { return normal; }
	RGBColor Color()const { return *color; }

	Plane& SetPoint(const Vector3& a) { point = a; return *this; }
	Plane& SetNormal(const Vector3& a) { normal = a; return *this; }
	//Plane& SetColor(const RGBColor* a) { color = a; return *this; }

	// Inherited via SceneObject
	virtual bool Intersects(Ray ray, Vector3 & p) override;
};

