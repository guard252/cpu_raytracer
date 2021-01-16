#include "Plane.h"



Plane::Plane()
{
}


Plane::~Plane()
{
}

bool Plane::Intersects(Ray ray, Vector3 & p)
{
	//if (fabs((ray.Direction() - ray.Origin()).Dot(normal)) > 1e-8)
	double denom = fabs(ray.Direction().Dot(normal));
	if(denom > 1e-8)
	{
		double t;
		t = (point - ray.Origin()).Dot(normal) / ray.Direction().Dot(normal);
		if (t > 0)
		{
			p = ray.Origin() + ray.Direction() * t;
			return true;
		}
	}
	return false;
}

Vector3 Plane::GetNormal(Vector3 point)
{
	return normal;
}

std::string Plane::GetType()
{
	return std::string("Plane");
}
