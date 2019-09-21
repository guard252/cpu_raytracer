#include "Vector2.h"



Vector2::Vector2()
{
}

double Vector2::Dot(Vector2 other) const
{
	return x * other.x + y * other.y;
}

double Vector2::Magnitude() const
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Normalize() const
{
	double magn = Magnitude();
	Vector2 a(x / magn, y / magn);
	return a;
}

Vector2  Vector2::operator*(double number) const
{
	Vector2 res(x*number, y*number);
	return res;
}

Vector2  Vector2::operator-(Vector2 other) const
{
	Vector2 res(x - other.x, y - other.y);
	return res;
}

Vector2  Vector2::operator+(Vector2 other) const
{
	Vector2 res(x + other.x, y + other.y);
	return res;
}

bool Vector2::operator==(Vector2 other) const
{
	return x == other.x && y == other.y;
		
}


Vector2::~Vector2()
{
}
