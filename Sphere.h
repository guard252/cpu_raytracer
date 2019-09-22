#pragma once
#include "Ray.h"
#include "SceneObject.h"
#include "Math.h"

class Sphere : public SceneObject
{
	Vector3 center; 
	double radius{ 0.0 };
public:
	Sphere();
	Sphere(Vector3 center, double radius, RGBColor* c) :
		SceneObject(c), radius{ radius }, center{ center } {}
	virtual ~Sphere();
	double Radius() { return radius; }

	Sphere& SetCenter(const Vector3& c) { center = c; return *this; }
	Sphere& SetRadius(const double& r) { radius = r; return *this; }
	bool HasPoint(Vector3 point);



	// Inherited via SceneObject
	virtual bool Intersects(Ray ray, Vector3 & p) override;

	// Inherited via SceneObject
	virtual Vector3 GetNormal(Vector3 point) override;
};

