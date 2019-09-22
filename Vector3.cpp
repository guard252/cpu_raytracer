#include "Vector3.h"



Vector3::Vector3()
{
}

double Vector3::Dot(Vector3 other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Cross(Vector3 other) const
{
	double newX = y * other.z - other.y * z;
	double newY = x * other.z - other.x * z;
	double newZ = x * other.y - other.x * y;
	Vector3 result(newX, newY, newZ);
	return result;
}

double Vector3::Triple(Vector3 other1, Vector3 & other2)
{
	return Cross(other1).Dot(other2);
}

double Vector3::Magnitude() const
{
	return std::sqrt(x*x + y * y + z * z);
}

Vector3 Vector3::Normalize() const
{
	double magn = Magnitude();
	Vector3 a(x / magn, y / magn, z / magn);
	return a;
}

Vector3 Vector3::operator*(double number) const
{
	Vector3 res(x*number, y*number, z * number);
	return res;
}

Vector3 Vector3::operator-(Vector3 other) const
{
	Vector3 res(x - other.x, y - other.y, z - other.z);
	return res;
}

Vector3 Vector3::operator+(Vector3 other) const
{
	Vector3 res(x + other.x, y + other.y, z + other.z);
	return res;
}

double Vector3::operator*(Vector3 other) const
{
	return x*other.x + y*other.y + z*other.z;
}

bool Vector3::operator==(Vector3 other) const
{
	return fabs(x - other.x) < EPS &&
		fabs(y - other.y) < EPS &&
		fabs(z - other.z) < EPS;
}

bool Vector3::operator!=(Vector3 other) const
{
	return fabs(x - other.x) > EPS ||
		fabs(y - other.y) > EPS ||
		fabs(z - other.z) > EPS;
}

double Vector3::Cos(Vector3 other)const
{
	return  (*this * other) / (Magnitude() * other.Magnitude());
}


Vector3::~Vector3()
{
}
