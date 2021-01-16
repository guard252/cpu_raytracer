#pragma once
#include "Vector3.h"
class SceneObject;
class Ray
{
	Vector3 origin, direction{ 1.0, 0.0, 0.0 };
public:
	Ray();
	Ray(Vector3 o) :origin{ o } {}
	Ray(Vector3 o, Vector3 d) : origin{ o }, direction{ d }{}
	~Ray();


	// This method is used to find
	// any point on ray by formula
	// P(t) = O + t*D
	Vector3 PointOnRay(double t) { return origin + direction * t; }


	// Hit a scene object and get
	// scene point(s) if exist
	bool Hit(SceneObject* o, Vector3& point1);

	//Getters
	Vector3 Origin()const { return origin; }
	Vector3 Direction()const { return direction; }
	
	//Setters
	Ray& SetOrigin(const Vector3 o) { origin = o; return *this; }


};

