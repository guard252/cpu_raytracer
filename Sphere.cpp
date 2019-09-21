#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

bool Sphere::HasPoint(Vector3 point)
{
	return pow(center.X() - point.X(), 2) +
		pow(center.Y() - point.Y(), 2) +
		pow(center.Z() - point.Z(), 2) - radius * radius < 1e-8;
}

// We only get  the intersection point which is closest
// to the origin
bool Sphere::Intersects(Ray ray, Vector3 & p)
{
	double a = ray.Direction().Dot(ray.Direction());
	double b = 2 * ray.Direction().Dot(ray.Origin() - center);
	double c = (ray.Origin() - center).Dot(ray.Origin() - center) - radius * radius;
	double t1, t2;
	if (Quadratic(a, b, c, t1, t2))
	{
		double t = fabs(t1) < fabs(t2) ? t1 : t2;
		
		p = ray.Origin() + ray.Direction() * t;
		if (p != ray.Origin())
		{
			return true;
		}
	}
	return false;

}
