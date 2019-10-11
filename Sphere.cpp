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
		double t;
		if (t1 > t2) std::swap(t1, t2);

		if (t1 < 0) {
			t1 = t2; // if t0 is negative, use t1 instead 
			if (t1 < 0) return false; // both t0 and t1 are negative 
		}

		t = t1;
		p = ray.Origin() + ray.Direction() * t;
		if (p == ray.Origin())
			p = ray.Origin() + ray.Direction() * t2;

		return true;

	}
	return false;

}

Vector3 Sphere::GetNormal(Vector3 point)
{
	return point - center;
}

std::string Sphere::GetType()
{
	return std::string("Sphere");
}
