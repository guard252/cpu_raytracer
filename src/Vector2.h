#pragma once
#include <cmath>
class Vector2
{
	double x{ 0 }, y{ 0 };
public:
	Vector2();
	Vector2(double x, double y) : x{ x }, y{ y }{}
	~Vector2();

	// Different vector products
	double Dot(Vector2 other)const;
	

	// Vector operations
	double Magnitude()const;
	Vector2 Normalize()const;
	Vector2 operator*(double number)const;
	Vector2 operator-(Vector2 other)const;
	Vector2 operator+(Vector2 other)const;
	bool operator==(Vector2 other)const;

	// Getters
	double X()const { return x; }
	double Y()const { return y; }
	
	//Setters
	Vector2& SetX(double num) { x = num; return *this; }
	Vector2& SetY(double num) { y = num; return *this; }
	Vector2& Set(double num1, double num2)
	{
		x = num1; y = num2;
		return *this;
	}

};

