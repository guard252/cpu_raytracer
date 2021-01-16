#pragma once
#include <cmath>
#define EPS 1e-5
class Vector3
{
	double x{ 0 }, y{ 0 }, z{ 0 };
public:
	Vector3();
	Vector3(double x, double y, double z) : x{ x }, y{ y }, z{ z } {}
	~Vector3();

	// Different vector products
	double Dot(Vector3 other)const;
	Vector3 Cross(Vector3 other)const;
	double Triple(Vector3 other1, Vector3& other2);

	// Vector operations
	double Magnitude()const;
	Vector3 Normalize()const;
	Vector3 operator-()const { return Vector3(-x, -y, -z); }
	Vector3 operator*(double number)const;
	Vector3 operator-(Vector3 other)const;
	Vector3 operator+(Vector3 other)const;
	double operator*(Vector3 other)const;
	bool operator==(Vector3 other)const;
	bool operator!=(Vector3 other) const;
	double Cos(Vector3 other)const;
	// Getters
	double X()const { return x; }
	double Y()const { return y; }
	double Z()const { return z; }

	//Setters
	Vector3& SetX(double num) { x = num; return *this; }
	Vector3& SetY(double num) { y = num; return *this; }
	Vector3& SetZ(double num) { z = num; return *this; }
	Vector3& Set(double num1, double num2, double num3)
	{
		x = num1; y = num2, z = num3;
		return *this;
	}

};

